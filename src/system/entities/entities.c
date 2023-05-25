/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../../oop/new/new.h"
#include "../../window/window.h"
#include "../../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "entities.h"
#include "../file/file.h"
#include "aircrafts/aircrafts.h"
#include "towers/towers.h"

static void tower_area(EntitiesClass *_Entities)
{
    float dist_x;
    float dist_y;
    float testX;
    float testY;
    for (int y = 0; y < _Entities->nb_towers; y++){
        _Entities->_towers[y]->check = 0;
        for (int i = 0; i < _Entities->nb_airplanes; i++){
        float distance = sqrt(pow((_Entities->_aircrafts[i]->position.x + 10) - (_Entities->_towers[y]->position.x + 25), 2) + pow((_Entities->_aircrafts[i]->position.y + 10) - (_Entities->_towers[y]->position.y + 25), 2));
        if (distance < 200 && _Entities->_aircrafts[i]->visible == sfTrue){
            _Entities->_towers[y]->check = _Entities->_towers[y]->check + 1;
            _Entities->_towers[y]->contact_checker = sfTrue;
        }
        if (distance >= 200 && _Entities->_towers[y]->check == 0 && _Entities->_aircrafts[i]->visible == sfTrue)
            _Entities->_towers[y]->contact_checker = sfFalse;
        }
        if (_Entities->_towers[y]->contact_checker == sfFalse)
            sfCircleShape_setOutlineColor(_Entities->_towers[y]->tower_area, sfGreen);
        else
            sfCircleShape_setOutlineColor(_Entities->_towers[y]->tower_area, sfRed);
    }
}

static void entities_setter(EntitiesClass *_Entities)
{
    for (int i = 0; i < _Entities->nb_airplanes; i++){
        _Entities->_aircrafts[i]->_image = new(Image, "assets/plane.png", _Entities->_aircrafts[i]->position, _Entities->_aircrafts[i]->angle);
        _Entities->_aircrafts[i]->visible = sfTrue;
    }
    for (int y = 0; y < _Entities->nb_towers; y++){
       _Entities->_towers[y]->_image = new(Image, "assets/tower.png", _Entities->_towers[y]->position, 0);
    }
    for (int i = 0; i < _Entities->nb_airplanes; i++){
        set_position_(_Entities->_aircrafts[i]);
    }
}

static void entities_ctor(EntitiesClass *this, va_list *args)
{
    // Initialize internal resources
    char *file_path = va_arg(*args, char*);
    FileClass *file = new(File, file_path);
    _nb_entities(file, this);
    this->_aircrafts = malloc(sizeof(AircraftsClass) * this->nb_airplanes);
    this->_towers = malloc(sizeof(TowersClass) * this->nb_towers);
    _get_entities(file, this, this->_aircrafts, this->_towers);
}

//destructor
static void entities_dtor(EntitiesClass *this)
{
    // Release internal resources
}

static const EntitiesClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(EntitiesClass),
        .__name__ = "Entities",
        .__ctor__ = (ctor_t)&entities_ctor,
        .__dtor__ = (dtor_t)&entities_dtor,
    },
    /* Mehtods */
    .__set_entitites__ = &entities_setter,
    .__check_collisions__ = &tower_area,
};

const Class *Entities = (const Class*)&_description;