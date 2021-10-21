CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolbox)

if (MACOS)
    message("configure macos include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/macos")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/macos")
elseif (WINDOWS)
    message("configure win32 include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/win32")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/win32")
elseif (LINUX)
    message("configure linux include directory!")
    SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/linux")
    SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/linux")
endif ()

SET(TOOLBOX_ARCH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/arch/win32")
SET(TOOLBOX_ARCH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/win32")

message("TOOLBOX_ARCH_INCLUDE_DIR : ${TOOLBOX_ARCH_INCLUDE_DIR}")
message("TOOLBOX_ARCH_SOURCE_DIR : ${TOOLBOX_ARCH_SOURCE_DIR}")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox" 
    "${TOOLBOX_ARCH_INCLUDE_DIR}" 
)

SET(TOOLBOX_HANDLERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/defs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/toolbox/dso.h
    ${TOOLBOX_ARCH_INCLUDE_DIR}/sxx_arch_dso.h
)

SET(TOOLBOX_SOURCE
    ${TOOLBOX_ARCH_SOURCE_DIR}/dso.c
)

add_library(${PROJECT_NAME} STATIC ${TOOLBOX_HANDLERS} ${TOOLBOX_SOURCE})
