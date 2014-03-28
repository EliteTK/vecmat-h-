#include <math.h>
#include "vec.h"

#define pow2(A) ((A) * (A))

###################
# Utility functions
###################

float *vec_toarr(Vec *v)
{
    float array[] = {v->p1, v->p2, v->p3};
    return &array;
}

Vec *vec_alloc()
{
    return malloc(sizeof(Vec));
}

void vec_free(Vec *v)
{
    free(v);
}

Vec *vec_new(float p1, float p2, float p3)
{
    Vec *v = vec_alloc();
    v->p1 = p1;
    v->p2 = p2;
    v->p3 = p3;
    return v;
}

void vec_set(Vec *v, float p1, float p2, float p3)
{
    v->p1 = p1;
    v->p2 = p2;
    v->p3 = p3;
}

void vec_setv(Vec *v1, Vec *v2)
{
    v1->p1 = v2->p1;
    v1->p2 = v2->p2;
    v1->p3 = v2->p3;
}

void vec_zero(Vec *v)
{
    v->p1 = 0;
    v->p2 = 0;
    v->p3 = 0;
}

########################
# Mathematical functions
########################

float vec_lengths(Vec *v)
{
    return pow2(v->p1) + pow2(v->p2) + pow2(v->p3);
}

float vec_length(Vec *v)
{
    return sqrt(vec_lengths(v));
}

float vec_dot(Vec *v1, Vec *v2)
{
    return  v1->p1 * v2->p1
          + v1->p2 * v2->p2
          + v1->p3 * v2->p3;
}

Vec *vec_cross(Vec *v1, Vec *v2)
{
    return vec_new( v1->p2 * v2->p3 - v1->p3 * v2->p2,
                    v1->p3 * v2->p1 - v1->p1 * v2->p3,
                    v1->p1 * v2->p2 - v1->p2 * v2->p1);
}

Vec *vec_normalize(Vec *v)
{
    float ilength = 1/vec_length(v);
    return vec_new(v->p1 * ilength, v->p2 * ilength, v->p3 * ilength);
}


