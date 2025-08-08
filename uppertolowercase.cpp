#include <stdio.h>

int main()
{
	char lc,uc;
	
	printf ("Enter an upper case alphabet: ");
	scanf ("%c", &uc);
	
	lc = uc + 32;
	printf ("Lower case is %c", lc);
}
