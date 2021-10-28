#ifndef __SXX_DSO_H__
#define __SXX_DSO_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

typedef struct sxx_dso_handle_t sxx_dso_handle_t;

typedef sxx_ptr_t sxx_dso_handle_sym_t;

SXX_DECLARE(sxx_status_t) sxx_dso_load(sxx_dso_handle_t **h, const char *path);

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_handle_t *h, const char *symname, sxx_dso_handle_sym_t *sym);

SXX_DECLARE(sxx_status_t) sxx_dso_unload(sxx_dso_handle_t *h);

SXX_EXTERN_C_END

#endif // !__SXX_DSO_H__
