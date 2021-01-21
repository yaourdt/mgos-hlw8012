# HLW8012 and BL0937 sensors library for Mongoose OS

A HLW8012 and BL0937 energy meter library for Mongoose OS.

## Usage

> ⚠ DO NOT CONNECT TO SERIAL LINE WHEN THE HLW8012 / BL0937 IS WORKING (ie when it is connected to the mains)!
> Use UDP logging instead.

Add the following to your projects `mos.yml`, and configure the respective GPIO
pins:

```yml
config_schema:
  - ["hlw8012.cf_pin", -1, {title: "cf_pin"}]
  - ["hlw8012.cf1_pin", -1, {title: "cf1_pin"}]
  - ["hlw8012.sel_pin", -1, {title: "sel_pin"}]

libs:
  - origin: https://github.com/yaourdt/mgos-hlw8012
```

Further parameters can be found in this libraries `mos.yml` file, all of them
are explained in further detail in the [original library](https://github.com/xoseperez/hlw8012).

First use requires [a manual calibration](https://github.com/xoseperez/hlw8012#manual-calibration).
Use a pure resistive load with a well-known power consumption (e.g. a water
kettle). Example for a device with 10 A current draw at 220V:

```
mgos_hlw8012_expectedCurrent(10.0);
mgos_hlw8012_expectedVoltage(220);
mgos_hlw8012_expectedActivePower(2200);
```

Subsequently, energy values can be read as

```
double current = mgos_hlw8012_getCurrent();
unsigned int voltage = mgos_hlw8012_getVoltage();
unsigned int active_power = mgos_hlw8012_getActivePower();
unsigned int apparent_power = mgos_hlw8012_getApparentPower();
unsigned int reactive_power = mgos_hlw8012_getReactivePower();
double power_factor = mgos_hlw8012_getPowerFactor();
unsigned long energy = mgos_hlw8012_getEnergy();
mgos_hlw8012_resetEnergy();
```

The last of the above commands will reset the energy counter.

If you encounter any problems with this library, please open a new issue. Before
you do, however, please consult the documentation of the original library to
avoid typical pitfalls.

If you encounter the compile time error `fatal: Couldn't find remote ref master`,
add a version tag to this library in your projects `mos.yml`:
```yml
libs:
  - origin: https://github.com/yaourdt/mgos-hlw8012
    version: main
```

## Acknowledgments
This library is a wrapper around [xoseperez/hlw8012](https://github.com/xoseperez/hlw8012).
The original work is licensed under the GPL-3.0 License, so this code as a
derivative work needs to be distributed under the same or equivalent license
terms.

## License

Copyright (C) 2020, Mark Dornbach

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see https://www.gnu.org/licenses/.
