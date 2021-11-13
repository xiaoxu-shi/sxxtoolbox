#include <stdio.h>
#include <sxx_toolbox.h>

sxx_bool_t sxx_tester_list(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[]);
sxx_bool_t sxx_tester_atomic(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
sxx_bool_t sxx_tester_memory_pool(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[]);

int main(int argc, char* argv[]) {
    sxx_test_framework_t *framework = sxx_test_framework_create();
    sxx_memory_pool_t *pool = sxx_test_framework_pool_get(framework);

    sxx_test_suite_t *list = sxx_test_suite_create(pool, "tester_list", NULL, sxx_tester_list);
    sxx_test_suite_t* atomic = sxx_test_suite_create(pool, "tester_atomic", NULL, sxx_tester_atomic);
    sxx_test_suite_t *mpool = sxx_test_suite_create(pool, "tester_memory_pool", NULL, sxx_tester_memory_pool);

    sxx_test_framework_suite_add(framework, list);
    sxx_test_framework_suite_add(framework, atomic);
    sxx_test_framework_suite_add(framework, mpool);

    sxx_test_framework_run(framework, argc, argv);

    sxx_test_framework_destroy(framework);

    return 0;
}
