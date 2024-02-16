/*
** EPITECH PROJECT, 2022
** swap_endian_color
** File description:
** Implementation of swap_endian_color
*/

union color {
    int value;
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
};

int swap_endian_color(int color)
{
    union color c = { .value = color };
    union color c2 = { .value = color };

    c.bytes.byte1 = c2.bytes.byte4;
    c.bytes.byte2 = c2.bytes.byte3;
    c.bytes.byte3 = c2.bytes.byte2;
    c.bytes.byte4 = c2.bytes.byte1;
    return c.value;
}
