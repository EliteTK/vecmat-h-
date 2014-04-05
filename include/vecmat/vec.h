#ifndef __VECMAT_VEC

typedef struct vec {
    float x;
    float y;
    float z;
} Vec;

// Utility functions
Vec *vec_new(const float, const float, const float);
void vec_set(Vec *, const float, const float, const float);
void vec_setv(Vec *, const Vec *);
float *vec_toarr(const Vec *);
void vec_tostring(char *, const Vec *);

// Mathematical functions
float vec_lengths(const Vec *v);
float vec_length(const Vec *v);
float vec_dot(const Vec *, const Vec *);
Vec *vec_cross(const Vec *, const Vec *);
Vec *normalize(const Vec *v);

#define __VECMAT_VEC 1
#endif
