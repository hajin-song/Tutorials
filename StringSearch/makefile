CC=gcc
CFLAGS=-I
DEPS = naiveSearch.h kmp.h
OBJ = main.o naiveSearch.o kmp.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o search.exe $^ $(CFLAGS)

clean:
	rm -f *.o search.exe