/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** randomess.c
*/

#include "include/my.h"

void draw_mess(framebuffer *fb, sfml_obj *obj)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(obj->window)) {
        draw_circle(fb, generate_rand_num(fb->width),
                    generate_rand_num(fb->height),
                    20, generate_rand_color());
        if (generate_rand_num(200) == generate_rand_num(200))
            framebuffer_clear(fb);
        update_screen(obj, fb);
        close_button(obj, event, fb);
    }
}