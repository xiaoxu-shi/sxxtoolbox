#include "sxx_arch_dso.h"

SXX_DECLARE(sxx_dso_t *) sxx_dso_create(sxx_memory_pool_t *pool, sxx_const_char_t *path)
{
    return NULL;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_t *handle, sxx_const_char_t *symname, sxx_dso_sym_t *sym)
{
    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_t *handle)
{
    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_t *handle, sxx_string_t *error)
{
    return NULL;
}