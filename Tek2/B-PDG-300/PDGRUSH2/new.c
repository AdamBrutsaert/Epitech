/*
** EPITECH PROJECT, 2024
** new.c
** File description:
** new.c
*/

#include "new.h"

#include <stdlib.h>

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list ap;
    
    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return obj;
}

void delete(Object *ptr)
{
    const Class *class = ptr;

    if (ptr == NULL)
        raise("Cannot delete NULL");
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return obj;
}
