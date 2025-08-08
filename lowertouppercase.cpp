#include <stdio.h>

int main()
{
	char lc,uc;
	
	printf ("Enter a lower case alphabet: ");
	scanf ("%c", &lc);
	
	uc = lc -32;
	printf ("Upper case is %c", uc);
}
