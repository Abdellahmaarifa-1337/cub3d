#include<stdio.h>
  #include <string.h>
int main()
{
	int a = 0;

	for(int i = 0 ; i < 32; i++)
		printf("1");
	printf("\n");
	//char c = *((char *)&a);
	memset(&a, 255, 4);
	//memset(&a, 0, 3);
	
	//memset(&c + 1, 119, 1);
	// memset(&a, 84, 2);
	// memset(&a, 159, 1);
	printf("%d\n", a);
	return (0);
}

// 24597663

// 1 01110111 01010100 10011111