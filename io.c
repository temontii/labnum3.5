#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_data(int N, const char* output_file) {
    FILE* file = output_file ? fopen(output_file, "w") : stdout;
    if (!file) {
        perror("Failed to open file");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        ApartmentBuilding building;
        sprintf(building.developer, "Developer%d", rand() % 100);
        sprintf(building.neighborhood, "Neighborhood%d", rand() % 100);
        building.type = rand() % 3;
        building.year = 1900 + rand() % 121;
        building.has_elevator = rand() % 2;
        building.has_garbage_chute = rand() % 2;
        building.num_apartments = 10 + rand() % 100;
        building.num_floors = 1 + rand() % 50;
        building.avg_apartment_area = 30.0 + (rand() % 1000) / 10.0;

        fprintf(file, "%s,%s,%d,%d,%d,%d,%d,%d,%.2f\n",
                building.developer, building.neighborhood, building.type,
                building.year, building.has_elevator, building.has_garbage_chute,
                building.num_apartments, building.num_floors, building.avg_apartment_area);
    }

    if (output_file) fclose(file);
}

void read_data(Vector* vec, const char* input_file) {
    FILE* file = input_file ? fopen(input_file, "r") : stdin;
    if (!file) {
        perror("Failed to open file");
        return;
    }

    ApartmentBuilding building;
    while (fscanf(file, "%99[^,],%99[^,],%d,%d,%d,%d,%d,%d,%lf\n",
                  building.developer, building.neighborhood, &building.type,
                  &building.year, &building.has_elevator, &building.has_garbage_chute,
                  &building.num_apartments, &building.num_floors, &building.avg_apartment_area) != EOF) {
        vector_push_back(vec, building);
    }

    if (input_file) fclose(file);
}

void print_data(Vector* vec, const char* output_file) {
    FILE* file = output_file ? fopen(output_file, "w") : stdout;
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < vec->size; i++) {
        ApartmentBuilding* building = vector_get(vec, i);
        fprintf(file, "%-20s %-20s %-10s %-10d %-10s %-10s %-10d %-10d %.2f\n",
                building->developer, building->neighborhood,
                building->type == PANEL ? "Panel" : (building->type == BRICK ? "Brick" : "Monolith"),
                building->year,
                building->has_elevator ? "YES" : "NO",
                building->has_garbage_chute ? "YES" : "NO",
                building->num_apartments, building->num_floors, building->avg_apartment_area);
    }

    if (output_file) fclose(file);
}