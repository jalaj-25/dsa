#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
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
    int n, arr[n];
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
