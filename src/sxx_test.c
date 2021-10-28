#include "sxx_test.h"
#include "sxx_string.h"

struct sxx_test_suite_t {
	sxx_memory_pool_t *pool;
	sxx_string_t name;
	sxx_ptr_t   obj;
    sxx_test_f  tester;
};

struct sxx_test_framework_t
{
    sxx_memory_pool_t *pool;
    //sxx_list_t *suite;
};


SXX_DECLARE(sxx_test_suite_t*)  sxx_test_suite_create(
    sxx_memory_pool_t *pool, const sxx_char_t *name,
    sxx_ptr_t obj, sxx_test_f tester)
{
    return NULL;
}


SXX_DECLARE(sxx_test_framework_t*) sxx_test_framework_create(sxx_void_t)
{
    return NULL;
}


SXX_DECLARE(sxx_void_t) sxx_test_framework_destroy(sxx_test_framework_t *framework)
{

}


SXX_DECLARE(sxx_bool_t) sxx_test_framework_suite_add(sxx_test_framework_t *framework, sxx_test_suite_t *suite)
{
    return SXX_ERROR;
}


SXX_DECLARE(sxx_bool_t) sxx_test_framework_run(sxx_test_framework_t *framework, sxx_int32_t argc, sxx_char_t* argv[])
{
    return SXX_ERROR;
}


SXX_DECLARE(sxx_memory_pool_t*) sxx_test_framework_pool_get(const sxx_test_framework_t *framework)
{
    return framework->pool;
}

