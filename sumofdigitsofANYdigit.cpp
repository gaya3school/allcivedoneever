#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	int sum = 0;
	int i = n;
	while(i>0)
	{
		int n1 = i%10;
		sum = sum + n1;
		i=i/10;
	}
	printf("%d is the sum of the digits of the number", sum);
	
	return 7;
}
