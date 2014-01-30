APIs
====

There are two sorts for API used within EACOF - internal ones and public ones. While internal APIs could be used by any application which wishes to, they are not designed to be entirely stable between releases of EACOF. The public API, on the other hand, is designed to remain stable and usable without modification between multiple EACOF versions.

Public API
----------

The public EACOF APIs are used by Providers and Consumers to input and output energy data from the framework. The Provider and Consumer APIs are distinct from each other, however provide similar CRUD capabilities in the relevant ways.

### Provider API

This is used for modifying Probes and consists of five functions:

* `createProbe()` - Used to create a new Probe to monitor a specified set of Devices.
* `deleteProbe()` - Used to delete a Probe which has previously been created.
* `activateProbe()` - Used to indicate that a Probe is active.
* `deactivateProbe()` - Used to indicate that a Probe is not currently active, but may appear again (and has therefore not been deleted).
* `addSample()` - Adds a Sample for a given Probe.

In combination, these functions allow data to be passed into EACOF.

### Consumer API

This is used for setting and sampling Checkpoints and consists of three functions:

* `setCheckpoint()` - Used to set (create) a new Checkpoint to monitor a specified set of Devices.
* `sampleCheckpoint()` - Used to find out how much energy has been used by the Devices monitored by a given Checkpoint.
* `deleteCheckpoint()` - Used to delete a Checkpoint which has previously been created.

Together, these functions allow data to be read from EACOF and utilised in energy-aware applications.

### Types

Types defined by are prefixed with `eacof_`.

Internal API
------------

The internal EACOF APIs are used for the different parts of code to communicate to each other. For example, they allow the Network code to communicate with the Storage code through a means that will ideally remain constant even if the implementation changes. They are not, however, deemed to be stable and should therefore not be relied upon by external code which may wish to upgrade to future versions of EACOF.

### Function Naming

It it possible to tell whether a function is part of an internal API because its name will be prefixed by `eacof_`. Similarly, it is often possible to tell which particular internal API a function belongs to by looking at the next part of the prefix.

Each of the categories of internal API has a prefix that follows `eacof_`. These are:

* `net` - General networking
* `netSend` - Implement network functionality for public API calls
* `netHandle` - Handle side-effects for network requests
* `serialize` - Serialize data to send over the network
* `deserialize` - Deserialize data when it has been received
* `storage` - Perform CRUD actions upon data

Some internal functions to not have a category following the `eacof_` prefix. It may be desired to change this.

### Macro Naming

As with functions, there is a naming scheme for macros which makes it easier to determine what is being referred to. All macros defined by EACOF are prefixed by `EACOF_`.

There are additional prefixes which follow `EACOF_` to help identify the category a macro belongs to. These are:

* `CMD_` - An identifier for a command to be sent over the network
* `DEVICE_` - A Device in the classification system
* `DEVICE_VALUE_` - A value to help uniquely identify Devices
* `ERR_` - Error codes
* `NET_` - Networking macros
* `NETBUF_` - Relating to the current network buffer implementation
* `PSPEC_` - A Process Specifier used in the Consumer API

Other macros do not contain a particular prefix beyond `EACOF_`.
