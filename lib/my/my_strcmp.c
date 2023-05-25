/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-gonzalo.larroya-martinez
** File description:
** my_strcmp.c
*/

int	my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}
