Limitations
===========

There are a number of limitations with the current implementation of EACOF. Some of these should be fairly simple fixes, while others will require a larger amount of effort to resolve. Some limitations are listed below, while others can be seen in EACOF's implementation through the use of `TODO:` comments.

Classification Tree
-------------------

There will inevitably be items which should be in the Device classification tree, but are not. These can be added to increase functionality.

Database
--------

A SQLite database is used internally. While this was ideal earlier in EACOF's pre-release development, changes to the structure, design and functionality mean that this is likely not an ideal solution. For example, it bloats binary sizes when statically linking EACOF to an application.

The storage system is designed such that it should be possible to write an alternative method of storing data better suited to EACOF's needs without modifying any non-storage code.

Language
--------

EACOF is currently written in C. This should allow for reasonably easy binding to a range of other languages, however these other bindings are yet to be written.

Memory
------

There is a reasonable amount of memory being allocated, freed and copied within EACOF. Using more blocks of memory which remain in use for longer periods of time would help improve performance.

Network
-------

Communication between components is currently pretty quick through the use of the loopback interface. The implementation also allows for components on different machines to interact. The overhead could, however, be lower through the use of a different network implementation.

The network system is designed such that it should be possible to write an alternative method of communicating between components better suited to EACOF's needs without modifying any non-network code.

Number of Devices
-----------------

There is currently a limited number of devices which may be set against a single Checkpoint. Ideally there would be no physical limit.

Running Order
-------------

At present, the components must be launched (initialise EACOF) in the order: Central Authority, Provider, Consumer. Ideally the order would not matter. Shut down order will also impact functionality in a non-optimal manner if careful consideration is not made.

While the present situation is useful for testing purposes during development, it is likely not flexible enough for general deployment.

Separate Libraries
------------------

The Central Authority, Provider and Consumer libraries all compile separately. There should ideally be a single library for all EACOF components. This would allow functionality such as being both a Provider and a Consumer at the same time.
