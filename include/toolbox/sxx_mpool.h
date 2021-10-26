#ifndef __SXX_MEMORY_POOL__
#define __SXX_MEMORY_POOL__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sxx_memory_pool_t sxx_memory_pool_t;

SXX_EXPORT sxx_memory_pool_t *sxx_memory_pool_create(sxx_size_t size);

SXX_EXPORT sxx_void_t sxx_memory_pool_reset(sxx_memory_pool_t *pool);

SXX_EXPORT sxx_void_t sxx_memory_pool_distory(sxx_memory_pool_t *pool);

SXX_EXPORT sxx_ptr_t sxx_memory_alloc(sxx_memory_pool_t *pool, sxx_size_t size);

#ifdef __cplusplus
}
#endif

#endif // !__SXX_MEMORY_POOL__
