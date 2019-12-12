/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** square.c
*/

#include "include/my.h"

void move_horizontal(circle *c, v_dpl *vect_move, sfClock *t)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(t)) >= 10) {
        c->x += vect_move->x;
        sfClock_restart(t);
    }
}

void move_vertical(circle *c, v_dpl *vect_move, sfClock *t)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(t)) >= 10) {
        c->y += vect_move->y;
        sfClock_restart(t);
    }
}

static void move_it(circle *c, framebuffer *fb,
                    v_dpl *vect_move, sfClock *t)
{
    int sens = 0;
    int done = 0;

    if (c->x <= fb->width - fb->width / 3 && sens == 0)
        move_horizontal(c, vect_move, t);
    if (c->x > fb->width - fb->width / 3 && done == 0) {
        sens = 1;
        rotate(-90 * M_PI / 180, vect_move);
        done++;
    }
    if (c->y <= fb->height - fb->height / 3 && sens == 1)
        move_vertical(c, vect_move, t);
}

void make_square(framebuffer *fb, sfml_obj *obj)
{
    sfEvent event;
    circle c = {fb->width / 3, fb->height / 3, 20, generate_rand_color()};
    v_dpl vect_move = {10, 0};
    sfClock *t = sfClock_create();

    while (sfRenderWindow_isOpen(obj->window)) {
        draw_circle(fb, c.x, c.y, c.radius, c.color);
        move_it(&c, fb, &vect_move, t);
        update_screen(obj, fb);
        close_button(obj, event, fb);
    }
}