# CMake - CppUTest - Raspberry Pi Pico

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)

:star: Star us on GitHub — it helps!

Example of a C development project for Raspberry Pi Pico using the Test Driven Development for Embedded C approach. Testing is done via CppUTest and build done with CMake.<br>
The source code for the demo used here was taken and modified from the Blink example code from the [pico-examples repository](https://github.com/raspberrypi/pico-examples)<br>
I use Linux (Debian) to develop with. I didn't try with Windows because I consider that it's not suitable for the Raspberry Pi Pico and CppUTest.

# pre-requisites

## Install the Toolchain and Pico-SDK

[Pico documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)<br>

### Toolchain
```
$ sudo apt update
$ sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential libstdc++-arm-none-eabi-newlib
```

### Pico-SDK
The installation of pico-sdk is described to be located in the home directory. You may choose to install it where you want.
```
$ cd ~
$ mkdir pico && cd pico
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
```
Create an environment variable:
```
$ export PICO_SDK_PATH=~/pico/pico-sdk
```


## Install CMake
```
$ sudo apt update && sudo apt install cmake
```

## Install CppUTest

The installation of CppUTest is described to be located in the home directory. You may choose to install it where you want.

```
$ cd ~
$ git clone https://github.com/cpputest/cpputest.git 
$ cd cpputest/cpputest_build
$ autoreconf .. -i
$ ../configure
$ sudo make install
```
Create an environment variable:
```
$ export CPPUTEST_HOME=~/cpputest
```

# Build Target
```
$ mkdir build && cd build
$ cmake ..
$ make
```

# Build and run tests
```
$ cd test && mkdir build && cd build
$ cmake ..
$ make
$ ./bin/RunAllTests
```
