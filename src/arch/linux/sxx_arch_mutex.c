#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_arch_mutex.h"

SXX_DECLARE(sxx_mutex_t *) sxx_mutex_create(sxx_memory_pool_t *pool, const sxx_char_t *name)
{
    sxx_mutex_t *mtx = sxx_memory_alloc(pool, sxx_sizeof(sxx_mutex_t));

    sxx_assert_return_val(mtx, NULL);
    sxx_assert_return_val(sxx_string_assign_cstr(pool, &mtx->name, (sxx_char_t*)name) != NULL, NULL);
    sxx_assert_return_val(pthread_mutex_init(&mtx->mutex, NULL) == 0, NULL);

    return mtx;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_lock(sxx_mutex_t *mutex)
{
    sxx_assert_return_val(pthread_mutex_lock(&mutex->mutex) == 0, SXX_ERROR);

    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_unlock(sxx_mutex_t *mutex)
{
    sxx_assert_return_val(pthread_mutex_unlock(&mutex->mutex) == 0, SXX_ERROR);

    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_trylock(sxx_mutex_t *mutex)
{
    sxx_assert_return_val(pthread_mutex_trylock(&mutex->mutex) == 0, SXX_ERROR);

    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_destroy(sxx_mutex_t *mutex)
{
    sxx_assert_return_val(pthread_mutex_destroy(&mutex->mutex) == 0, SXX_ERROR);

    return SXX_SUCCESS;
}

