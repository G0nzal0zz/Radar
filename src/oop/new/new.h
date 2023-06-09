/*
** EPITECH PROJECT, 2022
** oop
** File description:
** new.h
*/

#ifndef NEW_H_
    # define NEW_H_

    #include <stdarg.h>
    #include "../../object/object.h"

    Object* new(const Class *class, ...);
    Object* va_new(const Class *class, va_list* ap);
    void    delete(Object *ptr);

#endif /* !NEW_H_ */