comp: cg.c expr.c gen.c interp.c main.c scan.c tree.c
	gcc -o comp -g cg.c expr.c gen.c interp.c main.c scan.c tree.c

clean:
	 rm -f comp *.o *.s out

test1: comp
	./comp input01
	gcc -o out out.s
	./out

test2: comp
	./comp input02
	gcc -o out out.s
	./out

test3: comp
	./comp input06
	gcc -o out out.s
	./out
