#include "stdio.h"
#include "stdlib.h"
#include <limits.h>
#include <string.h>

void *ft_calloc(size_t count, size_t size)
{
	void *p  = malloc(count * size);
	memset(p,0, size * count);
	// for(size_t i = 0; i < count * size; i += size * 4)
	// {
	// 	printf("aaaaaa %zu\n", i);

	// 	((long double*)p)[i] = 0;
	// }
	return p;
}

int main()
{
	//printf("%d\n", INT_MAX);
	//long long a = 2147483647 * 12;
	void *p = ft_calloc(214748368847, 4);
	//ft_calloc(2147483647,  22);
	return 0;
}