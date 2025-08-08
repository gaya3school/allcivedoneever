#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	int f0 = 0;
	int f1 = 1;
	int count = 1;
	/* printf("%d %d ", f0, f1); */
	while (count <= n)
	{
		int res = f0 + f1;
		printf("%d ", res);
		f0 = f1;
		f1 = res;
		++count;
	}
	return 0;
}
