#ifndef __SXX_ALLOC_H__
#define __SXX_ALLOC_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

SXX_DECLARE(sxx_ptr_t) sxx_alloc(sxx_size_t size);

SXX_DECLARE(sxx_ptr_t) sxx_calloc(sxx_size_t size);

SXX_DECLARE(sxx_void_t) sxx_memset(sxx_ptr_t ptr, sxx_int32_t c, sxx_size_t s);

SXX_DECLARE(sxx_void_t) sxx_memzero(sxx_ptr_t ptr, sxx_size_t size);

SXX_DECLARE(sxx_void_t) sxx_free(sxx_ptr_t ptr);

SXX_DECLARE(sxx_void_t) sxx_safe_free(sxx_ptr_t *ptr);

SXX_EXTERN_C_END

#endif // ! __SXX_ALLOC_H__
