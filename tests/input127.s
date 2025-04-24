	.text
# internal switch(expr) routine
# %rsi = switch table, %rax = expr
# from SubC: http://www.t3x.org/subc/

switch:
        pushq   %rsi
        movq    %rdx, %rsi
        movq    %rax, %rbx
        cld
        lodsq
        movq    %rax, %rcx
next:
        lodsq
        movq    %rax, %rdx
        lodsq
        cmpq    %rdx, %rbx
        jnz     no
        popq    %rsi
        jmp     *%rax
no:
        loop    next
        lodsq
        popq    %rsi
        jmp     *%rax

	.data
counter:
	.long	0
	.text
fred:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$0, %rsp
	movslq	counter(%rip), %r10
	incl	counter(%rip)
	movl	%r10d, %eax
	jmp	L7
L7:
	addq	$0,%rsp
	popq	%rbp
	ret
L9:
	.byte	37
	.byte	100
	.byte	10
	.byte	0
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movq	$0, %r10
	movl	%r10d, -4(%rbp)
L10:
	movslq	-4(%rbp), %r10
	movq	$5, %r11
	cmpq	%r11, %r10
	jge	L11
	call	fred@PLT
	movq	%rax, %r10
	movq	%r10, %rsi
	leaq	L9(%rip), %r10
	movq	%r10, %rdi
	call	printf@PLT
	movq	%rax, %r10
	movslq	-4(%rbp), %r10
	incl	-4(%rbp)
	jmp	L10
L11:
	movq	$0, %r10
	movl	%r10d, %eax
	jmp	L8
L8:
	addq	$16,%rsp
	popq	%rbp
	ret
