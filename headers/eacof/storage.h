#ifndef EACOF_STORAGE_H
#define EACOF_STORAGE_H
/**
    @file

    @brief A header for the storage functions.
*/

#include <eacof/shared.h>

#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int eacof_initStorage();
int eacof_storageCreateProbe(eacof_Probe *probe);
int eacof_storageSelectProbe(eacof_Probe *probe, eacof_Sample *sample);
int eacof_storageSetProbeActiveStatus(eacof_Probe *probe);
int eacof_storageAddSample(eacof_Sample increase, eacof_ProbeID probeid);
int eacof_storageDeleteProbe(eacof_ProbeID probeid);

int eacof_storageLinkProbeToCheckpoint(eacof_Checkpoint *checkpoint);
int eacof_storageSampleCheckpoint(eacof_Checkpoint *checkpoint, eacof_Sample *currentSample);

int eacof_storageCreateCheckpoint(eacof_Checkpoint *checkpoint);
int eacof_storageSelectCheckpoint(eacof_Checkpoint *checkpoint);
int eacof_storageDeleteCheckpoint(eacof_CheckpointID checkpointid);
int eacof_freeStorage();

#ifdef __cplusplus
}
#endif

#endif // EACOF_STORAGE_H
