/**
    @file

    @brief Code for storing and retrieving data.

    Data stored includes Probes, Checkpoints and Samples.
    This storage implementation uses an SQLite database to keep track of information.

    Storage is a task performed by the Central Authority.
    Providers and Consumers communicate with the Central Authority over the network to provide information about the data to store.

    An alternative storage implementation may be created and will likely impact the storage-related members on the `_eacof` struct.

    @see internal-structure.md
*/
#include <eacof/storage.h>

extern eacof_config *_eacof;
#include <stdio.h>

// some convenience macros to make it easier to write nice looking
// code without having to skip some or all of the status checking

/**
    Prepare a statement for use

    @param STMT The sqlite3_stmt to prepare.
    @param QUERY The next of the SQL that makes up the statement.
*/
#define EACOF_STORAGE_PREPARE_STMT(STMT, QUERY) \
    eacofLog("Storage Init", "Preparing statement: %s Query: %s", #STMT, QUERY); \
    status = sqlite3_prepare_v2(_eacof->db, QUERY, -1, &STMT, NULL); \
    if(status != SQLITE_OK) { \
        eacofLogError("Storage Init", EACOF_ERR_STORAGE_STORING, "Problem preparing statement %d", status); \
        return EACOF_ERR_STORAGE_STORING; \
    }

/**
    Reset the statement from last time it was used.
    This should be called before binding encase an error caused an early
    return last time this was called, preventing a reset from happening.

    @param STMT The sqlite3_stmt to reset.
*/
#define EACOF_STORAGE_RESET_QUERY(STMT) \
    eacofLog("Storage Init", "Resetting statement. %s", #STMT); \
    status = sqlite3_reset(STMT); \
    if(status != SQLITE_OK) { \
        eacofLogError("Storage Init", EACOF_ERR_STORAGE_STORING, "Problem resetting statement %d", status); \
        return EACOF_ERR_STORAGE_STORING; \
    }

// allow arbitrary values to be outputted
// these are the types allowed for binding sqlite parameters
/**
    A printf()-style format specifier for a double datatype.
*/
#define EACOF_FORMAT_FOR_PRINTF_double "%lf"
/**
    A printf()-style format specifier for an int datatype.
*/
#define EACOF_FORMAT_FOR_PRINTF_int "%d"
/**
    A printf()-style format specifier for an int64 datatype.

    @todo Make this work when sqlite doesn't use int64_t internally for its int64
*/
#define EACOF_FORMAT_FOR_PRINTF_int64 "%" PRIi64
/**
    A printf()-style format specifier for a blob datatype.

    @todo Properly output the blob contents
*/
#define EACOF_FORMAT_FOR_PRINTF_blob "%d"
/**
    Obtain a format specifier for a datatype to be displayed in a printf()-style statement.

    @param DATATYPE The datatype to get a format specifier for
*/
#define EACOF_FORMAT_FOR_PRINTF(DATATYPE) EACOF_FORMAT_FOR_PRINTF_##DATATYPE

/**
    Bind a parameter to a statement.

    @param DATATYPE The datatype of the parameter being bound.
    @param STMT The sqlite3_stmt being bound to.
    @param PARAMNAME The name of the parameter in the original SQL for the statement.
    @param VALUE The value to be given to the parameter.
*/
#define EACOF_STORAGE_BIND_PARAM(DATATYPE, STMT, PARAMNAME, VALUE) \
    eacofLog("Storage DB", "Binding a parameter to a query. Query: %s, Type: %s, Param: %s, Value: " EACOF_FORMAT_FOR_PRINTF(DATATYPE), #STMT, #DATATYPE, #PARAMNAME, VALUE); \
    status = sqlite3_bind_##DATATYPE (STMT, sqlite3_bind_parameter_index(STMT, ":" PARAMNAME), VALUE); \
    if(status != SQLITE_OK) { \
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem binding a parameter to a statement %d", status); \
        return EACOF_ERR_STORAGE_STORING; \
    }

/**
    Bind a blob parameter to a statement.
    This differs from regular statements since there are more parameters.

    @param STMT The sqlite3_stmt being bound to.
    @param PARAMNAME The name of the parameter in the original SQL for the statement.
    @param VALUE The value to be given to the parameter.
    @param BYTES The number of bytes in the blob.
    @param DESTRUCTOR A destructor for the blob.
*/
#define EACOF_STORAGE_BIND_PARAM_BLOB(STMT, PARAMNAME, VALUE, BYTES, DESTRUCTOR) \
    eacofLog("Storage DB", "Binding a blob parameter to a query. %s", #STMT); \
    status = sqlite3_bind_blob (STMT, sqlite3_bind_parameter_index(STMT, ":" PARAMNAME), VALUE, BYTES, DESTRUCTOR); \
    if(status != SQLITE_OK) { \
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem binding a blob parameter to a statement %d", status); \
        return EACOF_ERR_STORAGE_STORING; \
    }

/**
    Execute a single-step query such as INSERT, UPDATE, DELETE

    @param STMT The sqlite3_stmt to perform the query for.
*/
#define EACOF_STORAGE_STEP_QUERY(STMT) \
    eacofLog("Storage DB", "Stepping a query to the next stage. %s", #STMT); \
    status = sqlite3_step(STMT); \
    if(status != SQLITE_DONE) { \
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem stepping a query to the next stage %d", status); \
        return EACOF_ERR_STORAGE_STORING; \
    }

// find the default values returned when querying the DB
#define EACOF_STORAGE_DEFAULT_GET_VALUE_double (0.0)
#define EACOF_STORAGE_DEFAULT_GET_VALUE_int (0)
#define EACOF_STORAGE_DEFAULT_GET_VALUE_int64 (0)
#define EACOF_STORAGE_DEFAULT_GET_VALUE_blob (NULL)
#define EACOF_STORAGE_DEFAULT_GET_VALUE(DATATYPE) EACOF_STORAGE_DEFAULT_GET_VALUE_##DATATYPE

/**
    Extract a value from a column and set a variable to this value, including a cast.

    @param VARIABLE A variable to store the result in.
    @param CAST The datatype to cast the query result to. This must be the same as the type of VARIABLE.
    @param DATATYPE The datatype of the column in the database.
    @param STMT The sqlite3_stmt to perform the get-value against.
    @param IDX The index of the column to get a value from.
*/
#define EACOF_STORAGE_GET_VALUE_WITH_CAST(VARIABLE, CAST, DATATYPE, STMT, IDX) \
    eacofLog("Storage DB", "Retrieving value from DB. Var: %s, Type: %s, Stmt: %s, Col idx: %d", #VARIABLE, #DATATYPE, #STMT, IDX); \
    VARIABLE = (CAST) sqlite3_column_##DATATYPE (STMT, IDX); \
    if(VARIABLE == EACOF_STORAGE_DEFAULT_GET_VALUE(DATATYPE) && sqlite3_errcode(_eacof->db) == SQLITE_NOMEM) { \
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_MALLOC, "Problem allocating memory to query storage"); \
    } \
    eacofLog("Storage DB", "Value retrieved for Var: %s - Value: " EACOF_FORMAT_FOR_PRINTF(DATATYPE), #VARIABLE, VARIABLE);

/**
    Extract a value from a column and set a variable to this value.

    @param VARIABLE A variable to store the result in.
    @param DATATYPE The datatype of the column in the database.
    @param STMT The sqlite3_stmt to perform the get-value against.
    @param IDX The index of the column to get a value from.
*/
#define EACOF_STORAGE_GET_VALUE(VARIABLE, DATATYPE, QUERY, IDX) \
    eacofLog("Storage DB", "Retrieving value from DB. Var: %s, Type: %s, Query: %s, Col idx: %d", #VARIABLE, #DATATYPE, #QUERY, IDX); \
    VARIABLE = sqlite3_column_##DATATYPE (QUERY, IDX); \
    if(VARIABLE == EACOF_STORAGE_DEFAULT_GET_VALUE(DATATYPE) && sqlite3_errcode(_eacof->db) == SQLITE_NOMEM) { \
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_MALLOC, "Problem allocating memory to query storage"); \
    } \
    eacofLog("Storage DB", "Value retrieved for Var: %s - Value: " EACOF_FORMAT_FOR_PRINTF(DATATYPE), #VARIABLE, VARIABLE);

/**
    Initialises the EACOF storage system.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_initStorage() {
    int numTables = 4;
    const char *createTableCommands[numTables];
    int status;

    createTableCommands[0] =    "CREATE TABLE probe ("
                                "ProbeID INTEGER NOT NULL,"
                                "Active INTEGER NOT NULL,"
                                "SockFD INTEGER,"
                                "Sample REAL NOT NULL DEFAULT 0,"
                                "UNIQUE (ProbeID)"
                                ")";

    createTableCommands[1] =    "CREATE TABLE checkpoint ("
                                "CheckpointID INTEGER NOT NULL,"
                                "ProcessSpecifier INTEGER NOT NULL,"
                                "UNIQUE (CheckpointID)"
                                ")";

    createTableCommands[2] =    "CREATE TABLE device ("
                                "ConnectionType TEXT NOT NULL,"
                                "ConnectionID INTEGER NOT NULL,"
                                "Type BLOB NOT NULL"
                                ")";

    createTableCommands[3] =    "CREATE TABLE probeConnections ("
                                "ProbeID INTEGER NOT NULL,"
                                "CheckpointID INTEGER NOT NULL,"
                                "LastSample REAL NOT NULL DEFAULT 0"
                                ")";

    eacofLog("Storage Init", "Initialising database");

    // open an in-memory database
    status = sqlite3_open(":memory:", &(_eacof->db));
    if(status != SQLITE_OK) {
        eacofLogError("Storage Init", EACOF_ERR_STORAGE_INIT, "Problem initialising database %d", status);
        eacof_freeStorage();
        return EACOF_ERR_STORAGE_INIT;
    }

    // create the tables in the database
    for(int currTable = 0; currTable < numTables; currTable++) {
        eacofLog("Storage Init", "Creating database table %s", createTableCommands[currTable]);
        status = sqlite3_exec(_eacof->db, createTableCommands[currTable], NULL, NULL, NULL);
        if(status != SQLITE_OK) {
            eacofLogError("Storage Init", EACOF_ERR_STORAGE_INIT, "Problem creating database table %d", status);
            eacof_freeStorage();
            return EACOF_ERR_STORAGE_INIT;
        }
    }

    // prepare the queries
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryCreateProbeProbe, "INSERT INTO probe(ProbeID, Active, SockFD) VALUES(:probeid, :active, :sockfd)")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryCreateProbeDevice, "INSERT INTO device(ConnectionType, ConnectionID, Type) VALUES('probe', :probeid, :devicetype)")
    EACOF_STORAGE_PREPARE_STMT(_eacof->querySelectProbe, "SELECT probe.ProbeID, probe.Active, probe.SockFD, probe.Sample, device.Type FROM probe INNER JOIN device ON probe.ProbeID=device.ConnectionID WHERE probe.ProbeID=:probeid AND device.ConnectionType='probe'")
    EACOF_STORAGE_PREPARE_STMT(_eacof->querySetProbeActiveStatus, "UPDATE probe SET Active=:value WHERE ProbeID=:probeid")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryAddSample, "UPDATE probe SET Sample=Sample+:sampleincrease WHERE ProbeID=:probeid")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryDeleteProbeProbe, "DELETE FROM probe WHERE ProbeID=:probeid")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryDeleteProbeDevice, "DELETE FROM device WHERE ConnectionType='probe' AND ConnectionID=:probeid")

    EACOF_STORAGE_PREPARE_STMT(_eacof->querySelectProbeIDsForDevice, "SELECT device.ConnectionID FROM device WHERE ConnectionType='probe' AND Type=:devicetype")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryAddCheckpointToProbeConnection, "INSERT INTO probeConnections(ProbeID, CheckpointID, LastSample) VALUES(:probeid, :checkpointid, :lastsample)")
    EACOF_STORAGE_PREPARE_STMT(_eacof->querySampleCheckpoint, "SELECT probe.Sample, probeConnections.LastSample FROM probe INNER JOIN probeConnections ON probe.ProbeID=probeConnections.ProbeID WHERE probeConnections.CheckpointID=:checkpointid")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryUpdateCheckpointSample, "UPDATE probeConnections SET LastSample=:lastsample WHERE CheckpointID=:checkpointid")

    EACOF_STORAGE_PREPARE_STMT(_eacof->queryCreateCheckpointCheckpoint, "INSERT INTO checkpoint(CheckpointID, ProcessSpecifier) VALUES(:checkpointid, :processspecifier)")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryCreateCheckpointDevice, "INSERT INTO device(ConnectionType, ConnectionID, Type) VALUES('checkpoint', :checkpointid, :devicetype)")
    EACOF_STORAGE_PREPARE_STMT(_eacof->querySelectCheckpoint, "SELECT checkpoint.CheckpointID, checkpoint.ProcessSpecifier, device.Type FROM checkpoint INNER JOIN device ON checkpoint.CheckpointID=device.ConnectionID WHERE checkpoint.CheckpointID=:checkpointid AND device.ConnectionType='checkpoint'")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryDeleteCheckpointCheckpoint, "DELETE FROM checkpoint WHERE CheckpointID=:checkpointid")
    EACOF_STORAGE_PREPARE_STMT(_eacof->queryDeleteCheckpointDevice, "DELETE FROM device WHERE ConnectionType='checkpoint' AND ConnectionID=:checkpointid")

    eacofLog("Storage Init", "Initialised database");

    return EACOF_OK;
}

/**
    Stores a newly created Probe

    @param[in] probe The Probe to add a new entry in storage for.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageCreateProbe(eacof_Probe *probe) {
    int status;

    eacofLog("Storage Query", "Attempting to store a Probe");
    eacofLog("Storage Query", "Storing Probe");

    // reset the query so that new values can be bound
    EACOF_STORAGE_RESET_QUERY(_eacof->queryCreateProbeProbe)

    // bind the Probe values to insert
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryCreateProbeProbe, "probeid", (sqlite3_int64)(probe->uid))
    EACOF_STORAGE_BIND_PARAM(int, _eacof->queryCreateProbeProbe, "active", probe->active ? 1 : 0)
    // TODO: Insert the correct socket value
    EACOF_STORAGE_BIND_PARAM(int, _eacof->queryCreateProbeProbe, "sockfd", 10)

    // insert the probe values
    EACOF_STORAGE_STEP_QUERY(_eacof->queryCreateProbeProbe)

    eacofLog("Storage Query", "Storing Devices for Probe");
    // insert the devices for this Probe
    // TODO: Do this in one query rather than lots
    for(eacof_DeviceCount currDev = 0; currDev < probe->deviceCount; currDev++) {
        EACOF_STORAGE_RESET_QUERY(_eacof->queryCreateProbeDevice)

        EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryCreateProbeDevice, "probeid", (sqlite3_int64)(probe->uid))
        EACOF_STORAGE_BIND_PARAM_BLOB(_eacof->queryCreateProbeDevice, "devicetype", &(probe->device[currDev]), 8, SQLITE_TRANSIENT)

        EACOF_STORAGE_STEP_QUERY(_eacof->queryCreateProbeDevice)
    }

    eacofLog("Storage Query", "Stored a Probe");

    return EACOF_OK;
}

/**
    Fills in a Probe struct with information about it.
    The information is from the DB, with values being based on the uid of the passed struct

    @param[in,out] probe A pointer to a Probe to fill in with data. It has had its UID field set.
    @param[out] sample A pointer to a Sample to fill in with the current reading for the specified Probe.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageSelectProbe(eacof_Probe *probe, eacof_Sample *sample) {
    int status;
    eacof_DeviceCount currDev;
    eacof_Device *deviceList;
    uint64_t *devicePtr;
    int sockfd;
    eacof_DeviceCount currDeviceListLength = 10;

    eacofLog("Storage Query", "Attempting to select a Probe");

    // reset the query from last time it was used
    EACOF_STORAGE_RESET_QUERY(_eacof->querySelectProbe)

    // bind the ID to select
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->querySelectProbe, "probeid", (sqlite3_int64)(probe->uid))

    // select the values from the DB
    eacofLog("Storage Query", "Selecting values from the DB");
    currDev = 0;
    deviceList = (eacof_Device *) malloc(currDeviceListLength * sizeof(eacof_Device));
    if(deviceList == NULL) {
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem malloc()ing an array");
        return EACOF_ERR_STORAGE_MALLOC;
    }
    while(1) {
        // NOTE: This does not use the macro version due to alternative error handling
        status = sqlite3_step(_eacof->querySelectProbe);
        if(status == SQLITE_DONE) {
            eacofLog("Storage DB", "Query stepping complete");
            break;
        } else if(status == SQLITE_ROW) {
            if(!currDev) {
                int probeIsActive;
                // TODO: Check for error (default) values being returned and handle appropriately
                // first row, so fill in the details for everything
                EACOF_STORAGE_GET_VALUE_WITH_CAST(probe->uid, eacof_ProbeID, int64, _eacof->querySelectProbe, 0)
                EACOF_STORAGE_GET_VALUE(probeIsActive, int, _eacof->querySelectProbe, 1)
                probe->active = probeIsActive ? true : false;
                EACOF_STORAGE_GET_VALUE(sockfd, int, _eacof->querySelectProbe, 2)
                EACOF_STORAGE_GET_VALUE((*sample), double, _eacof->querySelectProbe, 3)
            }
            // get the next type of device
            EACOF_STORAGE_GET_VALUE_WITH_CAST(devicePtr, uint64_t *, blob, _eacof->querySelectProbe, 4)
            // ensure that there is enough space in the array
            if(currDev >= currDeviceListLength) {
                currDeviceListLength *= 2;
                deviceList = realloc(deviceList, currDeviceListLength);
                if(deviceList == NULL) {
                    eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem realloc()ing an array");
                    return EACOF_ERR_STORAGE_REALLOC;
                }
            }
            deviceList[currDev] = *devicePtr;

            currDev++;
        } else {
            eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem stepping a query to select a Probe %d", status);
            return EACOF_ERR_STORAGE_STORING;
        }
    }

    probe->deviceCount = currDev;
    // TODO: Fix possible memory leaks that this causes
    probe->device = deviceList;

    eacofLog("Storage Query", "Selected a Probe");

    return EACOF_OK;
}

/**
    Updates whether or not a Probe is active

    @param[in] probe A Probe with a UID and active status set.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageSetProbeActiveStatus(eacof_Probe *probe) {
    int status;

    eacofLog("Storage Query", "Attempting to set Probe active status");

    EACOF_STORAGE_RESET_QUERY(_eacof->querySetProbeActiveStatus)

    EACOF_STORAGE_BIND_PARAM(int, _eacof->querySetProbeActiveStatus, "value", probe->active ? 1 : 0)
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->querySetProbeActiveStatus, "probeid", (sqlite3_int64)(probe->uid))

    EACOF_STORAGE_STEP_QUERY(_eacof->querySetProbeActiveStatus)

    eacofLog("Storage Query", "Set Probe active status");

    return EACOF_OK;
}

/**
    Increases the sample for a probe with the given ID

    @param[in] increase The amount that a Sample has increased by, in Joules.
    @param[in] probeid The ID of the Probe that the increase is for.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageAddSample(eacof_Sample increase, eacof_ProbeID probeid) {
    int status;

    eacofLog("Storage Query", "Attempting to add a sample, value: %lf", increase);

    EACOF_STORAGE_RESET_QUERY(_eacof->queryAddSample)

    EACOF_STORAGE_BIND_PARAM(double, _eacof->queryAddSample, "sampleincrease", increase)
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryAddSample, "probeid", (sqlite3_int64)(probeid))

    EACOF_STORAGE_STEP_QUERY(_eacof->queryAddSample)

    eacofLog("Storage Query", "Added a sample");

    return EACOF_OK;
}

/**
    Deletes a Probe with the passed uid

    @param[in] probeid The UID of the Probe to delete from storage.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageDeleteProbe(eacof_ProbeID probeid) {
    int status;

    eacofLog("Storage Query", "Attempting to delete a Probe");

    // perform the various steps for both the queries together
    EACOF_STORAGE_RESET_QUERY(_eacof->queryDeleteProbeProbe)
    EACOF_STORAGE_RESET_QUERY(_eacof->queryDeleteProbeDevice)

    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryDeleteProbeProbe, "probeid", (sqlite3_int64)(probeid))
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryDeleteProbeDevice, "probeid", (sqlite3_int64)(probeid))

    EACOF_STORAGE_STEP_QUERY(_eacof->queryDeleteProbeProbe)
    EACOF_STORAGE_STEP_QUERY(_eacof->queryDeleteProbeDevice)

    eacofLog("Storage Query", "Deleted a Probe");

    return EACOF_OK;
}

// TODO: Allow data from multiple Probes to be combined

/**
    Decides which Probe should be used for a given Checkpoint.

    @param[in] checkpoint The Checkpoint to find an appropriate Probe for.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageLinkProbeToCheckpoint(eacof_Checkpoint *checkpoint) {
    int status;
    eacof_ProbeID *connectionIDs;
    int currID;
    int numFoundIDs;
    eacof_Probe probe;
    eacof_Sample sample;
    int continueLookingForMatchingProbe;
    eacof_DeviceCount currConnectionIDListLength = 50;

    eacofLog("Storage Query", "Attempting to link a Checkpoint to a Probe");
    eacofLog("Storage Query", "Finding IDs of Probes monitoring Devices");

    connectionIDs = (eacof_ProbeID *) malloc(currConnectionIDListLength * sizeof(eacof_ProbeID));
    if(connectionIDs == NULL) {
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem malloc()ing an array");
        return EACOF_ERR_STORAGE_MALLOC;
    }
    currID = 0;

    // go through all the devices to be monitored
    // TODO: Use an algorithm that doesn't require an O(n*m) number of SQL queries/steps
    for(eacof_DeviceCount currDev = 0; currDev < checkpoint->deviceCount; currDev++) {
        EACOF_STORAGE_RESET_QUERY(_eacof->querySelectProbeIDsForDevice)

        EACOF_STORAGE_BIND_PARAM_BLOB(_eacof->querySelectProbeIDsForDevice, "devicetype", &(checkpoint->device[currDev]), 8, SQLITE_TRANSIENT)

        // find the probes which monitor this Device
        while(1) {
            // NOTE: This does not use the macro version due to alternative error handling
            status = sqlite3_step(_eacof->querySelectProbeIDsForDevice);
            if(status == SQLITE_DONE) {
                eacofLog("Storage DB", "Query stepping complete");
                break;
            } else if(status == SQLITE_ROW) {
                if(currID >= currConnectionIDListLength) {
                    currConnectionIDListLength *= 2;
                    connectionIDs = realloc(connectionIDs, currConnectionIDListLength);
                    if(connectionIDs == NULL) {
                        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem realloc()ing an array");
                        return EACOF_ERR_STORAGE_REALLOC;
                    }
                }
                // TODO: Check for error (default) values being returned and handle appropriately
                EACOF_STORAGE_GET_VALUE_WITH_CAST(connectionIDs[currID++], eacof_ProbeID, int64, _eacof->querySelectProbeIDsForDevice, 0)
            } else {
                eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem stepping a query to determine Probes with Device %d", status);
                return EACOF_ERR_STORAGE_STORING;
            }
        }
    }
    eacofLog("Storage Query", "Have the IDs of Probes monitoring Devices");
    // we now know all of the ProbeIDs we may be interested in

    // go through the Probes until we find one that has the same Devices as the Checkpoint
    // TODO: Implement the intelligent matching system
    eacofLog("Storage Query", "Determining which Probe is best to match to the Checkpoint");
    numFoundIDs = currID;
    currID = 0;
    continueLookingForMatchingProbe = 1;
    while(currID < numFoundIDs && continueLookingForMatchingProbe) {
        probe.uid = connectionIDs[currID++];
        status = eacof_storageSelectProbe(&probe, &sample);
        if(status != EACOF_OK) {
            eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem finding Probe with specified ID");
            return status;
        }

        int missedMatch = 0;
        eacof_DeviceCount currProbeDevice = 0;
        // very dumb algorithm - see if the Probe and Checkpoint each contain the same elements
        while(!missedMatch && currProbeDevice < probe.deviceCount) {
            eacof_DeviceCount currCheckpointDevice = 0;
            while(currCheckpointDevice < checkpoint->deviceCount) {
                if(checkpoint->device[currCheckpointDevice] == probe.device[currProbeDevice]) {
                    break;
                }
                currCheckpointDevice++;
            }

            if(currCheckpointDevice == checkpoint->deviceCount) {
                // this means we didn't break early, so this Device was not found
                missedMatch = 1;
            }

            currProbeDevice++;
        }

        if(!missedMatch) {
            // the Probe and Checkpoint care about the same Devices
            continueLookingForMatchingProbe = 0;
        }
    }
    free(connectionIDs);

    if(continueLookingForMatchingProbe) {
        eacofLog("Storage Query", "No matching Probe was found for this Checkpoint");
        return EACOF_ERR_STORAGE_NO_MATCH;
    }
    eacofLog("Storage Query", "Determined the best match Probe for this Checkpoint");

    // make a note of the found connection
    eacofLog("Storage Query", "Storing the Checkpoint-Probe connection");
    EACOF_STORAGE_RESET_QUERY(_eacof->queryAddCheckpointToProbeConnection)

    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryAddCheckpointToProbeConnection, "probeid", (sqlite3_int64)(probe.uid))
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryAddCheckpointToProbeConnection, "checkpointid", (sqlite3_int64)(checkpoint->uid))
    EACOF_STORAGE_BIND_PARAM(double, _eacof->queryAddCheckpointToProbeConnection, "lastsample", sample)

    EACOF_STORAGE_STEP_QUERY(_eacof->queryAddCheckpointToProbeConnection)
    eacofLog("Storage Query", "Stored the Checkpoint-Probe connection");

    eacofLog("Storage Query", "Linked a Checkpoint to a Probe");

    return EACOF_OK;
}

/**
    Samples a Checkpoint, updating it with the sample reading since the last time it was checked.

    @param[in,out] checkpoint The Checkpoint to sample. The UID must be set.
    @param[out] currentSample A pointer to a location to store the Sample for the Checkpoint.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageSampleCheckpoint(eacof_Checkpoint *checkpoint, eacof_Sample *currentSample) {
    int status;
    eacof_Sample probeSample = 0;
    eacof_Sample lastCheckpointSample = 0;

    eacofLog("Storage Query", "Attempting to sample a Checkpoint");

    eacofLog("Storage Query", "Attempting to find how much energy has been used");
    EACOF_STORAGE_RESET_QUERY(_eacof->querySampleCheckpoint)

    EACOF_STORAGE_BIND_PARAM(int64, _eacof->querySampleCheckpoint, "checkpointid", (sqlite3_int64)(checkpoint->uid))

    // should only need a single row of data, so no while() loop like other selects
    // NOTE: This does not use the macro version due to alternative error handling
    status = sqlite3_step(_eacof->querySampleCheckpoint);
    if(status == SQLITE_DONE) {
        // there was no data
    } else if(status == SQLITE_ROW) {
        // there is data - we should handle it
        EACOF_STORAGE_GET_VALUE(probeSample, double, _eacof->querySampleCheckpoint, 0)
        EACOF_STORAGE_GET_VALUE(lastCheckpointSample, double, _eacof->querySampleCheckpoint, 1)
    } else {
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem stepping a query to sample a checkpoint %d", status);
        return EACOF_ERR_STORAGE_STORING;
    }
    eacofLog("Storage Query", "Found how much energy has been used: Probe: %lf LastSample: %lf", probeSample, lastCheckpointSample);

    eacofLog("Storage Query", "Attempting to update the stored Sample reading");

    *currentSample = probeSample - lastCheckpointSample;

    EACOF_STORAGE_RESET_QUERY(_eacof->queryUpdateCheckpointSample)

    EACOF_STORAGE_BIND_PARAM(double, _eacof->queryUpdateCheckpointSample, "lastsample", probeSample)
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryUpdateCheckpointSample, "checkpointid", (sqlite3_int64)(checkpoint->uid))

    EACOF_STORAGE_STEP_QUERY(_eacof->queryUpdateCheckpointSample)

    eacofLog("Storage Query", "Updated the stored Sample reading");

    eacofLog("Storage Query", "Sampled a Checkpoint");

    return EACOF_OK;
}

/**
    Stores a newly created Checkpoint

    @param[in] checkpoint The Checkpoint to add a new entry in storage for.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageCreateCheckpoint(eacof_Checkpoint *checkpoint) {
    int status;

    eacofLog("Storage Query", "Attempting to store a Checkpoint");
    eacofLog("Storage Query", "Storing Checkpoint");

    // reset the query so that new values can be bound
    EACOF_STORAGE_RESET_QUERY(_eacof->queryCreateCheckpointCheckpoint)

    // bind the Probe values to insert
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryCreateCheckpointCheckpoint, "checkpointid", (sqlite3_int64)(checkpoint->uid))
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryCreateCheckpointCheckpoint, "processspecifier", checkpoint->pspec)

    // insert the probe values
    EACOF_STORAGE_STEP_QUERY(_eacof->queryCreateCheckpointCheckpoint)

    // insert the devices for this Probe
    // TODO: Do this in one query rather than lots
    eacofLog("Storage Query", "Storing Devices for Checkpoint");
    for(eacof_DeviceCount currDev = 0; currDev < checkpoint->deviceCount; currDev++) {
        EACOF_STORAGE_RESET_QUERY(_eacof->queryCreateCheckpointDevice)

        EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryCreateCheckpointDevice, "checkpointid", (sqlite3_int64)(checkpoint->uid))
        EACOF_STORAGE_BIND_PARAM_BLOB(_eacof->queryCreateCheckpointDevice, "devicetype", &(checkpoint->device[currDev]), 8, SQLITE_TRANSIENT)

        EACOF_STORAGE_STEP_QUERY(_eacof->queryCreateCheckpointDevice)
    }

    eacofLog("Storage Query", "Linking Checkpoint to Probe");

    eacof_storageLinkProbeToCheckpoint(checkpoint);

    eacofLog("Storage Query", "Linked Checkpoint to Probe");

    eacofLog("Storage Query", "Stored a Checkpoint");

    return EACOF_OK;
}

/**
    Fills in a Checkpoint struct with information about it.
    The information is from the DB, with values being based on the uid of the passed struct

    @param[in,out] checkpoint A pointer to a Checkpoint to fill in with data. It has had its UID field set.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageSelectCheckpoint(eacof_Checkpoint *checkpoint) {
    int status;
    eacof_DeviceCount currDev;
    eacof_Device *deviceList;
    uint64_t *devicePtr;
    eacof_DeviceCount currDeviceListLength = 10;

    eacofLog("Storage Query", "Attempting to select a Checkpoint");

    // reset the query from last time it was used
    EACOF_STORAGE_RESET_QUERY(_eacof->querySelectCheckpoint)

    // bind the ID to select
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->querySelectCheckpoint, "checkpointid", (sqlite3_int64)(checkpoint->uid))

    // select the values from the DB
    eacofLog("Storage Query", "Selecting values from the DB");
    currDev = 0;
    deviceList = (eacof_Device *) malloc(currDeviceListLength * sizeof(eacof_Device));
    if(deviceList == NULL) {
        eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem malloc()ing an array");
        return EACOF_ERR_STORAGE_MALLOC;
    }
    while(1) {
        // NOTE: This does not use the macro version due to alternative error handling
        status = sqlite3_step(_eacof->querySelectCheckpoint);
        if(status == SQLITE_DONE) {
            eacofLog("Storage DB", "Query stepping complete");
            break;
        } else if(status == SQLITE_ROW) {
            if(!currDev) {
                // first row, so fill in the details for everything
                EACOF_STORAGE_GET_VALUE_WITH_CAST(checkpoint->uid, eacof_CheckpointID, int64, _eacof->querySelectCheckpoint, 0)
                EACOF_STORAGE_GET_VALUE(checkpoint->pspec, int, _eacof->querySelectCheckpoint, 1)
            }
            // get the next type of device
            EACOF_STORAGE_GET_VALUE_WITH_CAST(devicePtr, uint64_t *, blob, _eacof->querySelectProbe, 2)
            // ensure that there is enough space in the array
            if(currDev >= currDeviceListLength) {
                currDeviceListLength *= 2;
                deviceList = realloc(deviceList, currDeviceListLength);
                if(deviceList == NULL) {
                    eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem realloc()ing an array");
                    return EACOF_ERR_STORAGE_REALLOC;
                }
            }
            deviceList[currDev] = *devicePtr;

            currDev++;
        } else {
            eacofLogError("Storage DB", EACOF_ERR_STORAGE_STORING, "Problem stepping a query to select a Checkpoint %d", status);
            return EACOF_ERR_STORAGE_STORING;
        }
    }

    checkpoint->deviceCount = currDev;
    // TODO: Fix possible memory leaks that this causes
    checkpoint->device = deviceList;

    eacofLog("Storage Query", "Selected a Checkpoint");

    return EACOF_OK;
}

/**
    Deletes a Checkpoint with the passed uid

    @param[in] checkpointid The UID of the Checkpoint to delete from storage.

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_storageDeleteCheckpoint(eacof_CheckpointID checkpointid) {
    int status;

    eacofLog("Storage Query", "Attempting to delete a Checkpoint");

    // perform the various steps for both the queries together
    EACOF_STORAGE_RESET_QUERY(_eacof->queryDeleteCheckpointCheckpoint)
    EACOF_STORAGE_RESET_QUERY(_eacof->queryDeleteCheckpointDevice)

    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryDeleteCheckpointCheckpoint, "checkpointid", (sqlite3_int64)(checkpointid))
    EACOF_STORAGE_BIND_PARAM(int64, _eacof->queryDeleteCheckpointDevice, "checkpointid", (sqlite3_int64)(checkpointid))

    EACOF_STORAGE_STEP_QUERY(_eacof->queryDeleteCheckpointCheckpoint)
    EACOF_STORAGE_STEP_QUERY(_eacof->queryDeleteCheckpointDevice)

    eacofLog("Storage Query", "Deleted a Checkpoint");

    return EACOF_OK;
}

/**
    Closes the storage system

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int eacof_freeStorage() {
    eacofLog("Storage Finalize", "Attempting to free the storage");
    eacofLog("Storage Finalize", "Finalizing queries");

    // TODO: Add error checking to see that this all goes OK
    sqlite3_finalize(_eacof->queryCreateProbeProbe);
    sqlite3_finalize(_eacof->queryCreateProbeDevice);
    sqlite3_finalize(_eacof->querySelectProbe);
    sqlite3_finalize(_eacof->querySetProbeActiveStatus);
    sqlite3_finalize(_eacof->queryAddSample);
    sqlite3_finalize(_eacof->queryDeleteProbeProbe);
    sqlite3_finalize(_eacof->queryDeleteProbeDevice);

    sqlite3_finalize(_eacof->queryCreateCheckpointCheckpoint);
    sqlite3_finalize(_eacof->queryCreateCheckpointDevice);
    sqlite3_finalize(_eacof->querySelectCheckpoint);
    sqlite3_finalize(_eacof->queryDeleteCheckpointCheckpoint);
    sqlite3_finalize(_eacof->queryDeleteCheckpointDevice);

    eacofLog("Storage Finalize", "Closing DB");
    sqlite3_close(_eacof->db);
    _eacof->db = NULL;

    eacofLog("Storage Finalize", "Freed the storage");

    return EACOF_OK;
}
