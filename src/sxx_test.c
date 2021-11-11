#include "sxx_test.h"
#include "sxx_cstr.h"
#include "sxx_string.h"
#include "sxx_list.h"

struct sxx_test_suite_t {
	sxx_memory_pool_t *pool;
	sxx_string_t name;
	sxx_ptr_t   obj;
    sxx_test_f  tester;
};
typedef struct sxx_test_suite_t sxx_test_suite_t;

struct sxx_test_list_t {
    SXX_LIST_MEMBER;
    sxx_test_suite_t* sutite;
};
typedef struct sxx_test_list_t sxx_test_list_t;

struct sxx_test_framework_t
{
    sxx_memory_pool_t*  pool;
    sxx_test_list_t     list;
};
typedef struct sxx_test_framework_t sxx_test_framework_t;


SXX_DECLARE(sxx_test_suite_t*)  sxx_test_suite_create(
    sxx_memory_pool_t *pool, const sxx_char_t *name,
    sxx_ptr_t obj, sxx_test_f tester)
{
    return NULL;
}


SXX_DECLARE(sxx_test_framework_t*) sxx_test_framework_create(sxx_void_t)
{
    sxx_memory_pool_t* pool = NULL;
    sxx_test_framework_t* framework = NULL;

    pool = sxx_memory_pool_create(0);
    sxx_assert(pool);
    if (pool == NULL) {
        return framework;
    }

    framework = sxx_memory_calloc(pool, sxx_sizeof(sxx_test_framework_t));
    sxx_assert(framework);
    if (framework == NULL) {
        sxx_memory_pool_distory(pool);
        return framework;
    }

    framework->pool = pool;
    sxx_list_init((sxx_ptr_t)&framework->list);

    return framework;
}


SXX_DECLARE(sxx_void_t) sxx_test_framework_destroy(sxx_test_framework_t *framework)
{
    sxx_assert(framework);
    sxx_assert(framework->pool);
    sxx_memory_pool_distory(framework->pool);
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
    sxx_assert(framework);
    sxx_assert(framework->pool);
    return framework->pool;
}

