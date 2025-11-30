#include <iostream>
using namespace std;

void bidirectionalSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[start], arr[minIndex]);

        if (maxIndex == start)
            maxIndex = minIndex;

        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bidirectionalSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
