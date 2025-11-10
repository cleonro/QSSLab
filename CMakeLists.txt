cmake_minimum_required(VERSION 3.16)

project(QtMainWindowApp VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

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
    src/MainWindow.ui
    resources/resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    BUNDLE DESTINATION .
)

set(_qt_plugin_destination "${CMAKE_INSTALL_BINDIR}/plugins")
if(EXISTS "${QT6_PLUGIN_DIR}")
    install(DIRECTORY "${QT6_PLUGIN_DIR}/"
        DESTINATION ${_qt_plugin_destination}
    )
endif()

get_target_property(_bundle_output_name ${PROJECT_NAME} OUTPUT_NAME)
if(NOT _bundle_output_name)
    set(_bundle_output_name ${PROJECT_NAME})
endif()
set(_bundle_output_name "${_bundle_output_name}${CMAKE_EXECUTABLE_SUFFIX}")

install(CODE
"include(BundleUtilities)
set(BU_CHMOD_BUNDLE_ITEMS ON)
set(_bundle \"\${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/${_bundle_output_name}\")
if(EXISTS \"\${_bundle}\")
  set(_qt_runtime_dirs \"${QT6_RUNTIME_DIRS}\")
  file(GLOB_RECURSE _qt_plugins
       \"\${CMAKE_INSTALL_PREFIX}/${_qt_plugin_destination}/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
  fixup_bundle(\"\${_bundle}\" \"\${_qt_plugins}\" \"\${_qt_runtime_dirs}\")
else()
  message(WARNING \"Bundle '\${_bundle}' does not exist. fixup_bundle skipped.\")
endif()
")

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "QtMainWindowApp")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Portable bundle of ${PROJECT_NAME}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}")
set(CPACK_GENERATOR "TGZ;ZIP")
set(CPACK_VERBATIM_VARIABLES ON)
include(CPack)
