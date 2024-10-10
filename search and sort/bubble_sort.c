//Jalaj Singhal
//bubble sort
#include<stdio.h>
#include<time.h>
//function for sorting
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) { //traverse first loop
        for(int j = 0; j < n; j++) { //traverse second loop
            if(arr[j] > arr[j + 1]) { //first number greater then second
                int temp = arr[j]; //temp variable
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    double cpu_time_used;
    clock_t start, end;
    printf("Enter the size of array: ");
    scanf("%d", &n); //size of array input
    int arr[n];
    printf("Enter the elements of array: \n");
    for(int i = 0; i < n; i++) {
        printf("Enter the element at %d position: ", i + 1);
        scanf("%d", &arr[i]); //array input
    }
    start = clock();  // Start time
    bubbleSort(arr, n);  //function call
    end = clock();  // End time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  // Calculate time in seconds

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]); //sorted array input array output
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);
}