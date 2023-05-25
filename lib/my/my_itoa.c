/*
** EPITECH PROJECT, 2022
** B-CPE-110-BAR-1-1-pushswap-gonzalo.larroya-martinez
** File description:
** my_itoa.c
*/

#include <string.h>
#include <stdlib.h>

char *my_itoa(int nb)
{
    int len;
    char		*str;
    int		tmp;

    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}
