#ifndef ARRAYDATATYPE_H
#define ARRAYDATATYPE_H
#define MAX_SIZE  100
#define ARRAY_T_ERROR  -1
#define ARRAY_T_OK  0

#include <stdbool.h>

/* Define a struct representing the type type array_t. It contains
 *   1. a long pointer : a list of long values 
 *   2. an int   : number of elements in the list
 * These two fields should be coherent. 
 * The list of functions defined below ensure this behaviour 
 */



typedef struct array_t 
{
   long values [MAX_SIZE];
   int size ;
} array_t;

bool arr_is_well_defined(array_t  array);

int arr_init(array_t ** array);

int arr_destroy(array_t ** array);

int arr_print(array_t array);

int arr_init_with_value(array_t ** array, long value, int length);

int arr_init_random(array_t ** array, int length, int min, int max);

int arr_get(array_t array, int index, long * value);

int arr_contains(array_t array, long value, bool *is_present);

int arr_remove(array_t * array, int index);

int arr_postpend(array_t * array, long value);

int arr_prepend(array_t * array, long value);

int arr_insert(array_t * array, long value, int index);

int arr_override(array_t *  array, long value, int index);

int arr_copy(array_t source, array_t ** copy);

int arr_sequence_equal(array_t array1, array_t array2, bool * equal);

int arr_get_distinct(array_t input, array_t ** result);

int arr_are_distinct(array_t array, bool * distinct);

int arr_set_included(array_t small, array_t big, bool * included);

int arr_set_equal(array_t array1, array_t array2, bool * equal);

#endif // ARRAYDATATYPE_H