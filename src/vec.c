#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec.h"

#define pow2(A) ((A) * (A))

///////////////////////
// Utility functions //
///////////////////////

Vec *vec_alloc()
{
    return malloc(sizeof(Vec));
}

void vec_free(Vec *v)
{
    free(v);
}

Vec *vec_new(const float x, const float y, const float z)
{
    Vec *v = vec_alloc();
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void vec_set(Vec *v, const float x, const float y, const float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void vec_setv(Vec *v1, const Vec *v2)
{
    v1->x = v2->x;
    v1->y = v2->y;
    v1->z = v2->z;
}

void vec_seta(Vec *v, const float *array)
{
    v->x = array[0];
    v->y = array[1];
    v->z = array[2];
}

void vec_zero(Vec *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
}

float *vec_toarr(const Vec *v)
{
    float *array = malloc(3 * sizeof(float));
    array[0] = v->x;
    array[1] = v->y;
    array[2] = v->z;
    return array;
}

void vec_tostring(char *string, const Vec *v)
{
    sprintf(string, "(%f, %f, %f)", v->x, v->y, v->z);
}

////////////////////////////
// Mathematical functions //
////////////////////////////

float vec_lengths(const Vec *v)
{
    return pow2(v->x) + pow2(v->y) + pow2(v->z);
}

float vec_length(const Vec *v)
{
    return sqrt(vec_lengths(v));
}

float vec_dot(const Vec *v1, const Vec *v2)
{
    return  v1->x * v2->x
          + v1->y * v2->y
          + v1->z * v2->z;
}

Vec *vec_cross(const Vec *v1, const Vec *v2)
{
    return vec_new( v1->y * v2->z - v1->z * v2->y,
                    v1->z * v2->x - v1->x * v2->z,
                    v1->x * v2->y - v1->y * v2->x);
}

Vec *vec_normalize(const Vec *v)
{
    const float ilength = 1/vec_length(v);
    return vec_new(v->x * ilength, v->y * ilength, v->z * ilength);
}
