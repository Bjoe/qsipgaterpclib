
if(CMAKE_CROSSCOMPILING)
    include(Coverage)
endif(CMAKE_CROSSCOMPILING)

find_package(GTest) # Required by gmock
find_package(GMock REQUIRED)
find_package(QtTestUtil)

find_package(Qt4 4.8.1  REQUIRED QtTest)
include(${QT_USE_FILE})

set(CERTIFICATE "${PROJECT_SOURCE_DIR}/secure.sipgate.de.pem")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/testconfig.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/testconfig.h"
  )

include_directories(
    ../src
    ${CMAKE_CURRENT_BINARY_DIR}/../src
    ${QT_TEST_UTIL_INCLUDE_DIR}
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

set(test_additional_lib
    sipgateRpcLib
    ${QT_TEST_UTIL_LIBRARIES}
    ${QXT_QXTCORE_LIB_RELEASE}
    ${QXT_QXTNETWORK_LIB_RELEASE}
    ${GMOCK_BOTH_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
)

#set(test_additional
#    foo.cpp
#)

qt4_add_test(rpcclientfactory rpcclientfactorytest.cpp)
qt4_add_test(rpchandler rpchandlertest.cpp)
qt4_test(abstractrequest abstractrequesttest.cpp)

qt4_test(systemlistmethodsrequest systemlistmethodsrequesttest.cpp)
qt4_add_test(systemlistmethodsresponse systemlistmethodsresponsetest.cpp)

qt4_test(systemmethodhelprequest systemmethodhelprequesttest.cpp)
qt4_test(systemmethodhelpresponse systemmethodhelpresponsetest.cpp)

qt4_test(systemmethodsignaturerequest systemmethodsignaturerequesttest.cpp)
qt4_test(systemmethodsignatureresponse systemmethodsignatureresponsetest.cpp)

qt4_test(systemserverinforequest systemserverinforequesttest.cpp)
qt4_test(systemserverinforesponse systemserverinforesponsetest.cpp)

qt4_test(samuraiaccountstatementgetrequest samuraiaccountstatementgetrequesttest.cpp)
qt4_test(samuraiaccountstatementgetresponse samuraiaccountstatementgetresponsetest.cpp)

qt4_wrap_cpp(MOC_OUTFILES output.h)
add_executable(sipgateRpcTest maintest.cpp output.cpp ${MOC_OUTFILES})
target_link_libraries(sipgateRpcTest sipgateRpcLib ${QT_LIBRARIES} ${QXT_QXTCORE_LIB_RELEASE} ${QXT_QXTNETWORK_LIB_RELEASE})
