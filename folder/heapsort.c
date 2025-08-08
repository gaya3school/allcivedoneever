#include <stdio.h>

void swap(int *a, int *b) { 
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	int large=i, left = 2*i+1, right=2*i+2;
	
	if (left<n && arr[left] > arr[large]) 
		large = left;
	
	if (right<n && arr[right] > arr[large]) 
		large = right;
	
	if (large!=i) {
		swap(&arr[large], &arr[i]);
		heapify(arr, n, large);
	}
}

void heapsort(int arr[], int n) {
	int i;
	for (i=n/2-1;i>=0;i--) {
		heapify(arr, n, i);
	}
	
	for (i=n-1;i>=0;i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);		
	}
}

void main() {
	int n, i;
	printf("Enter the number of elements: ");
	scanf(" %d", &n);
	
	int arr[n];
	printf("Enter the elements to be sorted: ");
	for (i=0;i<n;i++) {
		scanf(" %d", &arr[i]);
	}
	
	heapsort(arr, n);
	printf("The sorted list is: ");
	for (i=0;i<n;i++) {
		printf("%d ", arr[i]);
	}
}



/* Example Input
Let's assume the input array is:
`arr = [3, 9, 2, 6, 10]`, `n = 5` (size of the array), and `i = 0` (starting with the root).

1. Initial Values
   - Current index: `i = 0`
   - Left child index: `left = 2 * 0 + 1 = 1`
   - Right child index: `right = 2 * 0 + 2 = 2`
   - `large = i = 0`

2. Comparisons
   - Compare `arr[left]` (arr[1] = 9) with `arr[large]` (arr[0] = 3).
     - `9 > 3`, so update `large = 1`.
   - Compare `arr[right]` (arr[2] = 2) with `arr[large]` (arr[1] = 9).
     - `2 <= 9`, so `large` remains 1.

3. Swap
   - Since `large != i` (1 != 0), swap `arr[large]` (arr[1] = 9) and `arr[i]` (arr[0] = 3).
   - After swapping, `arr = [9, 3, 2, 6, 10]`.

4. Recursive Call
   - Call `heapify(arr, n, large)` with `i = 1`.
   - **Now tracing the recursive call:**
     - Current index: `i = 1`
     - Left child index: `left = 2 * 1 + 1 = 3`
     - Right child index: `right = 2 * 1 + 2 = 4`
     - `large = i = 1`.

5. Comparisons
   - Compare `arr[left]` (arr[3] = 6) with `arr[large]` (arr[1] = 3).
     - `6 > 3`, so update `large = 3`.
   - Compare `arr[right]` (arr[4] = 10) with `arr[large]` (arr[3] = 6).
     - `10 > 6`, so update `large = 4`.

6. **Swap**
   - Since `large != i` (4 != 1), swap `arr[large]` (arr[4] = 10) and `arr[i]` (arr[1] = 3).
   - After swapping, `arr = [9, 10, 2, 6, 3]`.

7. **Recursive Call**
   - Call `heapify(arr, n, large)` with `i = 4`.
   - At this point, `i = 4` has no children (`left = 9`, `right = 10`, both out of bounds), so the recursion ends.
*/