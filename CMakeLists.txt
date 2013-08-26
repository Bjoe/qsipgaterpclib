cmake_minimum_required(VERSION 2.8.9)

project(QSipgateRpcLib)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" CACHE PATH "cmake modul path") 
include(BuildUtil)

# The version number.
set(QSIPGATERPC_VERSION_MAJOR 0)
set(QSIPGATERPC_VERSION_MINOR 1)
set(QSIPGATERPC_VERSION_PATCH 0)
set(QSIPGATERPC_VERSION ${QSIPGATERPC_VERSION_MAJOR}.${QSIPGATERPC_VERSION_MINOR}.${QSIPGATERPC_VERSION_PATCH})

# http://www.cmake.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file
# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/QsipgateRpc)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()


if(${DOC})
  find_doxygen()
endif(${DOC})

add_definitions(-fPIC)

add_subdirectory(src)

if(${TEST})
    # The following are required to uses CTest, Dart and the Cdash dashboard
    enable_testing(true)
    include(CTest)
    add_subdirectory(tests)
endif(${TEST})

# Add all targets to the build-tree export set
export(TARGETS qsipgaterpc
  FILE "${PROJECT_BINARY_DIR}/QsipgateRpcTargets.cmake")
 
# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE QsipgateRpc)
 
# Create the QpjSipConfig.cmake and QpjSipConfigVersion files
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}")
configure_file(QsipgateRpcConfig.cmake.in
  "${PROJECT_BINARY_DIR}/QsipgateRpcConfig.cmake" @ONLY)

# ... for the install tree
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
set(CONF_INCLUDE_DIRS "\${QSIPGATERPC_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(QsipgateRpcConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/QsipgateRpcConfig.cmake" @ONLY)

# ... for both
configure_file(QsipgateRpcConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/QsipgateRpcConfigVersion.cmake" @ONLY)
 
# Install the QpjSipConfig.cmake and QpjSipConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/QsipgateRpcConfig.cmake"
  "${PROJECT_BINARY_DIR}/QsipgateRpcConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
 
# Install the export set for use with the install-tree
install(EXPORT QsipgateRpcTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)
