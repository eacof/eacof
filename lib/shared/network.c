/**
    @file

    @brief Code to undertake communication between EACOF-aware components.

    Communication allows components to keep track of the current state of other components.

    The Central Authority acts as a central hub, listening on messages from Providers and Consumers.
    Providers and Consumers connect to the Central Authority, sending messages to it.
    Responses may be sent back depending on the command.

    Messages are sent as packets which contain information in a header.
    This header information includes the network protocol version and the length of the packet.
    This allows packets to be buffered and handled even if multiple packets or a part packet is received at a time.

    The current implementation uses sockets to communicate.
    Because of this, communication may occur between components on different physical machines.

    An alternative network implementation may be created and will likely impact the network-related members on the `_eacof` struct.

    @see internal-structure.md
*/
#include <eacof/network.h>

extern eacof_config *_eacof;

/**
    Connects to a socket on the specified hostname and port
    If successful, will set a global variable with the connected sockfd
    If unsuccessful, will return an error code

    @param[in] node The hostname to connect to.
    @param[in] port The port to connect to.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_connectTo(char *node, char *port) {
    int sockfd;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct addrinfo *currInfo;
    int status;

    eacofLog("Network Init", "Attempting to connect to Node: %s Port: %s", node, port);

    // indicate that we want a streaming socket, but don't care about the IP version
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // try and find information about where we wish to connect to
    eacofLog("Network Init", "Attempting to find out where to connect to");
    status = getaddrinfo(node, port, &hints, &servinfo);
    if(status != 0) {
        // there was a problem connecting
        eacofLogError("Network Init", EACOF_ERR_NETWORK_INIT, "getaddrinfo() non-zero return code");
        return EACOF_ERR_NETWORK_INIT;
    }

    // loop through the list of potential places to connect to, trying to find a valid one
    eacofLog("Network Init", "Attempting to find somewhere valid to connect to");
    for(currInfo = servinfo; currInfo != NULL; currInfo = currInfo->ai_next) {
        // find a socket descriptor
        eacofLog("Network Init", "Attempting to find a socket descriptor");
        sockfd = socket(currInfo->ai_family, currInfo->ai_socktype, currInfo->ai_protocol);
        if(sockfd == -1) {
            // there was an error creating the socket
            continue;
        }

        // try connecting to the socket
        eacofLog("Network Init", "Attempting to connect to the found socket");
        status = connect(sockfd, currInfo->ai_addr, currInfo->ai_addrlen);
        if(status == -1) {
            // there was an error connecting
            continue;
        }

        // if we have reached this point, we have connected successfully so can stop checking
        break;
    }

    eacofLog("Network Init", "Finished working out where to connect to");
    if(currInfo == NULL) {
        // the end of the list was reached and no connection was made
        freeaddrinfo(servinfo);
        eacofLogError("Network Init", EACOF_ERR_NETWORK_INIT, "No connection made after all options checked");
        return EACOF_ERR_NETWORK_INIT;
    }

    freeaddrinfo(servinfo);

    // add information about the connection to the _eacof struct
    eacofLog("Network Init", "Making note of where has been connected to");
    _eacof->connectedSockfd = sockfd;
    // create a buffer for the new socket
    eacof_addNewSocket(_eacof->netBuffers, sockfd);

    eacofLog("Network Init", "Connected to %d successfully", sockfd);

    return EACOF_OK;
}

/**
    Connects to a default hostname-port combination

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_connectToDefault() {
    eacofLog("Network Init", "Connecting to default location");

    return eacof_connectTo("localhost", "50345");
}

/**
    Listens for incoming connections on the specified hostname and port
    This allows for a passive monitoring of incoming connections, not active seeking
    Functionality along these lines is required by the daemon

    @param[in] node The hostname to connect to.
    @param[in] port The port to connect to.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_listenOn(char *node, char *port) {
    int sockfd;
    struct addrinfo hints, *servinfo, *currInfo;
    int status;

    eacofLog("Network Init", "Attempting to listen on Node: %s Port: %s", node, port);

    // clear the master and temp sets of sockets being listened on
    // so that we are effectively starting from scratch
    FD_ZERO(&_eacof->master_fdSet);
    FD_ZERO(&_eacof->working_fdSet);

    // indicate that we want a passive streaming socket, but don't care about the IP version
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // try and find information about where we wish to connect to
    status = getaddrinfo(node, port, &hints, &servinfo);
    if(status != EACOF_OK) {
        // there was a problem connecting
        eacofLogError("Network Init", EACOF_ERR_NETWORK_INIT, "getaddrinfo() non-zero return code");
        return EACOF_ERR_NETWORK_INIT;
    }

    // loop through the list of potential places to connect to, trying to find a valid one
    for(currInfo = servinfo; currInfo != NULL; currInfo = currInfo->ai_next) {
        // find a socket descriptor
        sockfd = socket(currInfo->ai_family, currInfo->ai_socktype, currInfo->ai_protocol);
        if(sockfd == -1) {
            // there was an error creating the socket
            continue;
        }

        // allow address reuse
        int yes = 1;
        setsockopt(_eacof->listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        // try binding to the socket
        status = bind(sockfd, currInfo->ai_addr, currInfo->ai_addrlen);
        if(status == -1) {
            // there was a problem binding to the socket
            close(sockfd);
            continue;
        }

        // if we have reached this point, we have bound successfully so can stop checking
        break;
    }

    if(currInfo == NULL) {
        // the end of the list was reached and no connection was made
        freeaddrinfo(servinfo);
        eacofLogError("Network Init", EACOF_ERR_NETWORK_INIT, "No connection made after all options checked");
        return EACOF_ERR_NETWORK_INIT;
    }

    freeaddrinfo(servinfo);

    // start listening on a socket
    status = listen(sockfd, 20);
    if(status == -1) {
        // there was a problem listening
        eacofLogError("Network Init", EACOF_ERR_NETWORK_INIT, "Problem listening on chosen location");
        return EACOF_ERR_NETWORK_INIT;
    }

    // keep track of the _eacof->listener with the master set
    FD_SET(sockfd, &_eacof->master_fdSet);
    // and make it known that this is the _eacof->listener
    _eacof->listener = sockfd;

    // keep track of the biggest file descriptor
    _eacof->fdmax = sockfd > _eacof->fdmax ? sockfd : _eacof->fdmax;

    eacofLog("Network Init", "Listening on %d successfully", sockfd);

    return EACOF_OK;
}

/**
    Listens on the default hostname-port combination

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_listenOnDefault() {
    eacofLog("Network Init", "Listening on default location");

    return eacof_listenOn("localhost", "50345");
}

/**
    Handles a packet in the received buffer
    (the buffer may contain many packets)

    @param[in] buf The buffer to handle
    @param[in] msgLen The length of the packet to handle, in bytes.
    @param[in] sockfd The associated socket.
    @param[in] receivedData Data to be passed on to the handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_handlePacketInBuffer(eacof_nettype *buf, int16_t msgLen, int sockfd, eacof_netrecv_t *receivedData) {
    eacof_nettype *tmpBuf;
    eacof_Command cmd;

    eacofLog("Network Handling", "Handling packet of length %" PRIi16 " from %d", msgLen, sockfd);

    tmpBuf = buf;

    // the next couple of bytes contain the command
    tmpBuf = eacof_deserialize_command(tmpBuf, &cmd);
    receivedData->cmd = cmd;

    // act on the correct command
    switch(cmd) {
        case EACOF_CMD_PROBE_CREATE:
            tmpBuf = eacof_netHandleCreateProbe(tmpBuf, sockfd);
            break;
        case EACOF_CMD_PROBE_UID_RESPONSE:
            tmpBuf = eacof_netHandleProbeUidRequest(tmpBuf, receivedData);
            break;
        case EACOF_CMD_PROBE_DELETE:
            tmpBuf = eacof_netHandleDeleteProbe(tmpBuf);
            break;
        case EACOF_CMD_PROBE_UPDATE:
            tmpBuf = eacof_netHandleUpdateProbe(tmpBuf);
            break;
        case EACOF_CMD_SAMPLE_ADD:
            tmpBuf = eacof_netHandleAddSample(tmpBuf);
            break;
        case EACOF_CMD_CHECKPOINT_CREATE:
            tmpBuf = eacof_netHandleCreateCheckpoint(tmpBuf, sockfd);
            break;
        case EACOF_CMD_CHECKPOINT_UID_RESPONSE:
            tmpBuf = eacof_netHandleCheckpointUidRequest(tmpBuf, receivedData);
            break;
        case EACOF_CMD_CHECKPOINT_DELETE:
            tmpBuf = eacof_netHandleDeleteCheckpoint(tmpBuf);
            break;
        case EACOF_CMD_CHECKPOINT_DO_SAMPLE_REQUEST:
            tmpBuf = eacof_netHandleSampleCheckpointRequest(tmpBuf, sockfd);
            break;
        case EACOF_CMD_CHECKPOINT_DO_SAMPLE_RESPONSE:
            tmpBuf = eacof_netHandleSampleCheckpointResponse(tmpBuf, receivedData);
            break;
        default:
            break;
    }

    eacofLog("Network Handling", "Handled packet length %" PRIi16 " from %d", msgLen, sockfd);

    return tmpBuf;
}

/**
    Handles the data contained within a buffer

    @param[in,out] msgNode A netbuf node whose buffer needs handling.
    @param[in] receivedData Data to be passed on to the handler.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_handleMessageBuffer(eacof_netbuf_t *msgNode, eacof_netrecv_t *receivedData) {
    eacof_nettype *buf;
    int currBufIdx;
    eacof_nettype *tmpBuf;
    uint16_t protocolVersion;
    int16_t msgLen;
    int status;

    eacofLog("Network Handling", "Handling a message buffer");

    buf = msgNode->buf;
    currBufIdx = msgNode->currBufIdx;

    tmpBuf = buf;

    // keep handling packets until there are no more
    while(1) {
        if(&tmpBuf[EACOF_NETWORK_HEADER_SIZE] > &buf[currBufIdx]) {
            // not got another header to parse, so return
            eacofLog("Network Handling", "No more headers to parse");
            return EACOF_OK;
        }
        // TODO: Move the header values into a struct
        // the first couple of bytes contain the protocol version
        tmpBuf = eacof_deserialize_uint16(tmpBuf, &protocolVersion);
        if(!EACOF_CAN_USE_NET_VERSION(protocolVersion)) {
            // send a message saying we can't handle the request
            eacofLogError("Network Handling", EACOF_ERR_NETWORK_UNSUPPORTED_PROTOCOL, "Protocol version in packet unsupported");
            eacof_netSendCommandUnknown(msgNode->sockfd);

            return EACOF_ERR_NETWORK_UNSUPPORTED_PROTOCOL;
        }
        // the next couple of bytes contain the number of bytes in the message
        tmpBuf = eacof_deserialize_int16(tmpBuf, &msgLen);

        if(&tmpBuf[msgLen] > &buf[currBufIdx]) {
            // not a full packet to handle
            eacofLog("Network Handling", "Not a full packet to handle");
            return EACOF_OK;
        }

        // when here, there is a full packet to handle, so handle it
        tmpBuf = eacof_handlePacketInBuffer(tmpBuf, msgLen, msgNode->sockfd, receivedData);
        if(_eacof->netHandlingErrCode) {
            eacofLogError("Network Handling", _eacof->netHandlingErrCode, "Problem handling a packet in the buffer");
            return _eacof->netHandlingErrCode;
        }
        // remove the packet that was just handled from the buffer
        status = eacof_resetBuf(msgNode);
        if(status != EACOF_OK) {
            eacofLogError("Network Handling", status, "Problem removing packet from buffer for node %d", msgNode->sockfd);
            return status;
        }
    }
}

/**
    Closes a socket and cleans up after it

    @param[in] sockfd The socket to close and clean up after.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_closeSocket(int sockfd) {
    // close the socket and remove it from the master set
    close(sockfd);
    FD_CLR(sockfd, &_eacof->master_fdSet);
    eacof_removeSocket(_eacof->netBuffers, sockfd);

    return EACOF_OK;
}

/**
    Receives data from a specified already connected socket

    @param[in] sockfd The socket to receive data from
    @param[in] receivedData Data to pass on to a handler.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_receiveDataFrom(int sockfd, eacof_netrecv_t *receivedData) {
    int bytesReceived;
    eacof_nettype msgBuf[EACOF_MAX_MSG_SIZE];
    int status;

    eacofLog("Network Transfer", "Receiving data from %d", sockfd);

    // receive data from the specified socket
    bytesReceived = recv(sockfd, msgBuf, sizeof msgBuf, 0);
    eacofLog("Network Transfer", "Bytes received: %d", bytesReceived);
    if(bytesReceived <= 0) {
        eacof_closeSocket(sockfd);

        // make it known what these special values mean
        if(bytesReceived == 0) {
            // the socket was closed
            eacofLog("Network Transfer", "The connection was closed");
        } else if(bytesReceived == -1) {
            // there was an error
            eacofLogError("Network Transfer", EACOF_ERR_NETWORK_RECV, "Problem recv()ing data");
            return EACOF_ERR_NETWORK_RECV;
        }
    } else {
        eacof_netbuf_t *sockNode;

        // add the received bytes to the buffer for that socket
        eacof_addDataToBuf(_eacof->netBuffers, sockfd, msgBuf, bytesReceived);

        // find the full buffer for a socket
        sockNode = eacof_findNetbufNode(_eacof->netBuffers, sockfd);

        if(sockNode) {
            status = eacof_handleMessageBuffer(sockNode, receivedData);
            if(status) {
                eacofLogError("Network Transfer", status, "Problem handling the message buffer");
                return status;
            }
        }
    }

    eacofLog("Network Transfer", "Received data OK");

    return EACOF_OK;
}

/**
    Acts as the main loop for the CA, handling various network request things

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_acceptConnections() {
    int status;

    eacofLog("Network Update", "Accepting network requests");

    // perform operations on a working set so master remains consistent
    _eacof->working_fdSet = _eacof->master_fdSet;

    // wait, without timeout, for events to happen on one of the sockets in the monitored set
    status = select(_eacof->fdmax+1, &_eacof->working_fdSet, NULL, NULL, NULL);
    if(status == -1) {
        // there was a problem with the select
        eacofLogError("Network Update", EACOF_ERR_NETWORK_POLLING, "There was a problem select()ing data");
        return EACOF_ERR_NETWORK_POLLING;
    }

    // now that we have data, find which socket it was on and act on the data
    for(int fdNum = 0; fdNum <= _eacof->fdmax; fdNum++) {
        // ensure the current fd is in the monitored set
        if(FD_ISSET(fdNum, &_eacof->working_fdSet)) {
            if(fdNum == _eacof->listener) {
                // if the current socket is the _eacof->listener, we need to handle a new connection
                struct sockaddr_storage remoteaddr;
                socklen_t addrlen;
                int newfd;

                eacofLog("Network Update", "Attempting to handle a new connection");

                // try and accept the new connection
                addrlen = sizeof remoteaddr;
                newfd = accept(_eacof->listener, (struct sockaddr *)&remoteaddr, &addrlen);
                if(newfd == -1) {
                    // there was a problem accepting the connection
                    eacofLogError("Network Update", EACOF_ERR_NETWORK_POLLING, "There was a problem accept()ing the new connection");
                    return EACOF_ERR_NETWORK_POLLING;
                }

                // add the new socket to the master sets
                FD_SET(newfd, &_eacof->master_fdSet);
                _eacof->fdmax = newfd > _eacof->fdmax ? newfd : _eacof->fdmax;
                eacof_addNewSocket(_eacof->netBuffers, newfd);

                eacofLog("Network Update", "New connection from %d has been added to the master sets", newfd);
            } else {
                // handle data coming from an already connected node
                eacof_netrecv_t receivedData;

                eacofLog("Network Update", "Handling data from %d, an already-connected node", fdNum);

                status = eacof_receiveDataFrom(fdNum, &receivedData);
                if(status) {
                    eacofLogError("Network Update", status, "Problem handling data from an already-connected node");
                    return status;
                }
            }
        }
    }

    eacofLog("Network Update", "Network requests handled OK");

    return EACOF_OK;
}

/**
    Sends data through the specified socket to the CA.

    @param[in] sockfdToSendTo The socket to send data to.
    @param[in] buf The buffer of data to send to the specified socket.
    @param[in] len The length of the buffer to send, in bytes
    @param[out] sentBytes A pointer to a location to let the caller know how much data was sent. This allows for retrys upon failure.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_sendDataTo(int sockfdToSendTo, eacof_nettype *buf, int len, int *sentBytes) {
    int totalSent = 0;   // how many bytes we've sent
    int bytesLeft = len; // how many bytes we have left to send
    int n;

    eacofLog("Network Transfer", "Attempting to send %d bytes to %d", len, sockfdToSendTo);

    while(totalSent < len) {
        n = send(sockfdToSendTo, buf+totalSent, bytesLeft, 0);
        if(n == -1) {
            break;
        }
        totalSent += n;
        bytesLeft -= n;
        eacofLog("Network Transfer", "Sent %d bytes. %d bytes remaining.", totalSent, bytesLeft);
    }

    *sentBytes = totalSent;

    // return an error on failure, OK on success
    if(n == -1) {
        eacofLogError("Network Transfer", EACOF_ERR_NETWORK_SEND, "Problem sending data");
        return EACOF_ERR_NETWORK_SEND;
    }

    eacofLog("Network Transfer", "Data sent successfully");

    return EACOF_OK;
}

/**
    Sends data through the connected socket to the CA.

    @param[in] buf The buffer of data to send to the specified socket.
    @param[in] len The length of the buffer to send, in bytes
    @param[out] sentBytes A pointer to a location to let the caller know how much data was sent. This allows for retrys upon failure.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_sendData(eacof_nettype *buf, int len, int *sentBytes) {
    eacofLog("Network Transfer", "Attempting to send %d bytes to connected sockfd", len);

    return eacof_sendDataTo(_eacof->connectedSockfd, buf, len, sentBytes);
}

/**
    Parses a header from some data

    @param[in,out] buf The buffer to parse data from.
    @param[in] netVersion A pointer to a location to let the caller know the network API version.
    @param[in] len A pointer to a location to let the caller know the length of the packet the header is for.

    @returns A pointer to a point in the provided buffer after the header has been parsed.
*/
eacof_nettype *eacof_parseHeader(eacof_nettype *buf, uint16_t *netVersion, int16_t *len) {
    eacofLog("Network Handling", "Parsing a header from a buffer");

    buf = eacof_deserialize_uint16(buf, netVersion);
    buf = eacof_deserialize_int16(buf, len);

    return buf;
}

/**
    Removes a header from the buffer

    @param[in,out] buf The buffer to remove the header from. The header is at the start of the buffer.

    @returns A pointer to a point in the provided buffer after the header has been stripped.
*/
eacof_nettype *eacof_stripHeader(eacof_nettype *buf) {
    uint16_t netVersion;
    int16_t len;

    eacofLog("Network Handling", "Stripping a header from a buffer");

    buf = eacof_parseHeader(buf, &netVersion, &len);

    return buf;
}

/**
    Adds a header to some data

    @param[in,out] buf A buffer into which to store the header.
    @param[in] len The length to be specified in the header.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_addHeaderToBuffer(eacof_nettype *buf, int len) {
    eacofLog("Network Handling", "Adding a header to a buffer");

    buf = eacof_serialize_uint16(buf, EACOF_NET_VERSION);
    buf = eacof_serialize_int16(buf, (int16_t)len);

    return EACOF_OK;
}

/**
    Adds a header to some data and sends it
    @warning If the len parameter is large, future changes to
    EACOF_NETWORK_HEADER_SIZE may cause values which are currently valid
    to become invalid. Future-compatible code should handle this.

    @param[in] sockfdToSendTo The socket to send data to.
    @param[in,out] buf The buffer of data to send to the specified socket.
    @param[in] len The length of the buffer to send, in bytes
    @param[out] sentBytes A pointer to a location to let the caller know how much data was sent. This allows for retrys upon failure.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_encapsulateAndSendDataTo(int sockfdToSendTo, eacof_nettype *buf, int len, int *sentBytes) {
    eacof_nettype *newBuf;
    int status;

    eacofLog("Network Transfer", "Attempting to encapsulate and send %d bytes to %d", len, sockfdToSendTo);
    if((int32_t)len > (int32_t)(INT16_MAX - EACOF_NETWORK_HEADER_SIZE)) {
        eacofLogError("Network Transfer", EACOF_ERR_LOCAL_OUT_OF_RANGE, "Attempting to send too much data. Attempted: %d, Max: %" PRIi32, len, (int32_t)(INT16_MAX - EACOF_NETWORK_HEADER_SIZE));
        return EACOF_ERR_LOCAL_OUT_OF_RANGE;
    }
    if(len < 0) {
        eacofLogError("Network Transfer", EACOF_ERR_LOCAL_INVALID_PARAMETER, "Attempting to send a negative amount of data");
        return EACOF_ERR_LOCAL_INVALID_PARAMETER;
    }

    newBuf = (eacof_nettype *) malloc(len + EACOF_NETWORK_HEADER_SIZE);
    if(newBuf == NULL) {
        return EACOF_ERR_LOCAL_MALLOC;
    }

    eacof_addHeaderToBuffer(newBuf, len);
    memcpy(&newBuf[EACOF_NETWORK_HEADER_SIZE], buf, len);

    status = eacof_sendDataTo(sockfdToSendTo, newBuf, len + EACOF_NETWORK_HEADER_SIZE, sentBytes);

    // TODO: Change it so we don't need to keep malloc() and free()ing
    free(newBuf);

    eacofLog("Network Transfer", "Encapsulated and sent data. Possible error codes are propagating.");

    return status;
}

/**
    Adds a header to some data and sends it to the connected sockfd
    @warning See warning for encapusulateAndSendDataTo()

    @param[in,out] buf The buffer of data to send to the specified socket.
    @param[in] len The length of the buffer to send, in bytes
    @param[out] sentBytes A pointer to a location to let the caller know how much data was sent. This allows for retrys upon failure.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_encapsulateAndSendData(eacof_nettype *buf, int len, int *sentBytes) {
    eacofLog("Network Transfer", "Attempting to encapsulate and send %d bytes to connected sockfd", len);
    return eacof_encapsulateAndSendDataTo(_eacof->connectedSockfd, buf, len, sentBytes);
}
