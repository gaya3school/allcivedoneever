#include <stdio.h>

int main()
{
	/*do remainder and division separately */
	char type;
	int ic, c, c1, c2, tc, nb;
	
	printf ("Super: S, Premium: P, Regular: R");
	printf ("\nEnter type of plan: ");
	scanf (" %c", &type);
	printf ("Enter number of GBs consumed: ");
	scanf ("%d", &ic);
	printf ("Enter number of calls made: ");
	scanf ("%d", &c);
	
	
	if (type=='S')
	{
		ic = ic * 10;
		printf ("\nAmount charged for internet is Rs.%d", ic);
 		c1 = c%50;
		if (c1==0)
		{
			c2 = c/50;
			tc = c2 * 75;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}
		else
		{
			c2 = (c/50) + 1;
			tc = c2 * 75;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}		
		nb = (ic + tc)*0.5 + 800;
		printf ("\nThe final bill is Rs.%d", nb);
	}
	else if (type=='P')
	{
		ic = ic * 15;
		printf ("\nAmount charged for internet is Rs.%d", ic);
 		c1 = c%50;
		if (c1==0)
		{
			c2 = c/50 + 1;
			tc = c2 * 100;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}
		else
		{
			c2 = (c/50);
			tc = c2 * 100;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}		
		nb = (ic + tc)*0.3 + 400;
		printf ("\nThe final bill is Rs.%d", nb);
	}
	else if (type=='R')
	{
		ic = ic * 25;
		printf ("\nAmount charged for internet is Rs.%d", ic);
 		c1 = c%50;
		if (c1==0)
		{
			c2 = c/50 + 1;
			tc = c2 * 200;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}
		else
		{
			c2 = (c/50);
			tc = c2 * 200;
			printf ("\nAmount charged for telephone is Rs.%d", tc);
		}		
		nb = (ic + tc)*0.2;
		printf ("\nThe final bill is Rs.%d", nb);
	}
	else 
	{
		printf ("Invalid type.");
	}
	return 0;
}
