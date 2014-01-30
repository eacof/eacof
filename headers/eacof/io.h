#ifndef EACOF_IO_H
#define EACOF_IO_H
/**
    @file

    @brief A header for the IO functions.
*/

#include <eacof/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void testPrintProbe(eacof_Probe probe);
void testPrintCheckpoint(eacof_Checkpoint checkpoint);

void printProbe(eacof_Probe probe);
void printCheckpoint(eacof_Checkpoint checkpoint);

#ifdef __cplusplus
}
#endif

#endif // EACOF_IO_H
