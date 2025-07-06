#include <stdio.h>

int main()
{

	int a[5] = {1, 2, 3, 4, 5};

	int* (p) = a;

	printf("%d\n", *(p));

	printf("%d\n", *(p + 1));
}