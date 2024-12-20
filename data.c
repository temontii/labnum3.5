#include "data.h"
#include <stdlib.h>
#include <string.h>

void init_vector(Vector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void add_to_vector(Vector *vec, Apartment item) {
    if (vec->size == vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(Apartment));
    }
    vec->data[vec->size++] = item;
}

void clear_vector(Vector *vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;
}

Apartment get_from_vector(const Vector *vec, size_t index) {
    return vec->data[index];
}