
if(MITK_USE_Qt4) # only if MITK is built with Qt 4

project(QtSingleApplication)

set(_MOC_HEADERS
  qtlocalpeer.h
  qtsingleapplication.h
  qtsinglecoreapplication.h
)

set(_HEADERS
  qthandlenewappinstance.h
  qtlockedfile.h
)

set(_SOURCES
  qthandlenewappinstance.cpp
  qtlocalpeer.cpp
  qtsingleapplication.cpp
  qtsinglecoreapplication.cpp
)

find_package(Qt4 REQUIRED)
set(QT_USE_QTNETWORK 1)
include(${QT_USE_FILE})

qt4_wrap_cpp(_SOURCES ${_MOC_HEADERS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(qtsingleapplication STATIC ${_SOURCES})
target_link_libraries(qtsingleapplication ${QT_LIBRARIES})

MITK_CREATE_MODULE_CONF(qtsingleapplication
  INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
  PACKAGE_DEPENDS Qt4|QtNetwork+QtGui)

endif(MITK_USE_Qt4) # only if MITK is built with Qt 4
