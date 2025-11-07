# Changes

## Nucleo-H753zi BSP

A BSP has been added for the Nucleo-H753zi board. It is based on the existing 
BSP `arm/nucleo-h743zi`.

The following has been added/modified:

* Added GPIO support

### Files

* `spec/build/bsps/arm/stm32h7` - this is the _specifications_ are in the form of YAML files. Adding a new `bsp<name>.yml` file here with `build-type: bsp` will add the new BSP. Name is specified in `bsp:`. Currently, only an `install` section has been added to install the `stm32h753zi_gpio.h` file in `BSP_INCLUDEDIR`. The rest is as in the original.
* `spec/build/bsps/arm/stm32h7/grp.yml` - this file lists all the _include files_ for the spec as `build-dependency` entries (`.yml` removed from the filenames). A new entry has been added to include the file `optnucleoh753zi.yml`.
* `spec/build/bsps/arm/stm32h7/obj.yml` - this file lists all _common_ include files to be installed and source files to be compiles. Include files are installed in the `BSP_INCLUDEDIR` and can be included as `#include <filename>`. _Specific_ include/source files can be specified in the top `bsp....yml` file. Nothing has been changed in this file.
* `spec/build/bsps/arm/stm32h7/opt<...>.yml` - these files contain optional directives and are included from the `obj.yml` file. In this case, `optnucleoh753zi.yml` has been added which simple adds a `IS_NUCLEO_H753ZI` parameter with `true` if the BSP equals `arm/nucleo-h753zi` and `false` otherwise.  
  In the rest of the files (e.g. `optlinkcmds.yml`), the new BSP name has been added to the `enabled-by:` to use the same files/values for the new BSP.

* `bsps/arm/stm32h7/boards/stm/` - this is where new source/header files can be added. The original `nucleo-h743zi` has been copied to `nucleo-h753zi`.
* `bsps/arm/stm32h7/boards/stm/nucleo-h753zi/stm32h7-gpio.c` - new file that implements RTEMS GPIO functions.

### Building

1. Add a `config.ini` file with just `[arm/nucleo-h753zi]`.
2. Set both PATH and PREFIX environment variables
3. Configure:  `./waf configure --prefix=$HOME/Projs/rtems/rtems/6` - yes, the prefix _must_ be specified here also.
4. Build: `./waf`
5. Install files in RTEMS home directory: `./waf install`. This will copy files to `~/Projs/rtems/rtems/6/arm-rtems6/nucleo-h753zi/lib/`.

**Note:** If some of the files (say, the `linkcmds`) does not update when rebuilding/installing, do a `rm -rf buld` followed by configure, build and install...


_(Original README below)_

Real-Time Executive for Multiprocessing Systems
===============================================

RTEMS is a real-time executive (kernel) which provides a high performance 
environment for embedded applications with the following features:

 * Standards based user interfaces.
 * Multitasking capabilities.
 * Homogeneous and heterogeneous multiprocessor systems.
 * Event-driven, priority-based, preemptive scheduling.
 * Optional rate monotonic scheduling.
 * Intertask communication and synchronisation.
 * Priority inheritance.
 * Responsive interrupt management.
 * Dynamic memory allocation.
 * High level of user configurability.
 * Open source with a friendly user license.


Project git repositories are located at:

  * https://gitlab.rtems.org/rtems/


Online documentation is available at:

  * https://docs.rtems.org/


RTEMS Doxygen for CPUKit:

  * https://docs.rtems.org/doxygen/branches/master/


RTEMS POSIX 1003.1 Compliance Guide:

  * https://docs.rtems.org/branches/master/posix-compliance/


RTEMS Mailing Lists for general purpose use the users list and for developers 
use the devel list.

  * https://lists.rtems.org/mailman/listinfo


The version number for this software is indicated in the VERSION file.
