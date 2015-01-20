EACOF
=====

EACOF, the Energy Aware COmputing Framework, is a modular framework which provides a layer of abstraction between sources of energy data and the applications that exploit them, allowing developers to profile their code for energy consumption in a simple and portable manner.

Requirements
------------

EACOF will currently run on Linux and OS X.

For the included demo methods of measuring energy to work, the requirements are:

* Linux - a laptop or other device with a battery
* OS X - a machine with a 2nd generation or newer Intel Core processor. The [Intel Power Gadget API Driver and Framework](http://software.intel.com/en-us/blogs/2012/12/13/using-the-intel-power-gadget-api-on-mac-os-x) must also be installed.

Getting Started
---------------

To start, download or clone the repository. To quickly get things running, run:

* `make all`

This will, as the name suggests, build everything needed to get started with EACOF. With everything built, there are three executables to run. They must be launched in the specified order.

* `./examples/ca/ca`
* `./examples/provider/powerGadgetExample` (OS X) OR `./examples/provider/batteryExample` (Linux)
* `./examples/consumer/consumerOSXExample` (OS X) OR `./examples/consumer/consumerLinuxExample` (Linux)

This will first set up a central node for EACOF. It will then start a method of measuring energy data. Finally, it will start a program which uses the energy data.

Why use EACOF?
--------------

Portable devices - laptops, phones, tablets - are often restricted by battery capacity. A battery can hold a limited amount of energy, and once it runs out, charging needs to occur to continue use of the device. While changes to hardware can same some energy, there is a greater potential for energy saving when the requirements of software are considered. This is because control of the computation ultimately lies with the software and algorithms running on the hardware.

EACOF can help in several ways.

* It provides access to concrete numbers about energy consumption. This allows code to be profiled, making it possible to know exactly where energy is being used.
* It separates the reading of energy data from the collection. Traditional methods of measuring energy consumption tightly tie the method of energy measurement into the application. By separating the tasks of gathering and utilisation of data, EACOF simplifies the task of using multiple sources of energy data.
* It allows applications to adapt at run-time based on current energy consumption. By making energy consumption data available in real-time, EACOF enables applications to adapt based on a combination of context and energy consumption to provide a better user experience. For example, an EACOF-aware video player may intelligently adapt based on energy consumption readings to ensure a video will complete before the battery runs out.

Further Information
-------------------

EACOF has been and is to be presented at a couple of conferences. These presentations can provide additional information about the motivation behind, design of, and use cases for EACOF.

* FOSDEM 2014 - Content regarding this presentation can be found in a [separate repository](https://github.com/eacof/fosdem-2014).
* SAC 2014 - A research paper about EACOF was presented at [SAC 2014](http://www.acm.org/conferences/sac/sac2014/).
  * Hayden Field, Glen Anderson, Kerstin Eder, [EACOF: A Framework for Providing Energy Transparency to enable Energy-Aware Software Development](http://arxiv.org/abs/1406.0117). In [Proceedings of the 29th Annual ACM Symposium on Applied Computing](http://doi.acm.org/10.1145/2554850.2554920) (SAC '14) pp. 1194-1199. March 2014.
