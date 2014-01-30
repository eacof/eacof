#ifndef EACOF_DEVICES_H
#define EACOF_DEVICES_H
/**
    @file

    @brief Definitions of the Device classification tree.

    The Device classification tree is auto-generated from a human-readable list.
    This tree is defined in an included file.

    There are three types of macro defined directly in this file.

    - *Special values* which mean something particular
    - *Helper macros* are non-essential macros which can provide values which help detect types of Device
    - *Tree generation* macros will generate the classification tree by providing unique values for each Device

    @see device-classification.md
    @see generated_devices.h
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
    A special value to indicate all devices of a given type
*/
#define EACOF_DEVICE_COUNT_ALL (255)

// helper macros to determine whether a Device is of a given type
/**
    Get rid of the bits indicating the index of a Device, leaving just those for type.

    @param DEVICE The device to ignore bits from
*/
#define EACOF_DEVICE_IGNORE_INDEX(DEVICE) \
    (DEVICE & 0x00FF00FF00FF00FF)

/**
    Get rid of the bits indicating the type of a Device, leaving just those for index.

    @param DEVICE The device to ignore bits from
*/
#define EACOF_DEVICE_IGNORE_TYPE(DEVICE) \
    (DEVICE & 0xFF00FF00FF00FF00)

/**
    Check to see whether a Device is exactly a specified type at the given indexes

    @param DEVICE The device to check
    @param COMPARISON The device being compared against
*/
#define EACOF_DEVICE_IS(DEVICE, COMPARISON) \
    (DEVICE == COMPARISON)
/**
    Check to see whether a Device is of a given type, even if indexes are different

    @param DEVICE The device to check
    @param COMPARISON The devicetype being compared against
*/
#define EACOF_DEVICE_IS_A(DEVICE, COMPARISON) \
    ((EACOF_DEVICE_IGNORE_INDEX(DEVICE) & COMPARISON == COMPARISON) && (~EACOF_DEVICE_IGNORE_INDEX(DEVICE) & ~COMPARISON == ~COMPARISON))

// create the levels of the classification tree
/**
    Create a Device at level 1 (the top) of the classification tree.

    @param VAL The devicetype at this level of the tree
    @param IDX The index of the device at this level of the tree
*/
#define EACOF_DEVICE_TREE_LEVEL_1(VAL, IDX) \
    (VAL | (IDX << 8))

/**
    Create a Device at level 2 of the classification tree.

    @param LEVEL1 A value for the part of the device at level 1 of the tree
    @param VAL The devicetype at this level of the tree
    @param IDX The index of the device at this level of the tree

    @see EACOF_DEVICE_TREE_LEVEL_1
*/
#define EACOF_DEVICE_TREE_LEVEL_2(LEVEL1, VAL, IDX) \
    (LEVEL1 | ((VAL | (IDX << 8)) << 16))

/**
    Create a Device at level 3 of the classification tree.

    @param LEVEL2 A value for the part of the device at level 2 of the tree
    @param VAL The devicetype at this level of the tree
    @param IDX The index of the device at this level of the tree

    @see EACOF_DEVICE_TREE_LEVEL_2
*/
#define EACOF_DEVICE_TREE_LEVEL_3(LEVEL2, VAL, IDX) \
    (LEVEL2 | ((VAL | (IDX << 8)) << 32))

/**
    Create a Device at level 4 of the classification tree.

    @param LEVEL3 A value for the part of the device at level 3 of the tree
    @param VAL The devicetype at this level of the tree
    @param IDX The index of the device at this level of the tree

    @see EACOF_DEVICE_TREE_LEVEL_3
*/
#define EACOF_DEVICE_TREE_LEVEL_4(LEVEL3, VAL, IDX) \
    (LEVEL3 | ((VAL | (IDX << 8)) << 48))

#include <eacof/generated_devices.h>

#ifdef __cplusplus
}
#endif

#endif // EACOF_DEVICES_H
