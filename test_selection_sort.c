#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sortlib.h"

void test_array_t(array_t * array, char* array_id);


int main(void) {  
    array_t * my_array0 = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array1 = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array10 = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array50 = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array100 = (array_t *) malloc(sizeof(array_t *));

    arr_init_random(&my_array0, 0, -100, 100);    
    arr_init_random(&my_array1, 1, -100, 100);      
    arr_init_random(&my_array10, 10, -100, 100);
    arr_init_random(&my_array50, 50, -100, 100);
    arr_init_random(&my_array100, 100, -100, 100);

    test_array_t(my_array0, "my_array0");   
    test_array_t(my_array1, "my_array1");     
    test_array_t(my_array10, "my_array10"); 
    test_array_t(my_array50, "my_array50"); 
    test_array_t(my_array100, "my_array100");  
    printf("\n");
}

void test_array_t(array_t * array, char* array_id){
     array_t * array_copy = (array_t *) malloc(sizeof(array_t *));
      int exit_code = arr_copy(*array, &array_copy);
     if (exit_code == ARRAY_T_OK){
        exit_code = selection_sort(array);
        if (exit_code == ARRAY_T_OK){
            bool sorted = false;
            exit_code = is_sorted(*array, &sorted);
            if (exit_code == ARRAY_T_OK){
                if (sorted){
                    printf("\n [PASSED] %s is sorted", array_id);    
                    if (array_copy->size == array->size){
                        printf("\n [PASSED] %s elements are the same after sorting", array_id);

                    }   else {
                       printf("\n [FAILED] %s elements changed after sorting", array_id);
                }             
                } else {
                    printf("\n [FAILED] %s is not sorted", array_id);
                }
            } else {
                printf("\n [ERROR]  checking sortedness of %s finished on error", array_id);
            }
        } else {
            printf("\n [ERROR] selection sorting of %s finished on error", array_id);
        }
     } else {
            printf("\n [ERROR] Copying of %s finished on error", array_id);
            assert(false);
     }
}