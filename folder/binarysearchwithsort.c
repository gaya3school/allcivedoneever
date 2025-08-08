#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf(" %d", &n);
    
    int arr[n], i, j, found, left, right, mid, x, temp;
    printf("Enter array elements: \n");
    for (i=0;i<n;i++)
    {
        scanf(" %d", &arr[i]);
    }
    
    /* for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("The sorted array is: ");
    for (i=0;i<n;i++)
    {
    	printf("%d  ", arr[i]);
	}
	printf("\n"); */
    
    printf("Enter the element you want to search for: ");
    scanf(" %d", &x);
    
    left = 0;
    right = n-1;
    found=-1;
    while (left<=right)
    {
        mid = (left+(right - left))/2;
        if (arr[mid]==x)
        {
            found=mid;
            break;
        }
        else if (arr[mid] < x)
        {
            left = mid+1;
        }
        else 
        {
            right = mid-1;
        }
    }
    
    if (found != -1)
    {
        printf("Element found at %d", found);
    }
    else
    {
        printf("Element not found");  
    }
    
    return 0;
}