#ifndef EACOF_LOGGING_H
#define EACOF_LOGGING_H
/**
    @file

    @brief A header for the logging functions.

    Includes a macro definition to indicate how much logging should be output.
*/

#include <eacof/types.h>

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    A value to specify the verbosity of logging.
    Either enables (1) or disables (0) logging depending on the value.
*/
#define EACOF_FULL_LOGGING (0)

void eacofLog(const char *type, const char *format, ...);
void eacofLogError(const char *type, eacof_ErrorCode err, const char *reason, ...);

#ifdef __cplusplus
}
#endif

#ifdef EACOF_FULL_LOGGING

#else

#endif

#endif // EACOF_LOGGING_H

