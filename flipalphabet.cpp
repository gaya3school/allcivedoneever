#include <stdio.h>

int main()
{
	char al;
	
	printf("Enter an alphabet: ");
	scanf("%c", &al);
	
	int aln;
	aln = int(al);
	
	if (aln>=65 && aln<97)
	{
		int lc = aln + 32;
		printf ("Lower case is %c", lc);
	}
	else if (aln>=97)
	{
		int uc = aln - 32;
		printf ("Upper case is %c", uc);
	}
	else
	{
		printf("Invalid input");
	}
	
	return 0;
}
