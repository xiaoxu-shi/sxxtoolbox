#include "sxx_mpool.h"
#include "sxx_alloc.h"

#define SXX_POOL_DEFAULT_SIZE (16 * 1024)
#define SXX_POOL_DEFAULT_MAXSZIE (4 * 1024)

typedef struct sxx_memory_small_node_t sxx_memory_small_node_t;
typedef struct sxx_memory_large_node_t sxx_memory_large_node_t;

struct sxx_memory_small_node_t
{
    sxx_uchar_t *last;
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


sxx_memory_pool_t *sxx_memory_pool_create(sxx_size_t size)
{
    sxx_memory_pool_t *_pool = NULL;
    sxx_size_t _size = SXX_POOL_DEFAULT_SIZE;

    if( size > sizeof(sxx_memory_pool_t))
        _size = size;
    
    _pool = sxx_alloc(_size);

    if (_pool == NULL)
        return NULL;
    
    _pool->small->last = (sxx_uchar_t *)_pool + sizeof(sxx_memory_pool_t);
    _pool->small->end = (sxx_uchar_t *)_pool + _size;
    _pool->small->next = NULL;

    _size = _size - sizeof(sxx_memory_pool_t);
    _pool->max = (_size < SXX_POOL_DEFAULT_MAXSZIE) ? _size : SXX_POOL_DEFAULT_MAXSZIE;

    _pool->current = _pool->small;
    _pool->large = NULL;

    return _pool;
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
