#ifndef _ARRAY_C__H
#define _ARRAY_C__H

#include <stdbool.h>

typedef int DATA_T;

typedef struct {
    DATA_T* data;
    int len;
    int capacity;
}Array;

Array* init_array(int capacity);

int find_array(Array* array, DATA_T value);
int get_array(Array* array, int index);

bool insert_array(Array* array, int index, DATA_T value);
bool remove_array(Array* array, int index);

void print_array_int(Array* array);

#endif
