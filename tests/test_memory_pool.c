#include "sxx_toolbox.h"

sxx_bool_t sxx_tester_memory_pool_alloc_block(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
sxx_bool_t sxx_tester_memory_pool_small_alloc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
sxx_bool_t sxx_tester_memory_pool_large_alloc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);
sxx_bool_t sxx_tester_memory_pool_all(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[]);

sxx_bool_t sxx_tester_memory_pool(sxx_test_suite_t *suite, sxx_int32_t argc,  sxx_char_t *argv[])
{
	if (sxx_tester_memory_pool_alloc_block(suite, argc, argv) == SXX_FALSE) {
		return SXX_FALSE;
	}
	if (sxx_tester_memory_pool_small_alloc(suite, argc, argv) == SXX_FALSE) {
		return SXX_FALSE;
	}
	if (sxx_tester_memory_pool_large_alloc(suite, argc, argv) == SXX_FALSE) {
		return SXX_FALSE;
	}
	if (sxx_tester_memory_pool_all(suite, argc, argv) == SXX_FALSE) {
		return SXX_FALSE;
	}
	return SXX_TRUE;
}

sxx_bool_t sxx_tester_memory_pool_alloc_block(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_memory_pool_t* pool = sxx_memory_pool_create(1024);

	for (int i = 0; i < 100; i++) {
		sxx_ptr_t p = sxx_memory_alloc(pool, 900);
	}

	sxx_memory_pool_distory(pool);

	return SXX_TRUE;
}

sxx_bool_t sxx_tester_memory_pool_small_alloc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_memory_pool_t* pool = sxx_memory_pool_create(2048);

	for (int i = 0; i < 10; i++) {
		sxx_ptr_t p = sxx_memory_alloc(pool, 10);
	}

	sxx_memory_pool_distory(pool);

	return SXX_TRUE;
}

sxx_bool_t sxx_tester_memory_pool_large_alloc(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_memory_pool_t* pool = sxx_memory_pool_create(2048);

	for (int i = 0; i < 10; i++) {
		sxx_ptr_t p = sxx_memory_alloc(pool, 2048);
	}

	sxx_memory_pool_distory(pool);

	return SXX_TRUE;
}

sxx_bool_t sxx_tester_memory_pool_all(sxx_test_suite_t* suite, sxx_int32_t argc, sxx_char_t* argv[])
{
	sxx_ptr_t p = NULL;
	sxx_memory_pool_t* pool = sxx_memory_pool_create(2048);

	for (int i = 0; i < 1000; i++) {
		p = sxx_memory_alloc(pool, 1024);
		p = sxx_memory_alloc(pool, 2048);
	}

	sxx_memory_pool_distory(pool);

	return SXX_TRUE;
}
