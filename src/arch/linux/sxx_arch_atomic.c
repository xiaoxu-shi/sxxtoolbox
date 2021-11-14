#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_arch_atomic.h"

SXX_DECLARE(sxx_atomic_t *) sxx_atomic_create(sxx_memory_pool_t *pool, sxx_int64_t initial)
{
	sxx_atomic_t *atomic = sxx_memory_alloc(pool, sxx_sizeof(sxx_atomic_t));
	sxx_assert_return_val(atomic, NULL);

	atomic->mutex = sxx_mutex_create(pool, "sxx_atomic_create");
	sxx_assert_return_val(atomic->mutex, NULL);

	atomic->value = initial;

	return atomic;
}

SXX_DECLARE(sxx_void_t) sxx_atomic_destroy(sxx_atomic_t* atomic)
{
	sxx_assert_return(atomic && atomic->mutex);

	sxx_mutex_destroy(atomic->mutex);

	//SXX_UNUSED_ARG(atomic);
}


SXX_DECLARE(sxx_void_t) sxx_atomic_set(sxx_atomic_t* atomic, sxx_int64_t value)
{
	sxx_mutex_lock(atomic->mutex);

	atomic->value = value;

	sxx_mutex_unlock(atomic->mutex);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_get(sxx_atomic_t* atomic)
{
	sxx_int64_t val;

	sxx_mutex_lock(atomic->mutex);
	val = atomic->value;
	sxx_mutex_unlock(atomic->mutex);

	return val;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_inc(sxx_atomic_t* atomic)
{
	sxx_mutex_lock(atomic->mutex);
	++atomic->value;
	sxx_mutex_unlock(atomic->mutex);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_inc_and_get(sxx_atomic_t* atomic)
{
   	sxx_int64_t val;

    sxx_mutex_lock( atomic->mutex );
    val = ++atomic->value;
    sxx_mutex_unlock( atomic->mutex);

    return val;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_dec(sxx_atomic_t* atomic)
{
	sxx_mutex_lock(atomic->mutex);
	--atomic->value;
	sxx_mutex_unlock(atomic->mutex);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_dec_and_get(sxx_atomic_t* atomic)
{
   	sxx_int64_t val;

    sxx_mutex_lock( atomic->mutex );
    val = --atomic->value;
    sxx_mutex_unlock( atomic->mutex);

    return val;
}


SXX_DECLARE(sxx_void_t) sxx_atomic_add(sxx_atomic_t* atomic, sxx_int64_t value)
{
	sxx_mutex_lock(atomic->mutex);
    atomic->value += value;
    sxx_mutex_unlock(atomic->mutex);
}


SXX_DECLARE(sxx_int64_t) sxx_atomic_add_and_get(sxx_atomic_t* atomic, sxx_int64_t value)
{
    sxx_int64_t val;

    sxx_mutex_lock(atomic->mutex);
    atomic->value += value;
    val = atomic->value;
    sxx_mutex_unlock(atomic->mutex);

    return val;
}
