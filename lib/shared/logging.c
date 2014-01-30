/**
    @file

    @brief Code for performing logging of the state of EACOF.

    This includes different types of output:

    - *Standard logging* of where execution has passed
    - *Error logging* of things that happened, but didn't go OK

    There are are alternative implementations for the level of logging which has been specified.

    @see EACOF_FULL_LOGGING
*/
#include <eacof/logging.h>
#include <stdio.h>

#if EACOF_FULL_LOGGING

/**
    @param[in] type A title for the group of things to log, allowing easier identification.
    @param[in] format printf()-style text to output.
    @param[in] ... Parameters required for the printf()-style string.
*/
void eacofLog(const char *type, const char *format, ...) {
    va_list args;
    va_start(args, format);

    printf("EACOF: %s: ", type);
    vprintf(format, args);
    printf("\n");

    va_end(args);

    return;
}

/**
    @param[in] type A title for the group of things to log, allowing easier identification.
    @param[in] err The error code to output.
    @param[in] reason printf()-style text to output.
    @param[in] ... Parameters required for the printf()-style string.
*/
void eacofLogError(const char *type, eacof_ErrorCode err, const char *reason, ...) {
    va_list args;
    va_start(args, reason);

    printf("EACOF: ERROR: %s: %d ", type, err);
    vprintf(reason, args);
    printf("\n");

    va_end(args);

    return;
}

#else

/**
    @param[in] type A title for the group of things to log, allowing easier identification.
    @param[in] format printf()-style text to output.
    @param[in] ... Parameters required for the printf()-style string.
*/
void eacofLog(const char *type, const char *format, ...) {
    (void)(type);
    (void)(format);
    return;
}

/**
    @param[in] type A title for the group of things to log, allowing easier identification.
    @param[in] err The error code to output.
    @param[in] reason printf()-style text to output.
    @param[in] ... Parameters required for the printf()-style string.
*/
void eacofLogError(const char *type, eacof_ErrorCode err, const char *reason, ...) {
    (void)(type);
    (void)(err);
    (void)(reason);
    return;
}

#endif
