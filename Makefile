# Define the location of the include directory
# and the location to install the compiler binary
INCDIR=/tmp/include
BINDIR=/tmp

HSRCS= data.h decl.h defs.h incdir.h
SRCS= cg.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

SRCO= cg.c decl.c expr.c gen_old.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

SRCN= cgn.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

ARMSRCS= cg_arm.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRCS) $(HSRCS)
	cc -o comp -g -Wall -DINCDIR=\"$(INCDIR)\" $(SRCS)

comp_old: $(SRCO) $(HSRCS)
	cc -o comp -g -Wall -DINCDIR=\"$(INCDIR)\" $(SRCO)

compn: $(SRCN) $(HSRCS)
	cc -D__NASM__ -o compn -g -Wall -DINCDIR=\"$(INCDIR)\" $(SRCN)

comp_arm: $(ARMSRCS) $(HSRCS)
	cc -o comp_arm -g -Wall $(ARMSRCS)

incdir.h:
	echo "#define INCDIR \"$(INCDIR)\"" > incdir.h

install: comp
	mkdir -p $(INCDIR)
	rsync -a include/. $(INCDIR)
	cp comp $(BINDIR)
	chmod +x $(BINDIR)/comp

installn: compn
	mkdir -p $(INCDIR)
	rsync -a include/. $(INCDIR)
	cp compn $(BINDIR)
	chmod +x $(BINDIR)/compn

memmake:
	chmod +x ./memmake
	./memmake

memmake_2:
	chmod +x ./memmake_2
	./memmake_2

memmake_3:
	chmod +x ./memmake_3
	./memmake_3

cwj:
	rm cwj;
	cc -o cwj cg.o decl.o expr.o gen.o main.o misc.o \
        	opt.o scan.o stmt.o sym.o tree.o types.o	

clean:
	rm -f comp comp_arm compn cwj* *.o *.out out incdir.h
#	rm cg.s decl.s expr.s gen.s main.s misc.s opt.s scan.s stmt.s sym.s tree.s types.s

clean_assem:
	rm *.s

clean_pre:
	rm *.i

cwj2: cwj $(SRCS) $(HSRCS)
	./cwj -o cwj2 $(SRCS)

cwj: comp $(SRCS) $(HSRCS)
	./comp -o cwj $(SRCS)

test: install tests/runtests
	(cd tests; chmod +x runtests; ./runtests)

test_cwj: install tests/runtests_cwj
	(cd tests; chmod +x runtests_cwj; ./runtests_cwj)

test_cwj2: install tests/runtests_cwj2
	(cd tests; chmod +x runtests_cwj2; ./runtests_cwj2)

test_cwj3: install tests/runtests_cwj3
	(cd tests; chmod +x runtests_cwj3; ./runtests_cwj3)

# Try to do the triple test
triple: cwj cwj2
	size cwj
	size cwj2

testn: installn tests/runtestsn
	(cd tests; chmod +x runtestsn; ./runtestsn)
