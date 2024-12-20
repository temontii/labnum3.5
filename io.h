#ifndef IO_H
#define IO_H

#include "vector.h"

void generate_data(int N, const char* output_file);
void read_data(Vector* vec, const char* input_file);
void print_data(Vector* vec, const char* output_file);

#endif