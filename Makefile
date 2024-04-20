CFLAGS=-std=c11 -fno-common

pikkucc: main.o
	$(CC) -o pikkucc main.o $(LDFLAGS)

clean:
	rm -rf pikkucc *.o
