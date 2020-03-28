CC=gcc
CFLAGS=-I
DEPS = graph.h
OBJ = main.o graph.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o graph.exe $^ $(CFLAGS)

clean:
	rm -f *.o graph.exe