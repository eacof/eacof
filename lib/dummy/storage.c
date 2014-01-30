/**
    @file

    @brief This file is used so that implementations of the storage functions exist for Consumers and Providers.

    Since storage is not used by the libraries in these instances, functionality does not matter.
    Not using the actual implementation saves significant size because the storage library is not included.

    Ideally `libeacof` will be compiled such that this file is not required.

    @see lib/ca/storage.c for full documentation of contained functions.
*/
#include <eacof/storage.h>

/**
    Initialises the EACOF storage system.
*/
int eacof_initStorage() {
    return EACOF_OK;
}

/**
    Stores a newly created Probe
*/
int eacof_storageCreateProbe(eacof_Probe *probe) {
    (void)(probe);
    return EACOF_OK;
}

/**
    Fills in a Probe struct with information about it.
    The information is from the DB, with values being based on the uid of the passed struct
*/
int eacof_storageSelectProbe(eacof_Probe *probe, eacof_Sample *sample) {
    (void)(probe);
    (void)(sample);
    return EACOF_OK;
}

/**
    Updates whether or not a Probe is active
*/
int eacof_storageSetProbeActiveStatus(eacof_Probe *probe) {
    (void)(probe);
    return EACOF_OK;
}

/**
    Increases the sample for a probe with the given ID
*/
int eacof_storageAddSample(eacof_Sample increase, eacof_ProbeID probeid) {
    (void)(increase);
    (void)(probeid);
    return EACOF_OK;
}

/**
    Deletes a Probe with the passed uid
*/
int eacof_storageDeleteProbe(eacof_ProbeID probeid) {
    (void)(probeid);
    return EACOF_OK;
}

/**
    Decides which Probe should be used for a given Checkpoint.
*/
int eacof_storageLinkProbeToCheckpoint(eacof_Checkpoint *checkpoint) {
    (void)(checkpoint);
    return EACOF_OK;
}

/**
    Samples a Checkpoint, updating it with the sample reading since the last time it was checked.
*/
int eacof_storageSampleCheckpoint(eacof_Checkpoint *checkpoint, eacof_Sample *currentSample) {
    (void)(checkpoint);
    (void)(currentSample);
    return EACOF_OK;
}

/**
    Stores a newly created Checkpoint
*/
int eacof_storageCreateCheckpoint(eacof_Checkpoint *checkpoint) {
    (void)(checkpoint);
    return EACOF_OK;
}

/**
    Fills in a Checkpoint struct with information about it.
    The information is from the DB, with values being based on the uid of the passed struct
*/
int eacof_storageSelectCheckpoint(eacof_Checkpoint *checkpoint) {
    (void)(checkpoint);
    return EACOF_OK;
}

/**
    Deletes a Checkpoint with the passed uid
*/
int eacof_storageDeleteCheckpoint(eacof_CheckpointID checkpointid) {
    (void)(checkpointid);
    return EACOF_OK;
}

/**
    Closes the storage system
*/
int eacof_freeStorage() {
    return EACOF_OK;
}
