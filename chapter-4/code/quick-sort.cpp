#include <iostream>
using namespace std;

int partition(int arr[], int iBegin, int jEnd) {
    int i = iBegin;
    int j = jEnd;
    int pivLoc = i;

    while (true) {
        while (arr[pivLoc] <= arr[j] && pivLoc != j)
            j--;

        if (pivLoc == j) break;
        else if (arr[pivLoc] > arr[j]) {
            swap(arr[j], arr[pivLoc]);
            pivLoc = j;
        }

        while (arr[pivLoc] >= arr[i] && pivLoc != i)
            i++;

        if (pivLoc == i) break;
        else if (arr[pivLoc] < arr[i]) {
            swap(arr[i], arr[pivLoc]);
            pivLoc = i;
        }
    }
    return pivLoc;
}

void quickSort(int arr[], int iBegin, int jEnd) {
    if (iBegin >= jEnd) return;

    int pivLoc = partition(arr, iBegin, jEnd);

    quickSort(arr, iBegin, pivLoc - 1);  // sort left of pivot
    quickSort(arr, pivLoc + 1, jEnd);    // sort right of pivot
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}