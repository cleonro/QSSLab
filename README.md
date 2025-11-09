# Qt Main Window Sample

Simple Qt Widgets application with an out-of-source CMake build.

## Requirements
- CMake 3.21+
- A C++17 compiler
- Qt 6 Widgets development packages

## Configure and build
Use the provided presets so that build artifacts stay outside the source tree in `../build_Debug` and `../build_Release`.

```bash
cmake --preset debug
cmake --build --preset debug

cmake --preset release
cmake --build --preset release
```

You can still run the commands manually if your CMake version predates presets:

```bash
cmake -S . -B ../build_Debug -DCMAKE_BUILD_TYPE=Debug
cmake --build ../build_Debug

cmake -S . -B ../build_Release -DCMAKE_BUILD_TYPE=Release
cmake --build ../build_Release
```

Run the application from the chosen build directory, e.g. `../build_Debug/QtMainWindowApp`.
