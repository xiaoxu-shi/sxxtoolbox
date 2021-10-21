#ifndef __SXX_DSO_H__
#define __SXX_DSO_H__
#include "toolbox/defs.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct sxx_dso_handle_t sxx_dso_handle_t;

typedef void* sxx_dso_handle_sym_t;

SXXTB_EXPORT sxxtb_status_t sxx_dso_load(sxx_dso_handle_t **h, const char *path);

SXXTB_EXPORT sxxtb_status_t sxx_dso_sym(sxx_dso_handle_t *h, const char *symname, sxx_dso_handle_sym_t *sym);

SXXTB_EXPORT sxxtb_status_t sxx_dso_unload(sxx_dso_handle_t *h);



#ifdef __cplusplus
}
#endif

#endif // !__SXX_DSO_H__
