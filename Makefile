pratt_parser: main.c scan.c expr.c tree.c interp.c
		gcc -o pratt_parser -g main.c scan.c expr.c tree.c interp.c

prec_parser: main.c scan.c expr2.c tree.c interp.c
		gcc -o prec_parser -g main.c scan.c expr2.c tree.c interp.c

clean: *.o
	rm -rf *.o
