#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int price;
    string description;
    string availability;
};

class ProductList {
private:
    Product products[3];
    int n = 3;

    int partition(Product arr[], int low, int high) {
        int pivot = arr[high].price;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j].price < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(Product arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

public:
    void getInput() {
        cout << "Enter details of 3 products:\n\n";
        for (int i = 0; i < n; i++) {
            cout << "Product " << i + 1 << " name: ";
            getline(cin >> ws, products[i].name);
            cout << "Price: ";
            cin >> products[i].price;
            cout << "Description: ";
            getline(cin >> ws, products[i].description);
            cout << "Availability (In stock / Out of stock): ";
            getline(cin >> ws, products[i].availability);
            cout << endl;
        }
    }

    void sortByPrice() {
        quickSort(products, 0, n - 1);
    }

    void display() {
        cout << "Sorted Product List (by Price - Ascending):\n";
        cout << "---------------------------------------------------------------\n";
        cout << "Name\t\tPrice\tAvailability\tDescription\n";
        cout << "---------------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {
            cout << products[i].name << "\t\t"
                 << products[i].price << "\t"
                 << products[i].availability << "\t\t"
                 << products[i].description << endl;
        }

        cout << "---------------------------------------------------------------\n";
    }
};

int main() {
    ProductList pl;
    pl.getInput();
    pl.sortByPrice();
    pl.display();
    return 0;
}
