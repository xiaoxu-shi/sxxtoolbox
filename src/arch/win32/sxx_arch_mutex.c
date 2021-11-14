#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_arch_mutex.h"

SXX_DECLARE(sxx_mutex_t *) sxx_mutex_create(sxx_memory_pool_t *pool, const sxx_char_t *name)
{
    sxx_mutex_t *mtx = sxx_memory_alloc(pool, sxx_sizeof(sxx_mutex_t));

    sxx_assert_return_val(mtx, NULL);
    sxx_assert_return_val(sxx_string_assign_cstr(pool, &mtx->name, (sxx_char_t*)name) != NULL, NULL);

    InitializeCriticalSection(&mtx->mutex);

    return mtx;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_lock(sxx_mutex_t *mutex)
{
    EnterCriticalSection(&mutex->mutex);
    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_unlock(sxx_mutex_t *mutex)
{
    LeaveCriticalSection(&mutex->mutex);
    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_trylock(sxx_mutex_t *mutex)
{
    return TryEnterCriticalSection(&mutex->mutex) ? SXX_SUCCESS : SXX_ERROR;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_destroy(sxx_mutex_t *mutex)
{
    DeleteCriticalSection(&mutex->mutex);
    return SXX_SUCCESS;
}

