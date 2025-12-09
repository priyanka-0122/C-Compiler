Goal is to develop new compiler for C using acwj

priyanka@LPT-I-060:~/Compilers/64_6809_target$ cd                                                                              
priyanka@LPT-I-060:~$ mkdir 6809_Target                                                                                        
priyanka@LPT-I-060:~$ cd 6809_Target/                                                                                          

priyanka@LPT-I-060:~/6809_Target$ wget https://c9x.me/compile/release/qbe-1.2.tar.xz                                           
--2025-10-10 12:56:38--  https://c9x.me/compile/release/qbe-1.2.tar.xz                                                             
Resolving c9x.me (c9x.me)... 95.179.132.158, 2001:19f0:5001:efd:5400:1ff:fe7f:f1fc                                                 
Connecting to c9x.me (c9x.me)|95.179.132.158|:443... connected.                                                                    
HTTP request sent, awaiting response... 200 OK                                                                                     
Length: 246364 (241K) [application/octet-stream]                                                                                   
Saving to: ‘qbe-1.2.tar.xz’                                                                                                        
                                                                                                                                   
qbe-1.2.tar.xz      100%[=========================================================>] 240.59K   234KB/s in 1.0s     
                                                                                                                                   
2025-10-10 12:56:41 (234 KB/s) - ‘qbe-1.2.tar.xz’ saved [246364/246364]
priyanka@LPT-I-060:~/6809_Target$ xz -d qbe-1.2.tar.xz                                                                         

priyanka@LPT-I-060:~/6809_Target$ tar vxf qbe-1.2.tar                                                                          
qbe-1.2/                                                                                                                           
qbe-1.2/.gitignore
.
.                                                                                                            
qbe-1.2/tools/vatest.py                                                                                                            
qbe-1.2/util.c                                                                                                                     
priyanka@LPT-I-060:~/6809_Target$ cd qbe-1.2/                 

priyanka@LPT-I-060:~/6809_Target/qbe-1.2$ make                                                                                 
cc -std=c99 -g -Wall -Wextra -Wpedantic -c main.c -o main.o
.
.                                                       
cc  main.o util.o parse.o abi.o cfg.o mem.o ssa.o alias.o load.o  copy.o fold.o simpl.o live.o spill.o rega.o emit.o amd64/targ.o amd64/sysv.o amd64/isel.o amd64/emit.o arm64/targ.o arm64/abi.o arm64/isel.o arm64/emit.o rv64/targ.o rv64/abi.o rv64/isel.o rv64/emit.o -o qbe                                                                                               
priyanka@LPT-I-060:~/6809_Target/qbe-1.2$ ls                                                                                   
<-------check the presence of qbe --------->

priyanka@LPT-I-060:~/6809_Target/qbe-1.2$ cd                                                                                   
6809_Target  ACWJ  C-Compiler  Compilers  Graphs  Issue                                                                            

priyanka@LPT-I-060:~$ cd Compilers/64_6809_target/                    

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make install                                                                    
mkdir -p /opt/wcc/include/6809                                                                                                     
mkdir -p /opt/wcc/include/qbe                                                                                                      
.
.                                                       
cp: cannot create regular file '/opt/wcc/bin/cgenqbe': Permission denied                                                           
make: *** [Makefile:84: install] Error 1                                                                                           

priyanka@LPT-I-060:~/Compilers/64_6809_target$ vi Makefile
<------- change the TOPDIR path ----------->                                                                   

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make install                                                                    
mkdir -p /home/priyanka/6809_Target/include/6809                                                                                   
mkdir -p /home/priyanka/6809_Target/include/qbe                                                                                    
.
.
cp wcc cscan detok detree desym cpeep \                                                                                            
  cparse6809 cgen6809 \                                                                                                            
  cparseqbe cgenqbe /home/priyanka/6809_Target/bin                                                                                 

priyanka@LPT-I-060:~/Compilers/64_6809_target$ cd /home/priyanka/6809_Target/                                                  
bin  include  lib  qbe-1.2  qbe-1.2.tar                                                                                            

priyanka@LPT-I-060:~/6809_Target$ mkdir 6809_bins                                                                              
priyanka@LPT-I-060:~/6809_Target$ cd 6809_bins/                                                                                
priyanka@LPT-I-060:~/6809_Target/6809_bins$ which wcc                                                                          

priyanka@LPT-I-060:~/6809_Target/6809_bins$ cd ..                                                                              
6809_bins  bin  include  lib  qbe-1.2  qbe-1.2.tar                                                                                 

priyanka@LPT-I-060:~/6809_Target$ cd Compilers/64_6809_target/                                                                             

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make clean                                                                      
rm -f wcc cscan detok detree desym cpeep \                                                                                         
  cparse6809 cgen6809 \                                                                                                            
  cparseqbe cgenqbe                                                                                                                
rm -f *.o *.s out a.out dirs.h l?dirs.h *.gc??                                                                                     
rm -rf L1 L2                                                                                                                       

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make                                                                            
echo "#define TOPDIR \"/home/priyanka/6809_Target\"" > l0dirs.h                                                                    
echo "#define INCQBEDIR \"/home/priyanka/6809_Target/include/qbe\"" >> l0dirs.h                                                    
.
.            
cc -o cgenqbe -g -Wall cgqbe.c cgen.c gen.c misc.c sym.c targqbe.c tree.c types.c                                                  

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make install                                                                    

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make triple                                                                     
mkdir -p /home/priyanka/6809_Target/include/6809                                                                                   
mkdir -p /home/priyanka/6809_Target/include/qbe                                                                                    
.
.                                                                                                                      
wcc -o L1/wcc wcc.c                                                                                                                
make: wcc: No such file or directory                                                                                               
make: *** [Makefile:111: L1/wcc] Error 127                                                                                                         

priyanka@LPT-I-060:~/Compilers/64_6809_target$ export PATH=/home/priyanka/6809_Target/bin:$PATH

priyanka@-LPT-I-060:~/Compilers/64_6809_target$ which wcc
/home/priyanka/6809_Target/bin/wcc

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make clean                                                                      
priyanka@LPT-I-060:~/Compilers/64_6809_target$ make                                                                            

priyanka@LPT-I-060:~/Compilers/64_6809_target$ ls
<----------- check the presence of wcc ----->                    

priyanka@LPT-I-060:~/Compilers/64_6809_target$ make triple                                                                     
mkdir -p /home/priyanka/6809_Target/include/6809                                                                                   
mkdir -p /home/priyanka/6809_Target/include/qbe                                                                                    
.
.
eade6d174aaf0e5cecc798d4c3d0894b  L2/cparseqbe
fa06b33a13f452df6513ee19936ea425  L2/wcc                                                                                            

priyanka@LPT-I-060:~/Compilers/64_6809_target$ cd                                                                           
6809_Target  ACWJ  C-Compiler  Compilers  Graphs  Issue                                                                            

priyanka@LPT-I-060:~$ cd 6809_Target/                                                                                          
6809_bins  bin  include  lib  qbe-1.2  qbe-1.2.tar                                                                                 

priyanka@LPT-I-060:~/6809_Target$ git clone https://github.com/EtchedPixels/Fuzix-Bintools                                     
Cloning into 'Fuzix-Bintools'...                                                                                                   
remote: Enumerating objects: 799, done.                                                                                            
.
.
Receiving objects: 100% (799/799), 337.78 KiB | 811.00 KiB/s, done.                                                                
Resolving deltas: 100% (518/518), done.                                                                                            

priyanka@LPT-I-060:~/6809_Target$ cd Fuzix-Bintools/                       

priyanka@LPT-I-060:~/6809_Target/Fuzix-Bintools$ make as6809 ld6809                                                            
cc -Wall -pedantic  -DTARGET_6809 -o as6809 as0.c as2.c as3.c as4.c as1-6809.c as6-6809.c                                          
cc -Wall -pedantic -o ld6809 ld.c                                                                                                  

priyanka@LPT-I-060:~/6809_Target/Fuzix-Bintools$ ls
<------ verify the presence of ld6809 as6809 ----->                  

priyanka@LPT-I-060:~/6809_Target/Fuzix-Bintools$ cd ~                                                                          
6809_Target  ACWJ  C-Compiler  Compilers  Graphs  Issue                                                                            

priyanka@LPT-I-060:~$ cd 6809_Target                                                                                                       
6809_bins  Binaries  Fuzemsys  Fuzix-Bintools  bin  include  lib  qbe-1.2  qbe-1.2.tar                                                                            
priyanka@LPT-I-060:~/6809_Target$ pwd                                                                                                      
/home/priyanka/6809_Target                                                                                                                     

priyanka@LPT-I-060:~/6809_Target$ mkdir Binaries

priyanka@LPT-I-060:~/6809_Target$ cd -
/home/priyanka/6809_Target/Fuzix-Bintools                   

priyanka@LPT-I-060:~/6809_Target/Fuzix-Bintools$ cp as6809 ld6809 ~/6809_Target/Binaries/                                

priyanka@LPT-I-060:~/6809_Target/Fuzix-Bintools$ cd ~/6809_Target/Binaries/                                                                
as6809  ld6809                                                                                                                     

priyanka@LPT-I-060:~$ cd ~/Compilers/64_6809_target/                                                                             
priyanka@LPT-I-060:~/Compilers/64_6809_target$ which as6809                                                                    

priyanka@LPT-I-060:~/Compilers/64_6809_target$ which wcc                                                                       
/home/priyanka/Compilers/64_6809_target/wcc                                                                                          

priyanka@LPT-I-060:~/Compilers/64_6809_target$ export PATH=/home/priyanka/6809_Target/Binaries:$PATH
<------- add this in 6809triple_test ------------>                                      

priyanka@LPT-I-060:~/Compilers/64_6809_target$ which wcc                                                                       
/home/priyanka/Compilers/64_6809_target/wcc                                                                                        

priyanka@LPT-I-060:~/Compilers/64_6809_target$ which as6809                                                                    
/home/priyanka/Binaries/as6809                                                                                                    

priyanka@LPT-I-060:~/Compilers/64_6809_target$ cd                                                                              
6809_Target  ACWJ  Binaries  C-Compiler  Compilers  Graphs  Issue                                                                  

priyanka@LPT-I-060:~$ cd 6809_Target/                                                                                          
6809_bins  Fuzix-Bintools  bin  include  lib  qbe-1.2  qbe-1.2.tar                                                                 

priyanka@LPT-I-060:~/6809_Target$ git clone https://github.com/DoctorWkt/Fuzemsys                                              
Cloning into 'Fuzemsys'...                                                                                                         
remote: Enumerating objects: 2048, done.                                                                                           
remote: Counting objects: 100% (549/549), done.                                                                                    
remote: Compressing objects: 100% (485/485), done.                                                                                 
remote: Total 2048 (delta 116), reused 473 (delta 61), pack-reused 1499 (from 1)                                                   
Receiving objects: 100% (2048/2048), 1.09 MiB | 685.00 KiB/s, done.                                                                
Resolving deltas: 100% (700/700), done.                                                                                            

priyanka@LPT-I-060:~/6809_Target$ cd Fuzemsys/emulators/                                                                       
Makefile  d6809.h  e6809.h    emumon.c  emuz80.c  exec.h  mapfile.c  syscalls.c  z80dis.c                                          
d6809.c   e6809.c  emu6809.c  emumon.h  emuz80.h  libz80  mapfile.h  syscalls.h  z80dis.h                                          

priyanka@LPT-I-060:~/6809_Target/Fuzemsys/emulators$ make emu6809                                                              
cc -Wall -pedantic -g -c emu6809.c                                                                                                 
.
.                                                                     
cc -Wall -pedantic -g -o emu6809 emu6809.o e6809.o d6809.o \                                                                       
        syscalls6809.o mapfile.o emumon6809.o \                                                                                    
        -lreadline                                                                                                                 

priyanka@LPT-I-060:~/6809_Target/Fuzemsys/emulators$ cp emu6809 ~/6809_Target/Binaries/                                                    

priyanka@LPT-I-060:~/6809_Target/Fuzemsys/emulators$ cd                                                                        
6809_Target  ACWJ  Binaries  C-Compiler  Compilers  Graphs  Issue                                                                  

priyanka@LPT-I-060:~$ cd ~/Compilers/64_6809_target/                                                                             
priyanka@LPT-I-060:~/Compilers/64_6809_target$ make                                                                            
priyanka@LPT-I-060:~/Compilers/64_6809_target$ make install                                                                    
priyanka@LPT-I-060:~/Compilers/64_6809_target$ make triple
priyanka@LPT-I-060:~/Compilers/64_6809_target$ ./6809triple_test
rm -f wcc cscan detok detree desym cpeep \                                                                                                                               
  cparse6809 cgen6809 \                                                                                                                                                  
  cparseqbe cgenqbe
.
.
.
Doing: ld6809 -o L2/_cgen6809 /home/priyanka/Compilers/64_6809_target/lib/6809/crt0.o cg6809.c_o cgen.c_o gen.c_o misc.c_o sym.c_o targ6809.c_o tree.c_o types.c_o /home/
priyanka/Compilers/64_6809_target/lib/6809/libc.a /home/priyanka/Compilers/64_6809_target/lib/6809/lib6809.a
