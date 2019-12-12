/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** line_tracer.c
*/

#include "include/my.h"

void line_tracer(framebuffer *fb, sfml_obj *obj)
{
    sfEvent event;
    stCoo pt_a = {0};
    stCoo pt_b = {generate_rand_num(fb->width), generate_rand_num(fb->width)};

    while (sfRenderWindow_isOpen(obj->window)) {
        draw_line(fb, pt_b, pt_a, generate_rand_color());
        draw_line(fb, pt_a, pt_b, generate_rand_color());
        pt_a.x = pt_b.x;
        pt_a.y = pt_b.y;
        pt_b.x = generate_rand_num(fb->width);
        pt_b.y = generate_rand_num(fb->height);
        if (generate_rand_num(200) == generate_rand_num(200))
            framebuffer_clear(fb);
        update_screen(obj, fb);
        close_button(obj, event, fb);
    }
}