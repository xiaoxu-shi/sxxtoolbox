#ifndef __SXX_ARCH_DSO_H__
#define __SXX_ARCH_DSO_H__
#include "sxx_dso.h"

struct sxx_dso_handle_t {
    sxx_ptr_t       handle;
    sxx_status_t    load_error;
};

#endif // !__SXX_ARCH_DSO_H__
