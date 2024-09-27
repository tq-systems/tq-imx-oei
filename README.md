# Optional Executable Image (OEI)

[[TOC]]

## Overview

The Optional Executable Image (OEI) is an optional plugin loaded and executed by Cortex-M processor 
ROM on many NXP i.MX processors. The Cortex-M is the boot core, runs the boot ROM which loads the OEI, and then
branches to the OEI. The OEI then configures some aspects of the hardware such as DDR config, init TCM ECC, etc.
There could be multiple OEI images in the boot container. After execution of OEI, the processor returns
to ROM execution.

Supported development environments include Ubuntu 2020.04, 2022.04, and 2024.04.

## Download from GitHub

### NXP version

To download the repo from [GitHub](https://github.com/nxp-imx/imx-oei), first install git:

```
sudo apt update
sudo apt -y install git
```

Then clone the repo:

`git clone https://github.com/nxp-imx/imx-oei`

### TQ-Systems GmbH fork

Based on [NXP version](#nxp_version). Add support for TQ-Systems GmbH SoM

Clone the repo from [GitHub](https://github.com/tq-systems/tq-imx-oei).


## Installing the Toolchain

Compiling requires an ARM cross-compiler. Download and install the required arm-none-eabi toolchain from
the [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
website. For example, from the x86_64 Linux hosted cross toolchains AArch32 bare-metal target
(arm-none-eabi) section, download the *.xz file to a directory for the tool chain (e.g. tools) and then:

`tar xvf *.xz`

Set the `TOOLS` shell variable to the directory the toolchain is installed in. For example:

`export TOOLS=~/tools`

or set the `OEI_CROSS_COMPILE` variable to point to the path to the cross compiler tools including the prefix.

When the toolchain is in a directory like arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi in this
*tools* directory.

Also ensure the Linux installation is up-to-date and then install:

`sudo apt -y install make gcc g++-multilib srecord`

## Compiling an OEI Image

To get started with the OEI on an NXP iMX95 EVK LP5 board, [download the repository](#download-from-github)
and then compile the OEI for the target configuration.

For example to build OEI for TQMa95xxSA with 2GiB DDR, in the top directory of the code base (e.g. `tq-imx-oei`):

```
make board=tqma95xxsa oei=ddr DEBUG=1 RAM_SIZE=4 all
make board=tqma95xxsa oei=tcm DEBUG=1 RAM_SIZE=4 all
```

Build artifacts:

| oei target | artifact name   | artifact path
| ---------- | --------------- | ---------------------------------- |
|    ddr     | oei-m33-ddr.bin | `build/$(SOM)/ddr/oei-m33-ddr.bin` |
|    tcm     | oei-m33-tcm.bin | `build/$(SOM)/tcm/oei-m33-tcm.bin` |

**Note:**

- `SOM` defaults to the `board` option passed to `make`.

Copy the resulting binary image files to the iMX95 directory of the
[mkimage tool](https://github.com/nxp-imx/imx-mkimage).

Build a boot container using mkimage, program it to the boot device, and boot the board.
The OEI will display debug messages on the M33 debug UART of TQMa95xxSA if compiled
with `DEBUG=1`. For production builds, debug output shall be disabled.

Usually the board configuration for TQ-Systems SoM are validated and can be used as is.

