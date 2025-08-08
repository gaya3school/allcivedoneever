#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter two numbers: ");
	scanf("%d %d", &n, &m);
	
	if ((n<=15) && (m<=15))
	{
		int j = 1;
		int fact = 1;
		while (j<=n)
		{
			fact = fact * j;
			j++;
		}
		printf("%d", fact);
		int i = (n+1); 
		int res = fact;
		while (i<=m)
		{
			res = res * i;
			i++;
			printf("\n%d", res);
		}
		printf("\n\n%d", res);
	}	
}
