#include <sxx_toolbox.h>

static sxx_bool_t sxx_tester_atomic_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_set(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_inc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_dec(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_add(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_inc_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_dec_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
static sxx_bool_t sxx_tester_atomic_add_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);

sxx_bool_t sxx_tester_atomic(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_assert_return_val(sxx_tester_atomic_get(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_set(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_inc(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_dec(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_add(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_inc_and_get(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_dec_and_get(suite, argc, argv), SXX_FALSE);
	sxx_assert_return_val(sxx_tester_atomic_add_and_get(suite, argc, argv), SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 1, "tester_atomic_get");

	sxx_assert_return_val(sxx_atomic_get(atomic) == 1, SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_set(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 0, "tester_atomic_set");

	sxx_atomic_set(atomic, 100);

	sxx_assert_return_val(sxx_atomic_get(atomic) == 100, SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_inc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 0, "tester_atomic_inc");

	sxx_atomic_inc(atomic);

	sxx_assert_return_val(sxx_atomic_get(atomic) == 1, SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_dec(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 1, "tester_atomic_dec");

	sxx_atomic_dec(atomic);

	sxx_assert_return_val(sxx_atomic_get(atomic) == 0, SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_add(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 0, "tester_atomic_add");

	sxx_atomic_add(atomic, 100);

	sxx_assert_return_val(sxx_atomic_get(atomic) == 100, SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_inc_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 0, "tester_atomic_inc_and_get");

	sxx_int64_t value = sxx_atomic_inc_and_get(atomic);

	sxx_assert_return_val((sxx_atomic_get(atomic) == value == 1), SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_dec_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 1, "ester_atomic_dec_and_get");

	sxx_int64_t value = sxx_atomic_dec_and_get(atomic);

	sxx_assert_return_val((sxx_atomic_get(atomic) == value && value == 0), SXX_FALSE);

	return SXX_TRUE;
}

static sxx_bool_t sxx_tester_atomic_add_and_get(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_atomic_t* atomic = sxx_atomic_create(sxx_test_suite_pool_get(suite), 0, "tester_atomic_add_and_get");

	sxx_int64_t value = sxx_atomic_add_and_get(atomic, 100);

	sxx_assert_return_val((sxx_atomic_get(atomic) == value && value == 100), SXX_FALSE);

	return SXX_TRUE;
}


