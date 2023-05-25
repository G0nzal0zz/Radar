/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-sokoban-gonzalo.larroya-martinez
** File description:
** my_sokoban.h
*/

// #include "../include/my.h"
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>


#ifndef TEXT_H_
    #define TEXT_H_

    #include "my.h"


typedef struct s_if_contact{
    int checker;
} if_contact;

typedef struct corner_s{
    sfIntRect area;
    unsigned int nb_circles;
    sfCircleShape **circles;
} corner_t;

typedef struct all_corners_s{
    corner_t *top_left;
    corner_t *top_right;
    corner_t *bottom_left;
    corner_t *bottom_right;  
} all_corners_t;
#endif
