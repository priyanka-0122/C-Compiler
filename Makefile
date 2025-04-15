SRC= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRC)
	gcc -o comp -g $(SRC)

clean:
	rm -f comp *.o *.s out

test:	comp tests/input01 lib/printint.c
	./comp tests/input01
	cc -o out out.s lib/printint.c
	./out

test2:	comp input02 lib/printint.c
	./comp input02
	gcc -o out out.s lib/printint.c
	./out

test3:	comp input03 lib/printint.c
	./comp input03
	gcc -o out out.s lib/printint.c
	./out

test4:	comp input04 lib/printint.c
	./comp input04
	gcc -o out out.s lib/printint.c
	./out

test5: comp input05 lib/printint.c
	./comp input05
	gcc -o out out.s lib/printint.c
	./out

test6: comp input06 lib/printint.c
	./comp input06
	gcc -o out out.s lib/printint.c
	./out
