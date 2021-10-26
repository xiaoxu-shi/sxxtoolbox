#include "sxx_mpool.h"

typedef struct sxx_memory_small_node_t sxx_memory_small_node_t;
typedef struct sxx_memory_large_node_t sxx_memory_large_node_t;


struct sxx_memory_small_node_t
{
    sxx_uchar_t *begin;
    sxx_uchar_t *end;
    sxx_memory_small_node_t *next;
};

struct sxx_memory_large_node_t
{
    sxx_uchar_t *alloc;
    sxx_memory_large_node_t *next;
};

struct sxx_memory_pool_t
{
    sxx_memory_small_node_t *small;
    sxx_memory_small_node_t *current;
    sxx_memory_large_node_t *large;
    sxx_size_t  max;
};


sxx_memory_pool_t *sxx_memory_pool_create() {
    sxx_memory_pool_t *pool = NULL;
    
    return pool;
}

sxx_void_t sxx_memory_pool_reset(sxx_memory_pool_t *pool)
{

}

sxx_void_t sxx_memory_pool_distory(sxx_memory_pool_t *pool)
{

}

sxx_ptr_t sxx_memory_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    return NULL;
}
