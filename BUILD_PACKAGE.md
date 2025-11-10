# Building and Packaging QtMainWindowApp

## Build and Create Package

To create a completely independent, portable bundle with all dependencies:

### Step 1: Configure the project
```bash
cmake -B build_Release -DCMAKE_BUILD_TYPE=Release
```

### Step 2: Build the project
```bash
cmake --build build_Release
```

### Step 3: Create the package
```bash
cd build_Release
cpack
```

Or combine build and package in one step:
```bash
cmake --build build_Release --target package
```

## Output

The packaged bundles will be created in `build_Release/packages/`:
- `QtMainWindowApp-0.1.0-Linux.tar.gz`
- `QtMainWindowApp-0.1.0-Linux.zip`

## Package Structure

The package will contain:
```
bin/
├── QtMainWindowApp          # The executable
├── qt.conf                  # Qt configuration
├── plugins/                 # Qt plugins
│   ├── platforms/           # Platform integration (required)
│   ├── imageformats/        # Image format support
│   ├── iconengines/         # Icon engine support
│   └── platformthemes/      # Platform theme support
└── lib/                     # Qt and system libraries (added by fixup_bundle)
    ├── libQt6Core.so.6
    ├── libQt6Gui.so.6
    ├── libQt6Widgets.so.6
    └── ... (other dependencies)
```

## Running the Application

After extracting the package on any Linux system:
```bash
cd bin
./QtMainWindowApp
```

The application will find all its dependencies automatically thanks to:
1. RPATH set to `$ORIGIN/lib` and `$ORIGIN/../lib`
2. `qt.conf` telling Qt where to find plugins
3. `fixup_bundle` copying all required libraries

## Notes

- The bundle is completely self-contained and portable
- No Qt installation required on the target system
- All dependencies are included and properly linked
- The application will work on any Linux distribution with compatible glibc
