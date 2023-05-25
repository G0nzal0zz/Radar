/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-gonzalo.larroya-martinez
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"

int count_sep(char const *str , char sep)
{
    int i = 0;
    int x = 1;
    while (str[i] != '\0') {
        if (str[i] == sep || str[i] != '\n')
            x = x + 1;
        i++;
    }
    return (x);
}

char **my_str_to_word_array(char const *str, char sep)
{
    int y = 0 ,cnt = 0,f = 0, n = 0, len = 0, k = 0;
    int x = count_sep(str, sep);
    char **string = malloc(sizeof(char*) * (x + 1));
    for (int i = 0; str[i]; i++){
        cnt = 0;
        y = i;
        while (str[y] != sep && str[y] != '\0' && str[y] != '\n') {
        cnt++; y++;
        }
    string[f] = malloc(sizeof(char)* (cnt + 1));
    k = 0;
        while (k < cnt) {
            string[f][k] = str[i];
            k++; i++;
        }
    string[f][cnt] = '\0';
    f++;
    }
    return (string);
}
