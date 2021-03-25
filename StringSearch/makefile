CC=gcc
CFLAGS=-I
DEPS = bmh.h
OBJ = main.o bmh.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o search.exe $^ $(CFLAGS)

clean:
	rm -f *.o search.exe