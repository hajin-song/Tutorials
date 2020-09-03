#include <stdio.h>
#include "naiveSearch.h"
#include "kmp.h"

int
main(int argc, char** argv){
  char* sourceString = "ABCAA";
  char* targetString = "ABCABCAAABCAAABCAA";

  int naive = naive_search(sourceString, targetString);
  int kms = kmp_search(sourceString, targetString);

  printf("NAIVE String found at index: %d\n", naive);
  printf("KMS String found at index: %d\n", kms);

  return 0;
}