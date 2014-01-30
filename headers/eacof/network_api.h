#ifndef EACOF_NETWORK_API_H
#define EACOF_NETWORK_API_H
/**
    @file

    @brief A header for the Network API functions.

    As well as the functions themselves, includes definitions of macros which define the commands which may be sent across the network.

    The commands are broken into three groups:

    - *Action commands* specify the type of action to be taken.
    - *Thing commands* specify what the action is to be performed on.
    - *Full commands* combine an action and a thing to send across the network.
*/

#include <eacof/serialization.h>
#include <eacof/network.h>

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies a create command.
*/
#define EACOF_CMD_CREATE     (0x01 << 8)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies an update command.
*/
#define EACOF_CMD_UPDATE     (0x02 << 8)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies a delete command.
*/
#define EACOF_CMD_DELETE     (0x03 << 8)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies an add command.
*/
#define EACOF_CMD_ADD        (0x04 << 8)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies a response command.
*/
#define EACOF_CMD_RESPONSE   (0x05 << 8)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the lower 8 bits before sending.
    Specifies a request command.
*/
#define EACOF_CMD_REQUEST    (0x06 << 8)

/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to a Probe.
*/
#define EACOF_CMD_PROBE          (0x81)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to a Sample.
*/
#define EACOF_CMD_SAMPLE         (0x82)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to a Checkpoint.
*/
#define EACOF_CMD_CHECKPOINT     (0x83)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to a Probe UID.
*/
#define EACOF_CMD_PROBE_UID      (0x84)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to a Checkpoint UID.
*/
#define EACOF_CMD_CHECKPOINT_UID (0x85)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies a command relating to sampling a Checkpoint.
*/
#define EACOF_CMD_CHECKPOINT_DO_SAMPLE (0x86)
/**
    Part of a command to send over the network.
    Should be combined with a value to fill the upper 8 bits before sending.
    Specifies that a previous message sent something that could not be understood.
*/
#define EACOF_CMD_CMD_UNKNOWN    (0x87)

/**
    A command to send over the network.
    Specifies a Create Probe command.
*/
#define EACOF_CMD_PROBE_CREATE     (EACOF_CMD_PROBE | EACOF_CMD_CREATE)
/**
    A command to send over the network.
    Specifies an Update Probe command.
*/
#define EACOF_CMD_PROBE_UPDATE     (EACOF_CMD_PROBE | EACOF_CMD_UPDATE)
/**
    A command to send over the network.
    Specifies a Delete Probe command.
*/
#define EACOF_CMD_PROBE_DELETE     (EACOF_CMD_PROBE | EACOF_CMD_DELETE)

/**
    A command to send over the network.
    Specifies an Add Sample command.
*/
#define EACOF_CMD_SAMPLE_ADD      (EACOF_CMD_SAMPLE | EACOF_CMD_ADD)
/**
    A command to send over the network.
    Specifies a command requesting a Sample.
*/
#define EACOF_CMD_SAMPLE_REQUEST  (EACOF_CMD_SAMPLE | EACOF_CMD_REQUEST)
/**
    A command to send over the network.
    Specifies a command responding to a Sample request.
*/
#define EACOF_CMD_SAMPLE_RESPONSE (EACOF_CMD_SAMPLE | EACOF_CMD_RESPONSE)

/**
    A command to send over the network.
    Specifies a Create Checkpoint command.
*/
#define EACOF_CMD_CHECKPOINT_CREATE    (EACOF_CMD_CHECKPOINT | EACOF_CMD_CREATE)
/**
    A command to send over the network.
    Specifies an Update Checkpoint command.
*/
#define EACOF_CMD_CHECKPOINT_UPDATE    (EACOF_CMD_CHECKPOINT | EACOF_CMD_UPDATE)
/**
    A command to send over the network.
    Specifies a Delete Checkpoint command.
*/
#define EACOF_CMD_CHECKPOINT_DELETE    (EACOF_CMD_CHECKPOINT | EACOF_CMD_DELETE)

/**
    A command to send over the network.
    Specifies a command requesting a Sample for a Checkpoint.
*/
#define EACOF_CMD_CHECKPOINT_DO_SAMPLE_REQUEST  (EACOF_CMD_CHECKPOINT_DO_SAMPLE | EACOF_CMD_REQUEST)
/**
    A command to send over the network.
    Specifies a command responding to a request for a Sample for a Checkpoint.
*/
#define EACOF_CMD_CHECKPOINT_DO_SAMPLE_RESPONSE (EACOF_CMD_CHECKPOINT_DO_SAMPLE | EACOF_CMD_RESPONSE)

/**
    A command to send over the network.
    Specifies a command providing a UID for a Probe.
*/
#define EACOF_CMD_PROBE_UID_RESPONSE      (EACOF_CMD_PROBE_UID | EACOF_CMD_RESPONSE)
/**
    A command to send over the network.
    Specifies a command providing a UID for a Checkpoint.
*/
#define EACOF_CMD_CHECKPOINT_UID_RESPONSE (EACOF_CMD_CHECKPOINT_UID | EACOF_CMD_RESPONSE)

/**
    A command to send over the network.
    Specifies a command responding to something where the command in the request was unknown.
*/
#define EACOF_CMD_RESPONSE_CMD_UNKNOWN (EACOF_CMD_CMD_UNKNOWN | EACOF_CMD_RESPONSE)

int eacof_netSendCommandUnknown(int sockfd);
int eacof_netSendCreateProbe(eacof_Probe *probe);
int eacof_netSendProbeUidRequest(int sockfd, eacof_ProbeID uid);
int eacof_netSendDeleteProbe(eacof_Probe *probe);
int eacof_netSendUpdateProbe(eacof_Probe *probe);
int eacof_netSendAddSample(eacof_ProbeID probeid, eacof_Sample sample);

int eacof_netSendCreateCheckpoint(eacof_Checkpoint *checkpoint);
int eacof_netSendCheckpointUidRequest(int sockfd, eacof_CheckpointID uid);
int eacof_netSendDeleteCheckpoint(eacof_Checkpoint *checkpoint);

int eacof_netSendSampleCheckpointRequest(eacof_Checkpoint *checkpoint, eacof_Sample *sample);
int eacof_netSendSampleCheckpointResponse(int sockfd, eacof_Sample sample);

#ifdef __cplusplus
}
#endif

#endif // EACOF_NETWORK_API_H
