Device Classification
=====================

The classification of Devices allows for a common understanding between EACOF-aware components. By specifying interest in the energy consumption of certain Devices, such as the CPU, a Consumer may understand energy usage is spread between hardware components. Similarly, a Provider may measure the energy consumption of specific Devices.

How Devices are Classified
--------------------------

EACOF uses a tree-like classification system for Devices, allowing up to 4 levels of description. For example:

* Level 1: Storage
* Level 2: Internal
* Level 3: HDD
* Level 4: Something even more specific

This allows Providers and Consumers to indicate their availability or interest at as general or specific a level as desired.

At each level, there may be multiple instances of a given Device. For example, a CPU may have multiple cores. These may be individually identified within the classification system, allowing for up to 250 items at a given level of the classification to be uniquely identified. Similarly, it is possible to request all of a given type with a special value. When indexing Devices, Providers and Consumers should have a shared understanding of the underlying ordering so as not to use different numbering systems.

How to Specify a Device
-----------------------

Devices are specified using a number of macros starting with `EACOF_DEVICE`. Each of these macros takes parameters to specify the desired indexes at each level of the tree. They are also named so that it is clear what the higher levels of the tree are. For example:

* `EACOF_DEVICE_STORAGE(EACOF_DEVICE_COUNT_ALL)` specifies all storage
* `EACOF_DEVICE_STORAGE_INTERNAL(EACOF_DEVICE_COUNT_ALL, 2)` specifies internal storage bay 2
* `EACOF_DEVICE_STORAGE_INTERNAL_HDD(EACOF_DEVICE_COUNT_ALL, 2, 3)` specifies HDD 3 in internal storage bay 2

These macros will expand and provide the bit representation as specified above. Valid indexes are from `0-249` inclusive. Specifying values outside this range will provide undefined behaviour.

If it is desired to specify all devices of a category rather than just that of a specific index, this may be done with the `EACOF_DEVICE_COUNT_ALL` macro. For example, `EACOF_DEVICE_CPU(EACOF_DEVICE_COUNT_ALL)` specifies all CPUs.

If it is desired to specify all devices at all levels of the tree, the levels of the tree need not all be specified. A helper macro with a `_ALL` suffix is provided. For example, instead of writing `EACOF_DEVICE_CPU(EACOF_DEVICE_COUNT_ALL)`, it is possible to write `EACOF_DEVICE_CPU_ALL`.

How Devices are Represented
---------------------------

The Device classification tree is represented using 64 bit values. Each level of the tree takes up 16 bits, allowing for the 4 levels of the tree. The least significant bits are the higher levels of the tree, while the more significant bits are the lower levels of the tree. Within the 16 bits at each level, the lower 8 bits indicate the type of Device, while the higher 8 bits indicate the index.

For example, take the value `0x1234567890ABCDEF` to be 64 bits representing a Device. The tree is broken down as follows:

* Level 1: Type: `EF` Index: `CD`
* Level 2: Type: `AB` Index: `90`
* Level 3: Type: `78` Index: `56`
* Level 4: Type: `34` Index: `12`

How Devices are Defined
-----------------------

Devices are defined using generated code. The list of devices is specified in `codegen/devices/used.devices`. The accompanying script generates a header file defining the specified devices.

The indentation level indicates the depth of an item in the tree. Indentation is performed using tabs.

Indented nodes are children of the preceding node of one level of indentation higher.

Numbers specify a value used to identify this device.

The name is the name of the device. The name must be alphanumeric, may contain spaces, may not be the word `Value`.

Numbers must be unique among a group. Names (not case sensitive and ignoring white space) must be unique among a group.
