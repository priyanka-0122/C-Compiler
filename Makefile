SRCS = cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c
SRCN = cgn.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

comp1: $(SRCS)
	cc -o comp1 -g $(SRCS)

compn: $(SRCN)
	cc -o compn -g $(SRCN)

clean:
	rm -f comp1 compn *.o *.s *.out

test: comp1 input01 input02
	./comp1 input01
	cc -o out out.s
	./out
	./comp1 input02
	cc -o out out.s
	./out

testn: compn input01 input02
	./compn input01
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out
	./compn input02
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out
