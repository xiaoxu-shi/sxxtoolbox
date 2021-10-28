#ifndef __SXX_TEST_H__
#define __SXX_TEST_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"
#include "toolbox/sxx_mpool.h"

SXX_EXTERN_C_BEGIN

/** Opaque test suite declaration */
typedef struct sxx_test_suite_t sxx_test_suite_t;

/** Prototype of test function */
typedef sxx_bool_t (*sxx_test_f)(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[]);

/**
 * Create test suite.
 * @param pool the pool to allocate memory from
 * @param name the unique name of the test suite
 * @param obj the external object associated with the test suite
 * @param tester the test function to execute
 */
SXX_DECLARE(sxx_test_suite_t*)  sxx_test_suite_create(
    sxx_memory_pool_t *pool, const sxx_char_t *name,
    sxx_ptr_t obj, sxx_test_f tester);


/** Opaque test framework declaration */
typedef struct sxx_test_framework_t sxx_test_framework_t;

/**
 * Create test framework.
 */
SXX_DECLARE(sxx_test_framework_t*) sxx_test_framework_create(sxx_void_t);

/**
 * Destroy test framework.
 * @param framework the test framework to destroy
 */
SXX_DECLARE(sxx_void_t) sxx_test_framework_destroy(sxx_test_framework_t *framework);

/**
 * Add test suite to framework.
 * @param framework the test framework to add test suite to
 * @param suite the test suite to add
 */
SXX_DECLARE(sxx_status_t) sxx_test_framework_suite_add(sxx_test_framework_t *framework, sxx_test_suite_t *suite);

/**
 * Run test suites.
 * @param framework the test framework
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
SXX_DECLARE(sxx_status_t) sxx_test_framework_run(sxx_test_framework_t *framework, sxx_int32_t argc, sxx_char_t* argv[]);

/**
 * Retrieve the memory pool.
 * @param framework the test framework to retrieve memory pool from
 */
SXX_DECLARE(sxx_memory_pool_t*) sxx_test_framework_pool_get(const sxx_test_framework_t *framework);

SXX_EXTERN_C_END

#endif // ! __SXX_TEST_H__
