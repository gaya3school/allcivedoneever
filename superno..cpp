/*Write a C program to find whether the given 3-digit number is super or not. (sum of the digits is same as its product)*/
#include <stdio.h>

int main()
{
	int n, n1, n2, n3;
	
	printf ("Enter a three-digit number: ");
	scanf ("%d", &n);
	
	n1 = n%10;
	n = n/10;
	n2 = n%10;
	n3 = n/10;
		
	int sum = n1+n2+n3, product = n1*n2*n3;
	
	if (sum==product)
	{
		printf ("The number is super.");
	}
	else 
	{
		printf ("The number is not super.");
	}
	
	return 0;
}
