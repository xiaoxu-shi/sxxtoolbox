#ifndef __SXX_ARCH_DSO_H__
#define __SXX_ARCH_DSO_H__
#include "sxx_dso.h"

struct sxx_dso_handle_t {
    sxx_memory_pool_t*  pool;
    sxx_ptr_t           handle;
    sxx_string_t        path;
    sxx_string_t        error;
};

#endif // !__SXX_ARCH_DSO_H__
