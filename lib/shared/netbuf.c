/**
    @file

    @brief Code for handling network buffers.

    The buffers are used to keep track of data that has been received from other EACOF-aware components.

    Network buffers are implemented as linked lists.
    There is therefore code to handle these lists, as well as the modification of the buffers themselves.
*/
#include <eacof/netbuf.h>

/**
    Create and allocate a netbuf.

    @returns A pointer to a new netbuf node which has been allocated and had default values set.
             Will return NULL if any malloc()s failed.
*/
eacof_netbuf_t *eacof_createNetbuf() {
    eacof_netbuf_t *nb;

    nb = (eacof_netbuf_t *) malloc(sizeof(eacof_netbuf_t));
    if(nb == NULL) {
        return NULL;
    }
    nb->buf = (eacof_nettype *) malloc(EACOF_NETBUF_BUF_LEN * sizeof(eacof_nettype));
    if(nb->buf == NULL) {
        free(nb);
        return NULL;
    }
    nb->currBufIdx = 0;
    nb->next = NULL;

    return nb;
}

/**
    Add a new socket to the list.

    @param[in,out] listHead A pointer to the head of the netbuf list.
    @param[in] sockfd The new socket to add a node for.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_addNewSocket(eacof_netbuf_t *listHead, int sockfd) {
    eacof_netbuf_t *newNode = NULL;

    newNode = eacof_createNetbuf();

    newNode->next = listHead->next;
    listHead->next = newNode;
    newNode->sockfd = sockfd;

    return EACOF_OK;
}

/**
    Finds the netbuf node for the specified socket.

    @param[in] listHead A pointer to the head of the netbuf list.
    @param[in] sockfd The socket to search for.

    @returns A pointer to a netbuf node with data about the specified sockfd.
             Will return NULL if there is not a netbuf node for the specified sockfd.
*/
eacof_netbuf_t *eacof_findNetbufNode(eacof_netbuf_t *listHead, int sockfd) {
    eacof_netbuf_t *currNode;

    currNode = listHead->next;

    while(currNode) {
        if(currNode->sockfd == sockfd) {
            return currNode;
        }
        currNode = currNode->next;
    }

    return NULL;
}

/**
    Adds data to the buffer for a socket.

    @param[in,out] listHead A pointer to the head of the netbuf list.
    @param[in] sockfd The socket to add data for.
    @param[in] newData The new data to add.
    @param[in] len The length of the newData in bytes.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_addDataToBuf(eacof_netbuf_t *listHead, int sockfd, eacof_nettype *newData, int len) {
    eacof_netbuf_t *nodeToModify;

    nodeToModify = eacof_findNetbufNode(listHead, sockfd);
    if(!nodeToModify) {
        return EACOF_ERR_LOCAL_UNAVAILABLE_DATA;
    }
    if(nodeToModify->currBufIdx + len > EACOF_NETBUF_BUF_LEN) {
        return EACOF_ERR_LOCAL_OUT_OF_RANGE;
    }

    memcpy(&nodeToModify->buf[nodeToModify->currBufIdx], newData, len);

    nodeToModify->currBufIdx += len;

    return EACOF_OK;
}

/**
    Removes the first packet of data from a buffer.

    @param[in,out] nodeToModify The node to remove a packet of data from.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_resetBuf(eacof_netbuf_t *nodeToModify) {
    uint16_t netVersion;
    int16_t packetLen;
    int packetLenInt;
    int tmpBufLen;
    eacof_nettype *tmpBuf;

    if((int32_t)(nodeToModify->currBufIdx) < (int32_t)EACOF_NETWORK_HEADER_SIZE) { // header size
        return EACOF_ERR_LOCAL_OUT_OF_RANGE;
    }

    eacof_parseHeader(nodeToModify->buf, &netVersion, &packetLen);
    packetLenInt = (int)packetLen + EACOF_NETWORK_HEADER_SIZE;
    if(packetLenInt < 0) {
        return EACOF_ERR_REMOTE_OUT_OF_RANGE;
    }

    tmpBufLen = nodeToModify->currBufIdx - packetLenInt;
    tmpBuf = (eacof_nettype *) malloc(tmpBufLen * sizeof(eacof_nettype));
    if(tmpBuf == NULL) {
        return EACOF_ERR_LOCAL_MALLOC;
    }
    memcpy(tmpBuf, &(nodeToModify->buf[packetLenInt]), tmpBufLen);
    memcpy(nodeToModify->buf, tmpBuf, tmpBufLen);
    free(tmpBuf);
    nodeToModify->currBufIdx = tmpBufLen;

    return EACOF_OK;
}

/**
    Gets the buffer for a socket.

    @param[in] listHead A pointer to the head of the netbuf list.
    @param[in] sockfd The socket to get the data buffer for.

    @returns A pointer to the head of the buffer containing data from the specified sockfd.
             Will return NULL if there is no buffer for the specified sockfd.
*/
eacof_nettype *eacof_getBufForSocket(eacof_netbuf_t *listHead, int sockfd) {
    eacof_netbuf_t *usedNode;

    usedNode = eacof_findNetbufNode(listHead, sockfd);
    if(usedNode == NULL) {
        return NULL;
    }

    return usedNode->buf;
}

/**
    Remove a socket from the list.

    @param[in,out] listHead A pointer to the head of the netbuf list.
    @param[in] sockfd The socket to remove.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_removeSocket(eacof_netbuf_t *listHead, int sockfd) {
    eacof_netbuf_t *currNode;
    eacof_netbuf_t *prevNode = NULL;

    currNode = listHead->next;

    while(currNode) {
        if(currNode->sockfd == sockfd) {
            if(prevNode) {
                prevNode->next = currNode->next;
            }
            eacof_freeNetbuf(currNode);

            return EACOF_OK;
        }

        prevNode = currNode;
        currNode = currNode->next;
    }

    return EACOF_ERR_LOCAL_UNAVAILABLE_DATA;
}

/**
    Free a netbuf list.

    @param[in,out] listHead A pointer to the head of the netbuf list to free.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_freeNetbufList(eacof_netbuf_t *listHead) {
    eacof_netbuf_t *currNode;
    eacof_netbuf_t *tmpNode;
    int status;

    currNode = listHead;
    while(currNode) {
        tmpNode = currNode->next;
        status = eacof_freeNetbuf(currNode);
        if(status != EACOF_OK) {
            return status;
        }
        currNode = tmpNode;
    }

    return EACOF_OK;
}

/**
    Free a netbuf.

    @param[in,out] nb A pointer to a single netbuf node to free.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_freeNetbuf(eacof_netbuf_t *nb) {
    int status;

    status = close(nb->sockfd);
    if(status == -1) {
        return EACOF_ERR_LOCAL_CLOSE;
    }
    free(nb->buf);
    free(nb);

    return EACOF_OK;
}
