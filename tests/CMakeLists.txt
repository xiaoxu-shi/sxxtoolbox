CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

PROJECT(sxxtoolboxtest)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/../include" 
)

set(CMAKE_BUILD_TYPE DEBUG)

message(${CMAKE_CURRENT_SOURCE_DIR})

set(TOOLBOX_TEST_SOURCE
    main.c
    test_list.c
    test_atomic.c
    test_memory_pool.c
)

add_executable(${PROJECT_NAME} ${TOOLBOX_TEST_SOURCE})

target_link_libraries(${PROJECT_NAME} sxxtoolbox)
