#include "vector.h"
#include <stdlib.h>
#include <string.h>

void vector_init(Vector* vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

int vector_size(Vector* vec) {
    return vec->size;
}

ApartmentBuilding* vector_get(Vector* vec, int index) {
    if (index < 0 || index >= vec->size) {
        return NULL;
    }
    return &vec->data[index];
}

void vector_push_back(Vector* vec, ApartmentBuilding item) {
    if (vec->size == vec->capacity) {
        vec->capacity = vec->capacity == 0 ? 1 : vec->capacity * 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(ApartmentBuilding));
    }
    vec->data[vec->size++] = item;
}

void vector_free(Vector* vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vector_sort(Vector* vec, int (*comparator)(const void*, const void*)) {
    qsort(vec->data, vec->size, sizeof(ApartmentBuilding), comparator);
}