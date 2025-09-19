#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    bubbleSort(arr, n, comparisons);

    cout << "Sorted Element List:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal Comparisons: " << comparisons << endl;

    return 0;
}
