#ifndef EACOF_PROVIDER_H
#define EACOF_PROVIDER_H
/**
    @file

    @brief A header for the public Provider API.
*/

#include <eacof/shared.h>
#include <eacof/network_api.h>

#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int createProbe(eacof_Probe **newProbe, eacof_DeviceCount numDevices, ...);
int deleteProbe(eacof_Probe **probe);
int activateProbe(eacof_Probe *probe);
int deactivateProbe(eacof_Probe *probe);
int addSample(eacof_Probe *probe, eacof_Sample sample);

#ifdef __cplusplus
}
#endif

#endif // EACOF_PROVIDER_H
