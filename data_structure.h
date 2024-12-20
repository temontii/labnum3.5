#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdbool.h>

typedef enum {
    PANEL,
    BRICK,
    MONOLITH
} BuildingType;

typedef struct {
    char developer[100];
    char neighborhood[100];
    BuildingType type;
    int year;
    bool has_elevator;
    bool has_garbage_chute;
    int num_apartments;
    int num_floors;
    double avg_apartment_area;
} ApartmentBuilding;

#endif