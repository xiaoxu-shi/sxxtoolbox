#ifndef __SXX_TOOLBOX_MUTEX_H__
#define __SXX_TOOLBOX_MUTEX_H__
#include "sxx_defs.h"
#include "sxx_types.h"
#include "sxx_memory_pool.h"

SXX_EXTERN_C_BEGIN

/**
 * Opaque data type for atomic operations.
 */
typedef struct sxx_mutex_t sxx_mutex_t;

/**
 * Create mutex of the specified type.
 *
 * @param pool	    The pool.
 * @param name	    Name to be associated with the mutex (for debugging).
 * @param type	    The type of the mutex, of type #pj_mutex_type_e.
 * @param mutex	    Pointer to hold the returned mutex instance.
 *
 * @return      SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_mutex_t *) sxx_mutex_create(sxx_memory_pool_t *pool, const sxx_char_t *name);

/**
 * Acquire mutex lock.
 *
 * @param mutex	    The mutex.
 * @return	    SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_mutex_lock(sxx_mutex_t *mutex);

/**
 * Release mutex lock.
 *
 * @param mutex	    The mutex.
 * @return	    SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_mutex_unlock(sxx_mutex_t *mutex);

/**
 * Try to acquire mutex lock.
 *
 * @param mutex	    The mutex.
 * @return	    SXX_SUCCESS on success, or the error code if the lock couldn't be acquired.
 */
SXX_DECLARE(sxx_status_t) sxx_mutex_trylock(sxx_mutex_t *mutex);

/**
 * Destroy mutex.
 *
 * @param mutex	    Te mutex.
 * @return	    SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_mutex_destroy(sxx_mutex_t *mutex);

SXX_EXTERN_C_END

#endif //! __SXX_TOOLBOX_MUTEX_H__
