#include <stdio.h>
#include <stdlib.h>

typedef int magic_number;
typedef char* my_string;

typedef struct something {
  int foo;
  char* bar;
} something_t;

int
main(int argc, char** argv){ 
  int a = 10;
  magic_number b = 20;

  printf("%d, %d\n", a, b);

  char* a_string = "Foo Bar";
  my_string b_string = "Fizz Buzz";

  printf("%s, %s\n", a_string, b_string);

  something_t* something_value = (something_t*)malloc(sizeof(something_t));
  something_value->bar = "foo bar";
  something_value->foo = 505;

  something_value->bar = "Fizz Bazz";

  printf("%d / %s\n", something_value->foo, something_value->bar);

  free(something_value);
  
  return 1;
}