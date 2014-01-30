#ifndef EACOF_SHARED_H
#define EACOF_SHARED_H
/**
    @file

    @brief A header for the shared EACOF functions.

    Also includes a macro to indicate whether EACOF is in debug mode or not.
*/

#include <eacof/status.h>
#include <eacof/devices.h>
#include <eacof/types.h>
#include <eacof/storage.h>
#include <eacof/logging.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NDEBUG
/**
    A truthy value indicating whether EACOF is in debug mode.
    If non-zero, is in debug mode, otherwise it isn't.
*/
#define EACOF_DEBUG (1)

#if EACOF_DEBUG
#include <stdio.h>
#endif // EACOF_DEBUG

int initEACOF();
int stopEACOF();

#ifdef __cplusplus
}
#endif

#endif // EACOF_SHARED_H
