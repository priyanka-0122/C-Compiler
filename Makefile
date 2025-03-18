SRC= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

comp: $(SRC)
	gcc -o comp -g $(SRC)

clean:
	rm -f comp *.o *.s *.out

test: comp tests/input_10
	./comp tests/input_10
	cc -o out out.s
	./out
