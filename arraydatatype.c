#include "arraydatatype.h"
#include <stdio.h>
#include <stdlib.h>

bool arr_is_well_defined (array_t array){
    if (0 <= array.size  && array.size < MAX_SIZE){
        return true;
    }
    else {
        return false;
    }
}

int arr_init(array_t ** array){
    array_t * tmp_array =  (array_t *)malloc(sizeof(struct array_t));
    tmp_array->size = 0;   
    * array = tmp_array;
    return ARRAY_T_OK;
}

int arr_destroy(array_t ** array){    
    free(*array);
    *array = NULL;
    return ARRAY_T_OK;
}


int arr_init_with_value(array_t ** array, long value, int length){
    if (length > 0 && length < MAX_SIZE){ 
        arr_init(array);
        for (int i = 0; i < length; i++){
            (*array)->values[i] = value;
        } 
        (*array)->size = length;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_init_random(array_t ** array, int length, int min, int max){    
    if (length > 0 && length < MAX_SIZE && min >= 1 && max >= min){        
        int distance = max - min;
        arr_init(array);
        for (int i = 0; i < length; i++){
            (*array)->values[i] =  min + (rand() % distance) ;            
        } 
        (*array)->size = length;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}


int arr_print(array_t  array){
    if (arr_is_well_defined(array)){
        printf("values: [");
        for (int i = 0; i < array.size - 1; i++){
            printf("%ld, ", array.values[i]);
        }
        if (array.size > 0){            
            printf("%ld", array.values[array.size - 1]);
        }
        printf("]\n");
        printf("size: %d\n", array.size);        
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}


int arr_get(array_t array, int index, long * value){   
    if (arr_is_well_defined(array) && index > 0 && index <  array.size){ 
         * value =  array.values[index];
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_contains(array_t array, long value, bool *is_present) {   
    if (arr_is_well_defined(array)){ 
        *is_present  = false;
        int cursor = 0;
        while (cursor < array.size && array.values[cursor] != value){
            cursor++;
        }
        *is_present =  cursor < array.size;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_remove(array_t * array, int index){
    if (array != NULL &&  arr_is_well_defined(*array) && index > 0 && index <  array->size){ 
        for (int i = index + 1; i < array->size; i++){
             array->values[i - 1] = array->values[i];
        } 
        array->size = array->size - 1;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_postpend(array_t * array, long value){
    if (array != NULL && arr_is_well_defined(*array)){ 
        array->values[array->size] = value;        
        array->size = array->size + 1;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_prepend(array_t  * array, long value){
    if (array != NULL &&  arr_is_well_defined(* array) ){  
        for (int i = array->size - 1; i >=0; i++){
             array->values[i + 1] = array->values[i];
        }        
        array->values[0] = value;        
        array->size = array->size + 1;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_insert(array_t * array, long value, int index){
    if (array != NULL &&  arr_is_well_defined(*array) && index > 0 && index <  array->size){ 
        for (int i = index; i <  array->size; i++){
             array->values[i + 1] = array->values[i];
        }        
        array->values[index] = value;        
        array->size = array->size + 1;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_override(array_t * array, long value, int index){
    if (array != NULL &&  arr_is_well_defined(*array) && index > 0 && index <  array->size){ 
        array->values[index] = value;    
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_copy(array_t source, array_t ** copy){
    if (arr_is_well_defined(source)){ 
        arr_init(copy);
        for (int i = 0; i < source.size ; i ++){
            (*copy)->values[i] = source.values[i];
        }
        (*copy)->size = source.size;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_sequence_equal(array_t array1, array_t array2, bool * equal){    
    if (arr_is_well_defined(array1) && arr_is_well_defined(array2)){ 
        if (array1.size == array2.size){   
            *equal = false;         
            int cursor = 0;
            while (cursor < array1.size && array1.values[cursor] == array2.values[cursor] ){
                cursor ++;
            }
            *equal = cursor == array1.size;
        } else {
            *equal = false;
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_get_distinct(array_t input, array_t ** result){        
    if (arr_is_well_defined(input)){ 
        arr_init(result);
        for (int i = 0; i < input.size; i++){
            bool is_present = false;
            arr_contains(**result, input.values[i], &is_present);
            if (!is_present){
                arr_postpend(*result, input.values[i]);
            }
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int arr_are_distinct(array_t array, bool * distinct){     
    if (arr_is_well_defined(array)){ 
        array_t * distinct_copy = (array_t *) malloc(sizeof(array_t *));
        arr_get_distinct(array, &distinct_copy);  
        *distinct  = array.size == distinct_copy->size;
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }

}

int arr_set_included(array_t small, array_t big, bool * included){
     if (arr_is_well_defined(small) && arr_is_well_defined(small)){ 
        (* included) = true;
        int cursor = 0;
        while ((* included) && cursor < small.size){
            arr_contains(big, small.values[cursor], included);
            cursor++;
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}


int arr_set_equal(array_t array1, array_t array2, bool * equal){        
     if (arr_is_well_defined(array1) && arr_is_well_defined(array2)){ 
        arr_set_included(array1, array2, equal);
        if(*equal){
          arr_set_included(array2, array1, equal);
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}
