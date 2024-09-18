#ifndef SORTINGLIB_H

#define SORTINGLIB_H

#include "arraydatatype.h"

int is_sorted(array_t array, bool * sorted);

int selection_sort(array_t * array);

int quicksort(array_t * array);

int merge_sort(array_t * array);

#endif // SORTINGLIB_H