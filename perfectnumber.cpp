#include <stdio.h>

int main()
{
	int n, i, sum;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	for (i=1 , sum=0 ; i<n ; i++)
	{
		if (n%i==0)
		{
			/* printf("\n%d", i); */
			sum = sum + i;
		}
		else {}
	}
	printf("\nThe sum of the divisors of the number is %d", sum);
	
	if (sum==n)
	{
		printf("\nThe number is a perfect number.");
	}
	else
	{
		printf("\nThe number is not a perfect number.");
	}
	
	return 0;
}
