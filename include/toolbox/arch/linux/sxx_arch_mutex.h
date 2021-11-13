#ifndef __SXX_TOOLBOX_ARCH_MUTEX_H__
#define __SXX_TOOLBOX_ARCH_MUTEX_H__
#include <pthread.h>
#include "sxx_mutex.h"
#include "sxx_string.h"

struct sxx_mutex_t {
    pthread_mutex_t mutex;
    sxx_string_t    name;
};

#endif // !__SXX_TOOLBOX_ARCH_MUTEX_H__
