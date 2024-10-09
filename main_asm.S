// 64 bit code - it doesnt run on 32 bit machine! :)
.global _start

// Simple "stack based" calling convention

_start:

	push $1 // $<value> (is immediate value, or you can call it "literal")
	push $msg // $msg (is the pointer of msg)
	push msg_len // msg_len (is the value pointed by msg_len)
	call write // write (1, msg, 7)

	push $0
	call exit // exit (0)

// ============================================================================

write:
	pop %r12 // store return value in a register
	pop %rdx
	pop %rsi
	pop %rdi
	mov $1, %rax // 1 is the syscall WRITE
	syscall
	push %r12 // push back return value to register
	ret

exit:
	pop %r12 // store return value in a register
	pop %rdi
	mov $60, %rax // 60 is the sycall EXIT
	syscall
	push %r12 // push back return value to register
	ret

// Is there better ways of doing that? yes.

msg: .string "Hello!\n"
msg_len: .int . - msg
