#ifndef ASM_H
#define ASM_H

#include <stdlib.h>

ssize_t	write(int fd, const void *buf, size_t count)
{
	ssize_t	len;

	asm ("syscall":"=a"(len):"a"(1), "D"(fd), "S"(buf), "d"(count));
	return (len);
}

void	exit(int status)
{
	asm ("syscall"::"a"(60),"D"(status));
	while (1);
}

int main(void); // TODO: find a way to get argc, argv & envp
void _start(void)
{
	exit(main());
}

#endif
