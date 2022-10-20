#include "stdio.h"


void test(void *s1, void *s2)
{
	write(1, s1, strlen(s1));
	write(1, "\n", 1);
	write(1, s1, strlen(s2));
}

int main()
{
	char *s1 = "A";
	char *s2 = "Z";
	// test(s1, s2);
	// test("A", "Z");
	// printf(">> %lu, %lu\n", sizeof(char *), sizeof(int *));
	// printf("%d\n", memcmp("ACE", "ACK" , 3));
	printf("%d\n", memcmp(s1, s2 , 3));
	return 0;
}