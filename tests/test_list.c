#include <sxx_toolbox.h>

struct sxx_list_tester_node_t {
    SXX_LIST_MEMBER;
    sxx_int32_t value;
};
typedef struct sxx_list_tester_node_t sxx_list_tester_node_t;

static sxx_bool_t sxx_list_tester_empty(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);




sxx_bool_t sxx_list_tester(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[])
{
    if (sxx_list_tester_empty(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }
    return SXX_TRUE;
}

static sxx_bool_t sxx_list_tester_empty(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t list;
    sxx_list_init(&list);

    if (sxx_list_empty(&list) != SXX_TRUE) {
        return SXX_FALSE;
    }

    sxx_list_tester_node_t* node = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    node->value = 0;
    sxx_list_push_back(&list, node);

    if (sxx_list_empty(&list) == SXX_TRUE) {
        return SXX_FALSE;
    }

    return SXX_TRUE;
}
