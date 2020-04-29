#include "quickSort.h"

int partition(int*, int, int);

void quick_sort(int* list, int start, int end){
  if(start < end){
    int partition_index = partition(list, start, end);
    quick_sort(list, start, partition_index - 1);
    quick_sort(list, partition_index + 1, end);
  }
}

int partition(int* list, int start, int end){
  int pivot = list[end];
  
  int left_pointer = start;
  int right_pointer = start;

  for(right_pointer ; right_pointer <= end - 1; right_pointer++){
    if(list[right_pointer] < pivot) {
      int right_value = list[right_pointer];
      list[right_pointer] = list[left_pointer]; 
      list[left_pointer] = right_value;
      left_pointer++;
    }
  }

  list[end] = list[left_pointer];
  list[left_pointer] = pivot;

  return left_pointer;
}
