#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter two numbers: ");
	scanf("%d %d", &n, &m);
	
	for (int i=n ; i<=m ;i++ )
	{
		int prim = 1;
		for (int j=2 ; j < i; j++ )
		{
			if (i%j==0)
			{
				prim = 0;
			} else {}
		}
		
		if (prim)
		{
			printf("\n%d", i);
		} else {}
	}
	
	
	return 0;
}

/* using break statement we dont need to use the prim variable 

(if 1 = not a prime number)
(-ve number not prime ) <-- for prime chek*/
