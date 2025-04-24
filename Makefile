SRCS= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

SRCN= cgn.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

ARMSRCS= cg_arm.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRCS)
	cc -o comp -g -Wall $(SRCS)

compn: $(SRCN)
	cc -o compn -g $(SRCN)

comp_arm: $(ARMSRCS)
	cc -o comp_arm -g -Wall $(ARMSRCS)

clean:
	rm -f comp comp_arm compn *.o *.s *.out out

test: comp tests/runtests
	(cd tests; chmod +x runtests; ./runtests)

arm_qemu: comp_arm ./tests/input02 ./lib/printint.c
	./comp_arm ./tests/input02
	arm-linux-gnueabi-gcc -o arm.out out.s ./lib/printint.c -static
	qemu-arm-static ./arm.out

armtest: comp_arm tests/armtests
	(cd tests; chmod +x armtests; ./armtests)

testn: compn tests/runtestsn
	(cd tests; chmod +x runtestsn; ./runtestsn)

test14: comp tests/input14 lib/printint.c
	./comp tests/input14
	cc -o out out.s lib/printint.c
	./out

armtest14: comp1arm tests/input14 lib/printint.c
	./comp_arm tests/input14
	cc -o out out.s lib/printint.c
	./out

test14n: compn tests/input14 lib/printint.c
	./compn tests/input14
	nasm -f elf64 out.s
	cc -no-pie -o out lib/printint.c out.o
	./out
