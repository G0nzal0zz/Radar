/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef TOWERS_H_
    #define TOWERS_H_

    #include <string.h>
    #include "../../../oop/new/new.h"
    #include "../../../window/window.h"
    #include "../../../../include/my.h"
    #include "../../images/images.h"

    typedef struct s_TowersClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        sfVector2f position;
        sfCircleShape *tower_area;
        sfVector2f circle_position;
        int rad;
        ImageClass *_image;
        sfBool contact_checker;
        int check;
        /* Methods definitions */
    }  TowersClass;

    extern const Class *Towers;


    #endif /* !TOWERS_H_ */