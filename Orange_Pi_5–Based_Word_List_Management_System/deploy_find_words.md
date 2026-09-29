# Deploying Find Words on Orange Pi 5

## 1. Purpose

This document explains how to add the **Find Words** project to the Orange Pi 5, compile it, run it, and verify that the application is working correctly.

The deployment flow is:

```text
Find_Words Source
       |
       v
Copy / Clone to Orange Pi 5
       |
       v
Compile
       |
       v
Run Pipeline
       |
       v
Verify stored.txt
```

## 2. Project Structure

The project should contain files similar to:

```text
Find_Words/
│
├── Makefile
├── README.md
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

After compilation, executable files will be created:

```text
clean_text
filter_duplicates
update_stored
sort_stored
```

## 3. Get the Source Code

If the project is hosted in GitHub:

```bash
git clone <YOUR_FIND_WORDS_REPOSITORY>
```

Enter the project directory:

```bash
cd Find_Words
```

Check the files:

```bash
ls -la
```

You should see the source files and Makefile.

## 4. Build the Project

Clean any previous build:

```bash
make clean
```

Build the complete project:

```bash
make
```

Verify the generated executables:

```bash
ls -l clean_text
ls -l filter_duplicates
ls -l update_stored
ls -l sort_stored
```

You can also check the executable architecture:

```bash
file clean_text
```

The binary should be an ARM64/AArch64 executable when compiled directly on a 64-bit Orange Pi 5 Linux system.

## 5. Prepare Test Input

Create a test input:

```bash
cat > input.txt << 'EOF'
Hello world!
Hello again.
Testing word processing.
Orange Pi 5 is running Find Words.
Testing duplicate words.
EOF
```

Check the input:

```bash
cat input.txt
```

## 6. Run the Processing Pipeline

Run the first stage:

```bash
./clean_text
```

Run duplicate filtering:

```bash
./filter_duplicates
```

Update the stored word list:

```bash
./update_stored
```

Sort the stored list:

```bash
./sort_stored
```

The complete workflow is:

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

## 7. Check the Result

Display the stored words:

```bash
cat stored.txt
```

The resulting file should contain the words extracted from the input without unwanted duplicate entries, according to the current implementation.

## 8. Test Incremental Updates

Add new text:

```bash
cat >> input.txt << 'EOF'
algorithm
blockchain
cryptocurrency
Orange Pi
EOF
```

Run the pipeline again:

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

Check the database:

```bash
cat stored.txt
```

The new words should be incorporated into the existing stored word list.

## 9. Verify Each Processing Stage

For debugging, inspect the intermediate files.

### Input

```bash
cat input.txt
```

### Cleaned data

Depending on the current implementation:

```bash
cat clean_text
```

### Filtered data

```bash
cat filtered.txt
```

### Master word list

```bash
cat stored.txt
```

This makes it possible to identify which processing stage produces an unexpected result.

## 10. Check Executables

Use:

```bash
file clean_text
file filter_duplicates
file update_stored
file sort_stored
```

Also check their permissions:

```bash
ls -lh clean_text filter_duplicates update_stored sort_stored
```

If an executable permission is missing:

```bash
chmod +x clean_text filter_duplicates update_stored sort_stored
```

## 11. Flashing the Application

The Find Words application normally does **not** need to be flashed directly into the Orange Pi 5 boot firmware.

Instead, the normal architecture is:

```text
+--------------------------------+
| Orange Pi 5 Storage            |
|                                |
| +----------------------------+ |
| | Linux Operating System     | |
| +----------------------------+ |
|                                |
| +----------------------------+ |
| | Find_Words Application     | |
| |                            | |
| | clean_text                 | |
| | filter_duplicates          | |
| | update_stored              | |
| | sort_stored                | |
| +----------------------------+ |
|                                |
| +----------------------------+ |
| | Word Database              | |
| | stored.txt                 | |
| +----------------------------+ |
+--------------------------------+
```

The **Linux OS is flashed** to the boot/storage device.

The **Find Words application is then copied or cloned onto the Linux filesystem and compiled**.

## 12. If You Want a Complete Prebuilt Image

For production, a complete system image can eventually be created containing:

```text
Linux
  +
Find_Words binaries
  +
Configuration
  +
Initial stored.txt
  +
Startup service
```

Then the complete image can be written to the target storage.

For the development stage, however, it is simpler to keep:

```text
OS image
+
Find_Words source
```

separate.

## 13. Automatic Startup

If the final device should run Find Words automatically after boot, a Linux systemd service can be created.

Example service:

```ini
[Unit]
Description=Find Words Application
After=network.target

[Service]
Type=oneshot
WorkingDirectory=/home/orangepi/Find_Words
ExecStart=/home/orangepi/Find_Words/clean_text
ExecStart=/home/orangepi/Find_Words/filter_duplicates
ExecStart=/home/orangepi/Find_Words/update_stored
ExecStart=/home/orangepi/Find_Words/sort_stored

[Install]
WantedBy=multi-user.target
```

The exact service configuration should be adjusted to match the actual Orange Pi user, project path, and desired startup behavior.

## 14. Final Functional Test

Run:

```bash
echo "Orange Pi 5 Find Words test" > input.txt
```

Then:

```bash
./clean_text && \
./filter_duplicates && \
./update_stored && \
./sort_stored
```

Finally:

```bash
cat stored.txt
```

Verify that the expected words appear.

## 15. Deployment Checklist

Before considering the system operational, verify:

```text
[ ] Orange Pi 5 boots successfully
[ ] Linux is installed
[ ] Network is working
[ ] GCC/G++ is installed
[ ] C++17 compilation works
[ ] Make is installed
[ ] Find_Words source is available
[ ] make completes successfully
[ ] clean_text runs
[ ] filter_duplicates runs
[ ] update_stored runs
[ ] sort_stored runs
[ ] stored.txt is updated
[ ] Incremental update works
[ ] Large word-list testing is completed
```

## 16. Final System

The completed prototype should operate as:

```text
                 Orange Pi 5
                      |
                      v
                 Linux OS
                      |
                      v
              Find Words Program
                      |
          +-----------+-----------+
          |           |           |
          v           v           v
     clean_text  filter_duplicates
                      |
                      v
                update_stored
                      |
                      v
                 sort_stored
                      |
                      v
                  stored.txt
```

The Orange Pi 5 therefore acts as the **processor-side embedded Linux platform**, while Find Words provides the word-processing application running on top of it.

