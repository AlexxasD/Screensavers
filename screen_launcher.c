/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** screen_launcher.c
*/

#include "include/my.h"

static void display_usage(void)
{
    my_putstr("animation rendering in a CSFML window.\n");
    my_putstr("\nUSAGE\n ./myscreensaver   [OPTIONS] animation_id\n animatio");
    my_putstr("n_id      ID of the animation to process (between 1 and 4).\n");
    my_putstr("\nOPTIONS\n -h                print the usage and quit.\n");
    my_putstr("\nUSER INTERACIONS\n LEFT_ARROW        switch to the ");
    my_putstr("previous animation.\n RIGHT_ARROW       switch to the next");
    my_putstr(" animation.\n");
}

void screen_chooser(char *id, framebuffer *fb, sfml_obj *obj)
{
    char nb = id[0] - '0';

    if (my_strcmp(id, "-h") == 0)
        display_usage();
    if (nb == 1)
        draw_kepler(fb, obj);
    if (nb == 2)
        draw_mess(fb, obj);
    if (nb == 3)
        dvd_f(fb, obj);
    if (nb == 4)
        line_tracer(fb, obj);
}