/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/kernel.h>

extern int z_vrfy_k_msgq_peek_at(struct k_msgq * msgq, void * data, uint32_t idx);
uintptr_t z_mrsh_k_msgq_peek_at(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; struct k_msgq * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; void * val; } parm1;
	parm1.x = arg1;
	union { uintptr_t x; uint32_t val; } parm2;
	parm2.x = arg2;
	int ret = z_vrfy_k_msgq_peek_at(parm0.val, parm1.val, parm2.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

