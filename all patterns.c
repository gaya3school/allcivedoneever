#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, k, h;
	char c;
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for (i=1;i<=n;i++) {
		for (j=1;j<=n-i;j++) {
			printf("   ");
		}
		for (j=n-i+1, k=i;j<=n;j++) {
			printf("%3d", k++);
		}
		for (j=n+1,k=2*i-2;j<n+i;j++) {
			printf("%3d", k--);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=0;i<n;i++)
	{
		for(j=1,k=1;j<=n;j++,k++)
		{
			if (j>=n-i)
			{
				printf("%2d", k);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	
	for(i=1;i<=n;i++)
	{
		for(j=0, c = 64+n;j<n;j++, c--)
		{
			if (j<=n-i)
			{
				printf("%c ", c);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=n;i>0;i--)
	{
		for(j=1, c='A';j<=n;j++,c++)
		{
			if (j>n-i)
			{
				printf("%c ", c);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=1;i<=n;i++)
	{
		for(j=1,c='A';j<=n-i+1;j++,c++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=n;i>0;i--)
	{
		for(j=1,c='A';j<=n-i+1;j++,c++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=n;i>0;i--)
	{
		for(j=1,k=n;j<=n;j++,k--)
		{
			if (j>n-i)
			{
				printf("%2d ", k);
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=1,k=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j>n-i)
			{
				printf("%2d ", k);
				k++;
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if (j>n-i)
			{
				printf("%d ", i);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=n;i>0;i--)
	{
		for(j=1,k=1;j<=n;j++,k++)
		{
			if (j>n-i)
			{
				printf("%d ", k);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (j>(n-i))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for(i=1;i<=n;i++)
	{
		for(j=1,k=1;j<=n;j++)
		{
			if (j>n-i)
			{
				printf("%d ", k);
				k++;
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
		
	printf("Enter a number: ");
	scanf(" %d", &n); 
	for (i=1,h=1;i<=n;i++)
	{
		k = h;
		if (i%2!=0)
		{
			for (j=0;j<n;j++,k++)
			{
				printf("%2d  ", k);
			}
			h += (2*n) - 1;
		}
		else
		{	
			for (j=0;j<n;j++,k--)
			{
				printf("%2d  ", k);
			}
			h += 1;
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=1,h=1;i<=n;i++,h+=2)
	{
		for(j=0,k=i;j<n;j++)
		{
			if (j%2!=0)
			{
				printf("%d  ", k);
				k += h;
			}
			else
			{
				printf("%d  ", k);
				k += (2*n)-h;
			}
		}
		printf("\n");
	} 
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=1;i<=n;i++)
	{
		for (k=i,j=0;j<n;j++,k+=n)
		{
			printf("%d  ", k);
		}
		printf("\n");
	}
		
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=n;i>0;i--)
	{
		for (j=0;j<n;j++)
		{
			printf("%d  ", i);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for(i=0,k=1;i<n;i++)
	{
		for(j=0;j<n-i;j++,k++)
		{
			printf("%d  ", k);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=0,k=n*n;i<n;i++)
	{
		for(j=0;j<n;j++,k--)
		{
			printf("%3d", k);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=1;i<=n;i++)
	{
		for (j=1,k=i;j<=n;j++,k=pow(i,j))
		{
			//printf("%d %d %djugtgt", k, j, pow(k,j));
			printf("%3d  ", k);
		}
		printf("\n");
	}
	
	printf("Enter number of rows and columns: ");
	scanf(" %d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	printf("Enter number of rows: ");
	scanf(" %d", &n);
	for (i=1;i<=n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%2d", i);
		}
		printf("\n");
	}
	
	printf("Enter number of rows: ");
	scanf(" %d", &n);
	for (i=0;i<n;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("%2d", j);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for (i=n;i>=1;i--)
	{
		for (j=i;j>=1;j--)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for(i=0,k=1;i<n;i++)
	{
		for (j=0;j<n;j++,k++)
		{
			printf("%3d", k);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for(i=1;i<=n;i++)
	{
		for (j=0,k=i;j<n;j++,k+=n)
		{
			printf("%3d", k);
		}
		printf("\n");
	}
	
	printf("Enter a number: ");
	scanf(" %d", &n);
	for(i=1,k=1;i<=n;i++)
	{
		for(j=0;j<i;j++,k++)
		{
			printf("%3d", k);
		}
		printf("\n");
	}
	
	return 0;
}
