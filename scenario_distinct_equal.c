#include <stdio.h>
#include <stdlib.h>
#include "sortlib.h"

int main(void) {  
    array_t * my_array = (array_t *) malloc(sizeof(array_t *));
    array_t * my_array_distinct = (array_t *) malloc(sizeof(array_t *));

    arr_init_random(&my_array, 10, 1, 10);        
    printf("my_array before copying\n");    
    arr_print(*my_array);     

    printf("\n");    
    printf("my_array_distinct after distinct\n"); 
    arr_print(*my_array);     
    arr_get_distinct(*my_array, &my_array_distinct);
    arr_print(*my_array_distinct);
    bool equal_sequences = false;
    arr_sequence_equal(*my_array, *my_array_distinct, &equal_sequences);

    printf("\n");  
    if (equal_sequences){
      printf("my_array and my_array_distinct are equal sequences\n");
    } else {
      printf("my_array and my_array_distinct are not equal sequences\n");
    }  

    
    bool equal_set = false;
    arr_set_equal(*my_array, *my_array_distinct, &equal_set);

    printf("\n");  
    if (equal_set){
      printf("my_array and my_array_distinct are equal sets\n");
    } else {
      printf("my_array and my_array_distinct are not equal sets\n");
    }  

    bool distinct = false;
    arr_are_distinct(*my_array_distinct, &distinct);

    printf("\n");  
    if (distinct){
      printf("my_array_distinct have distinct values\n");
    } else {
      printf("my_array_distinct have not distinct values\n");
    }  

    bool included = false;
    arr_remove(my_array_distinct, 0);
    arr_set_included(*my_array, *my_array_distinct, &included);

    printf("\n");  
    if (included){
      printf("inclusion after removal from my_array_distinct \n");
    } else {
      printf("inclusion after removal from my_array_distinct \n");
    } 
    
    
  return 0 ;

}