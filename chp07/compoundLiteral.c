#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int* arr = (const int[]) { 1, 2, 3, 4, 5 };

	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	// c 에서는 됩니다. char* str = "hello";
	char *str1 = "hello";
	char str2[] = "hello";
	char str3[] = "hello";

	printf("\n%p\n", str1);
	printf("%p\n", str2);
	printf("%p\n", str3);

	return 0;
}
