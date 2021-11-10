#ifndef __SXX_PLIST_H__
#define __SXX_PLIST_H__
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"
#include "toolbox/sxx_mpool.h"

SXX_EXTERN_C_BEGIN

#define SXX_LIST_MEMBER \
    sxx_ptr_t prev; \
    sxx_ptr_t next

#define SXX_LIST_OBJECT_PTR(obj) ((sxx_list_ptr_t)obj)


struct sxx_list_t
{
    SXX_LIST_MEMBER;
};
typedef struct sxx_list_t sxx_list_t;
typedef sxx_list_t* sxx_list_ptr_t;

SXX_DECLARE(sxx_void_t) sxx_list_init(sxx_ptr_t ptr);

SXX_DECLARE(sxx_bool_t) sxx_list_empty(const sxx_ptr_t ptr);

SXX_DECLARE(sxx_void_t) sxx_list_insert_before(sxx_ptr_t pos, sxx_ptr_t node);

SXX_DECLARE(sxx_void_t) sxx_list_insert_after(sxx_ptr_t pos, sxx_ptr_t node);

SXX_DECLARE(sxx_void_t) sxx_list_insert_nodes_before(sxx_ptr_t pos, sxx_ptr_t lst);

SXX_DECLARE(sxx_void_t) sxx_list_insert_nodes_after(sxx_ptr_t pos, sxx_ptr_t lst);

SXX_DECLARE(sxx_void_t) sxx_list_push_back(sxx_ptr_t list, sxx_ptr_t node);

SXX_DECLARE(sxx_void_t) sxx_list_push_front(sxx_ptr_t list, sxx_ptr_t node);

SXX_DECLARE(sxx_void_t) sxx_list_merge_first(sxx_ptr_t lst1, sxx_ptr_t lst2);

SXX_DECLARE(sxx_void_t) sxx_list_merge_last(sxx_ptr_t lst1, sxx_ptr_t lst2);

SXX_DECLARE(sxx_size_t) sxx_list_size(const sxx_ptr_t list);

SXX_DECLARE(sxx_void_t) sxx_list_erase(sxx_ptr_t node);

SXX_DECLARE(sxx_ptr_t) sxx_list_find(sxx_ptr_t list, sxx_ptr_t node);

SXX_DECLARE(sxx_ptr_t) sxx_list_search(sxx_ptr_t list, sxx_ptr_t val, int (*cmp)(sxx_ptr_t val, const sxx_ptr_t node));

SXX_EXTERN_C_END

#endif // ! __SXX_PLIST_H__
