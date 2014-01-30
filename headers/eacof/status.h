#ifndef EACOF_STATUS_H
#define EACOF_STATUS_H

/**
    @file

    @brief Status codes relating to the current operation of code.

    Most of these codes indicate errors, although there is one that indicates all went OK.
    Since the 'all is OK' value evaluates to false and other errors evaluate to true, they may be simply used as return codes to see whether an error occurred or not.

    The error codes are broken into three groups:

    - *Top-level classes* take the lower 8 bits of an error and indicate where an error occurred.
    - *Sub-classes* take the upper 8 bits of an error and indicate more specifically what went wrong.
    - *Full error codes* at 16 bits long and combine a top-level value and a sub-class
*/

#ifdef __cplusplus
extern "C" {
#endif

// helper macros
// TODO: Add a macro to see if an error type is of a higher class

// status codes
// top-level general classes
/**
    An error code indicating that everything was successful, nothing went wrong, and execution may continue as normal.

    @remark Has a value that evaluates to false.
*/
#define EACOF_OK (0x00)
/**
    An error code indicating there was an error relating to storage.
    This is a general group filling the lower 8 bits of an error code.
    It may be combined with error codes for the upper 8 bits to better specify the error.
*/
#define EACOF_ERR_STORAGE (0x01)
/**
    An error code indicating there was an error relating to something with the network.
    This is a general group filling the lower 8 bits of an error code.
    It may be combined with error codes for the upper 8 bits to better specify the error.
*/
#define EACOF_ERR_NETWORK (0x02)
/**
    An error code indicating there was an error locally.
    This is a general group filling the lower 8 bits of an error code.
    It may be combined with error codes for the upper 8 bits to better specify the error.
*/
#define EACOF_ERR_LOCAL (0x03)
/**
    An error code indicating there was an error on a remote EACOF-aware component.
    This is a general group filling the lower 8 bits of an error code.
    It may be combined with error codes for the upper 8 bits to better specify the error.
*/
#define EACOF_ERR_REMOTE (0x04)

// sub-classes of errors
/**
    An error code indicating there was an error during initialisation.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_INIT (0x01 << 8)
/**
    An error code indicating there was an error storing data.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_STORING (0x02 << 8)
/**
    An error code indicating there was an error allocating memory.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_MALLOC (0x03 << 8)
/**
    An error code indicating a message specified an unsupported protocol version.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_UNSUPPORTED_PROTOCOL (0x04 << 8)
/**
    An error code indicating there was an error receiving data.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_RECV (0x05 << 8)
/**
    An error code indicating there was an error when polling for updates of some kind.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_POLLING (0x06 << 8)
/**
    An error code indicating there was an error sending data.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_SEND (0x07 << 8)
/**
    An error code indicating there was an error because of a specified value being out of the allowed range.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_OUT_OF_RANGE (0x08 << 8)
/**
    An error code indicating there was an error because of a function parameter being invalid.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_INVALID_PARAMETER (0x09 << 8)
/**
    An error code indicating there was an error with a response.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_RESPONSE (0x0A << 8)
/**
    An error code indicating there was an error with requested data not existing.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_UNAVAILABLE_DATA (0x0B << 8)
/**
    An error code indicating there was an error matching things.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_NO_MATCH (0x0C << 8)
/**
    An error code indicating there was an error closing something.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_CLOSE (0x0D << 8)
/**
    An error code indicating there was an error ralloc()ing memory.
    This is a more specific error filling the upper 8 bits of an error code.
    It may be combined with error codes for the lower 8 bits to determine where it occurred.
*/
#define EACOF_ERR_REALLOC (0x0E << 8)

// combined error statuses
/**
    An error code indicating there was an error initialising storage.
*/
#define EACOF_ERR_STORAGE_INIT (EACOF_ERR_STORAGE | EACOF_ERR_INIT)
/**
    An error code indicating there was an error storing data.
*/
#define EACOF_ERR_STORAGE_STORING (EACOF_ERR_STORAGE | EACOF_ERR_STORING)
/**
    An error code indicating there was an error malloc()ing data while storing or retrieving data.
*/
#define EACOF_ERR_STORAGE_MALLOC (EACOF_ERR_STORAGE | EACOF_ERR_MALLOC)
/**
    An error code indicating there was an error realloc()ing data while storing or retrieving data.
*/
#define EACOF_ERR_STORAGE_REALLOC (EACOF_ERR_STORAGE | EACOF_ERR_REALLOC)
/**
    An error code indicating there was an error matching a Checkpoint with a Probe.
*/
#define EACOF_ERR_STORAGE_NO_MATCH (EACOF_ERR_STORAGE | EACOF_ERR_NO_MATCH)

/**
    An error code indicating there was an error initialising network connections.
*/
#define EACOF_ERR_NETWORK_INIT (EACOF_ERR_NETWORK | EACOF_ERR_INIT)
/**
    An error code indicating a message specified a network protocol version which is unsupported.

    @see EACOF_NET_VERSION
    @see EACOF_CAN_USE_NET_VERSION
*/
#define EACOF_ERR_NETWORK_UNSUPPORTED_PROTOCOL (EACOF_ERR_NETWORK | EACOF_ERR_UNSUPPORTED_PROTOCOL)
/**
    An error code indicating there was an error recv()ing data from the network.
*/
#define EACOF_ERR_NETWORK_RECV (EACOF_ERR_NETWORK | EACOF_ERR_RECV)
/**
    An error code indicating there was an error while polling for some kind of data from the network.
*/
#define EACOF_ERR_NETWORK_POLLING (EACOF_ERR_NETWORK | EACOF_ERR_POLLING)
/**
    An error code indicating there was an error send()ing data across the network.
*/
#define EACOF_ERR_NETWORK_SEND (EACOF_ERR_NETWORK | EACOF_ERR_SEND)
/**
    An error code indicating there was an error with a response from the network.
    This likely means that a response specified a command that was unexpected.
*/
#define EACOF_ERR_NETWORK_RESPONSE (EACOF_ERR_NETWORK | EACOF_ERR_RESPONSE)

/**
    An error code indicating that a local value was out of range.
*/
#define EACOF_ERR_LOCAL_OUT_OF_RANGE (EACOF_ERR_LOCAL | EACOF_ERR_OUT_OF_RANGE)
/**
    An error code indicating that a parameter passed to a function locally was invalid.
*/
#define EACOF_ERR_LOCAL_INVALID_PARAMETER (EACOF_ERR_LOCAL | EACOF_ERR_INVALID_PARAMETER)
/**
    An error code indicating that a local call to malloc() failed.
*/
#define EACOF_ERR_LOCAL_MALLOC (EACOF_ERR_LOCAL | EACOF_ERR_MALLOC)
/**
    An error code indicating that a local call to close() a network connection failed.
*/
#define EACOF_ERR_LOCAL_CLOSE (EACOF_ERR_LOCAL | EACOF_ERR_CLOSE)
/**
    An error code indicating that data which was requested locally doesn't exist.
*/
#define EACOF_ERR_LOCAL_UNAVAILABLE_DATA (EACOF_ERR_LOCAL | EACOF_ERR_UNAVAILABLE_DATA)

/**
    An error code indicating that a remote value was out of range.
*/
#define EACOF_ERR_REMOTE_OUT_OF_RANGE (EACOF_ERR_REMOTE | EACOF_ERR_OUT_OF_RANGE)
/**
    An error code indicating that a parameter passed to a function remotely was invalid.
*/
#define EACOF_ERR_REMOTE_INVALID_PARAMETER (EACOF_ERR_REMOTE | EACOF_ERR_INVALID_PARAMETER)

#ifdef __cplusplus
}
#endif

#endif // EACOF_STATUS_H
