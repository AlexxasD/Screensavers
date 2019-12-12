/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define ABS(val) ((val < 0) ? -val : val)
#define MAX(val, val2) ((val < val2) ? val2 : val)
#define ID_MAX 4

typedef struct fb {
    sfUint8 *pixels;
    int height;
    int width;
} framebuffer;

typedef struct cir {
    int x;
    int y;
    int radius;
    sfColor color;
} circle;

typedef struct vector {
    double x;
    double y;
} v_dpl;

typedef struct sfml_obj {
    sfTexture *texture;
    sfSprite *sprite;
    sfRenderWindow *window;
    char *av;
} sfml_obj;

typedef struct coo {
    double x;
    double y;
} stCoo;

typedef struct planetInfo {
    stCoo *coord;
    int radius;
    sfColor color;
    int period;
    stCoo prec;
} planete_info;

void draw_kepler(framebuffer *fb, sfml_obj *obj);
void draw_circle(framebuffer *fb, int x, int y, int rayon, sfColor color);
int generate_rand_num(int max);
sfColor generate_rand_color(void);
void draw_mess(framebuffer *fb, sfml_obj *obj);
void set_pixel(framebuffer *fb, int x, int y, sfColor color);
void framebuffer_clear(framebuffer *fb);
void update_screen(sfml_obj *obj, framebuffer *fb);
void close_button(sfml_obj *obj, sfEvent event, framebuffer *fb);
void draw_square(framebuffer *fb, int x, int y, sfColor color);
void screen_chooser(char *id, framebuffer *fb, sfml_obj *obj);
void draw_line(framebuffer *fb, stCoo coord, stCoo coord2, sfColor color);
void line_tracer(framebuffer *fb, sfml_obj *obj);
void dvd_f(framebuffer *fb, sfml_obj *obj);
void rotate(double a, v_dpl *coord);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
void make_square(framebuffer *fb, sfml_obj *obj);