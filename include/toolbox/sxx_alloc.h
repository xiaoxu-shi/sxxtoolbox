#ifndef __SXX_ALLOC_H__
#define __SXX_ALLOC_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

#ifdef __cplusplus
extern "C" {
#endif

SXX_EXPORT sxx_ptr_t sxx_alloc(sxx_size_t size);

SXX_EXPORT sxx_ptr_t sxx_calloc(sxx_size_t size);

SXX_EXPORT sxx_void_t sxx_memzero(sxx_ptr_t ptr, sxx_size_t size);

SXX_EXPORT sxx_void_t sxx_free(sxx_ptr_t ptr);

SXX_EXPORT sxx_void_t sxx_safe_free(sxx_ptr_t *ptr);

#ifdef __cplusplus
}
#endif

#endif // ! __SXX_ALLOC_H__
