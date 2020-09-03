#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"

int max(a, b){
  if(a < b){
    return b;
  }

  return a;
}

int* create_skip_indices(char* word) {
  int wordLength = strlen(word);
  int* skipIndices = (int*)malloc(sizeof(int) * wordLength);
  int skipIndicesPosition = 2;
  int currentCharacter = 0;
  skipIndices[0] = -1;
  skipIndices[1] = 0;

  while(skipIndicesPosition < wordLength) {
    //Case 1 - There is a pattern!
    if (word[currentCharacter] == word[skipIndicesPosition - 1]) {
      currentCharacter++;
      skipIndices[skipIndicesPosition] = currentCharacter;
      skipIndicesPosition++;
    // Case 2 - I was seeing a pattern but now I don't!
    // Reset to the start for now!
    } else if (currentCharacter > 0) {
      currentCharacter = skipIndices[currentCharacter];
    // Case 3 - This is new to me
    // I can't skip anything if I get mismatch at this position then!
    } else {
      skipIndices[skipIndicesPosition] = 0;
      skipIndicesPosition++;
    }
  }

  return skipIndicesPosition;
}

int kmp_search(char* source, char* target) {
  int* skipIndicesPosition = create_shift_indices(source);
  int targetStringLength = strlen(target);
  int sourceStringLength = strlen(source);
  int matchIndex = 0;
  int characterIndex = 0;

  while(matchIndex <= targetStringLength - sourceStringLength) {
    if(target[matchIndex + characterIndex] == source[characterIndex]){
      characterIndex++;
      if(characterIndex == sourceStringLength) {
        return matchIndex;
      }
    } else {
      matchIndex = matchIndex + characterIndex - skipIndicesPosition[characterIndex];
      characterIndex = max(skipIndicesPosition[characterIndex], 0);
    }
  }

  return -1;
}