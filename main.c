/*
** EPITECH PROJECT, 2019
** bootstrap_csml
** File description:
** main.c
*/

#include "include/my.h"

static framebuffer *framebuffer_create(int width, int height) {
    framebuffer *fb = malloc(sizeof(framebuffer));

    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(fb->width * fb->height * 32 / 8);
    return fb;
}

void set_pixel(framebuffer *fb, int x, int y, sfColor color)
{
    int formula = 4 * fb->width * (y - 1) + 4 * x;

    if (x > 0 && x < fb->width && y < fb->height && y > 0) {
        fb->pixels[formula] = color.r;
        fb->pixels[formula + 1] = color.g;
        fb->pixels[formula + 2] = color.b;
        fb->pixels[formula + 3] = color.a;
    }
}

int generate_rand_num(int max)
{
    int random = rand() % (max + 1);
    return random;
}

sfColor generate_rand_color(void)
{
    sfColor color;

    color.r = rand() % (255 + 1);
    color.g = rand() % (255 + 1);
    color.b = rand() % (255 + 1);
    color.a = 255;
    return color;
}

int main(int ac, char **av)
{
    framebuffer *fb = framebuffer_create(1920, 1080);
    sfVideoMode video_mode = {fb->width, fb->height, 32};
    sfRenderWindow *my_window = sfRenderWindow_create(video_mode,
                                "je suis une fenetre", sfFullscreen, NULL);
    sfTexture *texture = sfTexture_create(fb->width, fb->height);
    sfSprite *sprite = sfSprite_create();
    sfml_obj obj = {texture, sprite, my_window, av[1]};

    if (ac != 2)
        return 84;
    srand(time(NULL));
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(my_window, 60);
    screen_chooser(obj.av, fb, &obj);
    sfRenderWindow_destroy(my_window);
    return 0;
}