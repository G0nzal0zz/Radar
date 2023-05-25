/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.h
*/

#ifndef FILE_H_
    #define FILE_H_

    #include <string.h>
    #include "../../oop/new/new.h"
    #include "../../window/window.h"
    #include "../../../include/my.h"
    #include "file.h"
    #include "../entities/towers/towers.h"
    #include "../entities/aircrafts/aircrafts.h"
    #include "../entities/entities.h"

    typedef struct s_FileClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        char *path;
        char *content;
        char **sep_content;
        int _size;
        /* Methods definitions */
        void (*__get_entitites__)(struct s_FileClass*, EntitiesClass*, AircraftsClass**, TowersClass**);
        void (*__nb_entitites__)(struct s_FileClass*, EntitiesClass*);
    }  FileClass;

    extern const Class *File;

    #define _get_entities(f, e, a, t)   ((FileClass*)f)->__get_entitites__(f, e, a, t)
    #define _nb_entities(f, e)   ((FileClass*)f)->__nb_entitites__(f, e)
    #endif /* !FILE_H_ */