#ifndef SORT_H
#define SORT_H

#include "vector.h"

void comb_sort(Vector* vec, int (*comparator)(const void*, const void*));

#endif