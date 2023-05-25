/*
** EPITECH PROJECT, 2022
** oop
** File description:
** object.h
*/

#ifndef CLASS_H_
    # define CLASS_H_

    # include <sys/types.h>
    # include <stdarg.h>

    typedef void Object;
    typedef void (*ctor_t)(Object *this, va_list *args);
    typedef void (*dtor_t)(Object *this);

    typedef struct {
        /* Attributes */
        const size_t        __size__;
        const char          *__name__;

        /* Methods */
        ctor_t              __ctor__;
        dtor_t              __dtor__;
    } Class;

#endif /* !CLASS_H_ */