/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-sokoban-gonzalo.larroya-martinez
** File description:
** my.h
*/


#ifndef _MY_H_
    #define _MY_H_
    #include "my_radar.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <time.h>
    #include <math.h>

    int my_putchar(char c);
    int	my_putstr(char const *str);
    int	my_strcmp(char *s1, char *s2);
    char *my_itoa(int nb);
    int my_atoi(char *c);
    int my_strlen( char const * str );
    int check_intersection(sfCircleShape *c1, sfCircleShape *c2, if_contact *contact);
    int check_each_circle(int num_circles, sfCircleShape **circle, if_contact *contact);
    char **my_str_to_word_array(char const *str, char sep);

#endif /* !_MY_H_ */
