/*
** EPITECH PROJECT, 2022
** B-CPE-101-BAR-1-1-myprintf-gonzalo.larroya-martinez
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(char c)
{
    write (1, &c, 1);
    return (1);
}
