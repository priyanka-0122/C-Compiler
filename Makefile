# Define the location of the include directory
# and the location to install the compiler binary
INCDIR=/tmp/include
BINDIR=/tmp

HSRCS= data.h decl.h defs.h incdir.h
SRCS= cg.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

SRCN= cgn.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

ARMSRCS= cg_arm.c decl.c expr.c gen.c main.c misc.c \
	opt.c scan.c stmt.c sym.c tree.c types.c

comp: $(SRCS) $(HSRCS)
	cc -o comp -g -Wall -DINCDIR=\"$(INCDIR)\" $(SRCS)

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

clean:
	rm -f comp comp_arm compn *.o *.out out incdir.h

clean_assem:
	rm *.s

test: install tests/runtests
	(cd tests; chmod +x runtests; ./runtests)

testn: installn tests/runtestsn
	(cd tests; chmod +x runtestsn; ./runtestsn)
