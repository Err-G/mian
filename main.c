// $(CC) -nostdlib -static main.c -o main

#include <stdlib.h> // for size_t & ssize_t

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

void fd_puts(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void _start(void)
{
	fd_puts(1, "~ Nya <3\n");
	exit(0);
}
