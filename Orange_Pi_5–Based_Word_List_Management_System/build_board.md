# Building and Preparing the Orange Pi 5

## 1. Purpose

This document explains how to prepare the Orange Pi 5 so that it can run the Find Words application.

The process consists of:

```text
Download Linux Image
        |
        v
Prepare microSD / eMMC
        |
        v
Boot Orange Pi 5
        |
        v
Configure Linux
        |
        v
Install Development Tools
        |
        v
Build Find_Words
```

## 2. Required Hardware

You will need:

* Orange Pi 5
* Compatible power supply
* microSD card or eMMC storage
* USB keyboard
* USB mouse
* HDMI display and cable, if using a desktop setup
* Network connection
* Development PC
* microSD card reader/writer

An SSD is optional but recommended for large word databases.

## 3. Prepare the Operating System

Download an Orange Pi 5-compatible Linux image from the appropriate official Orange Pi/software distribution source.

Choose an operating system that provides:

* ARM64 support
* Linux kernel support for Orange Pi 5
* Package manager
* GCC/G++
* Standard filesystem support

For a development system, a Debian/Ubuntu-based ARM64 distribution is convenient.

## 4. Flash the Operating System

Insert the microSD card into your development computer.

Use a suitable image-writing application to write the Linux image to the microSD card.

The general procedure is:

```text
Linux Image
     |
     v
Image Writer
     |
     v
microSD Card
```

After writing the image, safely eject the card.

> **Important:** Selecting the wrong storage device when flashing an image can erase existing data. Verify the target device before starting the flash operation.

## 5. First Boot

Insert the prepared microSD card into the Orange Pi 5.

Connect:

* Display
* Keyboard
* Network
* Power

Power on the Orange Pi 5.

The system should boot from the prepared storage.

Complete the initial Linux configuration.

## 6. Update the Operating System

After logging in:

```bash
sudo apt update
sudo apt upgrade -y
```

Reboot if required:

```bash
sudo reboot
```

## 7. Install Development Tools

Install the compiler and build tools:

```bash
sudo apt install -y build-essential git
```

Verify the compiler:

```bash
g++ --version
```

Verify Make:

```bash
make --version
```

Verify Git:

```bash
git --version
```

## 8. Verify C++17

Create a test program:

```bash
nano test.cpp
```

Add:

```cpp
#include <iostream>

int main()
{
    std::cout << "C++17 is working" << std::endl;
    return 0;
}
```

Compile:

```bash
g++ -std=c++17 test.cpp -o test
```

Run:

```bash
./test
```

Expected output:

```text
C++17 is working
```

## 9. Check Storage

Check available storage:

```bash
df -h
```

Check memory:

```bash
free -h
```

Check processor information:

```bash
lscpu
```

These commands can be used to verify the Orange Pi 5 environment before deploying the application.

## 10. Development Environment

At this point the board should provide:

```text
Orange Pi 5
    |
    +-- Linux
    |
    +-- GCC/G++
    |
    +-- GNU Make
    |
    +-- Git
    |
    +-- C++17
    |
    +-- Storage
```

The board is now ready for the Find Words application.

## 11. Optional: SSH Access

If the Orange Pi 5 is connected to the network, SSH can be used instead of a monitor and keyboard.

From the development computer:

```bash
ssh <username>@<orange-pi-ip-address>
```

For example:

```bash
ssh orangepi@192.168.1.100
```

Use the actual username and IP address assigned to the board.

## 12. Ready for Application Deployment

After completing this document, the Orange Pi 5 should be ready for:

```text
Clone Find_Words
       |
       v
Build with Make
       |
       v
Run application
       |
       v
Test word processing
```

