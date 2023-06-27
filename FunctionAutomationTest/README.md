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

### bin Folder

The `bin` folder contains the compiled binary files generated during the build process. These files are the result of compiling and linking the source code and are necessary for running the automated tests. The contents of this folder include:

- `main.o`: The object file for the `main` function.
- `project`: The final executable file.

### src Folder

The `src` folder contains the source code files for the project. These files define the implementation of the function being tested, as well as utility functions used in the testing process. The contents of this folder include:

- `main.c`: The main file that initiates the automated testing.
- `project.h`: The header file that contains function declarations and utility function prototypes.
- `utils.c`: The file that defines utility functions used in the testing process.

### test_files Folder

The `test_files` folder is used to store the necessary files for testing. It includes the following files:

- `test_cases.txt`: The file that contains the test cases for the function being tested.
- `test_results.txt`: The file that stores the results of the test cases after running the automated tests.
