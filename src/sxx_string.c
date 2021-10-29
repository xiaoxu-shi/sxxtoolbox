#include "sxx_string.h"

SXX_DECLARE(sxx_bool_t) sxx_string_empty(sxx_string_t *str)
{
    return (str->len == 0);
}

SXX_DECLARE(sxx_size_t) sxx_string_lenght(sxx_string_t *str)
{
    return str->len;
} 

SXX_DECLARE(sxx_char_t*) sxx_string_buffer(sxx_string_t *str)
{
    return str->buf;
}

SXX_DECLARE(sxx_string_t*) sxx_string_set(sxx_string_t* dst, sxx_string_t* src)
{
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_set_1(sxx_string_t* dst, sxx_char_t* csrc)
{
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_assign(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_string_t* src)
{
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_assign_1(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_char_t* csrc)
{
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_dup(sxx_memory_pool_t* pool, sxx_string_t* str)
{
    return NULL;
}

SXX_DECLARE(sxx_string_t*) sxx_string_dup_1(sxx_memory_pool_t* pool, sxx_char_t* csrc)
{
    return NULL;
}



