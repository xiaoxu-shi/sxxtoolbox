#include "sxx_plist.h"

struct sxx_plist_t {
    sxx_plist_node_t *head;
    sxx_memory_pool_t *pool;
};

struct sxx_plist_node_t {
    sxx_plist_node_t *next;
    sxx_plist_node_t *prev;
    sxx_ptr_t data;
};

SXX_DECLARE(sxx_plist_t*) sxx_plist_create(sxx_memory_pool_t *pool)
{
    return NULL;
}

SXX_DECLARE(sxx_void_t) sxx_plist_destory(sxx_plist_t *l)
{

}

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_push(sxx_ptr_t *d)
{
    return NULL;
}

SXX_DECLARE(sxx_bool_t) sxx_plist_is_empty(sxx_void_t)
{
    return SXX_FALSE;
}

SXX_DECLARE(sxx_void_t) sxx_plist_remove(sxx_plist_node_t *n)
{
    
}

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_get_head(sxx_plist_t *l)
{
    return  l->head;
}

SXX_DECLARE(sxx_plist_node_t *) sxx_plist_get_next(sxx_plist_node_t *n)
{
    return NULL;
}

SXX_DECLARE(sxx_ptr_t) sxx_plist_get_data(sxx_plist_node_t *n)
{
    return  n->data;
}
