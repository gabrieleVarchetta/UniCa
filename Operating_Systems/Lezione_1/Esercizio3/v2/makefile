maxmin: top.o max.o min.o
	gcc top.o max.o min.o -o maxmin

top.o: top.c max.c min.c
	gcc -c top.c max.c min.c

max.o: max.h max.c
	gcc -c max.c

min.o: min.h min.c
	gcc -c min.c

clean:
	rm maxmin
	rm -f *.o 