
include(BundleUtilities)

set(BU_CHMOD_BUNDLE_ITEMS ON)

# Define the executable path
set(APP_EXECUTABLE "${CMAKE_INSTALL_PREFIX}/bin/QtMainWindowApp")

message(STATUS "Fixing up bundle: ${APP_EXECUTABLE}")

if(NOT EXISTS "${APP_EXECUTABLE}")
    message(FATAL_ERROR "Executable not found: ${APP_EXECUTABLE}")
endif()

# Collect all installed plugins
file(GLOB_RECURSE PLUGIN_FILES 
    "${CMAKE_INSTALL_PREFIX}/bin/plugins/*.so"
    "${CMAKE_INSTALL_PREFIX}/bin/plugins/*.dll"
)

message(STATUS "Found ${CMAKE_INSTALL_PREFIX}/bin/plugins plugins: ${PLUGIN_FILES}")

# Qt runtime directories for dependency resolution
set(QT_RUNTIME_DIRS "/usr/bin;/usr/lib;/usr/lib64")

message(STATUS "Qt runtime directories: ${QT_RUNTIME_DIRS}")

# Fix up the bundle
fixup_bundle("${APP_EXECUTABLE}" "${PLUGIN_FILES}" "${QT_RUNTIME_DIRS}")

message(STATUS "Bundle fixup completed successfully")
