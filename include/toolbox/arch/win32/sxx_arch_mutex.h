#ifndef __SXX_TOOLBOX_ARCH_MUTEX_H__
#define __SXX_TOOLBOX_ARCH_MUTEX_H__
#include <windows.h>
#include "sxx_string.h"
#include "sxx_mutex.h"

struct sxx_mutex_t {
    CRITICAL_SECTION	mutex;
    sxx_string_t        name;
};

#endif // !__SXX_TOOLBOX_ARCH_MUTEX_H__
