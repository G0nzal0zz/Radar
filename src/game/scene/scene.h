/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include <string.h>
    #include "../../oop/new/new.h"
    #include "../../window/window.h"
    #include "../../../include/my.h"
    #include "../../system/images/images.h"

    typedef struct s_SceneClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        WindowClass *_window;
        ImageClass *_image;

        /* Methods definitions */
        void (*__display_scene__)(struct s_SceneClass*, WindowClass*);
    } SceneClass;

    extern const Class *Scene;

    #define display_sc(s, w)   ((SceneClass*)s)->__display_scene__(s, w)

    #endif /* !SCENE_H_ */