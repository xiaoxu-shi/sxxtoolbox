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
    sxx_uint32_t        failed;
};

struct sxx_memory_pool_t
{
    sxx_size_t  max;
    sxx_memory_pool_data_t d;
    sxx_memory_pool_t *current;
    sxx_memory_large_node_t *large;
};

static sxx_inline sxx_ptr_t sxx_memory_small_alloc(sxx_memory_pool_t *pool, sxx_size_t size);
static sxx_inline sxx_ptr_t sxx_memory_large_alloc(sxx_memory_pool_t *pool, sxx_size_t size);
static sxx_inline sxx_ptr_t sxx_memory_block_alloc(sxx_memory_pool_t *pool, sxx_size_t size);

SXX_DECLARE(sxx_memory_pool_t*) sxx_memory_pool_create(sxx_size_t size)
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
    _pool->d.failed = 0;

    _size = _size - sizeof(sxx_memory_pool_t);
    _pool->max = (_size < SXX_POOL_DEFAULT_MAXSZIE) ? _size : SXX_POOL_DEFAULT_MAXSZIE;

    _pool->current = _pool;
    _pool->large = NULL;

    return _pool;
}

SXX_DECLARE(sxx_void_t) sxx_memory_pool_reset(sxx_memory_pool_t *pool)
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
        p->d.failed = 0;
    }
    
    pool->current = pool;
    pool->large = NULL;
}

SXX_DECLARE(sxx_void_t) sxx_memory_pool_distory(sxx_memory_pool_t *pool)
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

SXX_DECLARE(sxx_ptr_t) sxx_memory_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    if (size < pool->max) {
        return sxx_memory_small_alloc(pool, size);
    }

    return sxx_memory_large_alloc(pool, size);
}

SXX_DECLARE(sxx_ptr_t) sxx_memory_calloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    sxx_ptr_t p = NULL;

    p = sxx_memory_alloc(pool, size);
    if ( p != NULL) {
        sxx_memzero(p, size);
    }

    return p;
}

static sxx_inline sxx_ptr_t sxx_memory_small_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    sxx_uchar_t *m = NULL;
    sxx_memory_pool_t *p = NULL;

    p = pool->current;

    do {
        m = p->d.last;

        if ((sxx_size_t) (p->d.end - m) >= size) {
            p->d.last = m + size;

            return m;
        }

        p = p->d.next;

    } while (p);

    return sxx_memory_block_alloc(pool, size);
}

static sxx_inline sxx_ptr_t sxx_memory_large_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    sxx_uint32_t n;
    sxx_ptr_t p = NULL;
    sxx_memory_large_node_t  *l = NULL;

    p = sxx_alloc(size);
    if (p == NULL) {
        return NULL;
    }

    n = 0;

    for (l = pool->large; l; l = l->next) {
        if (l->alloc == NULL) {
            l->alloc = p;
            return p;
        }

        if (n++ > 3) {
            break;
        }
    }

    l = sxx_memory_small_alloc(pool, sizeof(sxx_memory_large_node_t));
    if (l == NULL) {
        sxx_free(p);
        return NULL;
    }

    l->alloc = p;
    l->next = pool->large;
    pool->large = l;

    return p;
}

static sxx_inline sxx_ptr_t sxx_memory_block_alloc(sxx_memory_pool_t *pool, sxx_size_t size)
{
    sxx_size_t psize;
    sxx_ptr_t m = NULL;
    sxx_memory_pool_t  *p = NULL, *n = NULL;

    psize = (sxx_size_t) (pool->d.end - (sxx_uchar_t *)pool);

    m = sxx_alloc(psize);
    if (m == NULL) {
        return NULL;
    }

    n = (sxx_memory_pool_t *) m;

    n->d.end = (sxx_uchar_t *)m + psize;
    n->d.last = (sxx_uchar_t *)m + sizeof(sxx_memory_pool_t);
    n->d.next = NULL;
    n->d.failed = 0;

    for (p = pool->current; p->d.next; p = p->d.next) {
        if (p->d.failed++ > 4) {
            pool->current = p->d.next;
        }
    }

    p->d.next = n;

    return m;
}

SXX_DECLARE(sxx_void_t) sxx_memeory_free(sxx_memory_pool_t *pool, sxx_ptr_t p)
{
    sxx_memory_large_node_t  *l = NULL;

    for (l = pool->large; l; l = l->next) {
        if (p == l->alloc) {
            sxx_free(l->alloc);
            l->alloc = NULL;
        }
    }
}

