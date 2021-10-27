#include "sxx_mpool.h"
#include "sxx_alloc.h"

#define SXX_POOL_DEFAULT_SIZE (16 * 1024)
#define SXX_POOL_DEFAULT_MAXSZIE (4 * 1024)

typedef struct sxx_memory_pool_data_t sxx_memory_pool_data_t;
typedef struct sxx_memory_large_node_t sxx_memory_large_node_t;

struct sxx_memory_large_node_t
{
    sxx_uchar_t *alloc;
    sxx_memory_large_node_t *next;
};

struct sxx_memory_pool_data_t {
    sxx_uchar_t         *last;
    sxx_uchar_t         *end;
    sxx_memory_pool_t   *next;
};

struct sxx_memory_pool_t
{
    sxx_size_t  max;
    sxx_memory_pool_data_t d;
    sxx_memory_pool_t *current;
    sxx_memory_large_node_t *large;
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
    
    _pool->d.last = (sxx_uchar_t *)_pool + sizeof(sxx_memory_pool_t);
    _pool->d.end = (sxx_uchar_t *)_pool + _size;
    _pool->d.next = NULL;

    _size = _size - sizeof(sxx_memory_pool_t);
    _pool->max = (_size < SXX_POOL_DEFAULT_MAXSZIE) ? _size : SXX_POOL_DEFAULT_MAXSZIE;

    _pool->current = _pool;
    _pool->large = NULL;

    return _pool;
}

sxx_void_t sxx_memory_pool_reset(sxx_memory_pool_t *pool)
{
    sxx_memory_pool_t *p = NULL;
    sxx_memory_large_node_t *l = NULL;

    for (l = pool->large; l ; l = l->next) {
        if (l->alloc) {
            sxx_free(l->alloc);
        }
    }

    for (p = pool; p; p = p->d.next)
    {
        p->d.last = (sxx_uchar_t *)p + sizeof(sxx_memory_pool_t); 
    }
    
    pool->current = pool;
    pool->large = NULL;
}

sxx_void_t sxx_memory_pool_distory(sxx_memory_pool_t *pool)
{
    sxx_memory_pool_t *p = NULL;
    sxx_memory_pool_t *n = NULL;
    sxx_memory_large_node_t *l = NULL;

    for (l = pool->large; l; l = l->next) {
        if (l->alloc) {
            sxx_free(l->alloc);
        }
    }

    for (p = pool, n = pool->d.next; /*no*/ ; p = n, n = n->d.next) {
        sxx_free(p);

        if (n == NULL) {
            break;
        }
    }
}

sxx_ptr_t sxx_memory_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    return NULL;
}

sxx_ptr_t sxx_memory_calloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    return NULL;
}


