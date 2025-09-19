#include <iostream>
using namespace std;

unsigned int seed = 123456789;

unsigned int simpleRand() {
    seed = (1103515245 * seed + 12345) % 2147483648;
    return seed;
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) arr[i] = (simpleRand() % 100) + 1;
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) dest[i] = source[i];
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) arr[j + 1] = arr[j--];
            else break;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) arr[j] = arr[j - gap], j -= gap;
                else break;
            }
            arr[j] = temp;
        }
    }
}

int main() {
    const int sizes[] = {20, 100};

    for (int s = 0; s < 2; s++) {
        int size = sizes[s];
        int original[size];
        generateRandomArray(original, size);

        cout << "Original Array (" << size << " elements):\n";
        displayArray(original, size);
        cout << "\n";

        int arr[size], comparisons;

        copyArray(original, arr, size);
        bubbleSort(arr, size, comparisons);
        cout << "Bubble Sort (" << comparisons << " comparisons):\n";
        displayArray(arr, size);
        cout << "\n";

        copyArray(original, arr, size);
        insertionSort(arr, size, comparisons);
        cout << "Insertion Sort (" << comparisons << " comparisons):\n";
        displayArray(arr, size);
        cout << "\n";

        copyArray(original, arr, size);
        selectionSort(arr, size, comparisons);
        cout << "Selection Sort (" << comparisons << " comparisons):\n";
        displayArray(arr, size);
        cout << "\n";

        copyArray(original, arr, size);
        shellSort(arr, size, comparisons);
        cout << "Shell Sort (" << comparisons << " comparisons):\n";
        displayArray(arr, size);
        cout << "\n";

        cout << "----------------------------\n\n";
    }

    return 0;
}
