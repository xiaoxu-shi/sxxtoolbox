#ifndef __SXX_MEMORY_POOL__
#define __SXX_MEMORY_POOL__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

typedef struct sxx_memory_pool_t sxx_memory_pool_t;

SXX_DECLARE(sxx_memory_pool_t *) sxx_memory_pool_create(sxx_size_t size);

SXX_DECLARE(sxx_void_t) sxx_memory_pool_reset(sxx_memory_pool_t *pool);

SXX_DECLARE(sxx_void_t) sxx_memory_pool_distory(sxx_memory_pool_t *pool);

SXX_DECLARE(sxx_ptr_t) sxx_memory_alloc(sxx_memory_pool_t *pool, sxx_size_t size);

SXX_DECLARE(sxx_ptr_t) sxx_memory_calloc(sxx_memory_pool_t *pool, sxx_size_t size);

SXX_DECLARE(sxx_void_t) sxx_memeory_free(sxx_memory_pool_t *pool, sxx_ptr_t p);

SXX_EXTERN_C_END

#endif // !__SXX_MEMORY_POOL__
