/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../../oop/new/new.h"
#include "../../window/window.h"
#include "../../../include/my.h"
#include "../../system/images/images.h"
#include "scene.h"

static void scene_display(SceneClass *this, WindowClass *window)
{
    sfRenderWindow_drawSprite(window->window, this->_image->sprite,NULL);
}

static void scene_ctor(SceneClass *this, va_list *args)
{
    // Initialize internal resources
    this->_image = new(Image, "assets/Espana.jpg", (sfVector2f){0, 0}, 0);
}

//destructor
static void game_dtor(SceneClass *this)
{
    // Release internal resources   
    sfRenderWindow_destroy(this->_window->window);
}

static const SceneClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(SceneClass),
        .__name__ = "Scene",
        .__ctor__ = (ctor_t)&scene_ctor,
        .__dtor__ = (dtor_t)&game_dtor,
    },
    ._image = NULL,
    ._window = NULL,
    /* Mehtods */
    .__display_scene__ = &scene_display,
};

const Class *Scene = (const Class*)&_description;