/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <string.h>
    #include "../../include/my.h"
    #include "../object/object.h"
    #include "../window/window.h"
    #include "../window/events/events.h"
    #include "scene/scene.h"
    #include "../system/entities/aircrafts/aircrafts.h"
    #include "../system/entities/entities.h"

    typedef struct s_GameClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        WindowClass *_window;
        SceneClass *_scene;
        EventsClass *_events;
        /* Methods definitions */
        int (*__process__)(struct s_GameClass*, EntitiesClass*);
        void (*__entities__)(struct s_GameClass*, EntitiesClass*);
        void (*__creator__)(struct s_GameClass*, EntitiesClass*);
    } GameClass;

    extern const Class *Game;

    #define process_game(g, e)   ((GameClass*)s)->__process__(g, e)
    #define _entities_display(g, e)   ((GameClass*)s)->__entities__(g, e)
    #define _entities_creator(g, e)   ((GameClass*)s)->__creator__(g, e)

    #endif /* !GAME_H_ */