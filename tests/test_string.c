#include "sxx_toolbox.h"

static sxx_bool_t sxx_tester_string_empty(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_lenght(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_buffer(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_set(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_null(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]); 
static sxx_bool_t sxx_tester_string_set_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_assign(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_assign_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t ssx_tester_string_dup(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);
static sxx_bool_t sxx_tester_string_dup_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[]);


sxx_bool_t sxx_tester_string(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_assert_return_val(sxx_tester_string_empty(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_lenght(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_buffer(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_set(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_null(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_set_cstr(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_assign_cstr(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(ssx_tester_string_dup(suite, argc, argv), SXX_FALSE);
    sxx_assert_return_val(sxx_tester_string_dup_cstr(suite, argc, argv), SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_empty(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_lenght(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_buffer(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_set(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_null(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_set_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_assign(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_assign_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t ssx_tester_string_dup(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_dup_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    return SXX_TRUE;
}

