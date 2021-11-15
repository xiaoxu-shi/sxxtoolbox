#include <windows.h>
#include "sxx_assert.h"
#include "sxx_arch_atomic.h"

SXX_DECLARE(sxx_atomic_t *) sxx_atomic_create(sxx_memory_pool_t *pool, sxx_int64_t initial, sxx_char_t* name)
{
	sxx_assert_return_val(pool, NULL);

	sxx_atomic_t* atomic = sxx_memory_alloc(pool, sizeof(sxx_atomic_t));
	sxx_assert_return_val(atomic, NULL);

	sxx_string_assign_cstr(pool, &atomic->name, name);
	atomic->value = initial;

	return atomic;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_destroy(sxx_atomic_t* atomic)
{
    SXX_UNUSED_ARG(atomic);
}


SXX_DECLARE(sxx_void_t) sxx_atomic_set(sxx_atomic_t* atomic, sxx_int64_t value)
{
	sxx_assert_return(atomic);

	InterlockedExchange(&atomic->value, value);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_get(sxx_atomic_t* atomic)
{
	sxx_assert_return_val(atomic, 0);

	return atomic->value;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_inc(sxx_atomic_t* atomic)
{
	sxx_assert_return(atomic);

	sxx_atomic_inc_and_get(atomic);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_inc_and_get(sxx_atomic_t* atomic)
{
	sxx_assert_return_val(atomic, 0);

	return InterlockedIncrement(&atomic->value);
}


SXX_DECLARE(sxx_void_t) sxx_atomic_dec(sxx_atomic_t* atomic)
{
	sxx_assert_return(atomic);

	sxx_atomic_dec_and_get(atomic);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_dec_and_get(sxx_atomic_t* atomic)
{
	sxx_assert_return_val(atomic, 0);

	return InterlockedDecrement(&atomic->value);
}


SXX_DECLARE(sxx_void_t) sxx_atomic_add(sxx_atomic_t* atomic, sxx_int64_t value)
{
	sxx_assert_return(atomic);

	InterlockedExchangeAdd(&atomic->value, value);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_add_and_get(sxx_atomic_t* atomic, sxx_int64_t value)
{
	sxx_assert_return_val(atomic, 0);

	sxx_int64_t old = InterlockedExchangeAdd(&atomic->value, value);
	return old + value;
}
