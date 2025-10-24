#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[50];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void displayRanks(int arr[], int n) {
    cout << "\nStudent\tScore\tRank\n";
    cout << "----------------------\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << "\t" << arr[i] << "\t" << i + 1 << endl;
}

int main() {
    int scores[50] = {
        82, 59, 47, 91, 16, 78, 62, 89, 94, 21,
        53, 37, 25, 69, 73, 41, 85, 66, 58, 92,
        18, 14, 33, 64, 88, 27, 45, 57, 79, 97,
        99, 39, 31, 29, 50, 61, 71, 81, 90, 100,
        8, 12, 23, 35, 44, 56, 63, 75, 83, 96
    };

    int n = 50;

    cout << "Original Scores:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << endl;

    radixSort(scores, n);

    cout << "\nSorted Scores (Ascending Order):\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << endl;

    displayRanks(scores, n);
    return 0;
}
