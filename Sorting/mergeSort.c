#include <stdio.h>
#include "mergeSort.h"


void merge(int* list, int start, int divide_index, int end) {
  int left_index, left_count;
  int right_index, right_count;
  int merged_index = start;

  left_count = divide_index - start + 1; //inclusive
  right_count = end - divide_index;

  int left_list[left_count], right_list[right_count];

  for(left_index = 0 ; left_index < left_count ; left_index++) {
    left_list[left_index] = list[start + left_index];
  }

  for(right_index = 0 ; right_index < right_count ; right_index++) {
    right_list[right_index] = list[divide_index + 1 + right_index];
  }

  left_index = 0;
  right_index = 0;

  while(left_index < left_count && right_index < right_count) {
    if(left_list[left_index] <= right_list[right_index]) {
      list[merged_index] = left_list[left_index];
      left_index++;
    } else {
      list[merged_index] = right_list[right_index];
      right_index++;
    }

    merged_index++;
  }

  while(left_index < left_count) {
    list[merged_index] = left_list[left_index];
    left_index++;
    merged_index++;
  }

  while(right_index < right_count) {
    list[merged_index] = right_list[right_index];
    right_index++;
    merged_index++;
  }
}

void merge_sort(int* list, int start, int end){
  if(start < end) {
    int divide_index = (start + end) /2;
    merge_sort(list, start, divide_index);
    merge_sort(list, divide_index + 1 , end);
    merge(list, start, divide_index, end);
  }
}