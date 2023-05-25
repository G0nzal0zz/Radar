/*
** EPITECH PROJECT, 2022
** task03
** File description:
** Function that counts and returns the number of characters in a string.
*/

#include <unistd.h>

int my_strlen( char const * str )
{
    int i = 0;

    while (str[i]){
        i ++;
    }
    i--;
    return (i + 1);
}
