
set(QT_MOC_HEADERS
    rpchandler.h
    systemlistmethodsrequest.h
    systemmethodhelprequest.h
    systemmethodsignaturerequest.h
    abstractrequest.h
)

set(QT_UI
)

set(QT_SRCS
    rpchandler.cpp
    abstractrequest.cpp
    systemlistmethodsrequest.cpp
    systemlistmethodsresponse.cpp
    systemmethodhelprequest.cpp
    systemmethodhelpresponse.cpp
    systemmethodsignaturerequest.cpp
    systemmethodsignatureresponse.cpp
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

qt4_wrap_cpp(MOC_OUTFILES ${QT_MOC_HEADERS})

# Die ui_xxxx.h files werden im CMAKE_CURRENT_BINARY_DIR erzeugt.
#qt4_wrap_ui(UI_OUTFILES ${QT_UI})

add_library(sipgateRpcLib STATIC ${QT_SRCS} ${MOC_OUTFILES}) # ${UI_OUTFILES}
