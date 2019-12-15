# TDD_by_example_cpp_gtest [![Build Status](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp.svg?branch=master)](https://travis-ci.org/Hoonyyhoon/TDD_book_in_Cpp)
This repo implements following progress of the book "Test Driven Development: By Example" by Kent Beck[[link](https://www.amazon.com/Test-Driven-Development-Kent-Beck/dp/0321146530)], using C++ and gtest.
Each branch in the repo corresponds to each chapter in the book.

## To do list:
- [ ] Part1
- [ ] Part2
- [ ] git hook  
<!-- - [ ] Earth (Orbit/Moon) -->

## Run code
The structure of the CMake highly referenced from a great project, **Modern CMake**[[link](https://gitlab.com/CLIUtils/modern-cmake)]

To configure:
```
cmake -S . -B build
```

To build:
```
cmake --build build
```

To test
```
cmake --build build --target test ARGS=-V
```
