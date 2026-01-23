# Steps to build the compiler

### 1. Making a Directory at my desired path where I can set all the executables and their respective source
	~/Compilers/64_6809_target$ cd
	~$ mkdir 6809_Target
	~$ cd 6809_Target/

### 2. Downloading the qbe zip file and exporting it
	~/6809_Target$ wget https://c9x.me/compile/release/qbe-1.2.tar.xz
			--2025-10-10 12:56:38--  https://c9x.me/compile/release/qbe-1.2.tar.xz
			Resolving c9x.me (c9x.me)... 95.179.132.158, 2001:19f0:5001:efd:5400:1ff:fe7f:f1fc
			.
			.
			Saving to: ‘qbe-1.2.tar.xz’
			qbe-1.2.tar.xz      100%[=========================================================>] 240.59K   234KB/s in 1.0s

			2025-10-10 12:56:41 (234 KB/s) - ‘qbe-1.2.tar.xz’ saved [246364/246364]
	~/6809_Target$ xz -d qbe-1.2.tar.xz
	~/6809_Target$ tar vxf qbe-1.2.tar
			qbe-1.2/
			.
			.
			qbe-1.2/util.c
	~/6809_Target$ cd qbe-1.2/
	~/6809_Target/qbe-1.2$ make
			cc -std=c99 -g -Wall -Wextra -Wpedantic -c main.c -o main.o
			.
			.
			cc  main.o util.o parse.o abi.o cfg.o mem.o ssa.o alias.o load.o  copy.o fold.o simpl.o live.o spill.o rega.o emit.o amd64/targ.o amd64/sysv.o amd64/isel.o amd64/emit.o arm64/targ.o arm64/abi.o arm64/isel.o arm64/emit.o rv64/targ.o rv64/abi.o rv64/isel.o rv64/emit.o -o qbe
	~/6809_Target/qbe-1.2$ ls
			<------- check the presence of qbe ------->
	~/6809_Target/qbe-1.2$ cd
			6809_Target  Compilers
	~$ cd Compilers/64_6809_target/

### 3. Making the executables related to compilation stages
	~/Compilers/64_6809_target$ make install
			mkdir -p /opt/wcc/include/6809
			.
			.
			cp: cannot create regular file '/opt/wcc/bin/cgenqbe': Permission denied
			make: *** [Makefile:84: install] Error 1

### 4. Set the TOPDIR to the directory created earlier to set all executables (i.e /home/priyanka/6809_Target in my case)
	~/Compilers/64_6809_target$ vi Makefile
			<------- change the TOPDIR path ----------->

	~/Compilers/64_6809_target$ make install
			mkdir -p /home/priyanka/6809_Target/include/6809
			.
			.
			cp wcc cscan detok detree desym cpeep \
			  cparse6809 cgen6809 \
			  cparseqbe cgenqbe /home/priyanka/6809_Target/bin
	~/Compilers/64_6809_target$ make clean
			rm -f wcc cscan detok detree desym cpeep \
			  cparse6809 cgen6809 \
			  cparseqbe cgenqbe
			rm -f *.o *.s out a.out dirs.h l?dirs.h *.gc??
			rm -rf L1 L2
	~/Compilers/64_6809_target$ make
			echo "#define TOPDIR \"/home/priyanka/6809_Target\"" > l0dirs.h
			echo "#define INCQBEDIR \"/home/priyanka/6809_Target/include/qbe\"" >> l0dirs.h
			.
			.
			cc -o cgenqbe -g -Wall cgqbe.c cgen.c gen.c misc.c sym.c targqbe.c tree.c types.c
	~/Compilers/64_6809_target$ make install
	~/Compilers/64_6809_target$ make triple
			mkdir -p /home/priyanka/6809_Target/include/6809
			.
			.
			wcc -o L1/wcc wcc.c
			make: wcc: No such file or directory
			make: *** [Makefile:111: L1/wcc] Error 127

### 5. Exporting the path of wcc and other executable for compilation stages and check the presence of wcc
	~/Compilers/64_6809_target$ export PATH=/home/priyanka/6809_Target/bin:$PATH
	~/Compilers/64_6809_target$ which wcc
			/home/priyanka/6809_Target/bin/wcc

### 6. Rebuilding the triple
	~/Compilers/64_6809_target$ make clean
	~/Compilers/64_6809_target$ make
	~/Compilers/64_6809_target$ make triple
			mkdir -p /home/priyanka/6809_Target/include/6809
			.
			.
			fa06b33a13f452df6513ee19936ea425  L2/wcc

### 7. Cloning and making the Bintools for 6809 assembling, loading and simulating
	~/Compilers/64_6809_target$ cd
			6809_Target  Compilers
	~/Compilers/64_6809_target$ cd /home/priyanka/6809_Target/
			bin  include  lib  qbe-1.2  qbe-1.2.tar
	~/6809_Target$ git clone https://github.com/EtchedPixels/Fuzix-Bintools
			Cloning into 'Fuzix-Bintools'...
			.
			.
			Resolving deltas: 100% (518/518), done.
	~/6809_Target$ cd Fuzix-Bintools/
	~/6809_Target/Fuzix-Bintools$ make as6809 ld6809
			cc -Wall -pedantic  -DTARGET_6809 -o as6809 as0.c as2.c as3.c as4.c as1-6809.c as6-6809.c
			cc -Wall -pedantic -o ld6809 ld.c
	~/6809_Target/Fuzix-Bintools$ ls
			<------ verify the presence of ld6809 as6809 ------>

### 8. Exporting the assembler, loader and simulator into the Binary directory
	~/6809_Target/Fuzix-Bintools$ cd ..
			Fuzemsys  Fuzix-Bintools  bin  include  lib  qbe-1.2  qbe-1.2.tar
	~/6809_Target$ pwd
			/home/priyanka/6809_Target
	~/6809_Target$ mkdir Binaries
	~/6809_Target$ cd -
			/home/priyanka/6809_Target/Fuzix-Bintools
	~/6809_Target/Fuzix-Bintools$ cp as6809 ld6809 ~/6809_Target/Binaries/
	~/6809_Target/Fuzix-Bintools$ cd ~/6809_Target/Binaries/
			as6809  ld6809
	~$ cd ~/Compilers/64_6809_target/
	~/Compilers/64_6809_target$ which as6809
	~/Compilers/64_6809_target$ which wcc
			/home/priyanka/Compilers/64_6809_target/wcc
	~/Compilers/64_6809_target$ export PATH=/home/priyanka/6809_Target/Binaries:$PATH
			<-------- add this in 6809triple_test as well -------->
	~/Compilers/64_6809_target$ which as6809
			/home/priyanka/Binaries/as6809
	~/Compilers/64_6809_target$ cd
			6809_Target  ACWJ  Binaries  C-Compiler  Compilers  Graphs  Issue
	~$ cd 6809_Target/
			6809_bins  Fuzix-Bintools  bin  include  lib  qbe-1.2  qbe-1.2.tar
	~/6809_Target$ git clone https://github.com/DoctorWkt/Fuzemsys
			Cloning into 'Fuzemsys'...
			.
			.
			Resolving deltas: 100% (700/700), done.
	~/6809_Target$ cd Fuzemsys/emulators/
			Makefile  d6809.h  e6809.h    emumon.c  emuz80.c  exec.h  mapfile.c  syscalls.c  z80dis.c
			d6809.c   e6809.c  emu6809.c  emumon.h  emuz80.h  libz80  mapfile.h  syscalls.h  z80dis.h
	~/6809_Target/Fuzemsys/emulators$ make emu6809
			cc -Wall -pedantic -g -c emu6809.c
			.
			.
			cc -Wall -pedantic -g -o emu6809 emu6809.o e6809.o d6809.o \
			        syscalls6809.o mapfile.o emumon6809.o \
			        -lreadline
	~/6809_Target/Fuzemsys/emulators$ cp emu6809 ~/6809_Target/Binaries/

### 9. Making the 6809 triple test which means self compiling the compiler
	~/6809_Target/Fuzemsys/emulators$ cd
			6809_Target Compilers
	~$ cd ~/Compilers/64_6809_target/
	~/Compilers/64_6809_target$ make
	~/Compilers/64_6809_target$ make install
	~/Compilers/64_6809_target$ make triple
	~/Compilers/64_6809_target$ ./6809triple_test
			rm -f wcc cscan detok detree desym cpeep \
			  cparse6809 cgen6809 \
			  cparseqbe cgenqbe
			.
			.
			Doing: ld6809 -o L2/_cgen6809 /home/priyanka/Compilers/64_6809_target/lib/6809/crt0.o cg6809.c_o cgen.c_o gen.c_o misc.c_o sym.c_o targ6809.c_o tree.c_o types.c_o /home/

			priyanka/Compilers/64_6809_target/lib/6809/libc.a /home/priyanka/Compilers/64_6809_target/lib/6809/lib6809.a
