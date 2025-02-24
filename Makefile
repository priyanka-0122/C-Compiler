comp: cg.c expr.c gen.c main.c misc.c scan.c stmt.c tree.c
	gcc -o comp -g cg.c expr.c gen.c main.c misc.c scan.c stmt.c tree.c

clean:
	rm -f comp *.o *.s out

test: comp input00
	./comp input00
	cc -o out out.s
	./out

test1: comp input01
	./comp input01
	cc -o out out.s
	./out

test2: comp input02
	./comp input02
	cc -o out out.s
	./out
