# c-core

A custom standard library around raw C libraries.

The goal of the this library is to provide safer and more modern wrappers
around old functionality, including proper string and file types, and memory arenas to reduce manual memory management.

## Library Compilation and Use
The standard library can be added to a CMake project through the following
steps.

1. Include the `c-core` directory within you CMake project.
2. Add the library subdirectory to the root `CMakeLists.txt` file
  ```cmake
  add_subdirectory(c-core/std)
  ```
3. Include and link the standard library within the executable's `CMakeLists.txt` file
  ```cmake
  target_link_libraries(${EXE_NAME} PRIVATE std)
  target_include_directories(${EXE_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/c-core/include")
  ```
4. Access standard library headers under the `std/` include flag:
  ```c
  #include "std/memory.h"
  ```

## Library use as a Submodule
Including the `c-core` directory as a git submodule instead of a raw directory makes it easy to update and keep up-to-date the `c-core` library from other projects. Add the submodule using
```bash
git submodule add https://github.com/Risheit/c-core/
```
