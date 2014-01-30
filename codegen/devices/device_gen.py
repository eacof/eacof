#!/usr/bin/env python
import os


# global variables
inputFile = os.path.join(os.path.dirname(os.path.abspath(__file__)), "used.devices")
outputFile = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "headers", "eacof", "generated_devices.h")
deviceStack = []
readableDeviceStack = []


# set things up for input
def startInput():
	return open(inputFile, "r")


# perform output
def output(str):
	f = open(outputFile, "w+")
	f.write("#ifndef EACOF_GENERATED_DEVICES_H\n#define EACOF_GENERATED_DEVICES_H\n")
	f.write("\n/**\n    @file\n\n    @brief The specification of the device classification tree.\n\n")
	f.write("    @remark THIS FILE IS AUTO-GENERATED AND SHOULD NOT BE MODIFIED MANUALLY\n\n")
	f.write("    @see devices.h\n    @see device-classification.md\n")
	f.write("*/\n\n")
	f.write(str)
	f.write("\n#endif // EACOF_GENERATED_DEVICES_H\n")
	f.close()


# read in a file
def readInput(f):
	lastDepth = 0
	valueDef = ""
	usedDef = ""
	usedDefAll = ""
	for line in f:

		if len(line) > 1:
			# find the parts of the line
			depth = line.count('\t') + 1
			number = int(line.split()[0])
			item = "".join(line.split()[1:]).upper()

			# modify the tree stack thing
			if depth <= lastDepth:
				depthDiff = lastDepth - depth + 1
				while depthDiff:
					deviceStack.pop()
					readableDeviceStack.pop()
					depthDiff = depthDiff - 1
			deviceStack.append(item)
			readableDeviceStack.append(" ".join(line.split()[1:]))
			lastDepth = depth

			# specify the value
			valueDef = valueDef + "/**\n    A value to uniquely identify an item in the classification tree at:\n        "
			for idx in range(0, len(readableDeviceStack)):
				if idx > 0:
					valueDef = valueDef + " -> "
				valueDef = valueDef + readableDeviceStack[idx]
			valueDef = valueDef + "\n*/\n"
			valueDef = valueDef + "#define EACOF_DEVICE_VALUE_" + "_".join(deviceStack) + " (" + hex(number) + ")\n"

			# create the device
			usedDef = usedDef + "/**\n    A macro to identify devices at the specified indexes within the classification tree at:\n        "
			for idx in range(0, len(readableDeviceStack)):
				if idx > 0:
					usedDef = usedDef + " -> "
				usedDef = usedDef + readableDeviceStack[idx]
			usedDef = usedDef + "\n*/\n"

			usedDef = usedDef + "#define EACOF_DEVICE_" + "_".join(deviceStack) + "("
			for idx in range(1, len(deviceStack) + 1):
				if idx > 1:
					usedDef = usedDef + ", "
				usedDef  = usedDef + "IDX" + str(idx)
			usedDef = usedDef + ") \\\n\tEACOF_DEVICE_TREE_LEVEL_" + str(depth) + "("
			if len(deviceStack) > 1:
				# output the parent devices
				usedDef = usedDef + "EACOF_DEVICE_" + "_".join(deviceStack[:-1]) + "("
				for idx in range(1, len(deviceStack)):
					if idx > 1:
						usedDef = usedDef + ", "
					usedDef = usedDef + "IDX" + str(idx)
				usedDef = usedDef + "), "
			# output this device
			usedDef = usedDef + "EACOF_DEVICE_VALUE_" + "_".join(deviceStack) + ", IDX" + str(len(deviceStack))
			usedDef = usedDef + ")\n"

			# shorthand versions for 'all'
			usedDefAll = usedDefAll + "/**\n    A shorthand macro which will specify all devices at all levels of the tree.\n\n    @see EACOF_DEVICE_COUNT_ALL\n    @see "
			usedDefAll = usedDefAll + "EACOF_DEVICE_" + "_".join(deviceStack) + "\n*/\n"
			usedDefAll = usedDefAll + "#define EACOF_DEVICE_" + "_".join(deviceStack) + "_ALL \\\n\t"
			usedDefAll  = usedDefAll + "EACOF_DEVICE_" + "_".join(deviceStack) + "("
			for idx in range(1, len(deviceStack) + 1):
				if idx > 1:
					usedDefAll = usedDefAll + ", "
				usedDefAll = usedDefAll + "EACOF_DEVICE_COUNT_ALL"
			usedDefAll  = usedDefAll + ")\n"
	# output the generated code
	output(valueDef + usedDef + usedDefAll)


# tidy up at the end
def endInput(f):
	return f.close()


def main():
	f = startInput()
	readInput(f)
	endInput(f)


if __name__ == '__main__':
	main()
