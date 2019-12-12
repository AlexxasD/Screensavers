/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** draw_things.c
*/

#include "include/my.h"

void draw_square(framebuffer *fb, int x, int y, sfColor color)
{
    for (int i = x; i < fb->width + x; i++) {
        for (int v = y; v < fb->height + y; v++) {
            set_pixel(fb, i, v, color);
        }
    }
}

void draw_circle(framebuffer *fb, int x, int y, int rayon, sfColor color)
{
    for (int i = 0; i < fb->width; i++) {
        for (int v = 0; v < fb->height; v++) {
            if ((i - x) * (i - x) + (v - y) * (v - y) <= rayon * rayon)
                set_pixel(fb, i, v, color);
        }
    }
}

void draw_line(framebuffer *fb, stCoo coord, stCoo coord2, sfColor color)
{
    int pt1 = coord2.y - coord.y;
    int pt2 = coord2.x - coord.x;
    float pt_ax = coord.x;
    float pt_ay = coord.y;
    float stepi = ((float)pt1 / (float)MAX(ABS(pt1), ABS(pt2)));
    float stepj = ((float)pt2 / (float)MAX(ABS(pt1), ABS(pt2)));

    for (float i = (float)coord.y; (int)i != coord2.y; i += stepi) {
        set_pixel(fb, (int)pt_ax, (int)i, color);
        pt_ax += stepj;
    }
    for (float j = (float)coord.x; (int)j != coord2.x; j += stepj) {
        set_pixel(fb, (int)j, (int)pt_ay, color);
        pt_ax += stepi;
    }
}