# Banker's Algorithm Implementation in C++

This project is an implementation of the Banker's Algorithm in C++. The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue.

## Files

- `bankersAlgorithm.cpp`: This is the main C++ file that contains the implementation of the Banker's Algorithm.
- `input.txt`: This file contains the input data for the program. It includes the allocation matrix, max matrix, and available resources.

## How to Run

1. Compile the program using the command `g++ -o bankersAlgorithm bankersAlgorithm.cpp`.
2. Run the program with the command `./bankersAlgorithm`.

The program reads the input data from the `input.txt` file and prints out either a safe sequence of processes or a message indicating that the system is not in a safe state.

## Input File Format

The `input.txt` file should contain the following:

- The allocation matrix: This should be a series of lines, each containing the resources allocated to each process.
- The max matrix: This should be a series of lines, each containing the maximum resources each process may need.
- The available resources: This should be a single line containing the resources available.

Here is an example of how the `input.txt` file could be formatted:
