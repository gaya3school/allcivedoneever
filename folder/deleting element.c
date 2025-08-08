#include <stdio.h>
const int n = 6;
int main()
{
	int ch, i;
		
	int arr[] = { 1, 4, 3, 6, 7, 9};
	printf("The array before insertion: ");
	for (i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\nEnter the index of the element you want to delete (between 0 and 5): ");
	scanf(" %d", &ch);
	
	if (ch==0)
	{
		for (i=0;i<n;i++)
		{
			arr[i] = arr[i+1];
		}
		printf("The element of the array at the index you chose is now %d", arr[ch]);
		/* printf("The array after deletion: ");
		for (i=1;i<6;i++)
		{
			printf("%d ", arr[i]);
		} */
	}
	else if (ch==5)
	{
		for (i=0;i<n;i++)
		{
			if (i==ch)
			{
				arr[i] = -1;
			}
		}
		printf("The element of the array at the index you chose is now %d", arr[ch]);
		/* printf("The array after deletion: ");
		for (i=0;i<5;i++)
		{
			printf("%d ", arr[i]);
		} */
	}
	else
	{
		for (i=ch;i<n;i++)
		{
			arr[i] = arr[i+1];
			if (i==n-1)
			{
				arr[i] = -1;
			}
		}
		/* printf("The array after deletion: ");
		for (i=0;i<5;i++)
		{
			printf("%d ", arr[i]);
		} */
	}
	
	printf("\nThe array after deletion: ");
	for (i=0;i<6;i++)
	{
		printf("%d ", arr[i]);
	}
	
	
}