#include <stdio.h>

int sumlte(int A[][10], int n);

/*int main()
{
	int n, m;
	printf("Enter the size of the matrix: ");
	scanf(" %d %d", &n, &m);

	int A[n][m], i, j, sum;
	printf("Enter the elements: \n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf(" %d", &A[i][j]);
		}
	}

	for (i=0, sum=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (i==j)
			{
				sum += A[i][j];
			}
		}
	}

	printf("The trace (sum of diagnol elements) of the matrix is %d", sum);


	int n, k;
	printf("Enter the number of elements and the element you want to search: ");
	scanf(" %d %d", &n, &k);

	int A[n], i, found, left, right, mid;
	printf("Enter the elements: ");
	for (i=0;i<n;i++)
	{
		scanf(" %d", &A[i]);
	}

	found = 0;
	left = 0;
	right = n-1;

	for (;left<=right;)
	{
		mid = (left+right)/2;
		if (A[mid] < k)
		{
			left = mid+1;
		}
		else if (A[mid] > k)
		{
			right = mid-1;
		}
		else if (A[mid] == k)
		{
			found = 1;
		}
	}

	if (found)
	{
		printf("Element found at %d", mid);
	}
	else
	{
		printf("Element not found");
	}

	int n, m;
	printf("Enter two numbers: ");
	scanf(" %d %d", &n, &m);

	int A[n][m], i, j, sum;
	printf("Enter elements: \n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf(" %d", &A[i][j]);
		}
	}

	for (i=0,sum=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (j>=i)
			sum += A[i][j];
		}
	}

	printf("Sum of upper triangle elements: %d", sum);

	int n;
	printf("Enter number of elements: ");
	scanf(" %d", &n);

	int A[n], i, prime, j;
	for (i=0;i<n;i++)
	{
		scanf(" %d", &A[i]);
	}

	for (i=0,prime=0;i<n;i++)
	{
		for (j=2;j<A[i];j++)
		{
			if (A[i]%j==0)
			{
				break;
			}
		}

		if (j>=A[i])
		{
			prime++;
		}
	}

	printf("The number of prime numbers in the given array is %d", prime);

	/*int n;
	printf("Enter number of elements: ");
	scanf(" %d", &n);

	int A[n], i, sum;
	float avg;
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf(" %d", &A[i]);
	}

	for (i=0,sum=0;i<n;i++)
	{
		sum += A[i];
	}
	avg = (float)sum/n;
	printf("The sum of all elements of the array is %d and the average is %.3f", sum, avg);

	int n;
	printf("Enter number of elements: ");
	scanf(" %d", &n);

	int A[n], i;
	printf("Enter elements: \n");
	for(i=0;i<n;i++)
	{
		scanf(" %d", &A[i]);
	}

	printf("Array in regular order: ");
	for(i=0;i<n;i++)
	{
		printf("%d ", A[i]);
	}
	printf("Array in reverse order: ");
	for (i=n-1;i>=0;i--)
	{
		printf("%d ", A[i]);
	}

	int n;
	printf("Enter the number of students: ");
	scanf(" %d", &n);

	float M[n], max, smax, tmax;
	int i;
	printf("Enter the marks of the students: \n");
	for(i=0;i<n;i++)
	{
		scanf(" %f", &M[i]);
	}

	max = M[0];
	smax = -1;
	tmax = -2;
	for (i=1;i<n;i++)
	{
		if (M[i]>max)
		{
			tmax = smax;
			smax = max;
			max = M[i];
		}
		else if (M[i]>smax)
		{
			tmax = smax;
			smax = M[i];
		}
		else if (M[i]>tmax)
		{
			tmax = M[i];
		}
	}

	printf("The highest marks are %.2f \nThe second highest marks are %.2f \nThe third highest marks are %.2f", max, smax, tmax);

	int n;
	printf("Enter the number of values: ");
	scanf(" %d", &n);

	float A[n], max, min;
	int i;
	printf("Enter the values: \n");
	for (i=0;i<n;i++)
	{
		scanf(" %f", &A[i]);
	}

	max = A[0];
	min = A[0];
	for (i=1;i<n;i++)
	{
		if (A[i]>=max)
		{
			max = A[i];
		}
		else if (A[i]<=min)
		{
			min = A[i];
		}
	}

	printf("The difference between maximum and minumum element is %f \n%f %f", max-min, max, min);

	int n;
	printf("Enter the number of vegetables: ");
	scanf(" %d", &n);

	int V[n], i, max, index1, min, index2, smax, smin, index3, index4;
	printf("Enter vegetable prices: \n");
	for(i=0;i<n;i++)
	{
		scanf(" %d", &V[i]);
	}

	max = V[0];
	index1=0;
	smax = -1;
	for(i=1;i<n;i++)
	{
		if (V[i] >= max)
		{
			smax = max;
			index3 = index1;
			max = V[i];
			index1 = i;
		}
		else if (V[i]>smax)
		{
			smax = V[i];
			index3 = i;
		}
	}

	min = V[0];
	index2 = 0;
	for(i=1;i<n;i++)
	{
		if (V[i] <= min)
		{
			smin = min;
			index4 = index2;
			min = V[i];
			index2 = i;
		}
		else if (V[i]<smin)
		{
			smin = V[i];
			index4 = i;
		}
	}

	printf("The maximum price is %d and its index is %d \nThe second maximum price is %d and its index is %d\n", max, index1, smax, index3);
	printf("The minimum price is %d and its index is %d \nThe second minimum price is %d and its index is %d", min, index2, smin, index4); */

int sumlte(int A[][10], int n)
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j <= i)
			{
				sum += A[i][j];
			}
		}
	}

	return sum;
}

int main() {
	int n;
	scanf("%d", &n);

	int a[n][n], i, j, sum;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		sum = sumlte(a, n);
		printf("The sum of lower triangle elements is %d", sum);
		return 0;
}