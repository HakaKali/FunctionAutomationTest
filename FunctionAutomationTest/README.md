## Makefile

The Makefile in this repository is used to compile and build the project. It provides convenient commands for building, running, and cleaning the project.

### Usage

- `make all`: Builds the project by compiling the necessary source files.
- `make clean`: Removes the compiled object files and the project executable.
- `make run`: Builds and runs the project, executing the tests and generating output files.
- `make $(BINDIR)/project`: Manually compiles the project executable.

Please make sure you have the necessary dependencies (e.g., GCC) installed before running the Makefile commands.

Note: The Makefile assumes the existence of a `bin` directory for storing the compiled object files and the project executable. It also expects a `test_files` directory for storing the test cases and results files.

Feel free to modify the Makefile according to your project's requirements and directory structure.
