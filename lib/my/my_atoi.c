/*
** EPITECH PROJECT, 2022
** B-CPE-110-BAR-1-1-BSQ-gonzalo.larroya-martinez
** File description:
** my_atoi.c
*/

#include "../../include/my.h"

int my_atoi(char *c)
{
    int  i = 0;
    int len;
    int sign = 0;
    int result = 0;
    if (c[0] == '-'){
    sign = 1;
    i++;
    }
    len = my_strlen(c);
    for (i ; i < len; i++) {
        result = result * 10 + ( c[i] - '0' );
    }
    if (sign == 1)
        result = result * -1;
    return (result);
}
