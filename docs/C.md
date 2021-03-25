# What is C?

C is a language used widely by the embedded system industry, but is also a great gateway language to programming. It belongs in imperative language family and is known to be efficient in terms of size of the program compared to other popular languages. While the beginners often fear it, it is necessary to understand the language as it forces users to think about how much memory spaces are being used and how much time is spent on solving a problem.
Of course, it’s just plain fun to program in C as well.

# Good old ‘Hello World’

The first step of learning any programming language is to say hello to the world using the language.

```c
#include <stdio.h>

void main(int argc, char** argv){
 printf("Hello World!");
}
```

Then, to generate an executable file, use the [GCC](https://gcc.gnu.org/) to compile the C file.

```sh
gcc -o helloWorld.exe helloWorld.c
```

Congratulation, you just made your first C program.

# Wait, what did I just do?

Lets take a look at the first line

```c
#include <stdio.h>
```

This is telling the compiler to include the library called `stdio` - a built in C library which has most of the input/output function. (Hence, the name `St`andar`d` `I`nput `O`utput)

By including the library (or more accurately the [Header](https://www.tutorialspoint.com/cprogramming/c_header_files.htm) file which you will learn more about down the road), your program gets the access to the function defined and saves you the trouble of writing them all over again yourself.

So far, your program has the ability to read and write to the 'outside' world, but how is it saying Hello to the World?

Take a look at the remaining snippet of the code.

```c
void main(int argc, char** argv){
 printf("Hello World!");
}
```

Ignoring the strange bits, you should be able to tell that you have a main function which executes a single line of code - `printf("Hello World!")`. What this line of code do should be straight-forward.

But there are things like `void`, `int argc` and `char** argv` - what are these?

Lets first take a look on how a function is defined in C -

`RETURN_TYPE FUNCTION_NAME(TYPE ARG_1_NAME, TYPE ARG_2_NAME, ..., TYPE ARG_N_NAME)`

Try to fit the mystery words to above structure and you will see that
* `void` refers to the return type of the function
* `int argc` is saying that the main function takes an argument named `argc` of type `int`.
* `char** argv` is saying that the main function takes an argument named `argv` of type `char**`.

So our main function takes two variable, `argc` of type `integer` and `argv` of `pointer to pointer to character`, as its arguments and returns a value of type `void` at the end.

Now, you should understand the how the C program prints out `Hello World!` to the console - well, at least the gist of it. Let peel the last few part of the onion.

# ARGC and ARGV - What?

Theres not much to these to variables - you can think `argc` as `Argument Count` and `argv` as `Argument Variables`. Leaving the programming aside, the first variable should tell you how many arguments are given to the function while the second variable contains the given arguments. But why does C do it this way? Why can't I just do this?

```c
void main(char* arg_one, char* arg_two, ..., char* arg_n)
```

Now, lets stop for a moment and see how a C program (executable file) is called in usual way.

```
helloWorld.exe
```

To call the executable, you type to name of the executable file in the console. Now, lets see how you would call an executable file with some custom arguments.

```
helloWorld.exe hello world, my name is Ha Jin Song
```


We just called an executable named `helloWorld.exe` with 8 arguments - `hello`, `world,`, `my`, `name`, `is`, `Ha`, `Jin` and `Song`.

Okay, we can maybe make the main function look like this - `void main(char* arg_one, char* arg_two, char* arg_three, char* arg_four, char* arg_five, char* arg_six, char* arg_seven, char* arg_eight)`.

But how about this?

```
helloWorld.exe hello world, my name is Esteban Julio Roberto Montoya Dela Rosa Ramirez
```

...Would you like to make ANOTHER main function (at which the GCC will yell at you and [you will be responsible for the horrors described here](https://github.com/paradoxxxzero/nocolon/issues/1)) OR just put all of the received argument into a single place such as a list?

Since the program doesn't know how many arguments it will received when executed, the C programs will put all of the arguments into a single list, `argv`, and keep track of number of arguments it received, `argc`.

# Okay fine, but what's the point of those hecking \*s?

Now, we come to the one of the joys and tears of the C, the pointers.

First, I want you to take a deep breath and scream internally before you proceed.

![SCREAMING TOAD IS HERE](http://iruntheinternet.com/lulzdump/images/gifs/toad-freaking-out-shaking-going-crazy-nintendo-13922502790.gif?id=)

The first encounter of pointer for us is most likely be `char** argv`, but since we are new here, lets take a step back.

`char` denotes a variable of type `character` - a single character of 1 byte which can represent the alphabets, numbers (as character) and other extra symbols such as `?`, `!` and whatnot.

`char*` denotes a `pointer` to a character - it's a variable that *points* to a character. It doesn't store the actual character, but stores the space (a memory address) that stores the character.

```c
#include <stdio.h>

void main(int argc, char** argv){
 char foo = 'f';
 char* foo_address;
 foo_address = &foo;
 printf("%c, %c\n", foo, *foo_address);
}
```

Note that `\n` is just a special character representing a newline if you haven't seen it before.

The resulting output is `f, f`.

So What happened up there?

We first made a variable named `foo` of type `char` which contains a value, `foo`.

Then we made a pointer variable which points to char and named it `foo_address` since it will hold the memory address of the variable, `foo`.

After that, we got the address of `foo` by referencing it (`&foo`) and stored into `foo_address`.

The output is therefore, `foo, foo` - since we are printing the variable `foo` and dereferenced `foo_address`. (`*foo_address`).

Lets clear up some terms we encounterd above -
* Dereferencing a pointer (`*foo_address`) means we are taking a pointer, a reference, and getting the actual value it is pointing to.
* Referencing a varaible (`&foo`) means we are taking a value and get a reference point (a memory address in this case) to that value.

So, we should know by now what pointer variable store - it stores a memory address of a variable.

But what happens if we try to change one of them?

Lets try changing the value in the variable that pointer is pointing to.

```c
#include <stdio.h>

void main(int argc, char** argv){
 char foo = 'f';
 char* foo_address;
 foo_address = &foo;
 printf("%c, %c\n", foo, *foo_address);
 foo = 'b';
 printf("%c, %c\n", foo, *foo_address);
}
```

the output is

```
f, f
b, b
```

So changing the underlying variable also changes the dereferenced value of the pointer - which is expected since the pointer variable doesn't hold the value, it holds the memory address of the value and we just changed the value that was sitting in that address.

What about this?

```c
#include <stdio.h>

void main(int argc, char** argv){
 char foo = 'f';
 char* foo_address;
 foo_address = &foo;
 printf("%c, %c\n", foo, *foo_address);
 foo_address = 'b';
 printf("%c, %c\n", foo, *foo_address);
}
```

What do you think will happen? Will it be the same as previous output?

```
test.c: In function 'main':
test.c:8:14: warning: assignment makes pointer from integer without a cast [-Wint-conversion]
 foo_address = 'b';
```

GCC will complain to you saying you just tried to assign incompatible value to the pointer variable. You can't put a character in the pointer variable, it can only take a memory address!

Nevertheless, GCC will compile it for you and if you try to run that executable, you will run into your very first C program failure! Hurray!

So, how should we fix this? How do you get a memory space of the `b`?

Unfortunately, you can't get a memory space of character constant, `b`, but you can allocate a memory space to a pointer variable and put the value in there!

```c
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv){
 char foo = 'f';
 char* foo_address;
 foo_address = &foo;
 printf("%c, %c\n", foo, *foo_address);

 foo_address = malloc(sizeof(char));
 *foo_address = 'z';

 printf("%c, %c\n", foo, *foo_address);
}

```

To allocate memory space to a pointer variable, you need a function named `malloc`, memory allocation, and `sizeof` which lives inside the library called `stdlib.h`.
* `sizeof` function takes a type of variable (`char`) and returns number of byte needed to represent that variable.
* `malloc` function takes an integer value representing number of byte it will try to allocate in the memory.

So the line, `foo_address = malloc(sizeof(char))`, allocated a memory address of one byte (size of char variable type) to `foo_address` variable.

Next, we want to put an actual value into the newly allocated memory space. Remember how to dereference a pointer variable? The `*` symbol.

`*foo_address = 'z'` is saying dereference the address the `foo_address` is pointing to and let it equal to character value `z`.

Then, the output is
```
f, f
f, z
```

Great, we saw how pointers work, but whats the deal with `**`?

Lets think about it for a moment, a single pointer hold memory address to a variable. So what should a double pointer hold?

A memory address of a memory address to a variable. Yep, it's a reference to a reference.

![Oh God Why](https://i.imgflip.com/1tx4ub.jpg)

But its not that bad, all it is a variable that points to a memory space which in turn points to a variable.

Congratualtion, now you won't have to curl up into a ball in fear in the presence of pointer variable! (If you still do, kindly look at [the Bible of C by Alistair Moffat](http://people.eng.unimelb.edu.au/ammoffat/ppsaa/) - seriously, get this book in physical book or as a PDF, it is damn useful).

# Awesome, did I conquer C?

![Hahaha, no](http://i0.kym-cdn.com/entries/icons/original/000/013/113/hahaha-no.gif)

This article was intended to be a warm up, *getting-your-head-wet-before-you-jump-into-the-pool* article.

There are number of things we haven't covered, Array, Structure, Forward Declaring and countless other things.

I haven't finished explaining on `argv` and its type, `char**` - this is because I haven't covered some of the related concepts as I wanted to focus on the pointer variables since it is the concept I personally struggled to understand when I was learning C.

So get out there and create some [segmentation faults](https://www.reddit.com/r/ProgrammerHumor/comments/54mzk3/roses_are_red/) - getting your hands dirty is best way to learn. ([Please don't do this kind of thing in production environment though](https://np.reddit.com/r/cscareerquestions/comments/6ez8ag/accidentally_destroyed_production_database_on/))

Have fun!


Ha Jin Song

Trapped in CS course since 2012
