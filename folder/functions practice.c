#include <stdio.h>

void palindrome (int n)
{
	int i, rev, i1;
	for (i=n, rev=0;i>0;)
	{
		i1 = i%10;
		//printf("%d\n", i1);
		rev = (rev)*10 + i1;
		i=i/10;
		/* printf("%d\n", i);
		printf("%d\n", rev); */
	}
	
	if (rev == n)
	{
		printf("Is a palindrome\n");
	}
	else
	{
		printf("is not a palindrome\n");
	}
}

int main()
{
	int n, m;
	printf("Enter a number: ");
	scanf(" %d", &n);
	
	palindrome(n);
	
	
	
	printf("Enter another number: ");
	scanf(" %d", &m);
	
	palindrome (m);
	
	return 0;
}