#include <stdio.h>
#include <math.h>

int main()
{
	int n, count, sum;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	int i1 = n;
	for (count=0;i1>0;i1=i1/10)
	{
		count++;
	}
	/* printf("%d", count); */
	
	int i = n;
	for (sum=0;i>0;i=i/10)
	{
		int n1 = i%10;
		int powerr = pow(n1,count);
		sum = sum + powerr;
	}
	
	if (sum==n)
	{
		printf("The number is an Armstrong number. ");
	}
	else
	{
		printf("The number is not an Armstrong number. ");
	}
	
	return 0;
}
