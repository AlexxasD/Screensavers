/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** globalfunc1.c
*/

#include "include/my.h"

void framebuffer_clear(framebuffer *fb)
{
    for (int i = 0; i < fb->height; i++)
        for (int v = 0; v < fb->width; v++)
            set_pixel(fb, v, i, sfBlack);
}

void close_button(sfml_obj *obj, sfEvent event, framebuffer *fb)
{
    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            if (obj->av[0] - '0' < ID_MAX) {
                framebuffer_clear(fb);
                obj->av[0] += 1;
                screen_chooser(obj->av, fb, obj);
            }
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            if (obj->av[0] - '0' > 0) {
                framebuffer_clear(fb);
                obj->av[0] += -1;
                screen_chooser(obj->av, fb, obj);
            }
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(obj->window);
    }
}

void update_screen(sfml_obj *obj, framebuffer *fb)
{
    sfTexture_updateFromPixels(obj->texture, fb->pixels,
                                fb->width, fb->height, 0, 0);
    sfRenderWindow_drawSprite(obj->window, obj->sprite, NULL);
    sfRenderWindow_display(obj->window);
}