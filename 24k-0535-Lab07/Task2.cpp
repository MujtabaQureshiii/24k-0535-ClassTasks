#include <iostream>
#include <string>
using namespace std;

class Marathon {
private:
    struct Participant {
        string name;
        int time;
    };

    Participant runners[10];
    int n;

    void merge(Participant arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Participant L[10], R[10];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i].time <= R[j].time)
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }

    void mergeSort(Participant arr[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    Marathon() {
        n = 10;
    }

    void getInput() {
        cout << "Enter names and finish times (in seconds):" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Runner " << i + 1 << " name: ";
            cin >> runners[i].name;
            cout << "Finish time (in seconds): ";
            cin >> runners[i].time;
        }
        cout << endl;
    }

    void sortResults() {
        mergeSort(runners, 0, n - 1);
    }

    void showTop5() {
        cout << "Top 5 Fastest Runners:" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << runners[i].name 
                 << " - " << runners[i].time << " seconds" << endl;
        }
    }
};

int main() {
    Marathon m;
    m.getInput();
    m.sortResults();
    m.showTop5();
    return 0;
}
