/*
** EPITECH PROJECT, 2022
** oop
** File description:
** window.c
*/

#include "../../include/my.h"
#include "stdio.h"
#include "window.h"
#include "stdlib.h"

//constructor
static void window_ctor(WindowClass *this, va_list *args)
{
    // Initialize internal resources
    this->mode = (sfVideoMode){1920, 1080, 32};
    this->window = sfRenderWindow_create(this->mode, "my_radar",
    sfClose | sfResize, NULL);
}

//destructor
static void window_dtor(WindowClass *this)
{
    // Release internal resources
    sfRenderWindow_destroy(this->window);
}

static const WindowClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(WindowClass),
        .__name__ = "Window",
        .__ctor__ = (ctor_t)&window_ctor,
        .__dtor__ = (dtor_t)&window_dtor,
    },
    .window = NULL,
    /* Mehtods */
};

const Class *Window = (const Class*)&_description;