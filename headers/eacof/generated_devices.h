#ifndef EACOF_GENERATED_DEVICES_H
#define EACOF_GENERATED_DEVICES_H

/**
    @file

    @brief The specification of the device classification tree.

    @remark THIS FILE IS AUTO-GENERATED AND SHOULD NOT BE MODIFIED MANUALLY

    @see devices.h
    @see device-classification.md
*/

/**
    A value to uniquely identify an item in the classification tree at:
        System
*/
#define EACOF_DEVICE_VALUE_SYSTEM (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        System -> Battery
*/
#define EACOF_DEVICE_VALUE_SYSTEM_BATTERY (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        System -> Mains
*/
#define EACOF_DEVICE_VALUE_SYSTEM_MAINS (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU
*/
#define EACOF_DEVICE_VALUE_CPU (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Core
*/
#define EACOF_DEVICE_VALUE_CPU_CORE (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Core -> Subcore
*/
#define EACOF_DEVICE_VALUE_CPU_CORE_SUBCORE (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> ALU
*/
#define EACOF_DEVICE_VALUE_CPU_ALU (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Pipeline
*/
#define EACOF_DEVICE_VALUE_CPU_PIPELINE (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Control Unit
*/
#define EACOF_DEVICE_VALUE_CPU_CONTROLUNIT (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Memory
*/
#define EACOF_DEVICE_VALUE_CPU_MEMORY (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Memory -> Register
*/
#define EACOF_DEVICE_VALUE_CPU_MEMORY_REGISTER (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Memory -> Cache
*/
#define EACOF_DEVICE_VALUE_CPU_MEMORY_CACHE (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Clock
*/
#define EACOF_DEVICE_VALUE_CPU_CLOCK (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        CPU -> Scheduler
*/
#define EACOF_DEVICE_VALUE_CPU_SCHEDULER (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage
*/
#define EACOF_DEVICE_VALUE_STORAGE (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal -> HDD
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL_HDD (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal -> SSD
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL_SSD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal -> Floppy Disk
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL_FLOPPYDISK (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal -> SSHD
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL_SSHD (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Internal -> Tape
*/
#define EACOF_DEVICE_VALUE_STORAGE_INTERNAL_TAPE (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> HDD
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_HDD (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> SSD
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_SSD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> Floppy Disk
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_FLOPPYDISK (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> SSHD
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_SSHD (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> Flash Drive
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_FLASHDRIVE (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> Memory Card
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_MEMORYCARD (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> External -> Tape
*/
#define EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_TAPE (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Storage -> Network
*/
#define EACOF_DEVICE_VALUE_STORAGE_NETWORK (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Display
*/
#define EACOF_DEVICE_VALUE_DISPLAY (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Display -> Monitor
*/
#define EACOF_DEVICE_VALUE_DISPLAY_MONITOR (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Display -> HMD
*/
#define EACOF_DEVICE_VALUE_DISPLAY_HMD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Display -> Projector
*/
#define EACOF_DEVICE_VALUE_DISPLAY_PROJECTOR (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Audio
*/
#define EACOF_DEVICE_VALUE_AUDIO (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Audio -> Speaker
*/
#define EACOF_DEVICE_VALUE_AUDIO_SPEAKER (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Audio -> Microphone
*/
#define EACOF_DEVICE_VALUE_AUDIO_MICROPHONE (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Audio -> Headphone
*/
#define EACOF_DEVICE_VALUE_AUDIO_HEADPHONE (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Audio -> Sound Card
*/
#define EACOF_DEVICE_VALUE_AUDIO_SOUNDCARD (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Optical Drive
*/
#define EACOF_DEVICE_VALUE_OPTICALDRIVE (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Optical Drive -> CD
*/
#define EACOF_DEVICE_VALUE_OPTICALDRIVE_CD (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Optical Drive -> DVD
*/
#define EACOF_DEVICE_VALUE_OPTICALDRIVE_DVD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Optical Drive -> Bluray
*/
#define EACOF_DEVICE_VALUE_OPTICALDRIVE_BLURAY (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Optical Drive -> ARMD
*/
#define EACOF_DEVICE_VALUE_OPTICALDRIVE_ARMD (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Memory
*/
#define EACOF_DEVICE_VALUE_MEMORY (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Memory -> RAM
*/
#define EACOF_DEVICE_VALUE_MEMORY_RAM (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Input
*/
#define EACOF_DEVICE_VALUE_INPUT (0x8)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing -> Mouse
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING_MOUSE (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing -> Trackpad
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING_TRACKPAD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing -> Graphics Tablet
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING_GRAPHICSTABLET (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing -> Joystick
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING_JOYSTICK (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Pointing -> Pointing Stick
*/
#define EACOF_DEVICE_VALUE_INPUT_POINTING_POINTINGSTICK (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Keyboard
*/
#define EACOF_DEVICE_VALUE_INPUT_KEYBOARD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Scanner
*/
#define EACOF_DEVICE_VALUE_INPUT_SCANNER (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Camera
*/
#define EACOF_DEVICE_VALUE_INPUT_CAMERA (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Input -> Camera -> Webcam
*/
#define EACOF_DEVICE_VALUE_INPUT_CAMERA_WEBCAM (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Output
*/
#define EACOF_DEVICE_VALUE_OUTPUT (0x9)
/**
    A value to uniquely identify an item in the classification tree at:
        Output -> Printer
*/
#define EACOF_DEVICE_VALUE_OUTPUT_PRINTER (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Graphics
*/
#define EACOF_DEVICE_VALUE_GRAPHICS (0xa)
/**
    A value to uniquely identify an item in the classification tree at:
        Graphics -> GPU
*/
#define EACOF_DEVICE_VALUE_GRAPHICS_GPU (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Graphics -> Memory
*/
#define EACOF_DEVICE_VALUE_GRAPHICS_MEMORY (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Graphics -> RAMDAC
*/
#define EACOF_DEVICE_VALUE_GRAPHICS_RAMDAC (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        FPGA
*/
#define EACOF_DEVICE_VALUE_FPGA (0xb)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD (0xc)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> TV Tuner
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_TVTUNER (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Sound Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_SOUNDCARD (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Network Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_NETWORKCARD (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> SCSI
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SCSI (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> ATA
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_ATA (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> SAS
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SAS (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> SATA
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SATA (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> eSATA
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_ESATA (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> RAID
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_RAID (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> IDE
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_IDE (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> EIDE
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_EIDE (0x8)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> FATA
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_FATA (0x9)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Host Adapter -> PATA
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_PATA (0xa)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> POST Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_POSTCARD (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Compatibility Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_COMPATIBILITYCARD (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Physics Card
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_PHYSICSCARD (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Disk Controller
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DISKCONTROLLER (0x8)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT (0x9)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Ethernet
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_ETHERNET (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Parallel
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_PARALLEL (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial -> SPI
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SPI (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial -> I2C
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_I2C (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial -> SMBus
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial -> GPIB
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Serial -> SCPI
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> USB
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_USB (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Firewire
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_FIREWIRE (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Thunderbolt
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_THUNDERBOLT (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Card Reader
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_CARDREADER (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> Fibre Channel
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL (0x8)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Data Port -> InfiniBand
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_INFINIBAND (0x9)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Radio Tuner
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_RADIOTUNER (0xa)
/**
    A value to uniquely identify an item in the classification tree at:
        Expansion Card -> Bluetooth
*/
#define EACOF_DEVICE_VALUE_EXPANSIONCARD_BLUETOOTH (0xb)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD (0xd)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Socket
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_SOCKET (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Chipset
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_CHIPSET (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Nonvolatile Memory
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Nonvolatile Memory -> Flash
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Nonvolatile Memory -> EEPROM
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Nonvolatile Memory -> EPROM
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Clock Generator
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_CLOCKGENERATOR (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PCI
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCI (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PCIe
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCIE (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> AGP
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_AGP (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> ISA
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_ISA (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> MCA
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_MCA (0x5)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> VLB
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_VLB (0x6)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PC Card
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD (0x7)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> PC Card
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD (0x1)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> CardBus
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS (0x2)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> CardBay
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY (0x3)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> ExpressCard
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD (0x4)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> Compact Flash
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH (0x8)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> SBus
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_SBUS (0x9)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> Zorro
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_ZORRO (0xa)
/**
    A value to uniquely identify an item in the classification tree at:
        Motherboard -> Expansion Slot -> NuBus
*/
#define EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_NUBUS (0xb)
/**
    A value to uniquely identify an item in the classification tree at:
        Power
*/
#define EACOF_DEVICE_VALUE_POWER (0xe)
/**
    A value to uniquely identify an item in the classification tree at:
        Power -> PSU
*/
#define EACOF_DEVICE_VALUE_POWER_PSU (0x1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        System
*/
#define EACOF_DEVICE_SYSTEM(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_SYSTEM, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        System -> Battery
*/
#define EACOF_DEVICE_SYSTEM_BATTERY(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_SYSTEM(IDX1), EACOF_DEVICE_VALUE_SYSTEM_BATTERY, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        System -> Mains
*/
#define EACOF_DEVICE_SYSTEM_MAINS(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_SYSTEM(IDX1), EACOF_DEVICE_VALUE_SYSTEM_MAINS, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU
*/
#define EACOF_DEVICE_CPU(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_CPU, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Core
*/
#define EACOF_DEVICE_CPU_CORE(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_CORE, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Core -> Subcore
*/
#define EACOF_DEVICE_CPU_CORE_SUBCORE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_CPU_CORE(IDX1, IDX2), EACOF_DEVICE_VALUE_CPU_CORE_SUBCORE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> ALU
*/
#define EACOF_DEVICE_CPU_ALU(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_ALU, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Pipeline
*/
#define EACOF_DEVICE_CPU_PIPELINE(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_PIPELINE, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Control Unit
*/
#define EACOF_DEVICE_CPU_CONTROLUNIT(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_CONTROLUNIT, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Memory
*/
#define EACOF_DEVICE_CPU_MEMORY(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_MEMORY, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Memory -> Register
*/
#define EACOF_DEVICE_CPU_MEMORY_REGISTER(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_CPU_MEMORY(IDX1, IDX2), EACOF_DEVICE_VALUE_CPU_MEMORY_REGISTER, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Memory -> Cache
*/
#define EACOF_DEVICE_CPU_MEMORY_CACHE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_CPU_MEMORY(IDX1, IDX2), EACOF_DEVICE_VALUE_CPU_MEMORY_CACHE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Clock
*/
#define EACOF_DEVICE_CPU_CLOCK(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_CLOCK, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        CPU -> Scheduler
*/
#define EACOF_DEVICE_CPU_SCHEDULER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_CPU(IDX1), EACOF_DEVICE_VALUE_CPU_SCHEDULER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage
*/
#define EACOF_DEVICE_STORAGE(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_STORAGE, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal
*/
#define EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_STORAGE(IDX1), EACOF_DEVICE_VALUE_STORAGE_INTERNAL, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal -> HDD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_HDD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_INTERNAL_HDD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal -> SSD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_SSD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_INTERNAL_SSD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal -> Floppy Disk
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_FLOPPYDISK(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_INTERNAL_FLOPPYDISK, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal -> SSHD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_SSHD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_INTERNAL_SSHD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Internal -> Tape
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_TAPE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_INTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_INTERNAL_TAPE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_STORAGE(IDX1), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> HDD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_HDD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_HDD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> SSD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_SSD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_SSD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> Floppy Disk
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_FLOPPYDISK(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_FLOPPYDISK, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> SSHD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_SSHD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_SSHD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> Flash Drive
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_FLASHDRIVE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_FLASHDRIVE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> Memory Card
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_MEMORYCARD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_MEMORYCARD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> External -> Tape
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_TAPE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_STORAGE_EXTERNAL(IDX1, IDX2), EACOF_DEVICE_VALUE_STORAGE_EXTERNAL_TAPE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Storage -> Network
*/
#define EACOF_DEVICE_STORAGE_NETWORK(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_STORAGE(IDX1), EACOF_DEVICE_VALUE_STORAGE_NETWORK, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Display
*/
#define EACOF_DEVICE_DISPLAY(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_DISPLAY, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Display -> Monitor
*/
#define EACOF_DEVICE_DISPLAY_MONITOR(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_DISPLAY(IDX1), EACOF_DEVICE_VALUE_DISPLAY_MONITOR, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Display -> HMD
*/
#define EACOF_DEVICE_DISPLAY_HMD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_DISPLAY(IDX1), EACOF_DEVICE_VALUE_DISPLAY_HMD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Display -> Projector
*/
#define EACOF_DEVICE_DISPLAY_PROJECTOR(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_DISPLAY(IDX1), EACOF_DEVICE_VALUE_DISPLAY_PROJECTOR, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Audio
*/
#define EACOF_DEVICE_AUDIO(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_AUDIO, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Audio -> Speaker
*/
#define EACOF_DEVICE_AUDIO_SPEAKER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_AUDIO(IDX1), EACOF_DEVICE_VALUE_AUDIO_SPEAKER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Audio -> Microphone
*/
#define EACOF_DEVICE_AUDIO_MICROPHONE(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_AUDIO(IDX1), EACOF_DEVICE_VALUE_AUDIO_MICROPHONE, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Audio -> Headphone
*/
#define EACOF_DEVICE_AUDIO_HEADPHONE(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_AUDIO(IDX1), EACOF_DEVICE_VALUE_AUDIO_HEADPHONE, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Audio -> Sound Card
*/
#define EACOF_DEVICE_AUDIO_SOUNDCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_AUDIO(IDX1), EACOF_DEVICE_VALUE_AUDIO_SOUNDCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Optical Drive
*/
#define EACOF_DEVICE_OPTICALDRIVE(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_OPTICALDRIVE, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Optical Drive -> CD
*/
#define EACOF_DEVICE_OPTICALDRIVE_CD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_OPTICALDRIVE(IDX1), EACOF_DEVICE_VALUE_OPTICALDRIVE_CD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Optical Drive -> DVD
*/
#define EACOF_DEVICE_OPTICALDRIVE_DVD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_OPTICALDRIVE(IDX1), EACOF_DEVICE_VALUE_OPTICALDRIVE_DVD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Optical Drive -> Bluray
*/
#define EACOF_DEVICE_OPTICALDRIVE_BLURAY(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_OPTICALDRIVE(IDX1), EACOF_DEVICE_VALUE_OPTICALDRIVE_BLURAY, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Optical Drive -> ARMD
*/
#define EACOF_DEVICE_OPTICALDRIVE_ARMD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_OPTICALDRIVE(IDX1), EACOF_DEVICE_VALUE_OPTICALDRIVE_ARMD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Memory
*/
#define EACOF_DEVICE_MEMORY(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_MEMORY, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Memory -> RAM
*/
#define EACOF_DEVICE_MEMORY_RAM(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MEMORY(IDX1), EACOF_DEVICE_VALUE_MEMORY_RAM, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input
*/
#define EACOF_DEVICE_INPUT(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_INPUT, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing
*/
#define EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_INPUT(IDX1), EACOF_DEVICE_VALUE_INPUT_POINTING, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing -> Mouse
*/
#define EACOF_DEVICE_INPUT_POINTING_MOUSE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_POINTING_MOUSE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing -> Trackpad
*/
#define EACOF_DEVICE_INPUT_POINTING_TRACKPAD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_POINTING_TRACKPAD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing -> Graphics Tablet
*/
#define EACOF_DEVICE_INPUT_POINTING_GRAPHICSTABLET(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_POINTING_GRAPHICSTABLET, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing -> Joystick
*/
#define EACOF_DEVICE_INPUT_POINTING_JOYSTICK(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_POINTING_JOYSTICK, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Pointing -> Pointing Stick
*/
#define EACOF_DEVICE_INPUT_POINTING_POINTINGSTICK(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_POINTING(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_POINTING_POINTINGSTICK, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Keyboard
*/
#define EACOF_DEVICE_INPUT_KEYBOARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_INPUT(IDX1), EACOF_DEVICE_VALUE_INPUT_KEYBOARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Scanner
*/
#define EACOF_DEVICE_INPUT_SCANNER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_INPUT(IDX1), EACOF_DEVICE_VALUE_INPUT_SCANNER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Camera
*/
#define EACOF_DEVICE_INPUT_CAMERA(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_INPUT(IDX1), EACOF_DEVICE_VALUE_INPUT_CAMERA, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Input -> Camera -> Webcam
*/
#define EACOF_DEVICE_INPUT_CAMERA_WEBCAM(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_INPUT_CAMERA(IDX1, IDX2), EACOF_DEVICE_VALUE_INPUT_CAMERA_WEBCAM, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Output
*/
#define EACOF_DEVICE_OUTPUT(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_OUTPUT, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Output -> Printer
*/
#define EACOF_DEVICE_OUTPUT_PRINTER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_OUTPUT(IDX1), EACOF_DEVICE_VALUE_OUTPUT_PRINTER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Graphics
*/
#define EACOF_DEVICE_GRAPHICS(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_GRAPHICS, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Graphics -> GPU
*/
#define EACOF_DEVICE_GRAPHICS_GPU(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_GRAPHICS(IDX1), EACOF_DEVICE_VALUE_GRAPHICS_GPU, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Graphics -> Memory
*/
#define EACOF_DEVICE_GRAPHICS_MEMORY(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_GRAPHICS(IDX1), EACOF_DEVICE_VALUE_GRAPHICS_MEMORY, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Graphics -> RAMDAC
*/
#define EACOF_DEVICE_GRAPHICS_RAMDAC(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_GRAPHICS(IDX1), EACOF_DEVICE_VALUE_GRAPHICS_RAMDAC, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        FPGA
*/
#define EACOF_DEVICE_FPGA(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_FPGA, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card
*/
#define EACOF_DEVICE_EXPANSIONCARD(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_EXPANSIONCARD, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> TV Tuner
*/
#define EACOF_DEVICE_EXPANSIONCARD_TVTUNER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_TVTUNER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Sound Card
*/
#define EACOF_DEVICE_EXPANSIONCARD_SOUNDCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_SOUNDCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Network Card
*/
#define EACOF_DEVICE_EXPANSIONCARD_NETWORKCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_NETWORKCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> SCSI
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SCSI(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SCSI, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> ATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ATA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_ATA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> SAS
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SAS(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SAS, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> SATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SATA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_SATA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> eSATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ESATA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_ESATA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> RAID
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_RAID(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_RAID, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> IDE
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_IDE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_IDE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> EIDE
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_EIDE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_EIDE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> FATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_FATA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_FATA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Host Adapter -> PATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_PATA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_HOSTADAPTER_PATA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> POST Card
*/
#define EACOF_DEVICE_EXPANSIONCARD_POSTCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_POSTCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Compatibility Card
*/
#define EACOF_DEVICE_EXPANSIONCARD_COMPATIBILITYCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_COMPATIBILITYCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Physics Card
*/
#define EACOF_DEVICE_EXPANSIONCARD_PHYSICSCARD(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_PHYSICSCARD, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Disk Controller
*/
#define EACOF_DEVICE_EXPANSIONCARD_DISKCONTROLLER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_DISKCONTROLLER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Ethernet
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_ETHERNET(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_ETHERNET, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Parallel
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_PARALLEL(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_PARALLEL, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial -> SPI
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SPI(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SPI, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial -> I2C
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_I2C(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_I2C, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial -> SMBus
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial -> GPIB
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Serial -> SCPI
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> USB
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_USB(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_USB, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Firewire
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIREWIRE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_FIREWIRE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Thunderbolt
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_THUNDERBOLT(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_THUNDERBOLT, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Card Reader
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_CARDREADER(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_CARDREADER, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> Fibre Channel
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Data Port -> InfiniBand
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_INFINIBAND(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_EXPANSIONCARD_DATAPORT(IDX1, IDX2), EACOF_DEVICE_VALUE_EXPANSIONCARD_DATAPORT_INFINIBAND, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Radio Tuner
*/
#define EACOF_DEVICE_EXPANSIONCARD_RADIOTUNER(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_RADIOTUNER, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Expansion Card -> Bluetooth
*/
#define EACOF_DEVICE_EXPANSIONCARD_BLUETOOTH(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_EXPANSIONCARD(IDX1), EACOF_DEVICE_VALUE_EXPANSIONCARD_BLUETOOTH, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard
*/
#define EACOF_DEVICE_MOTHERBOARD(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_MOTHERBOARD, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Socket
*/
#define EACOF_DEVICE_MOTHERBOARD_SOCKET(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MOTHERBOARD(IDX1), EACOF_DEVICE_VALUE_MOTHERBOARD_SOCKET, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Chipset
*/
#define EACOF_DEVICE_MOTHERBOARD_CHIPSET(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MOTHERBOARD(IDX1), EACOF_DEVICE_VALUE_MOTHERBOARD_CHIPSET, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Nonvolatile Memory
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MOTHERBOARD(IDX1), EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Nonvolatile Memory -> Flash
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Nonvolatile Memory -> EEPROM
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Nonvolatile Memory -> EPROM
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Clock Generator
*/
#define EACOF_DEVICE_MOTHERBOARD_CLOCKGENERATOR(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MOTHERBOARD(IDX1), EACOF_DEVICE_VALUE_MOTHERBOARD_CLOCKGENERATOR, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_MOTHERBOARD(IDX1), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT, IDX2)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PCI
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCI(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCI, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PCIe
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCIE(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCIE, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> AGP
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_AGP(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_AGP, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> ISA
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ISA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_ISA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> MCA
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_MCA(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_MCA, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> VLB
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_VLB(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_VLB, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PC Card
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> PC Card
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> CardBus
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> CardBay
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> PC Card -> ExpressCard
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD(IDX1, IDX2, IDX3, IDX4) \
	EACOF_DEVICE_TREE_LEVEL_4(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(IDX1, IDX2, IDX3), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD, IDX4)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> Compact Flash
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> SBus
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_SBUS(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_SBUS, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> Zorro
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ZORRO(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_ZORRO, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Motherboard -> Expansion Slot -> NuBus
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_NUBUS(IDX1, IDX2, IDX3) \
	EACOF_DEVICE_TREE_LEVEL_3(EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(IDX1, IDX2), EACOF_DEVICE_VALUE_MOTHERBOARD_EXPANSIONSLOT_NUBUS, IDX3)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Power
*/
#define EACOF_DEVICE_POWER(IDX1) \
	EACOF_DEVICE_TREE_LEVEL_1(EACOF_DEVICE_VALUE_POWER, IDX1)
/**
    A macro to identify devices at the specified indexes within the classification tree at:
        Power -> PSU
*/
#define EACOF_DEVICE_POWER_PSU(IDX1, IDX2) \
	EACOF_DEVICE_TREE_LEVEL_2(EACOF_DEVICE_POWER(IDX1), EACOF_DEVICE_VALUE_POWER_PSU, IDX2)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_SYSTEM
*/
#define EACOF_DEVICE_SYSTEM_ALL \
	EACOF_DEVICE_SYSTEM(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_SYSTEM_BATTERY
*/
#define EACOF_DEVICE_SYSTEM_BATTERY_ALL \
	EACOF_DEVICE_SYSTEM_BATTERY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_SYSTEM_MAINS
*/
#define EACOF_DEVICE_SYSTEM_MAINS_ALL \
	EACOF_DEVICE_SYSTEM_MAINS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU
*/
#define EACOF_DEVICE_CPU_ALL \
	EACOF_DEVICE_CPU(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_CORE
*/
#define EACOF_DEVICE_CPU_CORE_ALL \
	EACOF_DEVICE_CPU_CORE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_CORE_SUBCORE
*/
#define EACOF_DEVICE_CPU_CORE_SUBCORE_ALL \
	EACOF_DEVICE_CPU_CORE_SUBCORE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_ALU
*/
#define EACOF_DEVICE_CPU_ALU_ALL \
	EACOF_DEVICE_CPU_ALU(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_PIPELINE
*/
#define EACOF_DEVICE_CPU_PIPELINE_ALL \
	EACOF_DEVICE_CPU_PIPELINE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_CONTROLUNIT
*/
#define EACOF_DEVICE_CPU_CONTROLUNIT_ALL \
	EACOF_DEVICE_CPU_CONTROLUNIT(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_MEMORY
*/
#define EACOF_DEVICE_CPU_MEMORY_ALL \
	EACOF_DEVICE_CPU_MEMORY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_MEMORY_REGISTER
*/
#define EACOF_DEVICE_CPU_MEMORY_REGISTER_ALL \
	EACOF_DEVICE_CPU_MEMORY_REGISTER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_MEMORY_CACHE
*/
#define EACOF_DEVICE_CPU_MEMORY_CACHE_ALL \
	EACOF_DEVICE_CPU_MEMORY_CACHE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_CLOCK
*/
#define EACOF_DEVICE_CPU_CLOCK_ALL \
	EACOF_DEVICE_CPU_CLOCK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_CPU_SCHEDULER
*/
#define EACOF_DEVICE_CPU_SCHEDULER_ALL \
	EACOF_DEVICE_CPU_SCHEDULER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE
*/
#define EACOF_DEVICE_STORAGE_ALL \
	EACOF_DEVICE_STORAGE(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL_HDD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_HDD_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL_HDD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL_SSD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_SSD_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL_SSD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL_FLOPPYDISK
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_FLOPPYDISK_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL_FLOPPYDISK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL_SSHD
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_SSHD_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL_SSHD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_INTERNAL_TAPE
*/
#define EACOF_DEVICE_STORAGE_INTERNAL_TAPE_ALL \
	EACOF_DEVICE_STORAGE_INTERNAL_TAPE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_HDD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_HDD_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_HDD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_SSD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_SSD_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_SSD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_FLOPPYDISK
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_FLOPPYDISK_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_FLOPPYDISK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_SSHD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_SSHD_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_SSHD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_FLASHDRIVE
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_FLASHDRIVE_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_FLASHDRIVE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_MEMORYCARD
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_MEMORYCARD_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_MEMORYCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_EXTERNAL_TAPE
*/
#define EACOF_DEVICE_STORAGE_EXTERNAL_TAPE_ALL \
	EACOF_DEVICE_STORAGE_EXTERNAL_TAPE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_STORAGE_NETWORK
*/
#define EACOF_DEVICE_STORAGE_NETWORK_ALL \
	EACOF_DEVICE_STORAGE_NETWORK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_DISPLAY
*/
#define EACOF_DEVICE_DISPLAY_ALL \
	EACOF_DEVICE_DISPLAY(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_DISPLAY_MONITOR
*/
#define EACOF_DEVICE_DISPLAY_MONITOR_ALL \
	EACOF_DEVICE_DISPLAY_MONITOR(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_DISPLAY_HMD
*/
#define EACOF_DEVICE_DISPLAY_HMD_ALL \
	EACOF_DEVICE_DISPLAY_HMD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_DISPLAY_PROJECTOR
*/
#define EACOF_DEVICE_DISPLAY_PROJECTOR_ALL \
	EACOF_DEVICE_DISPLAY_PROJECTOR(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_AUDIO
*/
#define EACOF_DEVICE_AUDIO_ALL \
	EACOF_DEVICE_AUDIO(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_AUDIO_SPEAKER
*/
#define EACOF_DEVICE_AUDIO_SPEAKER_ALL \
	EACOF_DEVICE_AUDIO_SPEAKER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_AUDIO_MICROPHONE
*/
#define EACOF_DEVICE_AUDIO_MICROPHONE_ALL \
	EACOF_DEVICE_AUDIO_MICROPHONE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_AUDIO_HEADPHONE
*/
#define EACOF_DEVICE_AUDIO_HEADPHONE_ALL \
	EACOF_DEVICE_AUDIO_HEADPHONE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_AUDIO_SOUNDCARD
*/
#define EACOF_DEVICE_AUDIO_SOUNDCARD_ALL \
	EACOF_DEVICE_AUDIO_SOUNDCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OPTICALDRIVE
*/
#define EACOF_DEVICE_OPTICALDRIVE_ALL \
	EACOF_DEVICE_OPTICALDRIVE(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OPTICALDRIVE_CD
*/
#define EACOF_DEVICE_OPTICALDRIVE_CD_ALL \
	EACOF_DEVICE_OPTICALDRIVE_CD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OPTICALDRIVE_DVD
*/
#define EACOF_DEVICE_OPTICALDRIVE_DVD_ALL \
	EACOF_DEVICE_OPTICALDRIVE_DVD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OPTICALDRIVE_BLURAY
*/
#define EACOF_DEVICE_OPTICALDRIVE_BLURAY_ALL \
	EACOF_DEVICE_OPTICALDRIVE_BLURAY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OPTICALDRIVE_ARMD
*/
#define EACOF_DEVICE_OPTICALDRIVE_ARMD_ALL \
	EACOF_DEVICE_OPTICALDRIVE_ARMD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MEMORY
*/
#define EACOF_DEVICE_MEMORY_ALL \
	EACOF_DEVICE_MEMORY(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MEMORY_RAM
*/
#define EACOF_DEVICE_MEMORY_RAM_ALL \
	EACOF_DEVICE_MEMORY_RAM(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT
*/
#define EACOF_DEVICE_INPUT_ALL \
	EACOF_DEVICE_INPUT(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING
*/
#define EACOF_DEVICE_INPUT_POINTING_ALL \
	EACOF_DEVICE_INPUT_POINTING(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING_MOUSE
*/
#define EACOF_DEVICE_INPUT_POINTING_MOUSE_ALL \
	EACOF_DEVICE_INPUT_POINTING_MOUSE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING_TRACKPAD
*/
#define EACOF_DEVICE_INPUT_POINTING_TRACKPAD_ALL \
	EACOF_DEVICE_INPUT_POINTING_TRACKPAD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING_GRAPHICSTABLET
*/
#define EACOF_DEVICE_INPUT_POINTING_GRAPHICSTABLET_ALL \
	EACOF_DEVICE_INPUT_POINTING_GRAPHICSTABLET(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING_JOYSTICK
*/
#define EACOF_DEVICE_INPUT_POINTING_JOYSTICK_ALL \
	EACOF_DEVICE_INPUT_POINTING_JOYSTICK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_POINTING_POINTINGSTICK
*/
#define EACOF_DEVICE_INPUT_POINTING_POINTINGSTICK_ALL \
	EACOF_DEVICE_INPUT_POINTING_POINTINGSTICK(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_KEYBOARD
*/
#define EACOF_DEVICE_INPUT_KEYBOARD_ALL \
	EACOF_DEVICE_INPUT_KEYBOARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_SCANNER
*/
#define EACOF_DEVICE_INPUT_SCANNER_ALL \
	EACOF_DEVICE_INPUT_SCANNER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_CAMERA
*/
#define EACOF_DEVICE_INPUT_CAMERA_ALL \
	EACOF_DEVICE_INPUT_CAMERA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_INPUT_CAMERA_WEBCAM
*/
#define EACOF_DEVICE_INPUT_CAMERA_WEBCAM_ALL \
	EACOF_DEVICE_INPUT_CAMERA_WEBCAM(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OUTPUT
*/
#define EACOF_DEVICE_OUTPUT_ALL \
	EACOF_DEVICE_OUTPUT(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_OUTPUT_PRINTER
*/
#define EACOF_DEVICE_OUTPUT_PRINTER_ALL \
	EACOF_DEVICE_OUTPUT_PRINTER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_GRAPHICS
*/
#define EACOF_DEVICE_GRAPHICS_ALL \
	EACOF_DEVICE_GRAPHICS(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_GRAPHICS_GPU
*/
#define EACOF_DEVICE_GRAPHICS_GPU_ALL \
	EACOF_DEVICE_GRAPHICS_GPU(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_GRAPHICS_MEMORY
*/
#define EACOF_DEVICE_GRAPHICS_MEMORY_ALL \
	EACOF_DEVICE_GRAPHICS_MEMORY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_GRAPHICS_RAMDAC
*/
#define EACOF_DEVICE_GRAPHICS_RAMDAC_ALL \
	EACOF_DEVICE_GRAPHICS_RAMDAC(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_FPGA
*/
#define EACOF_DEVICE_FPGA_ALL \
	EACOF_DEVICE_FPGA(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_TVTUNER
*/
#define EACOF_DEVICE_EXPANSIONCARD_TVTUNER_ALL \
	EACOF_DEVICE_EXPANSIONCARD_TVTUNER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_SOUNDCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_SOUNDCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD_SOUNDCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_NETWORKCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_NETWORKCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD_NETWORKCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SCSI
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SCSI_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SCSI(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ATA_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ATA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SAS
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SAS_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SAS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SATA_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_SATA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ESATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ESATA_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_ESATA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_RAID
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_RAID_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_RAID(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_IDE
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_IDE_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_IDE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_EIDE
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_EIDE_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_EIDE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_FATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_FATA_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_FATA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_PATA
*/
#define EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_PATA_ALL \
	EACOF_DEVICE_EXPANSIONCARD_HOSTADAPTER_PATA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_POSTCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_POSTCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD_POSTCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_COMPATIBILITYCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_COMPATIBILITYCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD_COMPATIBILITYCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_PHYSICSCARD
*/
#define EACOF_DEVICE_EXPANSIONCARD_PHYSICSCARD_ALL \
	EACOF_DEVICE_EXPANSIONCARD_PHYSICSCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DISKCONTROLLER
*/
#define EACOF_DEVICE_EXPANSIONCARD_DISKCONTROLLER_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DISKCONTROLLER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_ETHERNET
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_ETHERNET_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_ETHERNET(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_PARALLEL
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_PARALLEL_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_PARALLEL(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SPI
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SPI_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SPI(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_I2C
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_I2C_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_I2C(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SMBUS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_GPIB(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_SERIAL_SCPI(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_USB
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_USB_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_USB(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIREWIRE
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIREWIRE_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIREWIRE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_THUNDERBOLT
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_THUNDERBOLT_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_THUNDERBOLT(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_CARDREADER
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_CARDREADER_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_CARDREADER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_FIBRECHANNEL(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_DATAPORT_INFINIBAND
*/
#define EACOF_DEVICE_EXPANSIONCARD_DATAPORT_INFINIBAND_ALL \
	EACOF_DEVICE_EXPANSIONCARD_DATAPORT_INFINIBAND(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_RADIOTUNER
*/
#define EACOF_DEVICE_EXPANSIONCARD_RADIOTUNER_ALL \
	EACOF_DEVICE_EXPANSIONCARD_RADIOTUNER(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_EXPANSIONCARD_BLUETOOTH
*/
#define EACOF_DEVICE_EXPANSIONCARD_BLUETOOTH_ALL \
	EACOF_DEVICE_EXPANSIONCARD_BLUETOOTH(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD
*/
#define EACOF_DEVICE_MOTHERBOARD_ALL \
	EACOF_DEVICE_MOTHERBOARD(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_SOCKET
*/
#define EACOF_DEVICE_MOTHERBOARD_SOCKET_ALL \
	EACOF_DEVICE_MOTHERBOARD_SOCKET(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_CHIPSET
*/
#define EACOF_DEVICE_MOTHERBOARD_CHIPSET_ALL \
	EACOF_DEVICE_MOTHERBOARD_CHIPSET(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_ALL \
	EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH_ALL \
	EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_FLASH(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM_ALL \
	EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EEPROM(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM
*/
#define EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM_ALL \
	EACOF_DEVICE_MOTHERBOARD_NONVOLATILEMEMORY_EPROM(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_CLOCKGENERATOR
*/
#define EACOF_DEVICE_MOTHERBOARD_CLOCKGENERATOR_ALL \
	EACOF_DEVICE_MOTHERBOARD_CLOCKGENERATOR(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCI
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCI_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCI(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCIE
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCIE_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCIE(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_AGP
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_AGP_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_AGP(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ISA
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ISA_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ISA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_MCA
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_MCA_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_MCA(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_VLB
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_VLB_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_VLB(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_PCCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBUS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_CARDBAY(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_PCCARD_EXPRESSCARD(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_COMPACTFLASH(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_SBUS
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_SBUS_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_SBUS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ZORRO
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ZORRO_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_ZORRO(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_NUBUS
*/
#define EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_NUBUS_ALL \
	EACOF_DEVICE_MOTHERBOARD_EXPANSIONSLOT_NUBUS(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_POWER
*/
#define EACOF_DEVICE_POWER_ALL \
	EACOF_DEVICE_POWER(EACOF_DEVICE_COUNT_ALL)
/**
    A shorthand macro which will specify all devices at all levels of the tree.

    @see EACOF_DEVICE_COUNT_ALL
    @see EACOF_DEVICE_POWER_PSU
*/
#define EACOF_DEVICE_POWER_PSU_ALL \
	EACOF_DEVICE_POWER_PSU(EACOF_DEVICE_COUNT_ALL, EACOF_DEVICE_COUNT_ALL)

#endif // EACOF_GENERATED_DEVICES_H
