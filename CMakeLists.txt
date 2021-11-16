CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolbox)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    SET(CMAKE_MACOSX_RPATH 1)
    SET(SXX_TOOLBOX_ARCH_NAME "sxx_posix")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-D _CRT_SECURE_NO_WARNINGS)
    SET(SXX_TOOLBOX_ARCH_NAME "sxx_win32")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    SET(SXX_TOOLBOX_ARCH_NAME "sxx_posix")
endif ()

OPTION(SXX_STATIC_LIB "build static library" ON)

SET(CMAKE_BUILD_TYPE DEBUG)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox" 
)

SET(TOOLBOX_HANDLERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/sxx_toolbox.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_defs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_assert.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_cstr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_string.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_alloc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_test.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_memory_pool.h
 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_dso.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_mutex.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_atomic.h
)

SET(TOOLBOX_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_alloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_test.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_cstr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_string.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_memory_pool.c

    ${CMAKE_CURRENT_SOURCE_DIR}/src/dso/${SXX_TOOLBOX_ARCH_NAME}_dso.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mutex/${SXX_TOOLBOX_ARCH_NAME}_mutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/atomic/${SXX_TOOLBOX_ARCH_NAME}_atomic.c
)

if (${SXX_STATIC_LIB} STREQUAL "ON")
    add_definitions(-DSXX_STATIC_LIB)
    add_library(${PROJECT_NAME} STATIC ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
else()
    add_definitions(-DSXX_DYNAMIC_LIB)
    add_library(${PROJECT_NAME} SHARED ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
endif()

if (${SXX_TOOLBOX_ARCH_NAME} STREQUAL "sxx_posix")
    target_link_libraries(${PROJECT_NAME} dl pthread)
endif()

add_subdirectory(tests)
