	.file	"add.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	andl	$-16, %rsp
	subq	$32, %rsp
	movq	$2, 20(%rsp)
	movq	$3, 24(%rsp)
	movq	24(%rsp), %rax
	movq	20(%rsp), %rdx
	addq	%rdx, %rax
	movq	%rax, 28(%rsp)
	movq	28(%rsp), %rax
	movq	%rax, 4(%rsp)
	movq	$.LC0, (%rsp)
	call	printf
	movq	$0, %rax
	leave
	.cfi_restore 6
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
