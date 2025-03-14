# Sniff

Sniff is a high-performance, multithreaded text search utility that supports various search algorithms, including Boyer-Moore, Knuth-Morris-Pratt (KMP), and Rabin-Karp. It efficiently searches for patterns in large text files and provides options for threaded execution to enhance performance.

## Features
- Supports multiple search algorithms: **Boyer-Moore, KMP, Rabin-Karp**
- Multithreading for faster search performance
- Optimized for large text files
- Command-line interface with easy-to-use options

## Installation

### Prerequisites
Make sure you have the following installed:
- GCC (or Clang)
- CMake (version 3.10 or higher)
- Make
- POSIX Threads (pthread)

### Build and Install
Run the following commands to build and install Sniff:
```bash
# Clone the repository
git clone https://github.com/Arshdeep54/sniff.git
cd sniff

# Create build directory
mkdir -p build && cd build

# Generate Makefile using CMake
cmake ..

# Compile the project
make

# Install the binary system-wide
sudo make install
```
This installs `sniff` into `/usr/local/bin`, making it available globally.

## Usage
```bash
sniff "search_pattern" filename [--algo=boyer-moore|kmp|rabin-karp] [--threaded]
```

### Example Usage:
1. **Basic search using default Boyer-Moore algorithm**
   ```bash
   sniff "hello world" large_text.txt
   ```

2. **Use Knuth-Morris-Pratt (KMP) algorithm** [WIP]
   ```bash
   sniff "pattern" large_text.txt --algo=kmp
   ```

3. **Enable multithreading for faster search**
   ```bash
   sniff "pattern" large_text.txt --threaded
   ```

## License
This project is licensed under the MIT License.

