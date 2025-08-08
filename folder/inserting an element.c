#include <stdio.h>
const int n = 6;

int main()
{
	int ch, i, x, temp, tempn, tempnn;
	
	int arr[] = { 1, 4, 3, 6, 7};
	printf("The array before insertion: ");
	for (i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("Where do you want to insert the element (between 0-5): ");
	scanf(" %d", &ch);
	printf("Enter the number you want to insert: ");
	scanf(" %d", &x);
	
	if (ch==0)
	{
		for (i=0;i<n;i++)
		{
			if (i==ch)
			{
				temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = x;
			}
			else
			{
				tempn = temp;
				tempnn = arr[i+1];
				arr[i] = tempn;
			}
		}
	}
	else if (ch<n && ch>0)
	{
		for (i=ch;i<n;i++)
		{
			temp = arr[i];
			arr[i] = x;
			arr[i+1] = temp;
		}
	}
	else if (ch==n)
	{
		arr[n] = x;
	}
	
	printf("The array after insertion: ");
	for (i=0;i<6;i++)
	{
		printf("%d ", arr[i]);
	}
}