CC=gcc
CFLAGS=-I.
DEPS = pq.h
OBJ = main.o pq.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

traverse: $(OBJ)
	$(CC) -o shortest.exe $^ $(CFLAGS)

clean:
	rm -f *.o shortest.exe