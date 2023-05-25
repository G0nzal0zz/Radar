/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/


#include "../../../../include/my.h"
#include "towers.h"

void set_radius_tower(TowersClass *this)
{
 
}

static void towers_ctor(TowersClass *this, va_list *args)
{
    // Initialize internal resources
    char **content = va_arg(*args, char**);
    int pos = va_arg(*args, int);
    this->position.x = my_atoi(content[pos + 1]);
    this->position.y = my_atoi(content[pos + 2]);
    this->rad = my_atoi(content[pos + 3]);
    this->tower_area = sfCircleShape_create();
    this->circle_position.x = (my_atoi(content[pos + 1]) - (this->rad) + 25);
    this->circle_position.y = (my_atoi(content[pos + 2]) - (this->rad) + 25 );
    sfCircleShape_setRadius(this->tower_area, this->rad);
    sfCircleShape_setPosition(this->tower_area, this->circle_position);
    sfCircleShape_setFillColor(this->tower_area, sfTransparent);
    sfCircleShape_setOutlineColor(this->tower_area, sfGreen);
    sfCircleShape_setOutlineThickness(this->tower_area, 1.0);
}

//destructor
static void towers_dtor(TowersClass *this)
{
    // Release internal resources   
  
}

static const TowersClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(TowersClass),
        .__name__ = "Towers",
        .__ctor__ = (ctor_t)&towers_ctor,
        .__dtor__ = (dtor_t)&towers_dtor,
    },
    /* Mehtods */
};

const Class *Towers = (const Class*)&_description;