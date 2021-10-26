#ifndef __SXX_ARCH_DSO_H__
#define __SXX_ARCH_DSO_H__
#include "dso.h"

struct sxx_dso_handle_t {
    void            *handle;
    sxx_status_t    load_error;
};

#endif // !__SXX_ARCH_DSO_H__
