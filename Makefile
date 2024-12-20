all: main

main: main.c data_structure.c vector.c sort.c io.c
	gcc -o main main.c data_structure.c vector.c sort.c io.c

clean:
	rm -f main