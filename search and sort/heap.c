#include <stdio.h>
void heap(int arr[], int n, int i) {
    int max = i;
    int temp, left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if(left <n && arr[left] > arr[max]) {
        max = left;
    }
    if(right < n && arr[right] > arr[max]) {
        max = right;
    }
    if(max != i) {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heap(arr, n, max);
    }
}
void heapSort(int arr[], int n) {
    int temp;
    for(int i = n / 2; i >= 0; i--) {
        heap(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--) {
        temp = arr[0]; 
        arr[0] = arr[i]; 
        arr[i] = temp; 
        heap(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements af array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Enter %d elements in the array:\n", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Orignal array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapSort(arr, n);
    printf("After Heap sort: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}