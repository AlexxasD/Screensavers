/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** dvd.c
*/

#include "include/my.h"

static void move_calc(v_dpl *vec)
{
    rotate(90 * M_PI / 180, vec);
}

static void move_circle(framebuffer *fb, circle *dvd, v_dpl *vect, int *even)
{
    int x_pos = dvd->x + dvd->radius + vect->x;
    int y_pos = dvd->y + dvd->radius + vect->y;
    double savex = vect->x;
    double savey = vect->y;

    draw_circle(fb, dvd->x, dvd->y, 50, sfBlack);
    while (x_pos >= fb->width || dvd->x - dvd->radius + vect->x <= 0 ||
            y_pos >= fb->height || dvd->y - dvd->radius + vect->y <= 0) {
        move_calc(vect);
        if (vect->x == -savex && vect->y == -savey && *(even) % 2 == 0) {
            rotate(90 * M_PI / 180, vect);
            *(even)++;
        }
        x_pos = dvd->x + dvd->radius + vect->x;
        y_pos = dvd->y + dvd->radius + vect->y;
        dvd->color = generate_rand_color();
    }
    dvd->x += vect->x;
    dvd->y += vect->y;
    *(even)++;
}

void dvd_f(framebuffer *fb, sfml_obj *obj)
{
    sfEvent event;
    v_dpl vect = {10, 0};
    circle dvd = {fb->width / 2, fb->height / 2, 50, sfRed};
    int even = 0;

    rotate(-45 * M_PI / 180, &vect);
    while (sfRenderWindow_isOpen(obj->window)) {
        draw_circle(fb, dvd.x, dvd.y, dvd.radius, dvd.color);
        update_screen(obj, fb);
        move_circle(fb, &dvd, &vect, &even);
        close_button(obj, event, fb);
    }
}