# Define the location of the include directory
# and the location to install the compiler binary
INCDIR=/tmp/include
BINDIR=/tmp

HSRCS= data.h decl.h defs.h incdir.h
SRCS= cg.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

ARMSRCS= cg_arm.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRCS) $(HSRCS)
	cc -o comp -g -Wall $(SRCS)

comp_arm: $(ARMSRCS) $(HSRCS)
	cc -o comp_arm -g -Wall $(ARMSRCS)

incdir.h:
	echo "#define INCDIR \"$(INCDIR)\"" > incdir.h

install: comp
	mkdir -p $(INCDIR)
	rsync -a include/. $(INCDIR)
	cp comp $(BINDIR)
	chmod +x $(BINDIR)/comp

memmake:
	chmod +x ./memmake
	./memmake

clean:
	rm -f comp comp_arm cwj* *.o *.out out incdir.h

clean_pre:
	rm *.i

clean_qbe:
	rm *.q

clean_assem:
	rm *.s

cwj2: cwj $(SRCS) $(HSRCS)
	./cwj -o cwj2 $(SRCS)

cwj: comp $(SRCS) $(HSRCS)
	./comp -o cwj $(SRCS)

test: install tests/runtests
	(cd tests; chmod +x runtests; ./runtests)

test_cwj: install tests/runtests_cwj cwj
	(cd tests; chmod +x runtests_cwj; ./runtests_cwj)

test_cwj2: install tests/runtests_cwj2
	(cd tests; chmod +x runtests_cwj2; ./runtests_cwj2)

test_cwj3: install tests/runtests_cwj3
	(cd tests; chmod +x runtests_cwj3; ./runtests_cwj3)

# Run the tests, stop on the first failure compiler that compiled itself
stoptest: install tests/runtests
	(cd tests; chmod +x runtests; ./runtests stop)

stoptest_cwj: install tests/runtests_cwj
	(cd tests; chmod +x runtests_cwj; ./runtests_cwj stop)

stoptest_cwj2: install tests/runtests_cwj2
	(cd tests; chmod +x runtests_cwj2; ./runtests_cwj2 stop)

stoptest_cwj3: install tests/runtests_cwj3
	(cd tests; chmod +x runtests_cwj3; ./runtests_cwj3 stop)

# Try to do the triple test
triple: cwj cwj2
	size cwj
	size cwj2

testn: installn tests/runtestsn
	(cd tests; chmod +x runtestsn; ./runtestsn)
