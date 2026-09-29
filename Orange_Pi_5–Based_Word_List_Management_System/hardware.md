# Orange Pi 5 Hardware

## Project

**Find Words: An Automated Word List Management System Using Orange Pi 5**

## 1. Overview

The Find Words project is designed to run on an **Orange Pi 5** as the processor-side platform.

The Orange Pi 5 provides sufficient processing power, memory, storage interfaces, and Linux support to run the C++17 word-processing application.

The system processes text through the following stages:

```text
Input Text
    |
    v
+----------------+
|  clean_text    |
+----------------+
    |
    v
+----------------------+
| filter_duplicates    |
+----------------------+
    |
    v
+----------------+
| update_stored |
+----------------+
    |
    v
+----------------+
|  sort_stored   |
+----------------+
    |
    v
stored.txt
```

## 2. Main Hardware

### Orange Pi 5

The Orange Pi 5 is the main processor board.

The board is suitable for this project because it can run a standard Linux operating system and compile/run C++17 applications.

### Recommended configuration

| Component              | Recommendation         |
| ---------------------- | ---------------------- |
| Processor board        | Orange Pi 5            |
| RAM                    | 8 GB recommended       |
| Operating system       | Linux                  |
| Storage                | microSD card or eMMC   |
| High-volume storage    | USB SSD                |
| Development connection | Ethernet / Wi-Fi / USB |
| Programming language   | C++17                  |
| Build system           | GNU Make               |

## 3. Storage

The project uses text files such as:

```text
input.txt
clean_text
filtered.txt
stored.txt
output.txt
```

For development and testing, a microSD card is sufficient.

For a system that continuously updates a large word database, an SSD is recommended because the application performs repeated file read/write operations.

Recommended architecture:

```text
Orange Pi 5
     |
     +---- microSD/eMMC
     |       |
     |       +---- Linux OS
     |
     +---- USB SSD
             |
             +---- Find_Words data
                     |
                     +---- stored.txt
```

## 4. Power

Use a stable power supply appropriate for the Orange Pi 5.

Do not power the board from an unreliable USB source, especially when using USB peripherals or an SSD.

## 5. Network

A network connection is useful during development for:

* Installing packages
* Downloading source code
* Cloning the Find_Words repository
* Remote SSH access
* Updating the application

Example:

```text
Development PC
      |
    Ethernet / Network
      |
      v
 Orange Pi 5
      |
      v
 Find_Words
```

## 6. Interfaces

Depending on the final system design, the Orange Pi 5 can receive text through:

* USB keyboard
* USB storage
* Network
* UART
* Application-generated input
* Other external interfaces

The first implementation can simply use:

```text
input.txt
```

as the input source.

## 7. Software Environment

The application requires:

* Linux
* GCC/G++
* C++17 support
* GNU Make

Installation:

```bash
sudo apt update
sudo apt install build-essential git
```

Verify:

```bash
g++ --version
make --version
git --version
```

## 8. Hardware Block Diagram

```text
              +----------------------+
              |      Input Source    |
              | USB / Network / File |
              +----------+-----------+
                         |
                         v
              +----------------------+
              |      Orange Pi 5     |
              |                      |
              |      Linux OS        |
              |                      |
              |    C++17 Program     |
              +----------+-----------+
                         |
                         v
              +----------------------+
              |    Word Processing   |
              |                      |
              | clean_text           |
              | filter_duplicates    |
              | update_stored        |
              | sort_stored          |
              +----------+-----------+
                         |
                         v
              +----------------------+
              |      Storage         |
              |                      |
              | input.txt            |
              | filtered.txt         |
              | stored.txt           |
              +----------------------+
```

## 9. Recommended Prototype

For the first prototype:

```text
Orange Pi 5
     +
8 GB RAM
     +
microSD/eMMC
     +
Linux
     +
Ethernet
     +
Find_Words C++ application
```

Once the application is stable, additional input interfaces and external storage can be added.

