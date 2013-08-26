
if(CMAKE_CROSSCOMPILING)
    include(Coverage)
endif(CMAKE_CROSSCOMPILING)

find_package(GTest) # Required by gmock
find_package(GMock)
find_package(QtTestUtil)
find_package(Threads)

find_package(Qxt 0.6 REQUIRED QxtCore QxtNetwork)

find_package(Qt4 4.8 REQUIRED QtCore QtNetwork QtTest QtGui)
include(${QT_USE_FILE} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

set(CERTIFICATE "${PROJECT_SOURCE_DIR}/secure.sipgate.de.pem")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/testconfig.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/testconfig.h"
  )

include_directories(
    "../src"
    "${CMAKE_CURRENT_BINARY_DIR}/../src"
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${QT_TEST_UTIL_INCLUDE_DIRS}"
    "${GTEST_INCLUDE_DIRS}"
    "${GMOCK_INCLUDE_DIRS}"
    "${QXT_QXTCORE_INCLUDE_DIR}"
    "${QXT_QXTNETWORK_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_BINARY_DIR}/src"
)

set(test_additional_lib
    ${CMAKE_THREAD_LIBS_INIT}
    ${QT_TEST_UTIL_LIBRARIES}
    ${QXT_QXTCORE_LIB_RELEASE}
    ${QXT_QXTNETWORK_LIB_RELEASE}
    ${GMOCK_BOTH_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
    qsipgaterpc
)

#set(test_additional
#    foo.cpp
#)

qt_add_test(rpcclientfactory rpcclientfactorytest.cpp)
qt_add_test(rpchandler rpchandlertest.cpp)
qt_test(abstractrequest abstractrequesttest.cpp)

qt_test(systemlistmethodsrequest systemlistmethodsrequesttest.cpp)
qt_add_test(systemlistmethodsresponse systemlistmethodsresponsetest.cpp)

qt_test(systemmethodhelprequest systemmethodhelprequesttest.cpp)
qt_test(systemmethodhelpresponse systemmethodhelpresponsetest.cpp)

qt_test(systemmethodsignaturerequest systemmethodsignaturerequesttest.cpp)
qt_test(systemmethodsignatureresponse systemmethodsignatureresponsetest.cpp)

qt_test(systemserverinforequest systemserverinforequesttest.cpp)
qt_test(systemserverinforesponse systemserverinforesponsetest.cpp)

qt_test(samuraiaccountstatementgetrequest samuraiaccountstatementgetrequesttest.cpp)
qt_test(samuraiaccountstatementgetresponse samuraiaccountstatementgetresponsetest.cpp)

qt_test(samuraibalancegetrequest samuraibalancegetrequesttest.cpp)
qt_test(samuraibalancegetresponse samuraibalancegetresponsetest.cpp)

qt_test(samuraiclientidentifyrequest samuraiclientidentifyrequesttest.cpp)
qt_test(samuraiclientidentifyresponse samuraiclientidentifyresponsetest.cpp)

qt_test(samuraieventlistgetrequest samuraieventlistgetrequesttest.cpp)
qt_test(samuraieventlistgetresponse samuraieventlistgetresponsetest.cpp)

qt_test(samuraihistorygetbydaterequest samuraihistorygetbydaterequesttest.cpp)
qt_test(samuraihistorygetbydateresponse samuraihistorygetbydateresponsetest.cpp)

qt_test(samuraiitemizedentriesgetrequest samuraiitemizedentriesgetrequesttest.cpp)
qt_test(samuraiitemizedentriesgetresponse samuraiitemizedentriesgetresponsetest.cpp)

qt_test(samuraiownurilistgetrequest samuraiownurilistgetrequesttest.cpp)
qt_test(samuraiownurilistgetresponse samuraiownurilistgetresponsetest.cpp)

qt_test(samuraiphonebookentrygetrequest samuraiphonebookentrygetrequesttest.cpp)
qt_test(samuraiphonebookentrygetresponse samuraiphonebookentrygetresponsetest.cpp)

qt_test(samuraiphonebooklistgetrequest samuraiphonebooklistgetrequesttest.cpp)
qt_test(samuraiphonebooklistgetresponse samuraiphonebooklistgetresponsetest.cpp)

qt_test(samurairecommendedintervalgetrequest samurairecommendedintervalgetrequesttest.cpp)
qt_test(samurairecommendedintervalgetresponse samurairecommendedintervalgetresponsetest.cpp)

qt_test(samuraiserverdatagetrequest samuraiserverdatagetrequesttest.cpp)
qt_test(samuraiserverdatagetresponse samuraiserverdatagetresponsetest.cpp)

qt_test(samuraisessioncloserequest samuraisessioncloserequesttest.cpp)
qt_test(samuraisessioncloseresponse samuraisessioncloseresponsetest.cpp)

qt_test(samuraisessioninitiaterequest samuraisessioninitiaterequesttest.cpp)
qt_test(samuraisessioninitiateresponse samuraisessioninitiateresponsetest.cpp)

qt_test(samuraisessioninitiatemultirequest samuraisessioninitiatemultirequesttest.cpp)
qt_test(samuraisessioninitiatemultiresponse samuraisessioninitiatemultiresponsetest.cpp)

qt_test(samuraisessionstatusgetrequest samuraisessionstatusgetrequesttest.cpp)
qt_test(samuraisessionstatusgetresponse samuraisessionstatusgetresponsetest.cpp)

qt_test(samuraitoslistgetrequest samuraitoslistgetrequesttest.cpp)
qt_test(samuraitoslistgetresponse samuraitoslistgetresponsetest.cpp)

qt_test(samuraiumsummarygetrequest samuraiumsummarygetrequesttest.cpp)
qt_test(samuraiumsummarygetresponse samuraiumsummarygetresponsetest.cpp)

qt_test(samuraiuserdatagreetinggetrequest samuraiuserdatagreetinggetrequesttest.cpp)
qt_test(samuraiuserdatagreetinggetresponse samuraiuserdatagreetinggetresponsetest.cpp)

qt_test(samuraiuserdatasipgetrequest samuraiuserdatasipgetrequesttest.cpp)
qt_test(samuraiuserdatasipgetresponse samuraiuserdatasipgetresponsetest.cpp)

qt_test(request requesttest.cpp)
qt_test(response responsetest.cpp)

qt4_wrap_cpp(MOC_OUTFILES output.h mainwindow.h)
qt4_wrap_ui(UI_OUTFILES mainwindow.ui)

add_executable(qsipgaterpctest maintest.cpp output.cpp mainwindow.cpp ${MOC_OUTFILES} ${UI_OUTFILES})
target_link_libraries(qsipgaterpctest qsipgaterpc ${QT_LIBRARIES} ${QXT_QXTCORE_LIB_RELEASE} ${QXT_QXTNETWORK_LIB_RELEASE})
