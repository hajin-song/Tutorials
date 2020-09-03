#include <stdio.h>
#include <string.h>
#include "naiveSearch.h"

int naive_search(char* source, char* target) {
  int matchIndex = 0;
  int targetStringLength = strlen(target);
  int sourceStringLength = strlen(source);

  while(matchIndex < targetStringLength - sourceStringLength) {
    int matchCount;

    for(matchCount = 0 ; matchCount < sourceStringLength ; matchCount++) {
      if(target[matchIndex + matchCount] != source[matchCount]) {
        break;
      }
    }

    if(matchCount == sourceStringLength) {
      return matchIndex;
    }

    matchIndex++;
  }

  return -1;
}