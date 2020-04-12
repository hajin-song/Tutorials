CC=gcc
CFLAGS=-I
DEPS = graph.h prim.h utility.h
OBJ = main.o graph.o prim.o utility.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o mst.exe $^ $(CFLAGS)

clean:
	rm -f *.o mst.exe