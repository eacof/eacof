#ifndef EACOF_CONSUMER_H
#define EACOF_CONSUMER_H
/**
    @file

    @brief A header for the public Consumer API.

    Also includes definitions related to specifying processes to monitor.
*/

#include <eacof/shared.h>
#include <eacof/network_api.h>

#include <inttypes.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    A ProcessSpecifier indicating interest in energy for all processes
*/
#define EACOF_PSPEC_ALL (-1000)
/**
    A ProcessSpecifier indicating interest in energy for only the current process
*/
#define EACOF_PSPEC_SELF (-1001)

int setCheckpoint(eacof_Checkpoint **newCheckpoint, eacof_ProcessSpecifier pspec, eacof_DeviceCount deviceCount, ...);
int sampleCheckpoint(eacof_Checkpoint *checkpoint, eacof_Sample *value);
int deleteCheckpoint(eacof_Checkpoint **checkpoint);

#ifdef __cplusplus
}
#endif

#endif // EACOF_CONSUMER_H
