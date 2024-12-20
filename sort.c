#include "sort.h"
#include <stdlib.h>

void comb_sort(Vector* vec, int (*comparator)(const void*, const void*)) {
    int n = vec->size;
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (comparator(&vec->data[i], &vec->data[i + gap]) > 0) {
                ApartmentBuilding temp = vec->data[i];
                vec->data[i] = vec->data[i + gap];
                vec->data[i + gap] = temp;
                swapped = true;
            }
        }
    }
}