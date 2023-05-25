/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/


#include "../../../../include/my.h"
#include "aircrafts.h"
#include <math.h>
#include "stdio.h"

void set_position(AircraftsClass *this)
{
    double distance = sqrt((pow(this->arr_x - this->position.x, 2) + pow(this->arr_y - this->position.y, 2)));
    this->velocity_x = ((this->arr_x - this->position.x) / distance) * this->velocity;
    this->velocity_y = ((this->arr_y - this->position.y) / distance) * this->velocity;
}

static void aircraft_ctor(AircraftsClass *this, va_list *args)
{
    // Initialize internal resources
    char **content = va_arg(*args, char**);
    int pos = va_arg(*args, int);
    this->rect_position.x = 20;
    this->rect_position.y = 20;
    this->position.x = my_atoi(content[pos + 1]);
    this->position.y = my_atoi(content[pos + 2]);
    this->arr_x = my_atoi(content[pos + 3]);
    this->arr_y = my_atoi(content[pos + 4]);
    this->velocity = my_atoi(content[pos + 5]);
    this->delay = my_atoi(content[pos + 6]);
    this->rectangle = sfRectangleShape_create();
    float distance = sqrt(pow((this->position.x) - (this->arr_x), 2) + pow((this->position.y) - (this->arr_y), 2));
    float distance_x = abs(this->position.x - this->arr_x);
    float angle1 = acos(distance_x/distance);
    this->angle = angle1 * (180 / M_PI);
    if ((this->position.x - this->arr_x) > 0)
        this->angle = this->angle + 180; 
    sfRectangleShape_setSize(this->rectangle, this->rect_position);
    sfRectangleShape_setPosition(this->rectangle, this->position);
    sfRectangleShape_setFillColor(this->rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(this->rectangle, sfGreen);
    sfRectangleShape_setOutlineThickness(this->rectangle, 1.0);
    sfRectangleShape_setRotation(this->rectangle, this->angle);
}

//destructor
static void aircraft_dtor(AircraftsClass *this)
{
    // Release internal resources   
  
}

static const AircraftsClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(AircraftsClass),
        .__name__ = "Aircraft",
        .__ctor__ = (ctor_t)&aircraft_ctor,
        .__dtor__ = (dtor_t)&aircraft_dtor,
    },
    /* Mehtods */
    .__position__ = &set_position,
};

const Class *Aircraft = (const Class*)&_description;