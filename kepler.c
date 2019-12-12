/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** kepler.c
*/

#include "include/my.h"

static float get_time(sfClock *clock)
{
    return sfClock_getElapsedTime(clock).microseconds / 1000;
}

static void draw_sun(framebuffer *fb)
{
    sfColor col = {0};

    for (int i = 100; i > 0; i--) {
        col.r = 255 - 1.8 * i;
        col.b = 0;
        col.g = 255 - 1.8 * i;
        col.a = 255;
        draw_circle(fb, fb->width / 2, fb->height / 2, i, col);
    }
}

void planet(planete_info *i, framebuffer *fb, sfClock *t)
{
    stCoo planet_coo = {0};
    double w = (2 * 3.14) / (i->period * 1000);
    stCoo *prec = &(i->prec);

    i->coord = &planet_coo;
    i->coord->x = (i->radius * 2 * cos(w * get_time(t) + 180) + fb->width / 2);
    i->coord->y = (i->radius * sin(w * get_time(t) + 180) + fb->height / 2);
    draw_circle(fb, prec->x, prec->y, 20, sfBlack);
    draw_circle(fb, i->coord->x, i->coord->y, 20, i->color);
    prec->x = i->coord->x;
    prec->y = i->coord->y;
}

static void earth(framebuffer *fb, sfml_obj *obj, sfEvent event)
{
    sfClock *t = sfClock_create();
    stCoo prec = {0};
    planete_info mars_info = {0, 450, sfRed, 8, prec};
    planete_info earth_info = {0, 375, sfBlue, 6, prec};
    planete_info venus_info = {0, 225, sfYellow, 4, prec};
    planete_info mercure_info = {0, 170, sfGreen, 3, prec};
    planete_info jupiter_info = {0, 500, sfWhite, -12, prec};

    draw_sun(fb);
    while (sfRenderWindow_isOpen(obj->window)) {
        planet(&mars_info, fb, t);
        planet(&earth_info, fb, t);
        planet(&venus_info, fb, t);
        planet(&mercure_info, fb, t);
        planet(&jupiter_info, fb, t);
        update_screen(obj, fb);
        close_button(obj, event, fb);
    }
    sfClock_destroy(t);
}

void draw_kepler(framebuffer *fb, sfml_obj *obj) {
    sfEvent event;

    earth(fb, obj, event);
}