CC = gcc
CFLAGS = -g -O3
MAIN = fmm

.PHONY: all clean

all: $(MAIN)

$(MAIN): main.o fmm.o utilities.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

fmm.o: fmm.c
	$(CC) $(CFLAGS) -c -o $@ $<

utilities.o: utilities.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(MAIN)
	