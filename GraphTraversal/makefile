CC=gcc
CFLAGS=-I
DEPS = graph.h utility.h dfs.h
OBJ = main.o graph.o utility.o dfs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o graph.exe $^ $(CFLAGS)

clean:
	rm -f *.o graph.exe