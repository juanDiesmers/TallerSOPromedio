CC=gcc
CFLAGS=-Wall
TARGETS=calculadora_promedio

all: $(TARGETS)

calculadora_promedio: calculadora_promedio.o
	$(CC) $(CFLAGS) -o calculadora_promedio calculadora_promedio.o

calculadora_promedio.o: calculadora_promedio.c
	$(CC) $(CFLAGS) -c calculadora_promedio.c

clean:
	rm -f *.o $(TARGETS)

run: calculadora_promedio
	./calculadora_promedio test.txt
