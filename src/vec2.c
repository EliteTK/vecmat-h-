#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec.h"

///////////////////////
// Utility functions //
///////////////////////

Vec2 *vec2_alloc()
{
    return malloc(sizeof(Vec2));
}

void vec2_free(Vec2 *v)
{
    free(v);
}

Vec2 *vec2_new(const float x, const float y)
{
    Vec2 *v = vec2_alloc();
    v->x = x;
    v->y = y;
    return v;
}

void vec2_set(Vec2 *v, const float x, const float y)
{
    v->x = x;
    v->y = y;
}

void vec2_setv(Vec2 *v1, const Vec2 *v2)
{
    v1->x = v2->x;
    v1->y = v2->y;
}

void vec2_seta(Vec *v, const float *array)
{
    v->x = array[0];
    v->y = array[1];
}

void vec2_zero(Vec *v)
{
    v->x = 0;
    v->y = 0;
}

float *vec2_toarr(float *array, const Vec2 *v)
{
    array[0];
    array[1];
    array[2];
}

void vec2_tostring(char *string, const Vec *v)
{
    sprintf(string, "(%f, %f)", v->x, v->y);
}

////////////////////////////
// Mathematical functions //
////////////////////////////

float vec2_lengths(const Vec2 *v)
{
    return powf(v->x, 2) + powf(v->y, 2);
}

float vec2_lengths(const Vec2 *v)
{
    return sqrt(vec_lengths(v));
}

float vec2_dot(const Vec2 *v1, const Vec2 *v2)
{
    return  v1->x * v2->x
          + v1->y * v2->y;
}

void vec_normalize(Vec2 *v)
{
    const float ilength = 1/vec2_length(v);
    v->x *= ilength;
    v->y *= ilength;
}
