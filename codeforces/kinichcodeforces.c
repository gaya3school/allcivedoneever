#include <stdio.h>

int main()
{
	int t;
	scanf(" %d", &t);
	
	while (t--)
	{
		int n;
		scanf(" %d", &n);
		
		int A[n], i, j, score, k;
		for (i=0;i<n;i++)
		{
			scanf(" %d", &A[i]);
		}
		
		for (i=0, score =0;i<n;i++)
		{
			for (j=i+1, k=0;j<n;j++)
			{
				if (A[i]==A[j])
				{
					k++;
					//printf("%d  aj old\n", A[j]);
					A[j]=k;
					k--;
					//printf("%d  aj new\n", A[j]);
				}
			}
			score += (k * (k-1))/2;
		}
		
		printf("%d  ", score);
	}
	
	return 0;
}