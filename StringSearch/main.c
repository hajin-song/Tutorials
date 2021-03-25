#include <stdio.h>

#include "bmh.h"

int
main(int argc, char** argv){
  char* sourceString = "abacd";
  char* targetString = "abccdcadeabacdabdde";

  //int naive = naive_search(sourceString, targetString);
  //int kmp = kmp_search(sourceString, targetString);
  int bmh = bmh_search(sourceString, targetString);

  //printf("NAIVE String found at index: %d\n", naive);
  //printf("KMS String found at index: %d\n", kmp);
  printf("BMH String found at index: %d\n", bmh);

  return 0;
}