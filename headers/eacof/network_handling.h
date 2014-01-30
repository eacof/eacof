#ifndef EACOF_NETWORK_HANDLING_H
#define EACOF_NETWORK_HANDLING_H
/**
    @file

    @brief A header for functions to handle packets sent across the network.
*/

#include <eacof/serialization.h>
#include <eacof/network_api.h>
#include <eacof/storage.h>

#ifdef __cplusplus
extern "C" {
#endif

eacof_nettype *eacof_netHandleCreateProbe(eacof_nettype *buf, int sockfd);
eacof_nettype *eacof_netHandleProbeUidRequest(eacof_nettype *buf, eacof_netrecv_t *receivedData);
eacof_nettype *eacof_netHandleDeleteProbe(eacof_nettype *buf);
eacof_nettype *eacof_netHandleUpdateProbe(eacof_nettype *buf);
eacof_nettype *eacof_netHandleAddSample(eacof_nettype *buf);

eacof_nettype *eacof_netHandleCreateCheckpoint(eacof_nettype *buf, int sockfd);
eacof_nettype *eacof_netHandleCheckpointUidRequest(eacof_nettype *buf, eacof_netrecv_t *receivedData);
eacof_nettype *eacof_netHandleDeleteCheckpoint(eacof_nettype *buf);
eacof_nettype *eacof_netHandleSampleCheckpointRequest(eacof_nettype *buf, int sockfd);
eacof_nettype *eacof_netHandleSampleCheckpointResponse(eacof_nettype *buf, eacof_netrecv_t *receivedData);

#ifdef __cplusplus
}
#endif

#endif // EACOF_NETWORK_HANDLING_H
