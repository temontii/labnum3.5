#ifndef DATA_H
#define DATA_H

typedef struct {
    char developer[50];
    char district[50];
    char type[20];
    int year_built;
    int has_elevator;
    int has_chute;
    int num_apartments;
    int num_floors;
    double avg_area;
} Apartment;

typedef struct {
    Apartment *data;
    size_t size;
    size_t capacity;
} Vector;

void init_vector(Vector *vec);
void add_to_vector(Vector *vec, Apartment item);
void clear_vector(Vector *vec);
Apartment get_from_vector(const Vector *vec, size_t index);

#endif