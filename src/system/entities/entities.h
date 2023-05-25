/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_

    #include <string.h>
    #include "../../oop/new/new.h"
    #include "../../window/window.h"
    #include "../../../include/my.h"
    #include "../entities/aircrafts/aircrafts.h"
    #include "../entities/towers/towers.h"

    typedef struct s_EntitiesClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        int nb_airplanes;
        int nb_flying_planes;
        int nb_towers;
        AircraftsClass **_aircrafts;
        TowersClass **_towers;
        /* Methods definitions */
        void (*__set_entitites__)(struct s_EntitiesClass*);
        void (*__check_collisions__)(struct s_EntitiesClass*);
    }  EntitiesClass;

    extern const Class *Entities;
    #define _set_entities(e)   ((EntitiesClass*)e)->__set_entitites__(e)
    #define _tower_area(e)   ((EntitiesClass*)e)->__check_collisions__(e)

    #endif /* !ENTITIES_H_ */