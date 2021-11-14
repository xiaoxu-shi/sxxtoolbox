#include "sxx_arch_mutex.h"

SXX_DECLARE(sxx_mutex_t *) sxx_mutex_create(sxx_memory_pool_t *pool, const sxx_char_t *name)
{
    return (sxx_mutex_t*)name;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_lock(sxx_mutex_t *mutex)
{
    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_unlock(sxx_mutex_t *mutex)
{
    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_trylock(sxx_mutex_t *mutex)
{
    return SXX_SUCCESS;
}


SXX_DECLARE(sxx_status_t) sxx_mutex_destroy(sxx_mutex_t *mutex)
{
    return SXX_SUCCESS;
}

