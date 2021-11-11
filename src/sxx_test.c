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


SXX_DECLARE(sxx_test_suite_t*)  sxx_test_suite_create(
    sxx_memory_pool_t *pool, const sxx_char_t *name,
    sxx_ptr_t obj, sxx_test_f tester)
{
    sxx_assert(pool);
    sxx_assert(tester);

    sxx_test_suite_t* suite = NULL;

    suite = sxx_memory_calloc(pool, sxx_sizeof(sxx_test_suite_t));
    sxx_assert(suite);
    suite->pool = pool;
    suite->obj = obj;
    suite->tester = tester;
    if (sxx_string_assign_1(pool, &suite->name, (sxx_char_t*)name) == NULL) {
        return NULL;
    }

    return suite;
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
    sxx_assert(framework);
    sxx_assert(suite);
    sxx_test_list_t* node = NULL;

    node = sxx_memory_alloc(framework->pool, sxx_sizeof(sxx_test_list_t));
    sxx_assert(node);
    if (node == NULL) {
        return SXX_ERROR;
    }

    node->sutite = suite;

    sxx_list_push_back(&framework->list, node);

    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_bool_t) sxx_test_framework_run(sxx_test_framework_t *framework, sxx_int32_t argc, sxx_char_t* argv[])
{
    sxx_assert(framework);

    sxx_list_ptr_t it = framework->list.next;
    while (it != SXX_LIST_OBJECT_PTR(&framework->list)) {
        sxx_test_list_t* node = (sxx_test_list_t *)it;
        if (node->sutite && node->sutite->tester) {
            if (node->sutite->tester(node->sutite, argc, argv) != SXX_TRUE) {
                return SXX_ERROR;
            }
        }
        it = it->next;
    }

    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_memory_pool_t*) sxx_test_framework_pool_get(const sxx_test_framework_t *framework)
{
    sxx_assert(framework);
    sxx_assert(framework->pool);
    return framework->pool;
}

