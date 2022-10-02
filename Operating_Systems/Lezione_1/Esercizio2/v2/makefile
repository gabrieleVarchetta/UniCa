max: top.o max.o 
	gcc top.o max.o -o max 

top.o: max.h top.c
	gcc -c top.c

max.o: max.h max.c
	gcc -c max.c

clean:
	rm max
	rm -f *.o