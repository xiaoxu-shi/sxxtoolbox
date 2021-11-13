#include "sxx_cstr.h"
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
    dst->len = src->len;
    dst->buf = src->buf;
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_set_null(sxx_string_t *str)
{
    str->len = 0;
    str->buf = "";
    return str;
}

SXX_DECLARE(sxx_string_t*) sxx_string_set_cstr(sxx_string_t* dst, sxx_char_t* csrc)
{
    dst->len = sxx_strlen(csrc);
    dst->buf = csrc;
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_assign(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_string_t* src)
{
    dst->len = src->len;
    dst->buf = sxx_memory_calloc(pool, src->len + 1);
    sxx_strncpy(dst->buf, src->buf, dst->len);
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_assign_cstr(sxx_memory_pool_t* pool, sxx_string_t* dst, sxx_char_t* csrc)
{
    dst->len = sxx_strlen(csrc);
    dst->buf = sxx_memory_calloc(pool, dst->len + 1);
    sxx_strncpy(dst->buf, csrc, dst->len);
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_dup(sxx_memory_pool_t* pool, sxx_string_t* str)
{
    sxx_string_t *dst = sxx_memory_alloc(pool, sxx_sizeof(sxx_string_t));
    dst->buf = sxx_memory_calloc(pool, str->len + 1);
    dst->len = str->len;
    sxx_strncpy(dst->buf, str->buf, dst->len);
    return dst;
}

SXX_DECLARE(sxx_string_t*) sxx_string_dup_cstr(sxx_memory_pool_t* pool, sxx_char_t* csrc)
{
    sxx_string_t *dst = sxx_memory_alloc(pool, sxx_sizeof(sxx_string_t));
    dst->buf = sxx_memory_calloc(pool, sxx_strlen(csrc) + 1);
    dst->len = sxx_strlen(csrc);
    sxx_strncpy(dst->buf, csrc, dst->len);
    return dst;
}



