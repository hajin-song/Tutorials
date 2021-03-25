CC=gcc
CFLAGS=-I
DEPS = linkedList.h
OBJ = main.o linkedList.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
traverse: $(OBJ)
	$(CC) -o mst.exe $^ $(CFLAGS)

clean:
	rm -f *.o mst.exe