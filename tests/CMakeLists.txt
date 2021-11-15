CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolboxtest)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/../include" 
)

set(CMAKE_BUILD_TYPE DEBUG)

set(TOOLBOX_TEST_DSO_SOURCE
    so/test_dso_so.h
    so/test_dso_so.c
)

set(TOOLBOX_TEST_SOURCE
    main.c
    test_dso.c
    test_list.c
    test_atomic.c
    test_string.c
    test_memory_pool.c
)

add_library(sxxtestdso SHARED ${TOOLBOX_TEST_DSO_SOURCE})
target_link_libraries(sxxtestdso sxxtoolbox)

add_executable(${PROJECT_NAME} ${TOOLBOX_TEST_SOURCE})
target_link_libraries(${PROJECT_NAME} sxxtoolbox sxxtestdso)

