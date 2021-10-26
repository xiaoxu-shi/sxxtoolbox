CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolbox)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message("configure darwin include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/darwin")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/darwin")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("configure win32 include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/win32")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/win32")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("configure linux include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/linux")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/linux")
endif ()

message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("TOOLBOX_ARCH_INCLUDE_DIR : ${TOOLBOX_ARCH_INCLUDE_DIR}")
message("TOOLBOX_ARCH_SOURCE_DIR : ${TOOLBOX_ARCH_SOURCE_DIR}")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox" 
    "${TOOLBOX_ARCH_INCLUDE_DIR}" 
)

SET(TOOLBOX_HANDLERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_defs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_dso.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_alloc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/sxx_mpool.h
    ${TOOLBOX_ARCH_INCLUDE_DIR}/sxx_arch_dso.h
)

SET(TOOLBOX_SOURCE
    ${TOOLBOX_ARCH_SOURCE_DIR}/sxx_dso.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_alloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sxx_mpool.c
)

add_library(${PROJECT_NAME} STATIC ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
