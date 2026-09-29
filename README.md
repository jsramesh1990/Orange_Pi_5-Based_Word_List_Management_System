# Find Words

### An Automated Word List Management System Using Orange Pi 5

**Clean • Deduplicate • Update • Sort**

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Orange%20Pi%205-orange" alt="Orange Pi 5">
  <img src="https://img.shields.io/badge/Language-C%2B%2B17-blue" alt="C++17">
  <img src="https://img.shields.io/badge/OS-Linux-green" alt="Linux">
  <img src="https://img.shields.io/badge/Build-Make-yellow" alt="Make">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey" alt="MIT License">
</p>

---

## Overview

**Find Words** is a lightweight C++17-based word-list management system designed to run on the **Orange Pi 5**.

The project takes raw text as input and automatically processes it through multiple stages to create and maintain a clean, deduplicated, and sorted master word list.

The system is designed for applications such as:

* Search systems
* Dictionary and vocabulary management
* NLP preprocessing
* Text processing
* Linguistic research
* Embedded Linux applications

---

## System Architecture

```text
                         ┌─────────────────────┐
                         │      Input Text     │
                         │      input.txt      │
                         └──────────┬──────────┘
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │     clean_text      │
                         │                     │
                         │ Remove unwanted     │
                         │ characters / clean  │
                         │ input text          │
                         └──────────┬──────────┘
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │ filter_duplicates   │
                         │                     │
                         │ Remove duplicate    │
                         │ words               │
                         └──────────┬──────────┘
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │    update_stored    │
                         │                     │
                         │ Merge new words     │
                         │ into master list    │
                         └──────────┬──────────┘
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │     sort_stored     │
                         │                     │
                         │ Sort master word    │
                         │ list alphabetically │
                         └──────────┬──────────┘
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │     stored.txt      │
                         │                     │
                         │ Master Word List    │
                         └─────────────────────┘
```

---

## Hardware Platform

The project is designed for the **Orange Pi 5**, providing an ARM-based Linux environment for running the C++ application.

```text
┌─────────────────────────────────────┐
│             Orange Pi 5             │
│                                     │
│  ┌─────────────┐  ┌──────────────┐  │
│  │   Linux OS  │  │  C++17 App   │  │
│  └─────────────┘  └──────────────┘  │
│                                     │
│          Word Processing            │
│               │                     │
│               ▼                     │
│          stored.txt                 │
└─────────────────────────────────────┘
```

### Recommended Hardware

| Component       | Recommendation   |
| --------------- | ---------------- |
| Processor Board | Orange Pi 5      |
| RAM             | 8 GB recommended |
| OS              | Linux ARM64      |
| Storage         | microSD / eMMC   |
| Large Database  | USB SSD          |
| Compiler        | GCC/G++          |
| Language        | C++17            |
| Build System    | GNU Make         |

---

## Features

### Text Cleaning

Processes raw text and removes unwanted characters according to the current cleaning implementation.

### Duplicate Filtering

Removes duplicate words before they are added to the master word list.

### Incremental Updates

New words can be added to an existing `stored.txt` without manually rebuilding the complete database.

### Sorting

The stored word list can be alphabetically sorted.

### Lightweight

The application uses standard C++ and does not require external runtime libraries beyond the normal Linux development/runtime environment.

### Modular Design

Each processing stage is implemented as a separate executable:

```text
clean_text
filter_duplicates
update_stored
sort_stored
```

---

## Project Structure

```text
Find_Words/
│
├── README.md
├── LICENSE
├── Makefile
│
├── clean_text.cpp
├── filter_duplicates.cpp
├── update_stored.cpp
├── sort_stored.cpp
│
├── input.txt
├── filtered.txt
├── stored.txt
└── output.txt
```

Documentation:

```text
docs/
├── hardware.md
├── build_board.md
└── deploy_find_words.md
```

---

## Requirements

### Hardware

* Orange Pi 5
* microSD card or eMMC
* Compatible power supply
* Optional USB SSD
* Network connection

### Software

A Linux-based ARM64 environment is recommended.

Install the required development tools:

```bash
sudo apt update
sudo apt install -y build-essential git
```

Verify:

```bash
g++ --version
make --version
git --version
```

---

## Quick Start

### 1. Clone the Repository

```bash
git clone <YOUR_REPOSITORY_URL>
```

Enter the project directory:

```bash
cd Find_Words
```

### 2. Build

Compile all components:

```bash
make
```

Verify the executables:

```bash
ls -l clean_text
ls -l filter_duplicates
ls -l update_stored
ls -l sort_stored
```

### 3. Prepare Input

Create an input file:

```bash
echo "Hello world! Hello again. Testing word processing." > input.txt
```

### 4. Run the Pipeline

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

### 5. View the Result

```bash
cat stored.txt
```

The `stored.txt` file now contains the processed word list.

---

## Incremental Word Updates

One of the main features of Find Words is the ability to maintain a growing master word list.

Add additional text:

```bash
echo "algorithm blockchain cryptocurrency Orange Pi" >> input.txt
```

Run the pipeline again:

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

View the updated database:

```bash
cat stored.txt
```

New words can therefore be incorporated into the existing master list over time.

---

## Makefile

The project uses GNU Make to simplify compilation.

### Build Everything

```bash
make
```

### Build Individual Components

```bash
make clean_text
make filter_duplicates
make update_stored
make sort_stored
```

### Remove Compiled Binaries

```bash
make clean
```

---

## Testing

A simple functional test can be performed using:

```bash
echo "Orange Pi 5 Find Words Find Words test" > input.txt
```

Run:

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

Then:

```bash
cat stored.txt
```

Check that the expected words are present and duplicate processing behaves according to the current implementation.

---

## Documentation

Detailed project documentation is available here:

| Document                                            | Description                                        |
| --------------------------------------------------- | -------------------------------------------------- |
| [`hardware.md`](docs/hardware.md)                   | Orange Pi 5 hardware and system architecture       |
| [`build_board.md`](docs/build_board.md)             | Preparing and building the Orange Pi 5 environment |
| [`deploy_find_words.md`](docs/deploy_find_words.md) | Deploying, compiling, storage setup, and testing   |

---

## How It Works

The project separates word processing into independent stages.

### Stage 1 — Clean

```text
input.txt
    ↓
clean_text
```

Raw text is processed and unwanted characters are removed according to the implementation.

### Stage 2 — Deduplicate

```text
clean_text
    ↓
filter_duplicates
    ↓
filtered.txt
```

Duplicate words are removed.

### Stage 3 — Update

```text
filtered.txt
       +
stored.txt
       ↓
update_stored
       ↓
stored.txt
```

New words are merged into the existing master list.

### Stage 4 — Sort

```text
stored.txt
    ↓
sort_stored
    ↓
stored.txt
```

The master list is sorted.

---

## Project Goals

The main goal of this project is to create a simple and efficient **embedded Linux word-list processing system**.

Future improvements may include:

* [ ] Unicode / multilingual text support
* [ ] Word-frequency counting
* [ ] Stemming and lemmatization
* [ ] Configurable word filters
* [ ] Large-file optimization
* [ ] Better error handling
* [ ] Unit testing
* [ ] Logging and debug mode
* [ ] Batch processing
* [ ] Automatic startup on Orange Pi 5
* [ ] Web-based management interface
* [ ] Python API
* [ ] Database-backed word storage

---

## Development Roadmap

```text
Phase 1
│
├── Core C++ processing
├── File-based word storage
└── Orange Pi 5 deployment
        │
        ▼
Phase 2
│
├── Error handling
├── Unit tests
├── Logging
└── Performance improvements
        │
        ▼
Phase 3
│
├── Unicode support
├── Frequency analysis
├── NLP features
└── Configurable processing
        │
        ▼
Phase 4
│
├── Web interface
├── Python bindings
├── Database support
└── Production deployment
```

---

## Deployment Architecture

The intended embedded deployment is:

```text
                    ┌──────────────────────┐
                    │     Input Source     │
                    │                      │
                    │ File / USB / Network │
                    └──────────┬───────────┘
                               │
                               ▼
                    ┌──────────────────────┐
                    │      Orange Pi 5     │
                    │                      │
                    │      Linux ARM64     │
                    │          │           │
                    │          ▼           │
                    │    Find Words C++    │
                    └──────────┬───────────┘
                               │
                               ▼
                    ┌──────────────────────┐
                    │      Word Storage    │
                    │                      │
                    │      stored.txt      │
                    │       / SSD          │
                    └──────────────────────┘
```

---

## Contributing

Contributions are welcome.

To contribute:

```bash
git clone <YOUR_REPOSITORY_URL>
cd Find_Words

git checkout -b feature/your-feature

make clean
make
```

After testing your changes, submit a pull request.

---

## Project

**Find Words**

> An Automated Word List Management System Using Orange Pi 5

Built with:

**C++17 · Linux · GNU Make · Orange Pi 5**
