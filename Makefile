parser: *.c
	gcc -o parser -g *.c

clean: *.o
	rm -f *.o
