/*
** EPITECH PROJECT, 2022
** get_color
** File description:
** Implementation of get_color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16) + (green << 8) + blue;
}
