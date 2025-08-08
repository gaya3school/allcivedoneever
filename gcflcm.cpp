#include <stdio.h>

int main()
{
	int a, b, big, small, r;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	
	if (a>b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
	
	/* Euclidian method */
	do 
	{
		r = big % small;
		if (r!=0)
		{
			big = small;
			small = r;
		}
	}
	while (r!=0);
	
	printf("The GCF is %d", small);
	
	printf("\nThe LCM is %d", (a*b)/small);
	
	return 0;
}
