#ifndef EACOF_NETWORK_H
#define EACOF_NETWORK_H
/**
    @file

    @brief A header for the general functions for sending data across the network.
*/

#include <eacof/types.h>
#include <eacof/netbuf.h>
#include <eacof/network_api.h>
#include <eacof/network_handling.h>
#include <eacof/serialization.h>
#include <eacof/version.h>
#include <eacof/shared.h>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

int eacof_connectTo(char *node, char *port);
int eacof_connectToDefault();
int eacof_listenOn(char *node, char *port);
int eacof_listenOnDefault();
eacof_nettype *eacof_handlePacketInBuffer(eacof_nettype *buf, int16_t msgLen, int sockfd, eacof_netrecv_t *receivedData);
int eacof_handleMessageBuffer(eacof_netbuf_t *msgNode, eacof_netrecv_t *receivedData);
int eacof_closeSocket(int sockfd);
int eacof_receiveDataFrom(int sockfd, eacof_netrecv_t *receivedData);
int eacof_acceptConnections();

int eacof_sendDataTo(int sockfdToSendTo, eacof_nettype *buf, int len, int *sentBytes);
int eacof_sendData(eacof_nettype *buf, int len, int *sentBytes);

eacof_nettype *eacof_parseHeader(eacof_nettype *buf, uint16_t *netVersion, int16_t *len);
eacof_nettype *eacof_stripHeader(eacof_nettype *buf);
int eacof_addHeaderToBuffer(eacof_nettype *buf, int len);

int eacof_encapsulateAndSendDataTo(int sockfdToSendTo, eacof_nettype *buf, int len, int *sentBytes);
int eacof_encapsulateAndSendData(eacof_nettype *buf, int len, int *sentBytes);

#ifdef __cplusplus
}
#endif

#endif // EACOF_NETWORK_H
