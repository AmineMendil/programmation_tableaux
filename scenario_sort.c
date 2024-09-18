#include <stdio.h>
#include <stdlib.h>
#include "sortlib.h"

int main(void) {  
    array_t * my_array = (array_t *) malloc(sizeof(array_t *));
    arr_init_random(&my_array, 1, 1, 10);
        
    printf("my_array before sorting\n");    
    arr_print(*my_array);

    printf("\n");    
    printf("my_array after sorting\n");    
    selection_sort(my_array);
    arr_print(*my_array);

    bool sorted = false;

    is_sorted(*my_array, &sorted);

    printf("\n");  
    if (sorted){
      printf("my_array is sorted\n");
    } else {
      printf("my_array is not sorted\n");
    }       
  return 0 ;

}