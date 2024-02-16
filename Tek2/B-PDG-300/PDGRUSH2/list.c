/*
** EPITECH PROJECT, 2024
** list.c
** File description:
** list.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "list.h"
#include "new.h"

typedef struct ListNode_s ListNode;

struct ListNode_s {
    Object *value;
    ListNode *next;
};

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    ListNode *_head;
    ListNode *_tail;
} ListClass;

typedef struct {
    Iterator base;
    ListNode *_node;
    size_t index;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->index = va_arg(*args, size_t);
    this->_node = va_arg(*args, ListNode *);
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->index == other->index);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->index > other->index);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->index < other->index);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_node = this->_node->next;
    this->index += 1;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_node == NULL)
        raise("Out of range");
    return (this->_node->value);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list ap;

    if (this->_node == NULL)
        raise("Out of range");
    delete(this->_node->value);
    va_start(ap, this);
    this->_node->value = va_new(this->_node->value, &ap);
    va_end(ap);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        {
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t) &ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t) &ListIterator_eq,
            .__gt__ = (binary_comparator_t) &ListIterator_gt,
            .__lt__ = (binary_comparator_t) &ListIterator_lt
        },
        .__incr__ = (incr_t) &ListIterator_incr,
        .__getval__ = (getval_t) &ListIterator_getval,
        .__setval__ = (setval_t) &ListIterator_setval,
    },
    ._node = NULL,
    .index = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static void List_push_back(ListClass *this, va_list *copy)
{
    ListNode *node = malloc(sizeof(ListNode));
    Object *obj = va_new(this->_type, copy);

    if (node == NULL)
        raise("Out of memory");
    node->value = obj;
    node->next = NULL;
    if (this->_head == NULL) {
        this->_head = node;
        this->_tail = node;
    } else {
        this->_tail->next = node;
        this->_tail = node;
    }
    this->_size += 1;
}

static void List_ctor(ListClass *this, va_list *args)
{
    va_list args_copy;
    size_t size = va_arg(*args, size_t);

    this->_type = va_arg(*args, Class *);
    this->_head = NULL;
    this->_tail = NULL;
    for (size_t i = 0; i < size; i++) {
        va_copy(args_copy, *args);
        List_push_back(this, &args_copy);
        va_end(args_copy);
    }
}

static void List_dtor(ListClass *this)
{
    ListNode *tmp = this->_head;
    ListNode *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        delete(tmp->value);
        free(tmp);
        tmp = next;
    }
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, 0ul, this->_head));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this->_size, this->_tail));
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list args;
    size_t index;
    ListNode *tmp = this->_head;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);
    if (index >= this->_size)
        raise("Out of range");
    for (size_t i = 0; i < index; i++)
        tmp = tmp->next;
    return (tmp->value);
}

static void List_setitem(ListClass *this, ...)
{
    va_list args;
    size_t index;
    ListNode *tmp = this->_head;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index >= this->_size)
        raise("Out of range");
    for (size_t i = 0; i < index; i++)
        tmp = tmp->next;
    delete(tmp->value);
    tmp->value = va_new(this->_type, &args);
    va_end(args);
}

static const ListClass _descr = {
    {
        {
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t) &List_ctor,
            .__dtor__ = (dtor_t) &List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL
        },
        .__len__ = (len_t) &List_len,
        .__begin__ = (iter_t) &List_begin,
        .__end__ = (iter_t) &List_end,
        .__getitem__ = (getitem_t) &List_getitem,
        .__setitem__ = (setitem_t) &List_setitem
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL,
    ._tail = NULL
};

const Class *List = (const Class *)&_descr;
