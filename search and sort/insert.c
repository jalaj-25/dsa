#include <math.h>
#include <stdio.h>
void insertion(int arr[], int n) {
    for(int i = 0; i <= n - 1; i++) {
        int key = arr[i];
        int j = i -  1;
        while(j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j = j - 1;
        }  
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertion(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
