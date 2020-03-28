CC=gcc
CFLAGS=-I
DEPS = 
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o graph.exe $^ $(CFLAGS)

clean:
	rm -f *.o graph.exe