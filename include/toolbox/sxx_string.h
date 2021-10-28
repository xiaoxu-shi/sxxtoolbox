#ifndef __SXX_STRING_H__
#define __SXX_STRING_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

typedef struct sxx_string_t {
    sxx_size_t len;
    sxx_char_t *buf;
} sxx_string_t;

SXX_DECLARE(sxx_bool_t) sxx_string_empty(sxx_string_t *str);

SXX_DECLARE(sxx_size_t) sxx_string_lenght(sxx_string_t *str);

SXX_DECLARE(sxx_char_t*) sxx_string_buffer(sxx_string_t str);


SXX_EXTERN_C_END

#endif // ! __SXX_STRING_H__
