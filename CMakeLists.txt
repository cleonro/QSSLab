cmake_minimum_required(VERSION 3.16)

project(QtMainWindowApp VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets  3DExtras 3DInput 3DRender REQUIRED)

get_filename_component(_qt6_cmake_dir "${Qt6_DIR}" DIRECTORY)
get_filename_component(_qt6_lib_dir "${_qt6_cmake_dir}" DIRECTORY)
get_filename_component(QT6_INSTALL_PREFIX "${_qt6_lib_dir}" DIRECTORY)

set(QT6_BIN_DIR "${QT6_INSTALL_PREFIX}/bin")
set(QT6_LIB_DIR "${QT6_INSTALL_PREFIX}/lib")
set(QT6_LIB64_DIR "${QT6_INSTALL_PREFIX}/lib64")
set(QT6_PLUGIN_DIR "${QT6_INSTALL_PREFIX}/plugins")

set(QT6_RUNTIME_DIRS "")
foreach(_dir IN LISTS QT6_BIN_DIR QT6_LIB_DIR QT6_LIB64_DIR QT6_PLUGIN_DIR)
    if(EXISTS "${_dir}")
        list(APPEND QT6_RUNTIME_DIRS "${_dir}")
    endif()
endforeach()
list(REMOVE_DUPLICATES QT6_RUNTIME_DIRS)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
    src/CSSEditor.h
    src/CSSEditor.cpp
    src/MainWindow.ui
    resources/resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::3DCore
    Qt6::3DExtras
    Qt6::3DInput
    Qt6::3DRender
)

# Set RPATH for the executable to find libraries in the bundle
set_target_properties(${PROJECT_NAME} PROPERTIES
    INSTALL_RPATH "\$ORIGIN/lib;\$ORIGIN/../lib"
    BUILD_WITH_INSTALL_RPATH OFF
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    BUNDLE DESTINATION .
)

# Install qt.conf to tell Qt where to find plugins
install(FILES "${CMAKE_SOURCE_DIR}/qt.conf"
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install only necessary Qt plugins (not all of them)
set(_qt_plugin_destination "${CMAKE_INSTALL_BINDIR}/plugins")

# Install platform plugins (required for Qt apps to run)
if(EXISTS "${QT6_PLUGIN_DIR}/platforms")
    install(DIRECTORY "${QT6_PLUGIN_DIR}/platforms"
        DESTINATION ${_qt_plugin_destination}
        FILES_MATCHING PATTERN "*.so" PATTERN "*.dll" PATTERN "*.dylib"
    )
endif()

# Install other commonly needed plugins
foreach(_plugin_dir IN ITEMS imageformats iconengines platformthemes)
    if(EXISTS "${QT6_PLUGIN_DIR}/${_plugin_dir}")
        install(DIRECTORY "${QT6_PLUGIN_DIR}/${_plugin_dir}"
            DESTINATION ${_qt_plugin_destination}
            FILES_MATCHING PATTERN "*.so" PATTERN "*.dll" PATTERN "*.dylib"
        )
    endif()
endforeach()

# Create a script for fixup_bundle
set(FIXUP_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/fixup_bundle.cmake")
file(WRITE "${FIXUP_SCRIPT}" "
include(BundleUtilities)

set(BU_CHMOD_BUNDLE_ITEMS ON)

# Define the executable path
set(APP_EXECUTABLE \"\${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/${PROJECT_NAME}\")

message(STATUS \"Fixing up bundle: \${APP_EXECUTABLE}\")

if(NOT EXISTS \"\${APP_EXECUTABLE}\")
    message(FATAL_ERROR \"Executable not found: \${APP_EXECUTABLE}\")
endif()

# Collect all installed plugins
file(GLOB_RECURSE PLUGIN_FILES 
    \"\${CMAKE_INSTALL_PREFIX}/${_qt_plugin_destination}/*.so\"
    \"\${CMAKE_INSTALL_PREFIX}/${_qt_plugin_destination}/*.dll\"
)

message(STATUS \"Found \${CMAKE_INSTALL_PREFIX}/${_qt_plugin_destination} plugins: \${PLUGIN_FILES}\")

# Qt runtime directories for dependency resolution
set(QT_RUNTIME_DIRS \"${QT6_RUNTIME_DIRS}\")

message(STATUS \"Qt runtime directories: \${QT_RUNTIME_DIRS}\")

# Fix up the bundle
fixup_bundle(\"\${APP_EXECUTABLE}\" \"\${PLUGIN_FILES}\" \"\${QT_RUNTIME_DIRS}\")

message(STATUS \"Bundle fixup completed successfully\")
")

# Install the fixup script to run at install time
install(SCRIPT "${FIXUP_SCRIPT}")

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "QtMainWindowApp")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Portable bundle of ${PROJECT_NAME}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}")
set(CPACK_GENERATOR "TGZ;ZIP")
set(CPACK_VERBATIM_VARIABLES ON)
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/packages")
include(CPack)
