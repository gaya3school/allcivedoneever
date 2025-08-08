#include <stdio.h>

int main()
{
	int r = 0, n;
	do
	{
		printf("Enter runs: ");
		scanf("%d", &n);
		
		r = r + n;
	}
	while (n>0); /* or while (n!=-1) */
	
	printf("Total runs scored is %d", r+1);
	
	return 0;
}
