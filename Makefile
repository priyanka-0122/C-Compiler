HSRCS= data.h decl.h defs.h
SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

SRCN= cgn.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

ARMSRCS= cg_arm.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRCS) $(HSRCS)
	cc -o comp -g -Wall $(SRCS)

compn: $(SRCN)
	cc -D__NASM__ -o compn -g -Wall $(SRCN)

clean:
	rm -f comp comp_arm compn *.o *.s *.out out

test: comp tests/runtests
	(cd tests; chmod +x runtests; ./runtests)

testn: compn tests/runtestsn
	(cd tests; chmod +x runtestsn; ./runtestsn)

test15: comp tests/input15.c lib/printint.c
	./comp tests/input15.c
	cc -o out out.s lib/printint.c
	./out

test14n: compn tests/input14 lib/printint.c
	./compn tests/input14
	nasm -f elf64 out.s
	cc -no-pie -o out lib/printint.c out.o
	./out
