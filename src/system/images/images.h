/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <string.h>
    #include "../../oop/new/new.h"
    #include "../../window/window.h"
    #include "../../../include/my.h"
    #include "images.h"

    typedef struct s_ImageClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        sfSprite *sprite;
        sfTexture *texture;     
        /* Methods definitions */
        void (*__set_image__)(struct s_ImageClass*);
    }  ImageClass;

    extern const Class *Image;

    #define _set_image(s)   ((ImageClass*)s)->__set_image__(s)

    #endif /* !IMAGE_H_ */