#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	// {
	// 	char *s = "dgdfgdf";
	// 	//char *p[]={"dqdq",NULL};
	// 	char **p;
	// 	p = malloc(sizeof(char*) * 2);
	// 	p[0] = strdup(s);
	// 	p[1] = NULL;
	// 	if (p)
	// 		printf("%p\n", p);
	// 	// printf("p: %s\n", *p);
	// 	void *i = p;
	// 	// printf("i: %s\n", *(char**)i);

	// }
	{
		// munmap(p, 8);
		// printf("%s\n", strerror(errno));
		// free((void*)(0x7f90cac02a90));
		// char *p = malloc(sizeof(char*));
		// printf(">>>>> %s\n", p);

		// p = (void*)0x7f90cac02a90;
	
		char *s = strdup("hello Ayoub");
		printf("s == %p\n", s);
		while(1);
	}
	
	return (0);
}