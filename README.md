# I2C RTC DS1307 Example

A demonstration project for interfacing an STM32F4 discovery to the DS1307 RTC peripheral
over an I2C bus.

## Requirements

Install the GNU ARM Embedded Toolchain:
https://launchpad.net/~terry.guo/+archive/ubuntu/gcc-arm-embedded

Clone the ST-Link linux line programmer and build from source, modify
the Makefile with the build location.
https://github.com/texane/stlink

Clone the STM32F4-workarea repo and specify the path in the Makefile.
https://github.com/g4lvanix/STM32F4-workarea

## Building

Type make

## Flashing

Type sudo make burn
