#ifndef VECTOR_H
#define VECTOR_H

#include "data_structure.h"

typedef struct {
    ApartmentBuilding* data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector* vec);
int vector_size(Vector* vec);
ApartmentBuilding* vector_get(Vector* vec, int index);
void vector_push_back(Vector* vec, ApartmentBuilding item);
void vector_free(Vector* vec);
void vector_sort(Vector* vec, int (*comparator)(const void*, const void*));

#endif