#ifndef __SXX_DSO_H__
#define __SXX_DSO_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"
#include "toolbox/sxx_string.h"
#include "toolbox/sxx_memory_pool.h"

SXX_EXTERN_C_BEGIN

/**
 * Opaque data type for dso operations.
 */
typedef struct sxx_dso_t sxx_dso_t;

/**
 * Structure for referencing symbols from dynamic objects
 */
typedef sxx_ptr_t sxx_dso_sym_t;

/**
 * Create a DSO library.
 * @param path Path to the DSO library
 * @param pool Pool to use.
 * @param dso Create handle to load the symbol from.
 * @return SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_dso_create(sxx_memory_pool_t *pool, sxx_const_char_t *path, sxx_dso_t **dso);

/**
 * Load a symbol from a DSO handle.
 * @param sym Location to store the loaded symbol
 * @param dso handle to load the symbol from.
 * @param symname Name of the symbol to load.
 * @return SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_t *dso, sxx_const_char_t *symname, sxx_dso_sym_t *sym);

/**
 * Destroy a DSO library.
 * @param dso handle to close.
 * @return SXX_SUCCESS on success, or the error code.
 */
SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_t *dso);

/**
 * Report more information when a DSO function fails.
 * @param dso The dso handle that has been opened
 * @param error Location to store the dso error
 * @return  Location to store the dso error
 */
SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_t *dso, sxx_string_t *error);

SXX_EXTERN_C_END

#endif // !__SXX_DSO_H__
