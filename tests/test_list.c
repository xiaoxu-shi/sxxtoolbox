#include <sxx_toolbox.h>

struct sxx_list_tester_node_t {
    SXX_LIST_MEMBER;
    sxx_int32_t value;
};
typedef struct sxx_list_tester_node_t sxx_list_tester_node_t;

static sxx_bool_t sxx_tester_list_empty(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_insert_before(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_insert_after(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_insert_nodes_before(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_insert_nodes_after(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_push_back(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_push_front(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_list_merge_first(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);


sxx_bool_t sxx_tester_list(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[])
{
    if (sxx_tester_list_empty(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_insert_before(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_insert_after(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_insert_nodes_before(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_insert_nodes_after(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_push_back(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_push_front(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    if (sxx_tester_list_merge_first(suite, argc, argv) != SXX_TRUE) {
        return SXX_FALSE;
    }

    return SXX_TRUE;
}

/**
 * Verification list value, must start with zero and in ascending order.
 * @param lst the to be list verified
 */
static sxx_inline sxx_bool_t sxx_tester_list_verification(sxx_list_tester_node_t* lst) {
    sxx_int32_t index = 0;

    if (sxx_list_empty(lst)) {
        return SXX_FALSE;
    }

    sxx_list_ptr_t it = lst->next;
    while (it != SXX_LIST_OBJECT_PTR(lst)) {
        sxx_list_tester_node_t* n = (sxx_list_tester_node_t*)it;
        //sxx_printf("%d\n", n->value);
        if (n->value != index) {
            return SXX_FALSE;
        }
        it = it->next;
        index++;
    }

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_list_empty(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
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

static sxx_bool_t sxx_tester_list_insert_before(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t list;
    sxx_list_init(&list);

    sxx_list_tester_node_t* node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node0->value = 2;
    node1->value = 1;
    node2->value = 0;

    sxx_list_insert_before(&list, node0);
    sxx_list_insert_before(node0, node1);
    sxx_list_insert_before(node1, node2);

    return sxx_tester_list_verification(&list);
}

static sxx_bool_t sxx_tester_list_insert_after(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t list;
    sxx_list_init(&list);

    sxx_list_tester_node_t* node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node0->value = 0;
    node1->value = 1;
    node2->value = 2;

    sxx_list_insert_after(&list, node0);
    sxx_list_insert_after(node0, node1);
    sxx_list_insert_after(node1, node2);

    return sxx_tester_list_verification(&list);
}

static sxx_bool_t sxx_tester_list_insert_nodes_before(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t* list = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    sxx_list_tester_node_t* node = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node->value = 3;
    nodes0->value = 0;
    nodes1->value = 1;
    nodes2->value = 2;

    sxx_list_init(list);
    sxx_list_insert_after(list, node);

    sxx_list_init(nodes0);
    sxx_list_insert_after(nodes0, nodes1);
    sxx_list_insert_after(nodes1, nodes2);

    sxx_list_insert_nodes_before(node, nodes0);

    return sxx_tester_list_verification(list);
}

static sxx_bool_t sxx_tester_list_insert_nodes_after(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t* list = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    sxx_list_tester_node_t* node = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* nodes2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node->value = 0;
    nodes0->value = 1;
    nodes1->value = 2;
    nodes2->value = 3;

    sxx_list_init(list);
    sxx_list_insert_after(list, node);

    sxx_list_init(nodes0);
    sxx_list_insert_after(nodes0, nodes1);
    sxx_list_insert_after(nodes1, nodes2);

    sxx_list_insert_nodes_after(node, nodes0);

    return sxx_tester_list_verification(list);
}

static sxx_bool_t sxx_tester_list_push_back(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
    sxx_list_tester_node_t* list = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node0->value = 0;
    node1->value = 1;
    node2->value = 2;

    sxx_list_init(list);
    sxx_list_push_back(list, node0);
    sxx_list_push_back(list, node1);
    sxx_list_push_back(list, node2);

    return sxx_tester_list_verification(list);
}

static sxx_bool_t sxx_tester_list_push_front(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
    sxx_list_tester_node_t* list = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* node2 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    node0->value = 0;
    node1->value = 1;
    node2->value = 2;

    sxx_list_init(list);
    sxx_list_push_front(list, node2);
    sxx_list_push_front(list, node1);
    sxx_list_push_front(list, node0);

    return sxx_tester_list_verification(list);
}

static sxx_bool_t sxx_tester_list_merge_first(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]) {
    sxx_list_tester_node_t* lst0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* lst1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* lst0node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* lst0node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* lst1node0 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));
    sxx_list_tester_node_t* lst1node1 = sxx_memory_alloc(sxx_test_suite_pool_get(suite), sxx_sizeof(sxx_list_tester_node_t));

    lst0node0->value = 2;
    lst0node1->value = 3;
    lst1node0->value = 0;
    lst1node1->value = 1;

    sxx_list_init(lst0);
    sxx_list_init(lst1);

    sxx_list_push_back(lst0, lst0node0);
    sxx_list_push_back(lst0, lst0node1);
    sxx_list_push_back(lst1, lst1node0);
    sxx_list_push_back(lst1, lst1node1);

    sxx_list_merge_first(lst0, lst1);

    return sxx_tester_list_verification(lst0);
}
