INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_CUSTOMMODULE customModule)

FIND_PATH(
    CUSTOMMODULE_INCLUDE_DIRS
    NAMES customModule/api.h
    HINTS $ENV{CUSTOMMODULE_DIR}/include
        ${PC_CUSTOMMODULE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    CUSTOMMODULE_LIBRARIES
    NAMES gnuradio-customModule
    HINTS $ENV{CUSTOMMODULE_DIR}/lib
        ${PC_CUSTOMMODULE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/customModuleTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CUSTOMMODULE DEFAULT_MSG CUSTOMMODULE_LIBRARIES CUSTOMMODULE_INCLUDE_DIRS)
MARK_AS_ADVANCED(CUSTOMMODULE_LIBRARIES CUSTOMMODULE_INCLUDE_DIRS)
