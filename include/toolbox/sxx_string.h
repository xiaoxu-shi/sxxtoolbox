#ifndef __SXX_STRING_H__
#define __SXX_STRING_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"
#include "toolbox/sxx_mpool.h"

SXX_EXTERN_C_BEGIN

typedef struct sxx_string_t {
    sxx_size_t len;
    sxx_char_t *buf;
} sxx_string_t;

SXX_DECLARE(sxx_bool_t) sxx_string_empty(sxx_string_t *str);

SXX_DECLARE(sxx_size_t) sxx_string_lenght(sxx_string_t *str);

SXX_DECLARE(sxx_char_t*) sxx_string_buffer(sxx_string_t *str);

SXX_DECLARE(sxx_string_t*) sxx_string_set(sxx_string_t* dst, sxx_string_t* src);
SXX_DECLARE(sxx_string_t*) sxx_string_set_1(sxx_string_t* dst, sxx_char_t* csrc);

SXX_DECLARE(sxx_string_t*) sxx_string_assign(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_string_t* src);
SXX_DECLARE(sxx_string_t*) sxx_string_assign_1(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_char_t* csrc);

SXX_DECLARE(sxx_string_t*) sxx_string_dup(sxx_memory_pool_t* pool, sxx_string_t* str);
SXX_DECLARE(sxx_string_t*) sxx_string_dup_1(sxx_memory_pool_t* pool, sxx_char_t* cstr);

SXX_EXTERN_C_END

#endif // ! __SXX_STRING_H__
