//binary search iteratrive
//08-08-2024
#include <stdio.h>
// function for binary search in the array
int binarySearch(int n, int array[], int choice) {
    int mid, high = n - 1, low = 0;
    while(low <= high) {
        mid = (low + high) / 2; //middle element
        if(choice == array[mid]) { //check the condition
            return mid;
        }
        else if(choice > array[mid]) {
            low = mid + 1;  //if choice is greater than mid element then search in right half

        }
        else if(choice < array[mid]) {
            high = mid - 1;  //if choice is smaller than mid element then search in right half
        }
    }
    return -1;
}
//main function
int main() {
    int n, choice; 
    printf("Binary search iterative \nEnter the size of array: ");//size of the array
    scanf("%d", &n);
    int array[n];
    printf("Enter the sorted array: ");//enter number of elements of array
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("\nEntered array is: "); //enter elements of array
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nEnter the number that has to be searched: "); //element to search
    scanf("%d", &choice);
    int index = binarySearch(n, array, choice);
    if(index == -1) {
        printf("\nElement not found.\n"); //if element not found
    }
    else {
        printf("\nElement found at: %d place.\n", index+1); //iof element is not found
    }
    return 0;
}