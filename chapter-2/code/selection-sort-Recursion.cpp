#include <iostream>
using namespace std;

void selectionSortRecursive(int arr[], int n, int index) {
    // Base case
    if (index == n - 1)
        return;

    int minIndex = index;

    // Find minimum element in remaining array
    for (int j = index + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    // Swap current element with minimum element
    swap(arr[index], arr[minIndex]);

    // Recursive call for the rest of the array
    selectionSortRecursive(arr, n, index + 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    selectionSortRecursive(arr, n, 0);
    printArray(arr, n);

    return 0;
}