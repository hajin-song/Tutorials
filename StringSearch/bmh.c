#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmh.h"

int* bmh_preprocess(char* needle) {
  // Assume case insensitive english alphabet - 26 
  int* indices = (int*)malloc(sizeof(int)*26);
  int patternLength = strlen(needle);

  for(int i = 0 ; i < 26 ; i++) {
    indices[i] = patternLength;
  }

  for(int i = 0 ; i < patternLength - 1 ; i++) {
    int currentIndex = needle[i] - 97; //a
    indices[currentIndex] = patternLength - i - 1;
    /**
     * pattern = abacd
     * patternLegnth is 5
     * at i = 0
     *  I have an 'a'
     *  if I mismatch on 'a', I can jump 5 - (0 - 1)  = 4
     * at i = 1
     *  I have a 'b'
     *  if I mismatch on 'b', I can jump 5 - (1 - 1) = 3
     * at i = 2
     *  I have an 'a'
     *  if I mismatch on 'a', I can jump 5 - (2 - 1) = 2
     * at i = 3
     *  I have a 'c'
     *  if I mismatch on 'c', I can jump 5 - (3 - 1) = 1
     * */
  }

  return indices;
}


int bmh_search(char* needle, char* haystack) {
  int* indices = bmh_preprocess(needle);

  int needleLength = strlen(needle);
  int haystackIndex = needleLength - 1;
  int haystackLength = strlen(haystack);

  int currentNeedleIndex = needleLength - 1;

  while(haystackIndex < haystackLength) {
    int currentHaystackIndex = haystackIndex - (needleLength - currentNeedleIndex);

    if(currentNeedleIndex < 0){
      return haystackIndex - (needleLength - 1);
    }
    if(needle[currentNeedleIndex] == haystack[currentHaystackIndex]){
      currentNeedleIndex -= 1;
    } else {
      int skipAmount = indices[(int)haystack[currentNeedleIndex] - 97];
      haystackIndex += skipAmount;
      currentNeedleIndex = needleLength - 1;
    }
  }

  return -1;
}