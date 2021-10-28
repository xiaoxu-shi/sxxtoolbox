#include "sxx_string.h"

SXX_DECLARE(sxx_bool_t) sxx_string_empty(sxx_string_t *str)
{
    return (str->len == 0);
}

SXX_DECLARE(sxx_size_t) sxx_string_lenght(sxx_string_t *str)
{
    return str->len;
} 

SXX_DECLARE(sxx_char_t*) sxx_string_buffer(sxx_string_t str)
{
    return str.buf;
}




