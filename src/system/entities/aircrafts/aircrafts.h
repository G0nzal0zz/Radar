/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef AIRCRAFTS_H_
    #define AIRCRAFTS_H_

    #include <string.h>
    #include "../../../oop/new/new.h"
    #include "../../../window/window.h"
    #include "../../../../include/my.h"
    #include "../../images/images.h"
    typedef struct s_AircraftsClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        sfRectangleShape *rectangle;
        sfVector2f rect_position;
        sfVector2f position;
        int arr_x;
        int arr_y;
        int velocity;
        float velocity_x;
        float velocity_y;
        int delay;
        ImageClass *_image;
        sfBool contact_checker;
        int angle;
        sfBool visible;
        /* Methods definitions */
        void (*__position__)(struct s_AircraftsClass*);
    }  AircraftsClass;

    extern const Class *Aircraft;

    #define set_position_(a)   ((AircraftsClass*)a)->__position__(a)


    #endif /* !AIRCRAFTS_H_ */