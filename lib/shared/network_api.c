/**
    @file

    @brief Code for sending and receiving commands across the network for actions in the public API.

    This allows other EACOF-aware components to know what actions Providers and Consumers are undertaking.

    Each command requires a number of steps to be taken:

    - *Serialization* to convert data into a format to send
    - *Send* the serialized data to connected components
    - *Receive* any response required for a particular request

    This wraps the network code so that network code may be swapped out underneath without impacting callers.
*/
#include <eacof/network_api.h>

extern eacof_config *_eacof;

/**
    Setup code for the network API.
    Keeps the code more DRY.
*/
#define EACOF_NET_API_REQ_PRE \
int status; \
int sentBytes; \
eacof_nettype *buf; \
buf = (eacof_nettype *) malloc(EACOF_MAX_MSG_SIZE * sizeof(eacof_nettype)); \
if(buf) { \
    eacof_nettype *tmpBuf; \
    tmpBuf = buf;

/**
    Code, with error handling, to perform a standard send to a specified socket.
    Keeps the code more DRY.
*/
#define EACOF_NET_API_STANDARD_SEND_TO \
status = eacof_encapsulateAndSendDataTo(sockfd, buf, tmpBuf - buf, &sentBytes); \
if(status != EACOF_OK) { \
    free(buf); \
    eacofLogError("Network Send", status, "Problem with the Standard Send To"); \
    return status; \
}

/**
    Code, with error handling, to perform a send to the default socket.
    Keeps the code more DRY.
*/
#define EACOF_NET_API_STANDARD_SEND \
status = eacof_encapsulateAndSendData(buf, tmpBuf - buf, &sentBytes); \
if(status != EACOF_OK) { \
    free(buf); \
    eacofLogError("Network Send", status, "Problem with the Standard Send"); \
    return status; \
}

/**
    Tidy up code for the network API.
    Keeps the code more DRY.
*/
#define EACOF_NET_API_REQ_POST \
    free(buf); \
} else { \
    eacofLogError("Network Send", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing buffer"); \
    return EACOF_ERR_LOCAL_MALLOC; \
} \
eacofLog("Network Send", "Sending the message went OK"); \
return EACOF_OK;

/**
    Handles a network request for sending a 'Command Unknown' message

    @param[in] sockfd The socket to send the message to.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendCommandUnknown(int sockfd) {
    eacofLog("Network Send", "Attempting to send 'Command Unknown' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_RESPONSE_CMD_UNKNOWN);

        EACOF_NET_API_STANDARD_SEND_TO

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the createProbe() call

    @param[in] probe The Probe to serialize and send data about.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendCreateProbe(eacof_Probe *probe) {
    eacofLog("Network Send", "Attempting to send 'Create Probe' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_PROBE_CREATE);
        tmpBuf = eacof_serialize_probe(tmpBuf, *probe);

        EACOF_NET_API_STANDARD_SEND

        // get back a uid
        eacof_netrecv_t receivedData;
        status = eacof_receiveDataFrom(_eacof->connectedSockfd, &receivedData);
        if(status != EACOF_OK) {
            free(buf);
            eacofLogError("Network Send", status, "Problem receiving data from %d", _eacof->connectedSockfd);
            return status;
        }
        if(receivedData.cmd != EACOF_CMD_PROBE_UID_RESPONSE) {
            free(buf);
            eacofLogError("Network Send", EACOF_ERR_NETWORK_RESPONSE, "Wrong response. Got %" PRIu16 " rather than %" PRIu16 " (Probe UID Response)", receivedData.cmd, EACOF_CMD_PROBE_UID_RESPONSE);
            return EACOF_ERR_NETWORK_RESPONSE;
        }
        eacofLog("Network Send", "Received a UID for the new Probe. %" PRIu32, receivedData.v.probeuid);
        probe->uid = receivedData.v.probeuid;

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for sending a Probe UID

    @param[in] sockfd The socket to send the ID to.
    @param[in] uid The ProbeID to send.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendProbeUidRequest(int sockfd, eacof_ProbeID uid) {
    eacofLog("Network Send", "Attempting to send 'Probe UID Request' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_PROBE_UID_RESPONSE);
        tmpBuf = eacof_serialize_probeid(tmpBuf, uid);

        // send it
        EACOF_NET_API_STANDARD_SEND_TO

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the deleteProbe() call

    @param[in] probe The Probe to get the ID from and send a delete request about.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendDeleteProbe(eacof_Probe *probe) {
    eacofLog("Network Send", "Attempting to send 'Delete Probe' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_PROBE_DELETE);
        tmpBuf = eacof_serialize_probeid(tmpBuf, probe->uid);

        EACOF_NET_API_STANDARD_SEND

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for updating a probe
    This is used when activating and deactivating a probe

    @param[in] probe The Probe to be serialized and have change data sent.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendUpdateProbe(eacof_Probe *probe) {
    eacofLog("Network Send", "Attempting to send 'Update Probe' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_PROBE_UPDATE);
        tmpBuf = eacof_serialize_probe(tmpBuf, *probe);

        EACOF_NET_API_STANDARD_SEND

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the addSample() call

    @param[in] probeid The ID of the Probe the sample is for.
    @param[in] sample The sample to add against the specified Probe.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendAddSample(eacof_ProbeID probeid, eacof_Sample sample) {
    eacofLog("Network Send", "Attempting to send 'Add Sample' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_SAMPLE_ADD);
        tmpBuf = eacof_serialize_probeid(tmpBuf, probeid);
        tmpBuf = eacof_serialize_sample(tmpBuf, sample);

        EACOF_NET_API_STANDARD_SEND

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the createCheckpoint() call

    @param[in] checkpoint The Checkpoint to serialize and send data about.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendCreateCheckpoint(eacof_Checkpoint *checkpoint) {
    eacofLog("Network Send", "Attempting to send 'Create Checkpoint' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_CHECKPOINT_CREATE);
        tmpBuf = eacof_serialize_checkpoint(tmpBuf, *checkpoint);

        EACOF_NET_API_STANDARD_SEND

        // get back a uid
        eacof_netrecv_t receivedData;
        status = eacof_receiveDataFrom(_eacof->connectedSockfd, &receivedData);
        if(status != EACOF_OK) {
            free(buf);
            eacofLogError("Network Send", status, "Problem receiving data from %d", _eacof->connectedSockfd);
            return status;
        }
        if(receivedData.cmd != EACOF_CMD_CHECKPOINT_UID_RESPONSE) {
            free(buf);
            eacofLogError("Network Send", EACOF_ERR_NETWORK_RESPONSE, "Wrong response. Got %" PRIu16 " rather than %" PRIu16 " (Checkpoint UID Response)", receivedData.cmd, EACOF_CMD_CHECKPOINT_UID_RESPONSE);
            return EACOF_ERR_NETWORK_RESPONSE;
        }
        eacofLog("Network Send", "Received a UID for the new Checkpoint. %" PRIu32, receivedData.v.checkpointuid);
        checkpoint->uid = receivedData.v.checkpointuid;

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for sending a Checkpoint UID

    @param[in] sockfd The socket to send the ID to.
    @param[in] uid The CheckpointID to send.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendCheckpointUidRequest(int sockfd, eacof_CheckpointID uid) {
    eacofLog("Network Send", "Attempting to send 'Checkpoint UID Request' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_CHECKPOINT_UID_RESPONSE);
        tmpBuf = eacof_serialize_checkpointid(tmpBuf, uid);

        EACOF_NET_API_STANDARD_SEND_TO

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the deleteCheckpoint() call

    @param[in] checkpoint The Checkpoint to get the ID from and send a delete request about.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendDeleteCheckpoint(eacof_Checkpoint *checkpoint) {
    eacofLog("Network Send", "Attempting to send 'Delete Checkpoint' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_CHECKPOINT_DELETE);
        tmpBuf = eacof_serialize_checkpointid(tmpBuf, checkpoint->uid);

        EACOF_NET_API_STANDARD_SEND

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for the sampleCheckpoint() call

    @param[in] checkpoint The Checkpoint to request a sample for.
    @param[in] sample A pointer to a memory location to store the sample in.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendSampleCheckpointRequest(eacof_Checkpoint *checkpoint, eacof_Sample *sample) {
    eacofLog("Network Send", "Attempting to send 'Sample Checkpoint Request' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_CHECKPOINT_DO_SAMPLE_REQUEST);
        tmpBuf = eacof_serialize_checkpointid(tmpBuf, checkpoint->uid);

        EACOF_NET_API_STANDARD_SEND

        // get back a sample
        eacof_netrecv_t receivedData;
        status = eacof_receiveDataFrom(_eacof->connectedSockfd, &receivedData);
        if(status != EACOF_OK) {
            free(buf);
            eacofLogError("Network Send", status, "Problem receiving data from %d", _eacof->connectedSockfd);
            return status;
        }
        if(receivedData.cmd != EACOF_CMD_CHECKPOINT_DO_SAMPLE_RESPONSE) {
            free(buf);
            eacofLogError("Network Send", EACOF_ERR_NETWORK_RESPONSE, "Wrong response. Got %" PRIu16 " rather than %" PRIu16 " (Checkpoint Do Sample Response)", receivedData.cmd, EACOF_CMD_CHECKPOINT_DO_SAMPLE_RESPONSE);
            return EACOF_ERR_NETWORK_RESPONSE;
        }
        *sample = receivedData.v.sample;

    EACOF_NET_API_REQ_POST
}

/**
    Handles a network request for sending a Sample.

    @param[in] sockfd The socket to send the data to.
    @param[in] sample The sample to serialize and send.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_netSendSampleCheckpointResponse(int sockfd, eacof_Sample sample) {
    eacofLog("Network Send", "Attempting to send 'Sample Checkpoint Response' message");

    EACOF_NET_API_REQ_PRE

        tmpBuf = eacof_serialize_command(tmpBuf, EACOF_CMD_CHECKPOINT_DO_SAMPLE_RESPONSE);
        tmpBuf = eacof_serialize_sample(tmpBuf, sample);

        // send it
        EACOF_NET_API_STANDARD_SEND_TO

    EACOF_NET_API_REQ_POST
}
