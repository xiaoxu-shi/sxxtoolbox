CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolbox)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    # SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/darwin")
    # SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/arch/darwin")
    set(CMAKE_MACOSX_RPATH 1)
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/linux")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/arch/linux")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-D _CRT_SECURE_NO_WARNINGS)
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/win32")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/arch/win32")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/linux")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/arch/linux")
endif ()

OPTION(SXX_STATIC_LIB "build static library" ON)

SET(CMAKE_BUILD_TYPE DEBUG)

#message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
#message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
#message("TOOLBOX_ARCH_INCLUDE_DIR : ${TOOLBOX_ARCH_INCLUDE_DIR}")
#message("TOOLBOX_ARCH_SOURCE_DIR : ${TOOLBOX_ARCH_SOURCE_DIR}")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox" 
    "${TOOLBOX_ARCH_INCLUDE_DIR}" 
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
    

    ${TOOLBOX_ARCH_INCLUDE_DIR}/sxx_arch_dso.h
    ${TOOLBOX_ARCH_INCLUDE_DIR}/sxx_arch_mutex.h
    ${TOOLBOX_ARCH_INCLUDE_DIR}/sxx_arch_atomic.h
)

SET(TOOLBOX_SOURCE
    ${TOOLBOX_ARCH_SOURCE_DIR}/sxx_arch_dso.c
    ${TOOLBOX_ARCH_SOURCE_DIR}/sxx_arch_mutex.c
    ${TOOLBOX_ARCH_SOURCE_DIR}/sxx_arch_atomic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_alloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_test.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_cstr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_string.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_memory_pool.c
)

if (${SXX_STATIC_LIB} STREQUAL "ON")
    add_definitions(-DSXX_STATIC_LIB)
    add_library(${PROJECT_NAME} STATIC ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
else()
    add_definitions(-DSXX_DYNAMIC_LIB)
    add_library(${PROJECT_NAME} SHARED ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
endif()

add_subdirectory(tests)
