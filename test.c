#include<stdio.h>
#include<string.h>
char    *ft_strchr(const char *s, int c)
{
    size_t    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char) c)
            return ((char *)s + i);
        i++;
    }
	// char t = (char)c;
	if (s[i] == c)
		return ((char *)s + i);
    if (!c)
    {
		// if (s[i] == c)
		// 	printf("the same\n");
        return ((char *)s + i);
    }
    return (NULL);

}

int same_offset(void *expected_start, void *expected_res, void *start, void *res)
{
	long offset = (long)res - (long)start;
	long expected_offset = (long)expected_res - (long)expected_start;

	if (res == NULL && expected_res == NULL)
		return 1;
	if (offset == expected_offset)
		return 1;
	if ((res == NULL && expected_res != NULL) || (res != NULL && expected_res == NULL))
		return 0;

	return 0;
}

int single_test_strchr(int test_number, char *str, int ch)
{
	//set_signature_tn(test_number, "ft_strchr(%p: \"%s\", %i: %s)", str, str, ch, escape_chr(ch));
	char *res = ft_strchr(str, ch);
	char *res_std = strchr(str, ch);

	return same_offset(str, res_std, str, res);
}

int    main()
{

    printf("%d\n",single_test_strchr(3, "teste", '\0'));
	return 0;
}

int main()
{
	float t = 0.5f;
	float k = 5lu / 2;
	printf("%f\n", k);
	return (0);
}