#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef KM_MATH_CONSTANTS_H
#define KM_MATH_CONSTANTS_H

#define KM_PI 3.14159265358979323846f
#define KM_TAU (2.0f * KM_PI)

#endif

typedef enum {
    KM_VEC_RESULT_OK,
    KM_VEC_RESULT_INVALID_ARG,
    KM_VEC_RESULT_LENGTH_ZERO,
} KmVectorResult;

typedef struct {
    double x;
    double y;
} Vec2;

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    Vec2 *items;
    size_t len;
    size_t capacity;

} Vec2Array;

static inline double km_clamp(double value, double min, double max) {
    if (value < min)
        return min;

    if (value > max)
        return max;

    return value;
}

static inline Vec2 km_vec2_create(double x, double y) {
    Vec2 vec = {x, y};
    return vec;
}

static inline double km_vec2_length(Vec2 vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

static inline KmVectorResult km_vec2_translate(Vec2 *vec, Vec2 offset) {
    if (vec == NULL)
        return KM_VEC_RESULT_INVALID_ARG;

    *vec = km_vec2_create(vec->x + offset.x, vec->y + offset.y);
}

static inline double km_vec2_angle(Vec2 vect) {
    double angle = atan2(vect.y, vect.x);

    if (angle < 0)
        angle += KM_TAU;

    return angle;
}

static inline void km_vec2_print(Vec2 vec) {
    printf("X: %f, Y: %f\n", vec.x, vec.y);
}

static inline double km_vec2_dot(Vec2 vec_a, Vec2 vec_b) {
    return vec_a.x * vec_b.x + vec_a.y * vec_b.y;
}

KmVectorResult km_vec2_set_length(Vec2 *vec, double length);
KmVectorResult km_vec2_normalize(Vec2 *vec);
KmVectorResult km_vec2_rotate(Vec2 *vect, double angle);
void km_vec2_print_detailed(Vec2 vec);

#endif
