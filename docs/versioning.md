Versioning
==========

EACOF uses a dual major-minor versioning system.

Major-Minor
-----------

Minor version updates should be backwards-compatible with other versions of EACOF with the same Major version numbers.

Major version updates are not necessarily interoperable with other versions of EACOF that have different Major version numbers.

Dual Versioning
---------------

It is a dual system in that there are two separate interfaces which are versioned separately. This allows version compatibility to be more precisely specified.

The first is the internal interface within a single component. This is the standard EACOF version number. It covers aspects such as variable names, types and APIs.

The second is the network interface, allowing communication between different components. It is used internally and specifies the protocol which is used to communicate intent between components.

Accessing Version Numbers
-------------------------

Version numbers are defined in `eacof/version.h`. Major and Minor versions are each 8 bit values, allowing 255 minor versions within a single major version. The full version number is 16 bits. The Major version takes up the more significant 8 bits.

The internal version numbers can be accessed with:

* `EACOF_VERSION`
* `EACOF_VERSION_MAJOR`
* `EACOF_VERSION_MINOR`

The network version numbers can be accessed with:

* `EACOF_NET_VERSION`
* `EACOF_NET_VERSION_MAJOR`
* `EACOF_NET_VERSION_MINOR`
