CC=gcc
CFLAGS=-I
DEPS = bst.h
OBJ = main.o bst.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o bst.exe $^ $(CFLAGS)

clean:
	rm -f *.o bst.exe