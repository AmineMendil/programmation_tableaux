#include "sortlib.h"
#include "arraydatatype.h"


int is_sorted(array_t array, bool * sorted){
    if (arr_is_well_defined(array)){        
        int cursor = 1;
        * sorted = true;
        while(cursor < array.size && * sorted){
            if(array.values[cursor - 1] > array.values[cursor]){
                * sorted = false;
            } else{
                cursor ++;
            }
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}

int selection_sort(array_t * array){
    if (arr_is_well_defined(*array)){        
        int index, remainder, min, swap;
        for(index = 0; index < array->size; index++)
        {
            min = index;
            for(remainder = index + 1; remainder < array->size; remainder++) {
                if(array->values[remainder] < array->values[min]){
                  swap = array->values[remainder];
                  array->values[remainder] = array->values[min];
                  array->values[min] = swap;
                }
            }
        }
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}
int quicksort(array_t * array);


void merge(array_t * array, int left, int mid, int right){
    const int l = mid - left + 1;
    const int r = right - mid;
    long leftA[l], rightA[r];
    int indexl=0; int indexr=0;
    int mergeA = left;
    for(int i=0; i < l; i++){
        leftA[i] = array->values[left + i];
    }
    for(int j=0; j < r; j++){
        rightA[j] = array->values[mid + 1 + j];
    }
    while((indexl < l) && (indexr < r)){
        if(leftA[indexl] <= rightA[indexr]){
            array->values[mergeA] = leftA[indexl];
            indexl++;
        } else{
            array->values[mergeA] = rightA[indexr];
            indexr++;
        }
        mergeA++;
    }
    while(indexl < l){
        array->values[mergeA] = leftA[indexl];
        indexl++;
        mergeA++;
    }
    while(indexr < r){
        array->values[mergeA] = rightA[indexr];
        indexr++;
        mergeA++;
    }
}

void do_merge_sort(array_t * array, int left, int right){
    int mid;
    if(left < right){
        mid = left + (right - left) / 2;
        do_merge_sort(array, left, mid);
        do_merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int merge_sort(array_t * array){        
    if (arr_is_well_defined(*array)){    
        do_merge_sort(array, 0, array->size);
        return ARRAY_T_OK;
    } else {
        return ARRAY_T_ERROR;
    }
}


