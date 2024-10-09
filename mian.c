#include "asm.h"

void fd_puts(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int mian(void)
{
	fd_puts(1, "~ Nya <3\n");
	return (0);
}

int main(void)
{
	return (mian());
}
