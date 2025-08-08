#include <stdio.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	int i = n;
	int reverse = 0;
	while (i>0)
	{
		int n1 = i%10;
		reverse = reverse * 10 + n1;
		i = i / 10;
	}
	if (reverse==n)
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not a palindrome");
	}
	
	return 0;
}
