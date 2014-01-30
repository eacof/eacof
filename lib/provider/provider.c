/**
    @file

    @brief Function implementations for the public Provider API.

    The Provider API is implemented here.
    This consists of create, read, update and delete functions for a Probe.

    Handling of memory for Probes is undertaken within EACOF.
    Creation and deletion of Probes also requires network communication.
    The freeProbe() function is therefore not visible within the header, so as to require access through deleteProbe().

    @see apis.md
*/
#include <eacof/provider.h>
#include <stdarg.h>

void freeProbe(eacof_Probe **probe);

/**
    Used to set (create) a new Probe to monitor a specified set of Devices.

    @param[out] newProbe A pointer to a pointer. The set Probe will be stored here.
    @param[in] deviceCount The number of devices the Probe will monitor energy for.
    @param[in] devices A number of Devices energy is being monitored for. The number of Devices must be the same as deviceCount.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int createProbe(eacof_Probe **newProbe, eacof_DeviceCount numDevices, ...) {
    int status;

    eacofLog("API Probe", "Attempting setProbe()");

    va_list ap;

    eacofLog("API Probe", "New Probe - setting values");
    (*newProbe) = (eacof_Probe *) malloc(sizeof(eacof_Probe));
    if(*newProbe == NULL) {
        eacofLogError("API Probe", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing Probe");
        return EACOF_ERR_LOCAL_MALLOC;
    }

    (*newProbe)->uid = 0;
    (*newProbe)->deviceCount = numDevices;
    (*newProbe)->device = (eacof_Device *) malloc(numDevices * sizeof(eacof_Device));

    if((*newProbe)->device == NULL) {
        eacofLogError("API Probe", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing Probe Device array");
        free(newProbe);
        return EACOF_ERR_LOCAL_MALLOC;
    }

    va_start(ap, numDevices);

    for(eacof_DeviceCount i = 0; i < numDevices; i++) {
        // TODO: Check for invalid devices
        // TODO: Check for duplicate devices
        // TODO: Handle numDevices having an incorrect value
        (*newProbe)->device[i] = va_arg(ap,eacof_Device);
    }
    va_end(ap);

    (*newProbe)->active = false;

    eacofLog("API Probe", "New Probe - obtaining UID");
    status = eacof_netSendCreateProbe(*newProbe);
    if(status != EACOF_OK) {
        // problem getting the uid
        eacofLogError("API Probe", status, "Problem getting Probe UID");
        freeProbe(newProbe);
        return status;
    }

    eacofLog("API Probe", "Completed setProbe() OK");

    return EACOF_OK;
}

/**
    Used to delete a Probe which has previously been created.

    @param[in,out] probe A pointer to a pointer where a Probe has been allocated.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int deleteProbe(eacof_Probe **probe) {
    int status;

    eacofLog("API Probe", "Attempting deleteProbe()");

    eacofLog("API Probe", "Sending request to notify others of delete request");
    status = eacof_netSendDeleteProbe(*probe);
    if(status != EACOF_OK) {
        // problem deleting the probe
        eacofLogError("API Probe", status, "Problem notifying others of Probe delete request");
        freeProbe(probe);
        return status;
    }

    freeProbe(probe);

    eacofLog("API Probe", "Completed deleteProbe() OK");

    return EACOF_OK;
}

/**
    Used to indicate that a Probe is active.

    @param[in,out] probe The probe to activate.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int activateProbe(eacof_Probe *probe) {
    int status;

    eacofLog("API Probe", "Attempting activateProbe()");

    probe->active = true;

    eacofLog("API Probe", "Sending request to notify others of activate request");
    status = eacof_netSendUpdateProbe(probe);
    if(status != EACOF_OK) {
        // problem updating the probe
        eacofLogError("API Probe", status, "Problem notifying others of Probe activate request");
        return status;
    }

    eacofLog("API Probe", "Completed activateProbe() OK");

    return EACOF_OK;
}

/**
    Used to indicate that a Probe is not currently active, but may appear again (and has therefore not been deleted).

    @param[in,out] probe The probe to deactivate.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int deactivateProbe(eacof_Probe *probe) {
    int status;

    eacofLog("API Probe", "Attempting deactivateProbe()");

    probe->active = false;

    eacofLog("API Probe", "Sending request to notify others of deactivate request");
    status = eacof_netSendUpdateProbe(probe);
    if(status != EACOF_OK) {
        // problem updating the probe
        eacofLogError("API Probe", status, "Problem notifying others of Probe deactivate request");
        return status;
    }

    eacofLog("API Probe", "Completed deactivateProbe() OK");

    return EACOF_OK;
}

/**
    Add a sample against a Probe.

    @param[in] probe The probe that the sample is for.
    @param[in] sample The sample to add. This is measured in Joules.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int addSample(eacof_Probe *probe, eacof_Sample sample) {
    int status;

    eacofLog("API Probe", "Attempting addSample()");

    status = eacof_netSendAddSample(probe->uid, sample);
    if(status) {
        eacofLogError("API Probe", status, "Problem sending request to update sample");
    } else {
        eacofLog("API Probe", "Completed addSample() OK");
    }

    return status;
}

/**
    Used to free the memory allocated to a Probe.

    @param[in,out] probe A pointer to a pointer where the Probe to free is located.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
void freeProbe(eacof_Probe **probe) {
    eacofLog("API Private Probe", "Attempting freeProbe()");

    eacofLog("API Private Probe", "free()ing Probe Device list");
    free((*probe)->device);
    eacofLog("API Private Probe", "free()ing Probe");
    free(*probe);
    eacofLog("API Private Probe", "NULLing pointer to pointer");
    *probe = NULL;

    eacofLog("API Private Probe", "Completed freeProbe() OK");
    return;
}
