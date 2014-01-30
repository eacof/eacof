/**
    @file

    @brief Function implementations for the public Consumer API.

    The Consumer API is implemented here.
    This consists of create, read and delete functions for a Checkpoint.

    Handling of memory for Checkpoints is undertaken within EACOF.
    Creation and deletion of Checkpoints also requires network communication.
    The freeCheckpoint() function is therefore not visible within the header, so as to require access through deleteCheckpoint().

    @see apis.md
*/
#include <eacof/consumer.h>

#include <stdarg.h>

void freeCheckpoint(eacof_Checkpoint **checkpoint);

/**
    Used to set (create) a new Checkpoint to monitor a specified set of Devices.

    @param[out] newCheckpoint A pointer to a pointer. The set Checkpoint will be stored here.
    @param[in] pspec The ID of the process to monitor energy for. Currently only uses 'all'.]
    @param[in] deviceCount The number of devices the Checkpoint will monitor energy for.
    @param[in] devices A number of Devices to monitor energy for. The number of Devices must be the same as deviceCount.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int setCheckpoint(eacof_Checkpoint **newCheckpoint, eacof_ProcessSpecifier pspec, eacof_DeviceCount deviceCount, ...) {
    int status;

    eacofLog("API Checkpoint", "Attempting setCheckpoint()");

    va_list ap;

    eacofLog("API Checkpoint", "New Checkpoint - setting values");
    *newCheckpoint = (eacof_Checkpoint *) malloc(sizeof(**newCheckpoint));
    if(*newCheckpoint == NULL) {
        eacofLogError("API Checkpoint", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing Checkpoint");
        return EACOF_ERR_LOCAL_MALLOC;
    }

    (*newCheckpoint)->uid = 0;
    (*newCheckpoint)->deviceCount = deviceCount;
    (*newCheckpoint)->device = (eacof_Device *) malloc(deviceCount * sizeof(*((*newCheckpoint)->device)));

    if ((*newCheckpoint)->device == NULL) {
        eacofLogError("API Checkpoint", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing Checkpoint Device array");
        free(newCheckpoint);
        return EACOF_ERR_LOCAL_MALLOC;
    }

    va_start(ap, deviceCount);

    for(eacof_DeviceCount i = 0; i < deviceCount; i++) {
      // TODO: Check for invalid devices
      // TODO: Check for duplicate devices
      // TODO: Handle deviceCount having an incorrect value
      (*newCheckpoint)->device[i] = va_arg(ap,eacof_Device);
    }
    va_end(ap);

    (*newCheckpoint)->pspec = pspec;

    eacofLog("API Checkpoint", "New Checkpoint - obtaining UID");
    status = eacof_netSendCreateCheckpoint(*newCheckpoint);
    if(status != EACOF_OK) {
        // problem getting the uid
        eacofLogError("API Checkpoint", status, "Problem getting Checkpoint UID");
        freeCheckpoint(newCheckpoint);
        return status;
    }

    eacofLog("API Checkpoint", "Completed setCheckpoint() OK");

    return EACOF_OK;
}

/**
    Used to find out how much energy has been used by the Devices monitored by a given Checkpoint.

    @param[in] checkpoint A pointer to a Checkpoint.
    @param[out] value A pointer to where the sample will be stored.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int sampleCheckpoint(eacof_Checkpoint *checkpoint, eacof_Sample *value) {
    int status;

    eacofLog("API Checkpoint", "Attempting sampleCheckpoint()");

    status = eacof_netSendSampleCheckpointRequest(checkpoint, value);
    if(status) {
        eacofLogError("API Checkpoint", status, "Problem sending Sample Checkpoint Request");
    } else {
        eacofLog("API Checkpoint", "Completed sampleCheckpoint() OK");
    }

    return status;
}

/**
    Used to delete a Checkpoint which has previously been created.

    @param[in,out] checkpoint A pointer to a pointer where a Checkpoint has been allocated.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int deleteCheckpoint(eacof_Checkpoint **checkpoint) {
    int status;

    eacofLog("API Checkpoint", "Attempting deleteCheckpoint()");

    eacofLog("API Checkpoint", "Sending request to notify others of delete request");
    status = eacof_netSendDeleteCheckpoint(*checkpoint);
    if(status != EACOF_OK) {
        // problem deleting the probe
        eacofLogError("API Checkpoint", status, "Problem notifying others of Checkpoint delete request");
        freeCheckpoint(checkpoint);
        return status;
    }

    freeCheckpoint(checkpoint);

    eacofLog("API Checkpoint", "Completed deleteCheckpoint() OK");

    return EACOF_OK;
}

/**
    Used to free the memory allocated to a Checkpoint.

    @param[in,out] checkpoint A pointer to a pointer where the Checkpoint to free is located.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
void freeCheckpoint(eacof_Checkpoint **checkpoint) {
    eacofLog("API Private Checkpoint", "Attempting freeCheckpoint()");

    eacofLog("API Private Checkpoint", "free()ing Checkpoint Device list");
    free((*checkpoint)->device);
    eacofLog("API Private Checkpoint", "free()ing Checkpoint");
    free(*checkpoint);
    eacofLog("API Private Checkpoint", "NULLing pointer to pointer");
    *checkpoint = NULL;

    eacofLog("API Private Checkpoint", "Completed freeCheckpoint() OK");
    return;
}
