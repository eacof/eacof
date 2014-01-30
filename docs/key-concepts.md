Key Concepts
============

EACOF is based around a number of key concepts. These allow for the functionality presented by EACOF to take place. These key concepts are:

* Devices
* Probes
* Samples
* Checkpoints

Devices
-------

Devices are individual components which may have their energy consumption measured. They are organised using a Device Classification system, and range from high level components like `Whole System` to lower level ones like `CPU 1 Core 2`.

The classification system is described in detail within the `Device Classification` documentation.

Probes
------

Probes are used by Providers to specify their capabilities, each Probe specifying one or more Devices which can have energy collected in a given group. A Provider may define multiple Probes if its capabilities allow for this.

After defining them, a Provider will provide periodic updates about the energy consumption of each of its Probes. This information, having been passed on to the Central Authority, becomes available to any Consumers interested in information from defined Devices.

Samples
-------

Samples indicate either how much energy has been consumed by a given Probe, or how much energy has been used between a pair of attempts to sample a Checkpoint. They are measured in Joules, ensuring that all values made available to Consumers are in the same unit.

Checkpoints
-----------

Checkpoints are used by Consumers to determine how much energy has been used between two points in time. Like Probes, they are created against a set of one or more Devices, with the Central Authority matching Checkpoints to the best available Probes for a specified Device set.

The timeline of a Checkpoint consists of several key points. First it is created, setting a point in time to use as a baseline for energy being measured. It is then sampled to obtain energy readings. Each Sample will provide the number of Joules used on associated Devices since the Checkpoint was last sampled. Creating a Checkpoint is deemed to be the first sample point. Once finished with, a Checkpoint can be deleted.

Like with Providers having multiple Probes, it is possible for a Consumer to have multiple active Checkpoints, each monitoring one or more Devices. Likewise, it is possible for multiple Consumers to be monitoring the same Device.
