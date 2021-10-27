#include <memory.h>
#include <stdlib.h>
#include <assert.h>

#include "sxx_alloc.h"

sxx_ptr_t sxx_alloc(sxx_size_t size)
{
    sxx_ptr_t p = NULL;

    p = malloc(size);
    if (p == NULL) {
        assert(0);
    }

    return p;
}

sxx_ptr_t sxx_calloc(sxx_size_t size)
{
    sxx_ptr_t p = NULL;

    p = malloc(size);
    if (p != NULL) {
        sxx_memzero(p, size);
    }

    return p;
}

sxx_void_t sxx_memset(sxx_ptr_t ptr, sxx_int32_t c, sxx_size_t s)
{
    memset(ptr, c, s);
}

sxx_void_t sxx_memzero(sxx_ptr_t ptr, sxx_size_t size)
{
    memset(ptr, 0, size);
}

sxx_void_t sxx_free(sxx_ptr_t ptr)
{
    free(ptr);
}

sxx_void_t sxx_safe_free(sxx_ptr_t *ptr)
{
    free(*ptr);
    *ptr = NULL;
}
