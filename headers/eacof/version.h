#ifndef EACOF_VERSION_H
#define EACOF_VERSION_H
/**
    @file

    @brief A header defining version numbers for EACOF.
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
    The major part of EACOF's version number
*/
#define EACOF_VERSION_MAJOR (0x01)
/**
    The minor part of EACOF's version number
*/
#define EACOF_VERSION_MINOR (0x01)
/**
    EACOF's version number for compatibility within a component.
*/
#define EACOF_VERSION (EACOF_VERSION_MINOR | (EACOF_VERSION_MAJOR << 8))

/**
    The major part of EACOF's network API version number
*/
#define EACOF_NET_VERSION_MAJOR (0x01)
/**
    The minor part of EACOF's network API version number
*/
#define EACOF_NET_VERSION_MINOR (0x01)
/**
    EACOF's version number for compatibility for inter-component communication.
*/
#define EACOF_NET_VERSION (EACOF_NET_VERSION_MINOR | (EACOF_NET_VERSION_MAJOR << 8))
/**
    A truthy value to see whether a network version may be used.
    This may be useful when sent a message using a network version newer than the current local version of EACOF.

    @param VERSION The version number to check
*/
#define EACOF_CAN_USE_NET_VERSION(VERSION) \
	(((VERSION & 0xFF00) >> 8) <= EACOF_NET_VERSION_MAJOR)

#ifdef __cplusplus
}
#endif

#endif // EACOF_VERSION_H
