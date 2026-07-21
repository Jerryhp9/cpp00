# cpp00

A C++ introductory project focused on core object-oriented programming concepts and idiomatic C++ class design.

## Overview

This repository contains exercises that build a solid foundation in C++ by practicing:

- Class and object creation
- Member functions and access control
- Constructors and destructors
- Encapsulation
- Basic project organization with headers and source files

## Repository Structure

Typical structure for this project:

- `ex00/` ... first exercise module
- `ex01/` ... additional exercise module
- `ex02/` ... additional exercise module
- `...`

Each exercise generally includes:

- `*.hpp` header files
- `*.cpp` implementation files
- `Makefile`

## Build

Most exercises can be built independently from their own directory.

```bash
cd ex00
make
```

Common Makefile targets:

- `make` or `make all` - build the executable
- `make clean` - remove object files
- `make fclean` - remove object files and executable
- `make re` - rebuild from scratch

## Run

After building, run the generated executable (name depends on the exercise):

```bash
./<executable_name>
```

## Learning Goals

- Understand C++ compilation units and header/source separation
- Practice canonical class form basics
- Improve code readability and maintainability
- Work with Makefiles for repeatable builds

## Requirements

- C++ compiler (e.g., `c++`, `g++`, or `clang++`)
- `make`

## Notes

- Follow exercise-specific constraints and expected output.
- Prefer clear, modular class implementations.
- Keep formatting and naming consistent across exercises.
