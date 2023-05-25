/*
** EPITECH PROJECT, 2022
** B-CPE-110-BAR-1-1-pushswap-gonzalo.larroya-martinez
** File description:
** my_put_str.c
*/

#include "../../include/my.h"

int	my_putstr(char const *str)
{
    int num;
    num = 0;
    while (str[num] != '\0'){
        my_putchar(str[num]);
        num++;
    }
    return (0);
}
