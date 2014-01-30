#ifndef EACOF_NETBUF_H
#define EACOF_NETBUF_H
/**
    @file

    @brief A header for the network buffer functions.

    Includes macro definitions specifying buffer sizes.
    These buffer sizes include maximum sizes as well as actual sizes.
*/

#include <eacof/types.h>
#include <eacof/serialization.h>
#include <eacof/network.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    The maximum length, in bytes, that a message can be.
*/
#define EACOF_MAX_MSG_SIZE (INT16_MAX)
/**
    The size, in bytes, of a network buffer.
    This allows for up to two messages to be in the buffer before the first must have been handled.
*/
#define EACOF_NETBUF_BUF_LEN (2 * EACOF_MAX_MSG_SIZE)
/**
    The size, in bytes, of the header for a network message.
*/
#define EACOF_NETWORK_HEADER_SIZE (sizeof(uint16_t) + sizeof(int16_t))

eacof_netbuf_t *eacof_createNetbuf();
int eacof_addNewSocket(eacof_netbuf_t *listHead, int sockfd);
eacof_netbuf_t *eacof_findNetbufNode(eacof_netbuf_t *listHead, int sockfd);
int eacof_addDataToBuf(eacof_netbuf_t *listHead, int sockfd, eacof_nettype *newData, int len);
int eacof_resetBuf(eacof_netbuf_t *nodeToModify);
eacof_nettype *eacof_getBufForSocket(eacof_netbuf_t *listHead, int sockfd);
int eacof_removeSocket(eacof_netbuf_t *listHead, int sockfd);
int eacof_freeNetbufList(eacof_netbuf_t *listHead);
int eacof_freeNetbuf(eacof_netbuf_t *nb);

#ifdef __cplusplus
}
#endif

#endif // EACOF_NETBUF_H
