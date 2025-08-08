#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	int sum = 0;
	int count = 1;
	int n1 = 0;
	while (count<=n)
	{
		n1 = (n1*10) + 9;
		printf("%d + ", n1);
		sum = sum +n1;
		count++;
	}
	printf("\n%d", sum);
}
