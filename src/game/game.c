/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../oop/new/new.h"
#include "../window/window.h"
#include "game.h"
#include "../../include/my.h"
#include "scene/scene.h"
#include "../system/images/images.h"

static void game_display(GameClass *this)
{   
    display_sc(this->_scene, this->_window);
}

static void entities_display(GameClass *this, EntitiesClass *_Entities)
{
    for (int i = 0; i < _Entities->nb_airplanes; i++){
        if (_Entities->_aircrafts[i]->visible == sfTrue){
            sfRenderWindow_drawSprite(this->_window->window, _Entities->_aircrafts[i]->_image->sprite ,NULL);
            sfRenderWindow_drawRectangleShape(this->_window->window, _Entities->_aircrafts[i]->rectangle, 0);
        }
    }
    for (int i = 0; i < _Entities->nb_towers; i++){
        sfRenderWindow_drawSprite(this->_window->window, _Entities->_towers[i]->_image->sprite ,NULL);
        sfRenderWindow_drawCircleShape(this->_window->window, _Entities->_towers[i]->tower_area, 0);
    }
}

static int game_process(GameClass *this, EntitiesClass *_Entities)
{    
    this->_events = new(Events);
    _set_entities(_Entities);
    while (sfRenderWindow_isOpen(this->_window->window)) {
            if (_Entities->nb_airplanes == _Entities->nb_flying_planes)
                return(0);
            _manage_events(this->_events, this->_window->window);
            this->_events->timer = sfTime_asMilliseconds(sfClock_getElapsedTime(this->_events->plane_mvm));
            _movement_timer(this->_events, _Entities);
            sfRenderWindow_clear(this->_window->window, sfBlack);
            game_display(this);
            entities_display(this, _Entities);
            _tower_area(_Entities);
            sfRenderWindow_display(this->_window->window);
        }
}

static void game_ctor(GameClass *this, va_list *args)
{
    // Initialize internal resources
    this->_window = new(Window);
    this->_scene = new(Scene);
}

//destructor
static void game_dtor(GameClass *this)
{
    // Release internal resources   
    sfRenderWindow_destroy(this->_window->window);
}

static const GameClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(GameClass),
        .__name__ = "Game",
        .__ctor__ = (ctor_t)&game_ctor,
        .__dtor__ = (dtor_t)&game_dtor,
    },
    /* Mehtods */
    .__process__ = &game_process,
    .__entities__  = &entities_display,
};

const Class *Game = (const Class*)&_description;