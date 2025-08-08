#include <stdio.h>

int max (int a1, int b1)
{
	if (a1>b1)
	{
		return a1;
	}
	else
	{
		return b1;
	}
	
}

int main()
{
	int a, b, big;
	scanf(" %d %d", &a, &b);
	
	big = max(a,b);
	printf("The greater number is %d", big);
}
