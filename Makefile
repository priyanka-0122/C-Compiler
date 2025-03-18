SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

comp: $(SRCS)
	gcc -o comp -g $(SRCS)

clean:
	rm -f comp *.o *.s *.out

test1:  comp tests/input_07
	./comp tests/input_07
	gcc -o out out.s
	./out
