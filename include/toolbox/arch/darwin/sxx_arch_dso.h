#ifndef __SXX_ARCH_DSO_H__
#define __SXX_ARCH_DSO_H__
#include "dso.h"

struct sxx_dso_handle_t {
    void            *handle;
    sxxtb_status_t  load_error;
};

#endif // !__SXX_ARCH_DSO_H__
