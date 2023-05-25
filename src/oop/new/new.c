/*
** EPITECH PROJECT, 2022
** oop
** File description:
** new.c
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdarg.h>
#include "../../object/object.h"
#include "new.h"
#include <stdio.h>

Object *new(const Class *class, ...)
{
    va_list ap;
    Object  *object;

    va_start(ap, class);
    object = va_new(class, &ap);
    va_end(ap);
    return (object);
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *object;

    if (class == NULL || class->__size__ < sizeof(*class))
        printf("invalid class");
    object = malloc(class->__size__);
    if (object == NULL)
        printf("malloc failed");
    memcpy(object, class, class->__size__);
    if (object->__ctor__ != NULL)
        object->__ctor__(object, ap);
    return (object);
}