#include <stdio.h>
#include <stdlib.h>
#include "sortlib.h"

int main(void) {  
    array_t * my_array = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array_copy = (array_t *) malloc(sizeof(array_t *));

    arr_init_random(&my_array, 10, 1, 10);
        
    printf("my_array before copying\n");    
    arr_print(*my_array);        
    printf("my_array_copy before copying\n");    
    arr_print(*my_array);

    printf("\n");    
    printf("my_array after copying\n");    
    arr_copy(*my_array, &my_array_copy);
    arr_print(*my_array);    
    printf("my_array_copy after copying\n");  
    arr_print(*my_array_copy);
    arr_remove(my_array_copy, 1);
    arr_remove(my_array_copy, 1);
    arr_remove(my_array_copy, 1);
    bool equal = false;
    arr_sequence_equal(*my_array, *my_array_copy, &equal);

    printf("\n");  
    if (equal){
      printf("my_array and my_array_copy are equal sequences\n");
    } else {
      printf("my_array and my_array_copy are not equal sequences\n");
    }       
  return 0 ;

}