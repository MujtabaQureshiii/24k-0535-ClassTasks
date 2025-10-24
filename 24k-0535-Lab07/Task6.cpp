#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

class Company {
private:
    Employee employees[12];
    int n = 12;

    void merge(Employee arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Employee L[12], R[12];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].salary >= R[j].salary)
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(Employee arr[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    void inputData() {
        employees[0] = {"raza", 10, 84000};
        employees[1] = {"kinza", 323, 80000};
        employees[2] = {"sana", 191, 63000};
        employees[3] = {"ali", 345, 54000};
        employees[4] = {"zahid", 477, 49000};
        employees[5] = {"zohaib", 156, 47000};
        employees[6] = {"yasir", 122, 39000};
        employees[7] = {"moiz", 121, 32000};
        employees[8] = {"saba", 990, 28000};
        employees[9] = {"laila", 240, 24000};
        employees[10] = {"saba", 123, 12000};
        employees[11] = {"ali", 321, 56000};
    }

    void sortBySalary() {
        mergeSort(employees, 0, n - 1);
    }

    void displayAll() {
        cout << "Employees Sorted by Salary (Descending):\n";
        cout << "Name\t\tID\tSalary\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << employees[i].name << "\t\t"
                 << employees[i].id << "\t"
                 << employees[i].salary << endl;
        }
        cout << endl;
    }

    void displayTop3() {
        cout << "Top 3 Highest Paid Employees:\n";
        cout << "Rank\tName\t\tID\tSalary\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "\t" << employees[i].name << "\t\t"
                 << employees[i].id << "\t"
                 << employees[i].salary << endl;
        }
    }
};

int main() {
    Company c;
    c.inputData();
    c.sortBySalary();
    c.displayAll();
    c.displayTop3();
    return 0;
}
