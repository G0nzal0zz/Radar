/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <string.h>
    #include "../../system/entities/entities.h"


    typedef struct s_EventsClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        sfEvent _event;
        sfClock *plane_mvm;
        int timer;
        /* Methods definitions */
        void (*_timer__)(struct s_EventsClass*, EntitiesClass*);
        void (*_manage__)(struct s_EventsClass*, sfRenderWindow*);
    }  EventsClass;

    extern const Class *Events;
    #define _movement_timer(v, e)   ((EventsClass*)v)->_timer__(v, e)
    #define _manage_events(v, w)   ((EventsClass*)v)->_manage__(v, w)

   #endif /* !EVENTS_H_ */
