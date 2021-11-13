#include "sxx_arch_atomic.h"

SXX_DECLARE(sxx_atomic_t *) sxx_atomic_create(sxx_memory_pool_t *pool, sxx_int64_t initial)
{
	return SXX_SUCCESS;
}

SXX_DECLARE(sxx_void_t) sxx_atomic_destroy(sxx_atomic_t* atomic)
{

}


SXX_DECLARE(sxx_void_t) sxx_atomic_set(sxx_atomic_t* atomic, sxx_int64_t value)
{

}


SXX_DECLARE(sxx_int64_t) sxx_atomic_get(sxx_atomic_t* atomic)
{
	return atomic->value;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_inc(sxx_atomic_t* atomic) {

}


SXX_DECLARE(sxx_int64_t) sxx_atomic_inc_and_get(sxx_atomic_t* atomic)
{
	return atomic->value;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_dec(sxx_atomic_t* atomic)
{

}


SXX_DECLARE(sxx_int64_t) sxx_atomic_dec_and_get(sxx_atomic_t* atomic)
{
	return atomic->value;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_add(sxx_atomic_t* atomic, sxx_int64_t value)
{

}


SXX_DECLARE(sxx_int64_t) sxx_atomic_add_and_get(sxx_atomic_t* atomic, sxx_int64_t value)
{
	return atomic->value;
}
