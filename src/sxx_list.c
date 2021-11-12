#include "sxx_list.h"

static sxx_inline sxx_void_t sxx_link_node(sxx_ptr_t prev, sxx_ptr_t next)
{
    SXX_LIST_OBJECT_PTR(prev)->next = next;
    SXX_LIST_OBJECT_PTR(next)->prev = prev;
}

SXX_DECLARE(sxx_void_t) sxx_list_init(sxx_ptr_t ptr)
{
    SXX_LIST_OBJECT_PTR(ptr)->next = SXX_LIST_OBJECT_PTR(ptr)->prev = ptr;
}

SXX_DECLARE(sxx_bool_t) sxx_list_empty(const sxx_ptr_t ptr)
{
    return (SXX_LIST_OBJECT_PTR(ptr)->next == ptr);
}

SXX_DECLARE(sxx_void_t) sxx_list_insert_before(sxx_ptr_t pos, sxx_ptr_t node)
{
    sxx_list_insert_after(SXX_LIST_OBJECT_PTR(pos)->prev, node);
}

SXX_DECLARE(sxx_void_t) sxx_list_insert_after(sxx_ptr_t pos, sxx_ptr_t node)
{
    SXX_LIST_OBJECT_PTR(node)->prev = pos;
    SXX_LIST_OBJECT_PTR(node)->next = SXX_LIST_OBJECT_PTR(pos)->next;
    SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(pos)->next)->prev = node;
    SXX_LIST_OBJECT_PTR(pos)->next = node;
}

SXX_DECLARE(sxx_void_t) sxx_list_push_back(sxx_ptr_t list, sxx_ptr_t node)
{
    sxx_list_insert_before(list, node);
}

SXX_DECLARE(sxx_void_t) sxx_list_push_front(sxx_ptr_t list, sxx_ptr_t node)
{
    sxx_list_insert_after(list, node);
}

SXX_DECLARE(sxx_void_t) sxx_list_insert_nodes_before(sxx_ptr_t pos, sxx_ptr_t lst)
{
    sxx_list_insert_nodes_after(SXX_LIST_OBJECT_PTR(pos)->prev, lst);
}

SXX_DECLARE(sxx_void_t) sxx_list_insert_nodes_after(sxx_ptr_t pos, sxx_ptr_t lst)
{
    sxx_list_ptr_t lst_last = SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(lst)->prev);
    sxx_list_ptr_t pos_next = SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(pos)->next);

    sxx_link_node(pos, lst);
    sxx_link_node(lst_last, pos_next);
}

SXX_DECLARE(sxx_void_t) sxx_list_merge_first(sxx_ptr_t lst1, sxx_ptr_t lst2)
{
    if (!sxx_list_empty(lst2)) {
        sxx_link_node(SXX_LIST_OBJECT_PTR(lst2)->prev, SXX_LIST_OBJECT_PTR(lst1)->next);
        sxx_link_node(SXX_LIST_OBJECT_PTR(lst1), SXX_LIST_OBJECT_PTR(lst2)->next);
        sxx_list_init(lst2);
    }
}

SXX_DECLARE(sxx_void_t) sxx_list_merge_last(sxx_ptr_t lst1, sxx_ptr_t lst2)
{
    if (!sxx_list_empty(lst2)) {
        sxx_link_node(SXX_LIST_OBJECT_PTR(lst1)->prev, SXX_LIST_OBJECT_PTR(lst2)->next);
        sxx_link_node(SXX_LIST_OBJECT_PTR(lst2)->prev, lst1);
        sxx_list_init(lst2);
    }
}

SXX_DECLARE(sxx_size_t) sxx_list_size(const sxx_ptr_t list)
{
    sxx_size_t size = 0;
    sxx_list_ptr_t node = SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(list)->next); 
    
    while (node != list) {
	    ++size;
	    node = SXX_LIST_OBJECT_PTR(node->next);
    }

    return size;
}

SXX_DECLARE(sxx_void_t) sxx_list_erase(sxx_ptr_t node)
{
    sxx_link_node(SXX_LIST_OBJECT_PTR(node)->prev, SXX_LIST_OBJECT_PTR(node)->next);
    sxx_list_init(node);
}

SXX_DECLARE(sxx_ptr_t) sxx_list_find(sxx_ptr_t list, sxx_ptr_t node)
{
    sxx_list_ptr_t p = SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(list)->next);
    while (p != list && p != node)
        p = SXX_LIST_OBJECT_PTR(p->next);

    return (p==node ? p : NULL);
}

SXX_DECLARE(sxx_ptr_t) sxx_list_search(sxx_ptr_t list, sxx_ptr_t val, sxx_bool_t (*cmp)(sxx_ptr_t val, const sxx_ptr_t node))
{
    sxx_list_ptr_t p = SXX_LIST_OBJECT_PTR(SXX_LIST_OBJECT_PTR(list)->next);
    while (p != list && (*cmp)(val, p) != SXX_TRUE)
	    p = SXX_LIST_OBJECT_PTR(p->next);

    return (p==list ? NULL : p);
}

