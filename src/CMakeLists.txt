
set(QT_MOC_HEADERS
    rpchandler.h
    systemlistmethodsrequest.h
    systemmethodhelprequest.h
    systemmethodsignaturerequest.h
    systemserverinforequest.h
    samuraiaccountstatementgetrequest.h
    samuraibalancegetrequest.h
    samuraiclientidentifyrequest.h
    samuraieventlistgetrequest.h
    samuraihistorygetbydaterequest.h
    samuraiitemizedentriesgetrequest.h
    samuraiownurilistgetrequest.h
    samuraiphonebookentrygetrequest.h
    samuraiphonebooklistgetrequest.h
    samurairecommendedintervalgetrequest.h
    samuraiserverdatagetrequest.h
    samuraisessioncloserequest.h
    samuraisessioninitiaterequest.h
    samuraisessioninitiatemultirequest.h
    samuraisessionstatusgetrequest.h
    samuraitoslistgetrequest.h
    samuraiumsummarygetrequest.h
    samuraiuserdatagreetinggetrequest.h
    samuraiuserdatasipgetrequest.h
    abstractrequest.h

    request.h
)

set(HEADERS
    ${QT_MOC_HEADERS}
    response.h
    rpcclientfactory.h
    samuraiaccountstatementgetresponse.h
    samuraibalancegetresponse.h
    samuraiclientidentifyresponse.h
    samuraieventlistgetresponse.h
    samuraihistorygetbydateresponse.h
    samuraiitemizedentriesgetresponse.h
    samuraiownurilistgetresponse.h
    samuraiphonebookentrygetresponse.h
    samuraiphonebooklistgetresponse.h
    samurairecommendedintervalgetresponse.h
    samuraiserverdatagetresponse.h
    samuraisessioncloseresponse.h
    samuraisessioninitiatemultiresponse.h
    samuraisessioninitiateresponse.h
    samuraisessionstatusgetresponse.h
    samuraitoslistgetresponse.h
    samuraiumsummarygetresponse.h
    samuraiuserdatagreetinggetresponse.h
    samuraiuserdatasipgetresponse.h
    systemlistmethodsresponse.h
    systemmethodhelpresponse.h
    systemmethodsignatureresponse.h
    systemserverinforesponse.h
)

set(QT_UI
)

set(QT_SRCS
    rpchandler.cpp
    rpcclientfactory.cpp
    abstractrequest.cpp
    systemlistmethodsrequest.cpp
    systemlistmethodsresponse.cpp
    systemmethodhelprequest.cpp
    systemmethodhelpresponse.cpp
    systemmethodsignaturerequest.cpp
    systemmethodsignatureresponse.cpp
    systemserverinforequest.cpp
    systemserverinforesponse.cpp
    samuraiaccountstatementgetrequest.cpp
    samuraiaccountstatementgetresponse.cpp
    samuraibalancegetrequest.cpp
    samuraibalancegetresponse.cpp
    samuraiclientidentifyrequest.cpp
    samuraiclientidentifyresponse.cpp
    samuraieventlistgetrequest.cpp
    samuraieventlistgetresponse.cpp
    samuraihistorygetbydaterequest.cpp
    samuraihistorygetbydateresponse.cpp
    samuraiitemizedentriesgetrequest.cpp
    samuraiitemizedentriesgetresponse.cpp
    samuraiownurilistgetrequest.cpp
    samuraiownurilistgetresponse.cpp
    samuraiphonebookentrygetrequest.cpp
    samuraiphonebookentrygetresponse.cpp
    samuraiphonebooklistgetrequest.cpp
    samuraiphonebooklistgetresponse.cpp
    samurairecommendedintervalgetrequest.cpp
    samurairecommendedintervalgetresponse.cpp
    samuraiserverdatagetrequest.cpp
    samuraiserverdatagetresponse.cpp
    samuraisessioncloserequest.cpp
    samuraisessioncloseresponse.cpp
    samuraisessioninitiaterequest.cpp
    samuraisessioninitiateresponse.cpp
    samuraisessioninitiatemultirequest.cpp
    samuraisessioninitiatemultiresponse.cpp
    samuraisessionstatusgetrequest.cpp
    samuraisessionstatusgetresponse.cpp
    samuraitoslistgetrequest.cpp
    samuraitoslistgetresponse.cpp
    samuraiumsummarygetrequest.cpp
    samuraiumsummarygetresponse.cpp
    samuraiuserdatagreetinggetrequest.cpp
    samuraiuserdatagreetinggetresponse.cpp
    samuraiuserdatasipgetrequest.cpp
    samuraiuserdatasipgetresponse.cpp

    request.cpp
    response.cpp
)

find_package(Qxt 0.6 REQUIRED QxtCore QxtNetwork)

find_package(Qt4 4.8 REQUIRED QtCore QtNetwork)
include(${QT_USE_FILE} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

include_directories(
  "${QXT_QXTCORE_INCLUDE_DIR}"
  "${QXT_QXTNETWORK_INCLUDE_DIR}"
  "${PROJECT_SOURCE_DIR}/src"
  "${PROJECT_BINARY_DIR}/src"
)

qt4_wrap_cpp(MOC_OUTFILES ${QT_MOC_HEADERS})

# Die ui_xxxx.h files werden im CMAKE_CURRENT_BINARY_DIR erzeugt.
#qt4_wrap_ui(UI_OUTFILES ${QT_UI})

add_library(qsipgaterpc STATIC ${QT_SRCS} ${MOC_OUTFILES}) # ${UI_OUTFILES}

set_target_properties(qsipgaterpc PROPERTIES
  PUBLIC_HEADER "${HEADERS};${CMAKE_CURRENT_BINARY_DIR}/config.h")
  
install(TARGETS qsipgaterpc
  # IMPORTANT: Add the qsipgaterpc library to the "export-set"
  EXPORT QsipgateRpcTargets
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT dev
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}" COMPONENT dev)
  
