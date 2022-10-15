#include <unistd.h>
#include <fcntl.h>


int main()
{
	int fd = open("test", O_WRNLY);
	write(fd, "FILE", 6);
	return 0;
}