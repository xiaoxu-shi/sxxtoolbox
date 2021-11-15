#include "sxx_toolbox.h"

typedef sxx_int32_t (*sxx_test_dso_add_f)(sxx_int32_t n1, sxx_int32_t n2);

sxx_bool_t sxx_tester_dso(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_dso_handle_t *dh = NULL;
    sxx_test_dso_add_f add_f = NULL;

    sxx_assert_return_val(sxx_dso_create(sxx_test_suite_pool_get(suite), "./libsxxtestdso.dylib", &dh) == SXX_SUCCESS, SXX_FALSE);

    sxx_assert_return_val(sxx_dso_sym(dh, "sxx_test_dso_add", (sxx_dso_sym_t*)&add_f) == SXX_SUCCESS, SXX_FALSE);

    sxx_assert_return_val(add_f(1, 2) == 3, SXX_FALSE);

    return SXX_TRUE;
}


