/**
    @file

    @brief Code for performing IO tasks relating to Probes and Checkpoints.

    Was used during a now-deleted test system, so provides less use than it did in the past.
*/
#include <eacof/io.h>
#include <stdio.h>

/**
    Outputs a Probe to the console for testing.

    @param[in] probe The Probe to output.
*/
void testPrintProbe(eacof_Probe probe) {
    printf("Probe(uid=%" PRIu32 ", device=[", probe.uid);
    for(eacof_DeviceCount i = 0; i < probe.deviceCount; i++) {
        printf("%" PRIu64 "", probe.device[i]);
        if(i < probe.deviceCount - 1) {
            printf(",");
        }
    }
    printf("], active=");
    if(probe.active) {
        printf("True");
    } else {
        printf("False");
    }
    printf(")\n");
}

/**
    Outputs a Checkpoint to the console for testing.

    @param[in] checkpoint The Checkpoint to output.
*/
void testPrintCheckpoint(eacof_Checkpoint checkpoint) {
    printf("Checkpoint(uid=%" PRIu32 ", device=[", checkpoint.uid);
    for(eacof_DeviceCount i = 0; i < checkpoint.deviceCount; i++) {
        printf("%" PRIu64 "", checkpoint.device[i]);
        if(i < checkpoint.deviceCount - 1) {
            printf(",");
        }
    }
    printf("], pspec=%" PRIi64 ")\n", checkpoint.pspec);
}

/**
    Outputs a Probe to the console.
    This is done in a detailed readable format.

    @param[in] probe The Probe to output.
*/
void printProbe(eacof_Probe probe) {
    printf("Num devices: %" PRIu16 "\n", probe.deviceCount);
    for(eacof_DeviceCount i = 0; i < probe.deviceCount; i++) {
        printf("Dev %" PRIu16 ": %" PRIu64 "\n", i, probe.device[i]);
    }
}

/**
    Outputs a Checkpoint to the console.
    This is done in a detailed readable format.

    @param[in] checkpoint The Checkpoint to output.
*/
void printCheckpoint(eacof_Checkpoint checkpoint) {
    printf("Num devices: %" PRIu16 "\n", checkpoint.deviceCount);
    for(eacof_DeviceCount i = 0; i < checkpoint.deviceCount; i++) {
        printf("Dev %" PRIu16 ": %" PRIu64 "\n", i, checkpoint.device[i]);
    }
    printf("pspec: %" PRIi64 "\n", checkpoint.pspec);
}
