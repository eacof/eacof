Internal Structure
==================

EACOF is designed to be modular, both from an internal and external perspective. This allows different sections of code to be swapped for functionally similar portions without impacting calling functions. The separable sections consist of:

* User-facing API
* Networking / Process Communication
* Storage / Internal representation
* Logging / Output

This separation allows for functionality to be implemented for a specific system's needs. For example, specific Inter-Process Communication (IPC) functionality may be included in EACOF on systems where it is suitable without having to modify any code related to performing other tasks.

User-facing API
---------------

The User-facing API is how EACOF is interacted with. It is split into two sections of its own, one for Consumers, the other for Providers.

This portion of code defines how the API should function, wrapping a number of internal functions to perform key tasks. So long as internal APIs do not change, there should be little need to modify the code within this section.

Networking / Process Communication
----------------------------------

The Networking code allows for communication between EACOF-aware components. Since components may be compiled and run separately, this allows for them to interact with one another.

The default networking implementation is split into three sections.

### Performing Communication

The central section of code, in `network.c`, performs the actual communication between components. It performs tasks including sending, receiving, and buffering data, as well as the setup to allow these tasks to be performed.

The default implementation uses sockets to allow for communication between components. The Central Authority listens for connections, acting as a server, while Consumers and Providers make the requests for data, initialising any communication. This adds slight latency when performing any request, however is tolerable for may use cases.

Alternative implementations may combine the Central Authority into the other components, creating a single executable. Alternatively, different IPC mechanisms may be used.

### Network API

This contains functionality to perform network requests for each of the tasks specified by the User-facing API. It performs a minimal amount of work of its own, passing the Send/Receive tasks onto the core code, and interpretation of events to the Handler.

### Network Handler

This performs the handling of network requests, undertaking any side-effects that may be necessary. These side-effects may include storing or updating data, or performing follow-on network requests.

Storage / Internal representation
---------------------------------

The Storage system keeps track of the current state of EACOF components. This means managing Checkpoints, Probes, Samples, and other important information.

The default implementation keeps track of this information within an database held by the Central Authority. This is updated or queried whenever network requests come in and require access to data.

The database is an in-memory SQLite database and provides reasonable performance. It is, however, a carry-over from earlier pre-release versions of EACOF when the User-facing API was different and the schema was better suited to this sort of database.

A preferable implementation would likely involve some sort of custom data structure suited to the sorts of CRUD operations undertaken by EACOF. It would also allow for data to be made more quickly accessible to Consumers, reducing the impact of network latency when utilising EACOF.

Logging / Output
----------------

The logging system is designed to be swapped out or disabled as required.

The default implementation outputs values to the console, which can be useful when debugging. Alternative implementations may write data to files, while an improved implementation would add support for features such as priorities, allowing smaller sections of logging to be enabled or disabled as desired.
