//binary search
#include <stdio.h>

int binarysearch(int n, int arr[], int left, int right, int target);

int main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf(" %d", &n);
	
	int arr[n], i, target, left, right;
	printf("Enter the elements: ");
	for (i=0;i<n;i++)
	{
		scanf(" %d", &arr[i]);
	}
	
	printf("Enter element to search for: ");
	scanf(" %d", &target);
	
	if (binarysearch(n, arr, 0, n-1, target))
	{
		printf("The element was found at %d", binarysearch(n, arr, 0, n-1, target));
	}
	else
	{
		printf("The element is not found. ");
	}
}

int binarysearch(int n, int arr[], int left, int right, int target)
{
	int mid;
	if (left>right)
	{
		return 0;
	}
	else
	{
		mid = left + (right-left)/2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{
			return binarysearch (n, arr, left, mid-1, target);
		}
		else
		{
			return binarysearch (n, arr, mid+1, right, target);
		}
	}
}