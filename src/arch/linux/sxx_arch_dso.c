#include "sxx_arch_so.h"

SXX_DECLARE(sxx_status_t) sxx_dso_load(sxx_dso_handle_t **h, const char *path)
{
    return SXX_ERROR;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_handle_t *h, const char *symname, sxx_dso_handle_sym_t *sym)
{
    return SXX_ERROR;
}

SXX_DECLARE(sxx_status_t) sxx_dso_unload(sxx_dso_handle_t *h)
{
    return SXX_ERROR;
}
