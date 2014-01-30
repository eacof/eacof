/**
    @file

    @brief Code shared between all EACOF-aware components.

    Consists of initialisation and shutdown code.
*/
#include <eacof/shared.h>
#include <eacof/network.h>
#include <stdlib.h>

/**
    A global configuration to keep track of the status of EACOF.

    This is where anything related to how EACOF works is kept.
    That includes network status, storage, and non-returned error codes.
*/
eacof_config *_eacof;

/**
    Initialises EACOF
    Sets up network connections for non-CA components

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int initEACOF() {
    int status;

    eacofLog("General Init", "Attempting to initialise EACOF");

    // initialise the _eacof struct
    _eacof = (eacof_config*) malloc(sizeof(eacof_config));
    if(_eacof == NULL) {
        eacofLogError("General Init", EACOF_ERR_LOCAL_MALLOC, "Problem malloc()ing the EACOF struct");
        return EACOF_ERR_LOCAL_MALLOC;
    }
    _eacof->connectedSockfd = -1;
    _eacof->listener = -1;
    _eacof->fdmax = -1;
    _eacof->netBuffers = eacof_createNetbuf();
    _eacof->netBuffers->sockfd = -1;

    eacofLog("General Init", "Initialised the EACOF struct");
    // TODO: The CA doesn't need to set up network connections like this
    eacofLog("General Init", "Attempting to set up network connection");

    status = eacof_connectToDefault();
    if(status != EACOF_OK) {
        // TODO: Free the EACOF struct if something went wrong
        // TODO: The current control flow for the CA falls through here
        eacofLogError("General Init", status, "Problem setting up the network connection");
        return status;
    }

    eacofLog("General Init", "Initialisation has set up EACOF");

    return status;
}

/**
    Stop running EACOF

    @returns A status code indicating whether all went OK, or something went wrong.
    @see <eacof/status.h>
*/
int stopEACOF() {
    eacofLog("General Finalize", "Attempting to stop EACOF");

    // TODO: See if any other network things need closing
    // TODO: Add error checking to see that this all goes OK
    eacofLog("General Finalize", "Stopping network");
    eacof_freeNetbufList(_eacof->netBuffers);
    eacofLog("General Finalize", "Stopping Storage");
    eacof_freeStorage();
    eacofLog("General Finalize", "free()ing everything else");
    free(_eacof);

    eacofLog("General Finalize", "Stopped EACOF OK");

    return EACOF_OK;
}
