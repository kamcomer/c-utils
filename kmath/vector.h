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
    KM_VEC_RESULT_ALLOC_ERROR
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

typedef struct {
    Vec3 *items;
    size_t len;
    size_t capacity;

} Vec3Array;

static inline double km_clamp(double value, double min, double max) {
    if (value < min)
        return min;

    if (value > max)
        return max;

    return value;
}

static inline Vec2 km_vec2_create(double x, double y) { return (Vec2){x, y}; }

static inline double km_vec2_length(Vec2 vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

static inline KmVectorResult km_vec2_translate(Vec2 *vec, Vec2 offset) {
    if (!vec)
        return KM_VEC_RESULT_INVALID_ARG;

    *vec = km_vec2_create(vec->x + offset.x, vec->y + offset.y);
    return KM_VEC_RESULT_OK;
}

static inline double km_vec2_angle(Vec2 vect) {
    double angle = atan2(vect.y, vect.x);

    if (angle < 0)
        angle += KM_TAU;

    return angle;
}

static inline double km_vec2_dot(Vec2 vec_a, Vec2 vec_b) {
    return vec_a.x * vec_b.x + vec_a.y * vec_b.y;
}

static inline Vec3 km_vec3_create(double x, double y, double z) {
    return (Vec3){x, y, z};
}

static inline double km_vec3_length(Vec3 vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

static inline KmVectorResult km_vec3_translate(Vec3 *vec, Vec3 offset) {
    if (!vec)
        return KM_VEC_RESULT_INVALID_ARG;

    *vec =
        km_vec3_create(vec->x + offset.x, vec->y + offset.y, vec->z + offset.z);
    return KM_VEC_RESULT_OK;
}

// TODO
/* static inline double km_vec3_angle(Vec3 vect) { */
/*     double angle = atan2(vect.y, vect.x); */

/*     if (angle < 0) */
/*         angle += KM_TAU; */

/*     return angle; */
/* } */

// TODO
/* static inline double km_vec3_dot(Vec3 vec_a, Vec3 vec_b) { */
/*     return vec_a.x * vec_b.x + vec_a.y * vec_b.y; */
/* } */

KmVectorResult km_vec2_set_length(Vec2 *vec, double length);
KmVectorResult km_vec2_normalize(Vec2 *vec);
KmVectorResult km_vec2_rotate(Vec2 *vect, double angle);
KmVectorResult km_vec2_array_create(Vec2Array *array, size_t cap);
KmVectorResult km_vec2_array_destroy(Vec2Array *array);
KmVectorResult km_vec3_array_create(Vec3Array *array, size_t cap);
KmVectorResult km_vec3_array_destroy(Vec3Array *array);

void km_vec2_print(Vec2 vec);
void km_vec2_print_detailed(Vec2 vec);

// TODO
/* void km_vec3_print(Vec3 vec); */
/* void km_vec3_print_detailed(Vec3 vec); */
/* KmVectorResult km_vec3_set_length(Vec3 *vec, double length); */
/* KmVectorResult km_vec3_normalize(Vec3 *vec); */
/* KmVectorResult km_vec3_rotate(Vec3 *vect, double angle); */

#endif
