/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../../oop/new/new.h"
#include "../../window/window.h"
#include "../../../include/my.h"
#include "images.h"

static void set_image(ImageClass *this)
{
    sfSprite_setTexture(this->sprite, this->texture, sfFalse);
}

static void image_ctor(ImageClass *this, va_list *args)
{

    // Initialize internal resources
    this->texture = sfTexture_createFromFile(va_arg(*args, char*), sfFalse);
    this->sprite = sfSprite_create();
    sfSprite_setPosition(this->sprite, va_arg(*args, sfVector2f));
    sfSprite_setTexture(this->sprite, this->texture, sfFalse);
    int angle = va_arg(*args, int);
    if(angle)
        sfSprite_setRotation(this->sprite, angle);
}

//destructor
static void image_dtor(ImageClass *this)
{
    // Release internal resources   
    sfSprite_destroy(this->sprite);
    sfTexture_destroy(this->texture);
}

static const ImageClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(ImageClass),
        .__name__ = "Image",
        .__ctor__ = (ctor_t)&image_ctor,
        .__dtor__ = (dtor_t)&image_dtor,
    },
    /* Mehtods */
    .__set_image__ = &set_image,
};

const Class *Image = (const Class*)&_description;