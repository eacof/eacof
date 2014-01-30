/**
    @file

    @brief Code to handle messages received across the network.

    When a packet comes in across the network, the network code determines what sort of message it is.
    The buffer for the message is then passed to one of the functions here so that action may be taken upon the message.

    This handler wraps both the Storage and Network API code, calling each as required to handle a message.
*/
#include <eacof/network_handling.h>

/**
    The UID to be given to the next created Probe.
*/
eacof_ProbeID currProbeUid = 1;
/**
    The UID to be given to the next created Checkpoint.
*/
eacof_CheckpointID currCheckpointUid = 1;

extern eacof_config *_eacof;

/**
    Sets an error code that can be accessed in other code.
    Cannot return the error code directly because a buffer pointer is returned instead.

    @param VALUE The error code to set.
    @param MSG A message to describe why the error was set.
*/
#define EACOF_SET_NET_HANDLING_ERR_CODE(VALUE, MSG) \
    _eacof->netHandlingErrCode = VALUE; \
    if(VALUE) { \
        eacofLogError("Network Handler", VALUE, MSG); \
        return tmpBuf; \
    }

/**
    Handle a createProbe() network request

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] sockfd A socket to send a response containing a UID to.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleCreateProbe(eacof_nettype *buf, int sockfd) {
    eacof_nettype *tmpBuf;
    eacof_Probe createdProbe;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Create Probe' message");

    // deserialize what has been sent
    tmpBuf = buf;
    tmpBuf = eacof_deserialize_probe(tmpBuf, &createdProbe);
    // set the UID
    createdProbe.uid = currProbeUid;

    // store the probe
    eacofLog("Network Handler", "Attempting to store the new Probe");
    status = eacof_storageCreateProbe(&createdProbe);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem storing the new Probe");

    // TODO: If you return early, the other end is still waiting for something to be sent

    // send back a UID
    eacofLog("Network Handler", "Attempting to send back the Probe's new UID");
    status = eacof_netSendProbeUidRequest(sockfd, currProbeUid++);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem sending new Probe's UID");

    eacofLog("Network Handler", "Handled 'Create Probe' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a network request responding with a probe id

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] receivedData A struct containing data which has been received.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleProbeUidRequest(eacof_nettype *buf, eacof_netrecv_t *receivedData) {
    eacof_nettype *tmpBuf;

    eacofLog("Network Handler", "Attempting to handle 'Probe UID Request' message");

    tmpBuf = buf;
    // deserialize the data to be used by the calling function
    tmpBuf = eacof_deserialize_probeid(tmpBuf, &receivedData->v.probeuid);

    eacofLog("Network Handler", "Handled 'Probe UID Request' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a deleteProbe() network request

    @param[in] buf A buffer containing the data to deserialize and handle.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleDeleteProbe(eacof_nettype *buf) {
    eacof_nettype *tmpBuf;
    eacof_ProbeID probeuid;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Delete Probe' message");

    tmpBuf = buf;
    tmpBuf = eacof_deserialize_probeid(tmpBuf, &probeuid);

    eacofLog("Network Handler", "Attempting to delete the Probe being deleted");
    status = eacof_storageDeleteProbe(probeuid);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem updating storage to delete Probe");

    eacofLog("Network Handler", "Handled 'Delete Probe' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a updateProbe() network request

    @param[in] buf A buffer containing the data to deserialize and handle.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleUpdateProbe(eacof_nettype *buf) {
    eacof_nettype *tmpBuf;
    eacof_Probe updatedProbe;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Update Probe' message");

    tmpBuf = buf;
    tmpBuf = eacof_deserialize_probe(tmpBuf, &updatedProbe);

    // TODO: Use a general update function rather than assuming only active changes
    eacofLog("Network Handler", "Attempting to set the Probe active status");
    status = eacof_storageSetProbeActiveStatus(&updatedProbe);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem updating storage to update Probe");

    eacofLog("Network Handler", "Handled 'Update Probe' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle an addSample() network request

    @param[in] buf A buffer containing the data to deserialize and handle.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleAddSample(eacof_nettype *buf) {
    eacof_nettype *tmpBuf;
    eacof_ProbeID probeuid;
    eacof_Sample sample;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Add Sample' message");

    tmpBuf = buf;
    tmpBuf = eacof_deserialize_probeid(tmpBuf, &probeuid);
    tmpBuf = eacof_deserialize_sample(tmpBuf, &sample);

    eacofLog("Network Handler", "Attempting to store the new Sample");
    status = eacof_storageAddSample(sample, probeuid);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem updating storage with new Sample");
    // TODO: See if anything other than storing needs doing to handle the sample

    eacofLog("Network Handler", "Handled 'Add Sample' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a createCheckpoint() network request

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] sockfd A socket to send a response containing the UID to.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleCreateCheckpoint(eacof_nettype *buf, int sockfd) {
    eacof_nettype *tmpBuf;
    eacof_Checkpoint createdCheckpoint;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Create Checkpoint' message");

    // deserialize the message
    tmpBuf = buf;
    tmpBuf = eacof_deserialize_checkpoint(tmpBuf, &createdCheckpoint);
    // set the uid
    createdCheckpoint.uid = currCheckpointUid;

    // store the checkpoint
    eacofLog("Network Handler", "Attempting to store the new Checkpoint");
    status = eacof_storageCreateCheckpoint(&createdCheckpoint);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem storing the new Checkpoint");

    // TODO: If you return early, the other end is still waiting for something to be sent

    // send back a UID
    eacofLog("Network Handler", "Attempting to send back the Checkpoint's new UID");
    status = eacof_netSendCheckpointUidRequest(sockfd, currCheckpointUid++);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem sending new Checkpoint's UID");

    eacofLog("Network Handler", "Handled 'Create Checkpoint' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a network request responding with a checkpoint id

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] receivedData A struct containing data which has been received.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleCheckpointUidRequest(eacof_nettype *buf, eacof_netrecv_t *receivedData) {
    eacof_nettype *tmpBuf;

    eacofLog("Network Handler", "Attempting to handle 'Checkpoint UID Request' message");

    tmpBuf = buf;
    // deserialize the data to be used by the calling function
    tmpBuf = eacof_deserialize_checkpointid(tmpBuf, &receivedData->v.checkpointuid);

    eacofLog("Network Handler", "Handled 'Checkpoint UID Request' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a deleteCheckpoint() network request

    @param[in] buf A buffer containing the data to deserialize and handle.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleDeleteCheckpoint(eacof_nettype *buf) {
    eacof_nettype *tmpBuf;
    eacof_CheckpointID checkpointuid;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Delete Checkpoint' message");

    tmpBuf = buf;
    tmpBuf = eacof_deserialize_checkpointid(tmpBuf, &checkpointuid);

    eacofLog("Network Handler", "Attempting to delete the Checkpoint being deleted");
    status = eacof_storageDeleteCheckpoint(checkpointuid);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem updating storage to delete Checkpoint");

    eacofLog("Network Handler", "Handled 'Delete Checkpoint' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a network request to sample a Checkpoint

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] sockfd A socket to send a response containing the Sample to.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleSampleCheckpointRequest(eacof_nettype *buf, int sockfd) {
    eacof_nettype *tmpBuf;
    eacof_CheckpointID checkpointuid;
    eacof_Checkpoint checkpoint;
    double sample;
    int status;

    eacofLog("Network Handler", "Attempting to handle 'Sample Checkpoint Request' message");

    tmpBuf = buf;
    tmpBuf = eacof_deserialize_checkpointid(tmpBuf, &checkpointuid);

    checkpoint.uid = checkpointuid;
    status = eacof_storageSampleCheckpoint(&checkpoint, &sample);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem sampling Checkpoint");

    // send back a Sample
    eacofLog("Network Handler", "Attempting to send back the Sample");
    status = eacof_netSendSampleCheckpointResponse(sockfd, sample);
    EACOF_SET_NET_HANDLING_ERR_CODE(status, "Problem sending response with Sample");

    eacofLog("Network Handler", "Handled 'Sample Checkpoint Request' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}

/**
    Handle a network request providing a Checkpoint sample

    @param[in] buf A buffer containing the data to deserialize and handle.
    @param[in] receivedData A struct containing data which has been received.

    @pre The header and command must have been removed from the buffer, with the pointer pointing to the first byte after the command.
    @pre The command must have specified that this is the correct handler.

    @returns A pointer to a point in the provided buffer after the handling has been undertaken.
*/
eacof_nettype *eacof_netHandleSampleCheckpointResponse(eacof_nettype *buf, eacof_netrecv_t *receivedData) {
    eacof_nettype *tmpBuf;

    eacofLog("Network Handler", "Attempting to handle 'Sample Checkpoint Response' message");

    tmpBuf = buf;
    // deserialize the data to be used by the calling function
    tmpBuf = eacof_deserialize_sample(tmpBuf, &receivedData->v.sample);

    eacofLog("Network Handler", "Handled 'Sample Checkpoint Response' message");

    EACOF_SET_NET_HANDLING_ERR_CODE(EACOF_OK, "");

    return tmpBuf;
}
