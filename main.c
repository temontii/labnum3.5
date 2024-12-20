#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "io.h"
#include "sort.h"

int comparator_asc(const void* a, const void* b) {
    const ApartmentBuilding* building_a = (const ApartmentBuilding*)a;
    const ApartmentBuilding* building_b = (const ApartmentBuilding*)b;
    return building_a->year - building_b->year;
}

int comparator_desc(const void* a, const void* b) {
    return comparator_asc(b, a);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s --generate N | --sort | --print\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--generate") == 0 || strcmp(argv[1], "-g") == 0) {
        int N = atoi(argv[2]);
        const char* output_file = NULL;
        for (int i = 3; i < argc; i++) {
            if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            }
        }
        generate_data(N, output_file);
    } else if (strcmp(argv[1], "--sort") == 0 || strcmp(argv[1], "-s") == 0) {
        Vector vec;
        vector_init(&vec);

        const char* input_file = NULL;
        const char* output_file = NULL;
        int sort_type = 0; // 0 = asc, 1 = desc

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 || strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            } else if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            } else if (strcmp(argv[i], "--type") == 0 || strcmp(argv[i], "-t") == 0) {
                sort_type = strcmp(argv[++i], "desc") == 0 ? 1 : 0;
            }
        }

        read_data(&vec, input_file);
        comb_sort(&vec, sort_type ? comparator_desc : comparator_asc);
        print_data(&vec, output_file);
        vector_free(&vec);
    } else if (strcmp(argv[1], "--print") == 0 || strcmp(argv[1], "-P") == 0) {
        Vector vec;
        vector_init(&vec);

        const char* input_file = NULL;
        const char* output_file = NULL;

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 || strcmp(argv[i], "-i") == 0) {
                input_file = argv[++i];
            } else if (strcmp(argv[i], "--out") == 0 || strcmp(argv[i], "-o") == 0) {
                output_file = argv[++i];
            }
        }

        read_data(&vec, input_file);
        print_data(&vec, output_file);
        vector_free(&vec);
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}