#ifndef EACOF_TYPES_H
#define EACOF_TYPES_H
/**
    @file

    @brief A header defining types used in EACOF.
*/

#include <eacof/sqlite3.h>
#include <eacof/status.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
    A type for specifying a Device.

    @see device-classification.md
*/
typedef uint64_t eacof_Device;
/**
    A type for specifying how many Devices are to be expected.

    @remark Ensure the maximum value of DeviceCount is less than the maximum value of size_t
*/
typedef uint16_t eacof_DeviceCount;

/**
    A type for specifying a Probe's ID.
*/
typedef uint32_t eacof_ProbeID;
/**
    A type for specifying a Checkpoint's ID.
*/
typedef uint32_t eacof_CheckpointID;
/**
    A type for specifying a process ID.

    @remark Would ideally be something like a pid_t, however this does not serialize nicely and is not very cross-platform.
            An int64_t *should* work, however there may be odd cases where it doesn't.
            At this point, there is no handling for per-process monitoring, so it can be investigated further in the future.
*/
typedef int64_t eacof_ProcessSpecifier;
/**
    A type for specifying a command which is sent across the network.
*/
typedef uint16_t eacof_Command;
/**
    A type for specifying a Sample.
*/
typedef double eacof_Sample;
/**
    A type for specifying an error code.

    @todo Ensure that errors work with signed values
*/
typedef int eacof_ErrorCode;

/**
    A struct to represent a Probe.
*/
struct eacof_probe_t {
    eacof_ProbeID           uid;         /**< A UID given to the Probe by the framework. */
    eacof_Device           *device;      /**< A list of Devices having their energy monitored by this Probe. */
    eacof_DeviceCount       deviceCount; /**< The number of Devices monitored by this Probe. */
    bool                    active;      /**< Indicates whether the Probe is currently active. */
};
/**
    A typedef for a Probe.
    This provides an improved name over the plain struct definition.
*/
typedef struct eacof_probe_t eacof_Probe;

/**
    A struct to represent a Checkpoint.
*/
struct eacof_checkpoint_t {
    eacof_CheckpointID      uid;            /**< A UID given to the Checkpoint by the framework. */
    eacof_Device           *device;         /**< A list of Device types that this Checkpoint is monitoring. */
    eacof_DeviceCount       deviceCount;    /**< The number of Devices being monitored by this Checkpoint. */
    eacof_ProcessSpecifier  pspec;          /**< Indicates which process(es) this Checkpoint is monitoring energy for. */
};
/**
    A typedef for a Checkpoint.
    This provides an improved name over the plain struct definition.
*/
typedef struct eacof_checkpoint_t eacof_Checkpoint;

/**
    The type used for communication buffers

    @remark Must be a type where (sizeof(type) == 1)
    @see EACOF_NETBUF_TYPE_SIZE
*/
typedef unsigned char eacof_nettype;

/**
    The number of bytes per item in the network buffer.

    @remark Must be 1
*/
#define EACOF_NETBUF_TYPE_SIZE (sizeof(eacof_nettype))
/**
    Increment the network buffer based on the bit widths of used values.

    @remark Assuming EACOF_NETBUF_TYPE_SIZE is 1, this should be redundant, but is here encase strange things happen.

    @param buf The buffer to increment
    @param bytes The number of bytes to increment the buffer by

    @see EACOF_NETBUF_TYPE_SIZE
*/
#define EACOF_NETBUF_PLUS_BYTES(buf, bytes) \
    (buf + (((int)bytes % (int)EACOF_NETBUF_TYPE_SIZE) ? (int)bytes / (int)EACOF_NETBUF_TYPE_SIZE + 1 : (int)bytes / (int)EACOF_NETBUF_TYPE_SIZE)))

/**
    A struct into which received data can be parsed.
    This parsed data may then be passed on to the handler.
*/
typedef struct eacof_netrecv_t {
    uint16_t cmd;                           /**< The command that this data represents. Different commands will contain different data in the union. */
    union {
        eacof_ProbeID probeuid;             /**< A Probe UID. */
        eacof_CheckpointID checkpointuid;   /**< A Checkpoint UID. */
        eacof_Sample sample;                /**< A Sample. */
    } v;                                    /**< Data which is associated with the command. */
} eacof_netrecv_t;

/**
    A struct to contain and keep track of a network buffer for a socket.
*/
typedef struct eacof_netbuf_t {
    int sockfd;                     /**< The socket that the buffer is for. */
    eacof_nettype *buf;             /**< The buffer containing data which has been received from the socket. */
    int currBufIdx;                 /**< The current index in the buffer to add data. If not 0, indicates that the buffer contains a partial packet. */
    struct eacof_netbuf_t *next;    /**< The next node in the list of buffers. */
} eacof_netbuf_t;

/**
    A struct so variables relating to an instance of EACOF are in one place.

    @remark This is used as a global variable.
*/
typedef struct {
    int connectedSockfd;        /**< The socket that the Central Authority may be accessed at from a Provider or Consumer. */
    int listener;               /**< The socket that the Central Authority listens on. */
    fd_set master_fdSet;        /**< The master set of sockets that the Central Authority is connected to. */
    fd_set working_fdSet;       /**< A set of sockets that operations are performed upon by the Central Authority when the master set is to remain unchanged. */
    int fdmax;                  /**< The maximum value given to a connected socket. */
    eacof_netbuf_t *netBuffers; /**< A pointer to the head of the list of network buffers. @see netbuf.c */
    int netHandlingErrCode;     /**< The status code returned from network handling functions. @remark These functions cannot return the status directly because they instead return a network buffer. */
    sqlite3 *db;                /**< The database in which data is stored in the Central Authority. */
    sqlite3_stmt *queryCreateProbeProbe;                /**< A prepared SQL query to store the Probe struct part of a new Probe. */
    sqlite3_stmt *queryCreateProbeDevice;               /**< A prepared SQL query to store the Devices monitored by a new Probe. */
    sqlite3_stmt *querySelectProbe;                     /**< A prepared SQL query to select a stored Probe. */
    sqlite3_stmt *querySetProbeActiveStatus;            /**< A prepared SQL query to set whether a Probe is active or not. */
    sqlite3_stmt *queryAddSample;                       /**< A prepared SQL query to add a Sample for a given Probe. */
    sqlite3_stmt *queryDeleteProbeProbe;                /**< A prepared SQL query to delete the Probe struct part of a Probe being deleted. */
    sqlite3_stmt *queryDeleteProbeDevice;               /**< A prepared SQL query to delete the Devices monitored by a Probe being deleted. */
    sqlite3_stmt *querySelectProbeIDsForDevice;         /**< A prepared SQL query to select the IDs of Probes monitoring a specified Device. */
    sqlite3_stmt *queryAddCheckpointToProbeConnection;  /**< A prepared SQL query to specify a Probe that may provide readings for a Checkpoint. */
    sqlite3_stmt *querySampleCheckpoint;                /**< A prepared SQL query to Sample a Checkpoint. */
    sqlite3_stmt *queryUpdateCheckpointSample;          /**< A prepared SQL query to update the last Sample for a Checkpoint. */
    sqlite3_stmt *queryCreateCheckpointCheckpoint;      /**< A prepared SQL query to store the Checkpoint struct part of a new Checkpoint. */
    sqlite3_stmt *queryCreateCheckpointDevice;          /**< A prepared SQL query to store the Devices monitored by a new Checkpoint. */
    sqlite3_stmt *querySelectCheckpoint;                /**< A prepared SQL query to select a stored Checkpoint. */
    sqlite3_stmt *queryDeleteCheckpointCheckpoint;      /**< A prepared SQL query to delete the Checkpoint struct part of a Checkpoint being deleted. */
    sqlite3_stmt *queryDeleteCheckpointDevice;          /**< A prepared SQL query to delete the Devices monitored by a Checkpoint being deleted. */
} eacof_config;

#ifdef __cplusplus
}
#endif

#endif // EACOF_TYPES_H
