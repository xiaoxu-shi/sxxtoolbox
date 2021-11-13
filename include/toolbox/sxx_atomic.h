#ifndef __SXX_TOOLBOX_ATOMIC_H__
#define __SXX_TOOLBOX_ATOMIC_H__
#include "sxx_defs.h"
#include "sxx_types.h"
#include "sxx_mpool.h"

SXX_EXTERN_C_BEGIN

/**
 * Opaque data type for atomic operations.
 */
typedef struct sxx_atomic_t sxx_atomic_t;

/**
 * Create atomic variable.
 *
 * @param pool	    The pool.
 * @param initial   The initial value of the atomic variable.
 * @param atomic    Pointer to hold the atomic variable upon return.
 *
 * @return	    SXX_SUCCESS on success, or the SXX_ERROR code.
 */
SXX_DECLARE(sxx_status_t) sxx_atomic_create( sxx_memory_pool_t *pool, 
				       sxx_int64_t initial,
				       sxx_atomic_t **atomic );

/**
 * Destroy atomic variable.
 *
 * @param atomi	the atomic variable.
 */
SXX_DECLARE(sxx_void_t) sxx_atomic_destroy(sxx_atomic_t* atomic);

/**
 * Set the value of an atomic type, and return the previous value.
 *
 * @param atomic	the atomic variable.
 * @param value		value to be set to the variable.
 */
SXX_DECLARE(sxx_void_t) sxx_atomic_set(sxx_atomic_t* atomic, sxx_int64_t value);

/**
 * Get the value of an atomic type.
 *
 * @param atomic	the atomic variable.
 * 
 * @return the value of the atomic variable.
 */
SXX_DECLARE(sxx_int64_t) sxx_atomic_get(sxx_atomic_t* atomic);

/**
 * Increment the value of an atomic type.
 *
 * @param atomic		the atomic variable.
 */
SXX_DECLARE(sxx_void_t) sxx_atomic_inc(sxx_atomic_t* atomic);

/**
 * Increment the value of an atomic type and get the result.
 *
 * @param atomic		the atomic variable.
 *
 * @return              The incremented value.
 */
SXX_DECLARE(sxx_int64_t) sxx_atomic_inc_and_get(sxx_atomic_t* atomic);

/**
 * Decrement the value of an atomic type.
 *
 * @param atomic		the atomic variable.
 */
SXX_DECLARE(sxx_void_t) sxx_atomic_dec(sxx_atomic_t* atomic);

/**
 * Decrement the value of an atomic type and get the result.
 *
 * @param atomic		the atomic variable.
 *
 * @return              The decremented value.
 */
SXX_DECLARE(sxx_int64_t) sxx_atomic_dec_and_get(sxx_atomic_t* atomic);

/**
 * Add a value to an atomic type.
 *
 * @param atomic	The atomic variable.
 * @param value		Value to be added.
 */
SXX_DECLARE(sxx_void_t) sxx_atomic_add(sxx_atomic_t* atomic, sxx_int64_t value);

/**
 * Add a value to an atomic type and get the result.
 *
 * @param atomic	The atomic variable.
 * @param value		Value to be added.
 *
 * @return			The result after the addition.
 */
SXX_DECLARE(sxx_int64_t) sxx_atomic_add_and_get(sxx_atomic_t* atomic, sxx_int64_t value);

SXX_EXTERN_C_END

#endif //! __SXX_TOOLBOX_ATOMIC_H__


