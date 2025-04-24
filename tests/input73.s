	.data
	.globl	Emp1
Emp1:	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.globl	Emp2
Emp2:	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.globl	Stu1
Stu1:	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
L3:
	.byte	37
	.byte	99
	.byte	9
	.byte	37
	.byte	100
	.byte	9
	.byte	37
	.byte	100
	.byte	10
	.byte	0
L4:
	.byte	37
	.byte	99
	.byte	9
	.byte	37
	.byte	100
	.byte	9
	.byte	37
	.byte	100
	.byte	10
	.byte	0
L5:
	.byte	37
	.byte	99
	.byte	9
	.byte	37
	.byte	100
	.byte	9
	.byte	37
	.byte	100
	.byte	10
	.byte	0
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$0, %rsp
	movq	$65, %r10
	leaq	Emp1(%rip), %r11
	movq	$0, %r12
	addq	%r11, %r12
	movb	%r10b, (%r12)
	movq	$2024, %r10
	leaq	Emp1(%rip), %r11
	movq	$4, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	movq	$54321, %r10
	leaq	Emp1(%rip), %r11
	movq	$8, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	movq	$66, %r10
	leaq	Emp2(%rip), %r11
	movq	$0, %r12
	addq	%r11, %r12
	movb	%r10b, (%r12)
	movq	$2021, %r10
	leaq	Emp2(%rip), %r11
	movq	$4, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	movq	$12345, %r10
	leaq	Emp2(%rip), %r11
	movq	$8, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	movq	$83, %r10
	leaq	Stu1(%rip), %r11
	movq	$0, %r12
	addq	%r11, %r12
	movb	%r10b, (%r12)
	movq	$23, %r10
	leaq	Stu1(%rip), %r11
	movq	$4, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	movq	$5, %r10
	leaq	Stu1(%rip), %r11
	movq	$12, %r12
	addq	%r11, %r12
	movl	%r10d, (%r12)
	leaq	Emp1(%rip), %r10
	movq	$8, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rcx
	leaq	Emp1(%rip), %r10
	movq	$4, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rdx
	leaq	Emp1(%rip), %r10
	movq	$0, %r11
	addq	%r10, %r11
	movzbq	(%r11), %r11
	movq	%r11, %rsi
	leaq	L3(%rip), %r10
	movq	%r10, %rdi
	call	printf@PLT
	movq	%rax, %r10
	leaq	Emp2(%rip), %r10
	movq	$8, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rcx
	leaq	Emp2(%rip), %r10
	movq	$4, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rdx
	leaq	Emp2(%rip), %r10
	movq	$0, %r11
	addq	%r10, %r11
	movzbq	(%r11), %r11
	movq	%r11, %rsi
	leaq	L4(%rip), %r10
	movq	%r10, %rdi
	call	printf@PLT
	movq	%rax, %r10
	leaq	Stu1(%rip), %r10
	movq	$12, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rcx
	leaq	Stu1(%rip), %r10
	movq	$4, %r11
	addq	%r10, %r11
	movq	(%r11), %r11
	movq	%r11, %rdx
	leaq	Stu1(%rip), %r10
	movq	$0, %r11
	addq	%r10, %r11
	movzbq	(%r11), %r11
	movq	%r11, %rsi
	leaq	L5(%rip), %r10
	movq	%r10, %rdi
	call	printf@PLT
	movq	%rax, %r10
	movq	$0, %r10
	movl	%r10d, %eax
	jmp	L2
L2:
	addq	$0,%rsp
	popq	%rbp
	ret
