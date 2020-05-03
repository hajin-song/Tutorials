CC=gcc
CFLAGS=-I
DEPS = quickSort.h mergeSort.h
OBJ = main.o quickSort.o mergeSort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o sort.exe $^ $(CFLAGS)

clean:
	rm -f *.o sort.exe