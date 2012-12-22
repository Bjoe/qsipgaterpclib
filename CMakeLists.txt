project(QSipgateRpcLib)
cmake_minimum_required(VERSION 2.8)

include(QtBuildUtil)

# The version number.
set (Project_VERSION_MAJOR 0)
set (Project_VERSION_MINOR 1)
set (Project_VERSION_PATCH 0)

find_package(Qt4 4.8.1 REQUIRED QtCore QtNetwork)
find_package(Qxt 0.6 REQUIRED QxtCore QxtNetwork)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${QXT_QXTCORE_INCLUDE_DIR} ${QXT_QXTNETWORK_INCLUDE_DIR})

include(${QT_USE_FILE} )

find_doxygen()

add_subdirectory(src)

set(NOTEST "false" CACHE BOOL "Without tests")
if(NOT ${NOTEST})
    # The following are required to uses CTest, Dart and the Cdash dashboard
    enable_testing(true)
    include(CTest)
    add_subdirectory(tests)
endif(NOT ${NOTEST})
