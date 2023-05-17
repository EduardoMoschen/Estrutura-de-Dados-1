all: lista

lista: lista.o main.o
	gcc -o lista lista.o main.o

lista.o: lista.c lista.h
	gcc -c lista.c -Wall -Werror -Wextra

main.o: main.c lista.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o lista