#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("hi", O_RDWR);
	char buf[1200];
	read(fd, buf, 10);
	write(fd, "hiasdasd", 23);
	printf("%s\n", buf);
	return 0;
}