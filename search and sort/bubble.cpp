#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j]; 
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

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++) {
        cout << "Enter the element at position " << i + 1 << ": ";
        cin >> arr[i];
    }

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTime taken: " << cpu_time_used << " seconds\n";

    return 0;
}
