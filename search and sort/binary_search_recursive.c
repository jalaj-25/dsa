#include <stdio.h>
#include <stdlib.h> // Needed for malloc and free
#include <time.h>

int binarySearch(int arr[], int low, int high, int x);

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Entered elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &x);

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int index = binarySearch(arr, 0, n - 1, x);
    end = clock();

    // Calculate the time taken
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index == -1) {
        printf("\nElement not found.\n");
    } else {
        printf("\nElement found at index: %d\n", index);
    }

    printf("Time taken for binary search: %f seconds\n", cpu_time_used);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}

int binarySearch(int arr[], int low, int high, int x) {
    // Function to perform binary search on a sorted array
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid; // Element found, return index
        } else if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x); // Search left half
        } else {
            return binarySearch(arr, mid + 1, high, x); // Search right half
        }
    }
    return -1; // Element not found
}
