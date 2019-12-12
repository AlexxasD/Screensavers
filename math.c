/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** math.c
*/

#include "include/my.h"

static double **matrix_prod(double **mat, double **matrix_r, double **matrix)
{
    for (int i = 0; i < 3; i++) {
        mat[i] = malloc(sizeof(double) * 3);
        for (int j = 0; j < 3; j++) {
            mat[i][j] = 0.0;
            for (int k = 0; k < 3; k++) {
                if (i != 3 && j != 3 && k != 3) {
                    mat[i][j] += matrix_r[i][k] * matrix[k][j];
                }
            }
            if (mat[i][j] < 0.0 && mat[i][j] > -0.0099)
                mat[i][j] = 0.0;
        }
    }
    mat[2][2] = 1;
    return mat;
}

static void coord_calc(v_dpl *coord, double **mat)
{
    double x = coord->x;

    coord->x = coord->x * mat[0][0] + coord->y * mat[0][1] + mat[0][2];
    coord->y = x * mat[1][0] + coord->y * mat[1][1] + mat[1][2];
}

static double **init_matrix_id(void)
{
    double **matrix = malloc(sizeof(double) * 3);

    for (int i = 0; i < 3; i++) {
        matrix[i] = malloc(sizeof(double) * 3);
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
        }
        matrix[i][i] = 1;
    }
    return matrix;
}

void rotate(double a, v_dpl *coord)
{
    double **matrix_r = init_matrix_id();
    double **matrix = malloc(sizeof(double) * 3);
    double **matrixC = malloc(sizeof(double) * 3);

    for (int i = 0; i < 3; i++) {
        matrix[i] = malloc(sizeof(double) * 3);
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = cos(a);
    matrix[0][1] = -sin(a);
    matrix[1][0] = sin(a);
    matrix[1][1] = cos(a);
    matrix[2][2] = 1;
    matrixC = matrix_prod(matrixC, matrix_r, matrix);
    coord_calc(coord, matrix);
}