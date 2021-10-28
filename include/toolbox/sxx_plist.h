#ifndef __SXX_PLIST_H__
#define __SXX_PLIST_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"
#include "toolbox/sxx_mpool.h"

SXX_EXTERN_C_BEGIN

typedef struct sxx_plist_t sxx_plist_t;
typedef struct sxx_plist_node_t sxx_plist_node_t;

SXX_DECLARE(sxx_plist_t*) sxx_plist_create(sxx_memory_pool_t *pool);

SXX_DECLARE(sxx_void_t) sxx_plist_destory(sxx_plist_t *l);

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_push(sxx_ptr_t *d);

SXX_DECLARE(sxx_bool_t) sxx_plist_is_empty(sxx_void_t);

SXX_DECLARE(sxx_void_t) sxx_plist_remove(sxx_plist_node_t *n);

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_get_head(sxx_plist_t *l);

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_get_next(sxx_plist_node_t *n);

SXX_DECLARE(sxx_ptr_t) sxx_plist_get_data(sxx_plist_node_t *n);

SXX_EXTERN_C_END

#endif // ! __SXX_PLIST_H__
