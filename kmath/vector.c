#include "vector.h"
#include <math.h>
#include <stdio.h>

void km_vec2_print(Vec2 vec) { printf("X: %f, Y: %f\n", vec.x, vec.y); }

void km_vec2_print_detailed(Vec2 vec) {
    printf("X: %f, Y: %f, Mag: %f, Angle: %f\n", vec.x, vec.y,
           km_vec2_length(vec), km_vec2_angle(vec));
}

KmVectorResult km_vec2_set_length(Vec2 *vec, double length) {
    if (!vec)
        return KM_VEC_RESULT_INVALID_ARG;

    double curr_length = km_vec2_length(*vec);

    if (curr_length == 0.0f)
        return KM_VEC_RESULT_LENGTH_ZERO;

    float scale = length / curr_length;

    vec->x *= scale;
    vec->y *= scale;
    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_normalize(Vec2 *vec) {
    if (!vec)
        return KM_VEC_RESULT_INVALID_ARG;

    double length = km_vec2_length(*vec);

    if (length == 0)
        return KM_VEC_RESULT_LENGTH_ZERO;

    vec->x /= length;
    vec->y /= length;
    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_rotate(Vec2 *vec, double angle) {
    if (!vec)
        return KM_VEC_RESULT_INVALID_ARG;

    double newX = vec->x * cos(angle) - vec->y * sin(angle);
    double newY = vec->x * sin(angle) + vec->y * cos(angle);
    vec->x = newX;
    vec->y = newY;

    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_angle_between(Vec2 vec_a, Vec2 vec_b, double *out) {
    double length_a = km_vec2_length(vec_a);
    double length_b = km_vec2_length(vec_b);

    if (length_a == 0 || length_b == 0)
        return KM_VEC_RESULT_LENGTH_ZERO;

    double cosine = km_vec2_dot(vec_a, vec_b) / (length_a * length_b);

    cosine = km_clamp(cosine, -1.0, 1.0);

    return acos(cosine);
}

double km_vec2_cross(Vec2 vec_a, Vec2 vec_b) {
    return vec_a.x * vec_b.y - vec_a.y * vec_b.x;
}

static KmVectorResult km_vec_array_create(void **out, size_t element_size,
                                          size_t cap) {
    if (!out || cap == 0 || element_size == 0)
        return KM_VEC_RESULT_INVALID_ARG;

    *out = calloc(cap, element_size);
    if (!out) {
        return KM_VEC_RESULT_ALLOC_ERROR;
    }
    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_array_create(Vec2Array *array, size_t cap) {
    if (!array)
        return KM_VEC_RESULT_INVALID_ARG;

    void *items = NULL;

    KmVectorResult res = km_vec_array_create(&items, sizeof(Vec2), cap);
    if (res != KM_VEC_RESULT_OK)
        return res;

    array->items = items;
    array->capacity = cap;
    array->len = 0;

    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_array_destroy(Vec2Array *array) {
    if (!array)
        return KM_VEC_RESULT_INVALID_ARG;

    if (array->items)
        free(array->items);
    array->items = NULL;
    array->capacity = 0;
    array->len = 0;

    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec3_array_create(Vec3Array *array, size_t cap) {
    if (!array)
        return KM_VEC_RESULT_INVALID_ARG;

    void *items = NULL;

    KmVectorResult res = km_vec_array_create(&items, sizeof(Vec3), cap);
    if (res != KM_VEC_RESULT_OK)
        return res;

    array->items = items;
    array->capacity = cap;
    array->len = 0;

    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec3_array_destroy(Vec3Array *array) {
    if (!array)
        return KM_VEC_RESULT_INVALID_ARG;

    if (array->items)
        free(array->items);
    array->items = NULL;
    array->capacity = 0;
    array->len = 0;

    return KM_VEC_RESULT_OK;
}
