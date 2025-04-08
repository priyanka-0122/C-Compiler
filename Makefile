SRC= cg.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

comp: $(SRC)
	gcc -o comp -g $(SRC)

clean:
	rm -f comp *.o *.s out

test: comp input01
	./comp input01
	gcc -o out out.s
	./out

test2: comp input02
	./comp input02
	gcc -o out out.s
	./out

test3: comp input03
	./comp input03
	gcc -o out out.s
	./out

test4: comp input04
	./comp input04
	gcc -o out out.s
	./out


test5: comp input05
	./comp input05
	gcc -o out out.s
	./out

test6: comp input06
	./comp input06
	gcc -o out out.s
	./out
