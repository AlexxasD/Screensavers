/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays one by one each characters of a string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    write(1, str, i);
    return (0);
}
