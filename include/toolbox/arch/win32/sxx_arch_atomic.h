#ifndef __SXX_TOOLBOX_ARCH_ATOMIC_H__
#define __SXX_TOOLBOX_ARCH_ATOMIC_H__
#include "sxx_string.h"
#include "sxx_atomic.h"

struct sxx_atomic_t {
    sxx_string_t    name;
    sxx_int64_t     value;
};

#endif // !__SXX_TOOLBOX_ARCH_ATOMIC_H__
