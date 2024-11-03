//quick sort
#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x) 
        {
            i = i + 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}
void quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}
 
int main()
{
    int n, i;
    int arr[MAX_SIZE];
    printf("Enter the number of elements you want to add in arrrray: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the element for position %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Given arrrray[] is: ");
    for(i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");
    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted arrrray is in: ");
    for (i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %f seconds\n", time_taken);
    return 0;
}