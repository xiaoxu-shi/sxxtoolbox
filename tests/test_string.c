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
    sxx_assert_return_val(sxx_tester_string_null(suite, argc, argv), SXX_FALSE);
    sxx_assert_return_val(sxx_tester_string_empty(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_buffer(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_set(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_set_cstr(suite, argc, argv), SXX_FALSE);
    sxx_assert_return_val(sxx_tester_string_assign(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_string_assign_cstr(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(ssx_tester_string_dup(suite, argc, argv), SXX_FALSE);
    sxx_assert_return_val(sxx_tester_string_dup_cstr(suite, argc, argv), SXX_FALSE);
    sxx_assert_return_val(sxx_tester_string_lenght(suite, argc, argv), SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_empty(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str;
    sxx_string_null(&str);

    sxx_assert_return_val(sxx_string_empty(&str), SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_lenght(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str;

    sxx_string_null(&str);
    sxx_assert_return_val(sxx_string_lenght(&str) == 0, SXX_FALSE);

    sxx_string_set_cstr(&str, "xiaoxu.shi");
    sxx_assert_return_val(sxx_string_lenght(&str) == sxx_strlen("xiaoxu.shi"), SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_buffer(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str;

    sxx_string_null(&str);
    sxx_assert_return_val(sxx_string_buffer(&str) == str.buf, SXX_FALSE);

    sxx_string_set_cstr(&str, "xiaoxu.shi");
    sxx_assert_return_val(sxx_strcmp(str.buf, "xiaoxu.shi") == 0, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_set(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str0;
    sxx_string_t str1 = {sxx_strlen("xiaoxu.shi"), "xiaoxu.shi"};

    sxx_string_set(&str0, &str1);
    sxx_assert_return_val(str0.len == str1.len, SXX_FALSE);
    sxx_assert_return_val(str0.buf == str1.buf, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_null(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str;
    sxx_string_null(&str);

    sxx_assert_return_val(str.len == 0, SXX_FALSE);
    sxx_assert_return_val(sxx_strcmp(str.buf, "") == 0, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_set_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str;
    sxx_char_t *cstr = "xiaoxu.shi";

    sxx_string_set_cstr(&str, cstr);
    sxx_assert_return_val(str.len == sxx_strlen(cstr), SXX_FALSE);
    sxx_assert_return_val(str.buf == cstr, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_assign(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str0 = {sxx_strlen("xiaoxu.shi"), "xiaoxu.shi"};
    sxx_string_t str1;

    sxx_string_assign(sxx_test_suite_pool_get(suite), &str1, &str0);
    sxx_assert_return_val(str0.buf != str1.buf, SXX_FALSE);
    sxx_assert_return_val(str0.len == str1.len, SXX_FALSE);
    sxx_assert_return_val(sxx_strcmp(str0.buf, str1.buf) == 0, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_assign_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_char_t* cstr = "xiaoxu.shi";
    sxx_string_t str1;

    sxx_string_assign_cstr(sxx_test_suite_pool_get(suite), &str1, cstr);
    sxx_assert_return_val(str1.buf != cstr, SXX_FALSE);
    sxx_assert_return_val(str1.len == sxx_strlen(cstr), SXX_FALSE);
    sxx_assert_return_val(sxx_strcmp(str1.buf, cstr) == 0, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t ssx_tester_string_dup(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_string_t str0 = {sxx_strlen("xiaoxu.shi"), "xiaoxu.shi"};
    sxx_string_t *str1 = sxx_string_dup(sxx_test_suite_pool_get(suite), &str0);

    sxx_assert_return_val(str0.buf != str1->buf, SXX_FALSE);
    sxx_assert_return_val(str0.len == str1->len, SXX_FALSE);
    sxx_assert_return_val(sxx_strcmp(str0.buf, str1->buf) == 0, SXX_FALSE);

    return SXX_TRUE;
}

static sxx_bool_t sxx_tester_string_dup_cstr(sxx_test_suite_t *suite, sxx_int32_t argc, sxx_char_t *argv[])
{
    sxx_char_t* cstr = "xiaoxu.shi";
    sxx_string_t* str = sxx_string_dup_cstr(sxx_test_suite_pool_get(suite), cstr);

    sxx_assert_return_val(cstr != str->buf, SXX_FALSE);
    sxx_assert_return_val(sxx_strlen(cstr) == str->len, SXX_FALSE);
    sxx_assert_return_val(sxx_strcmp(cstr, str->buf) == 0, SXX_FALSE);

    return SXX_TRUE;
}

