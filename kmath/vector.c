#include "vector.h"
#include <math.h>
#include <stdio.h>

KmVectorResult km_vec2_set_length(Vec2 *vec, double length) {
    if (vec == NULL)
        return KM_VEC_RESULT_INVALID_ARG;

    double curr_length = km_vec2_length(*vec);

    if (curr_length == 0.0f)
        return KM_VEC_RESULT_LENGTH_ZERO;

    float scale = length / curr_length;

    vec->x *= scale;
    vec->y *= scale;
    return KM_VEC_RESULT_OK;
}

void km_vec2_print_detailed(Vec2 vec) {
    printf("X: %f, Y: %f, Mag: %f, Angle: %f\n", vec.x, vec.y,
           km_vec2_length(vec), km_vec2_angle(vec));
}

KmVectorResult km_vec2_normalize(Vec2 *vec) {
    if (vec == NULL)
        return KM_VEC_RESULT_INVALID_ARG;

    double length = km_vec2_length(*vec);

    if (length == 0)
        return KM_VEC_RESULT_LENGTH_ZERO;

    vec->x /= length;
    vec->y /= length;
    return KM_VEC_RESULT_OK;
}

KmVectorResult km_vec2_rotate(Vec2 *vec, double angle) {
    if (vec == NULL)
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
