# QSSLab (Qt stylesheet playground)

Qt 6 Widgets app that lets you load, edit, and live-preview CSS/QSS files. Includes a basic syntax highlighter and a bundled example stylesheet (`resources/styles/fancy.qss`).

## Requirements
- CMake 3.21+
- A C++17 compiler
- Qt 6: Widgets, 3DCore, 3DExtras, 3DInput, 3DRender

## Configure and build
Use the presets to build out of source (recommended):

```bash
cmake --preset debug
cmake --build --preset debug

cmake --preset release
cmake --build --preset release
```

Or run manually if you prefer:

```bash
cmake -S . -B ../build_Debug -DCMAKE_BUILD_TYPE=Debug
cmake --build ../build_Debug

cmake -S . -B ../build_Release -DCMAKE_BUILD_TYPE=Release
cmake --build ../build_Release
```

Launch the app from the chosen build directory, e.g. `../build_Debug/QtMainWindowApp`.

## Usage
- `File -> Open…` to load a `.css`/`.qss` file; it applies immediately to the UI and the 3D view.
- `File -> Save` / `Save As…` to persist changes from the editor pane.
- External edits to the opened file are detected; the app reloads and reapplies the stylesheet unless there are unsaved in-app edits, in which case it keeps the in-memory version.
- The editor highlights selectors, properties, values, and multi-line comments for quick scanning.
- A color/gradient graph below the editor shows which selectors share the same fill; it rebuilds on load and after saving.
