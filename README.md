# I2C RTC DS1307 Example

A demonstration project for interfacing an STM32F4 discovery to the DS1307 RTC peripheral
over an I2C bus.

## Requirements

Install the GNU ARM Embedded Toolchain:
https://launchpad.net/~terry.guo/+archive/ubuntu/gcc-arm-embedded

Clone the STM32F4 examples from /dev/thrash github repo here:
https://github.com/devthrash/STM32F4-examples

Clone the ST-Link linux line programmer and build from source, modify
the Makefile with the build location.
https://github.com/texane/stlink

## Building

Type make

## Flashing

Type make burn