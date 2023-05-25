/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../../oop/new/new.h"
#include "../../window/window.h"
#include "../../../include/my.h"
#include "../../system/entities/entities.h"
#include "events.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static void manage_events(EventsClass *this, sfRenderWindow *_window)
{
    while (sfRenderWindow_pollEvent(_window, &this->_event)){
        if (this->_event.type == sfEvtClosed)
            sfRenderWindow_close(_window);

        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(_window);
    }
}

static void landing_event(EntitiesClass *_Entities, int i)
{
    if (_Entities->_aircrafts[i]->position.x -_Entities->_aircrafts[i]->arr_x < 2 
    &&_Entities->_aircrafts[i]->position.x - _Entities->_aircrafts[i]->arr_x > -2 &&
    _Entities->_aircrafts[i]->position.y -_Entities->_aircrafts[i]->arr_y < 2 
    &&_Entities->_aircrafts[i]->position.y - _Entities->_aircrafts[i]->arr_y > -2){
        _Entities->_aircrafts[i]->visible = sfFalse;
        _Entities->nb_flying_planes = _Entities->nb_flying_planes + 1;
    }
}

static void movement_timer(EventsClass *this, EntitiesClass *_Entities)
{
    if (this->timer >= 50) {
        for (int i = 0; i < _Entities->nb_airplanes; i++) {
            _Entities->_aircrafts[i]->position.x = _Entities->_aircrafts[i]->position.x + _Entities->_aircrafts[i]->velocity_x;
            _Entities->_aircrafts[i]->position.y = _Entities->_aircrafts[i]->position.y + _Entities->_aircrafts[i]->velocity_y;
            sfRectangleShape_setPosition(_Entities->_aircrafts[i]->rectangle, _Entities->_aircrafts[i]->position);
            sfSprite_setPosition(_Entities->_aircrafts[i]->_image->sprite,_Entities->_aircrafts[i]->position);
            sfClock_restart(this->plane_mvm);
            landing_event(_Entities, i);
        }
    }
}

static void events_ctor(EventsClass *this, va_list *args)
{
    // Initialize internal resources
    this->plane_mvm = sfClock_create();
    this->timer = 0;

}

//destructor
static void events_dtor(EventsClass *this)
{
    // Release internal resources
}

static const EventsClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(EventsClass),
        .__name__ = "Events",
        .__ctor__ = (ctor_t)&events_ctor,
        .__dtor__ = (dtor_t)&events_dtor,
    },
    /* Mehtods */
    ._timer__  = &movement_timer,
    ._manage__ = &manage_events,
};

const Class *Events = (const Class*)&_description;