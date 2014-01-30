Components
==========

The modular design of EACOF means it is split into a number of distinct sections, each of which performs a different task. The three key components are:

* Providers
* Consumers
* Central Authority

Each of these components can be developed and compiled independently and run as separate system processes, providing a simple method of modularly.

Providers
---------

Providers abstract the details of a data source, making it available to higher level components in a portable manner. They act as a wrapper for a source of energy data, collecting it in a platform specific manner before passing it on to the Central Authority in a portable format.

Consumers
---------

A Consumer is an application which makes use of the energy data made available by EACOF. By connecting to the Central Authority, it is able to obtain information from many Providers through the use of Checkpoints.

Central Authority
-----------------

The Central Authority marshals data between the Providers and Consumers as well as providing several additional services. It acts as a central location for knowledge in EACOF, keeping track of the information required for both Providers and Consumers to function.

By taking the role of a central node, all data must flow through it. In a large-scale deplyment of EACOF, this may act as a bottleneck, requiring an alternate implementation with Providers and Consumers communicating directly. On a regular small-scale deployment, this should not be of concern.
