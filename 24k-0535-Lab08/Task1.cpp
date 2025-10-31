#include <iostream>
#include <string>
using namespace std;

struct TourPackage {
    string name;
    TourPackage* left;
    TourPackage* right;

    TourPackage(string n) {
        name = n;
        left = right = nullptr;
    }
};

class TourTree {
private:
    TourPackage* root;

    TourPackage* insert(TourPackage* node, string packageName) {
        if (node == nullptr)
            return new TourPackage(packageName);

        char choice;
        cout << "Where do you want to add \"" << packageName
             << "\" under \"" << node->name << "\"? (L for left / R for right): ";
        cin >> choice;
        cin.ignore();  

        if (choice == 'L' || choice == 'l')
            node->left = insert(node->left, packageName);
        else if (choice == 'R' || choice == 'r')
            node->right = insert(node->right, packageName);
        else
            cout << "Invalid choice! Try again.\n";

        return node;
    }

    void display(TourPackage* node, int level = 0) {
        if (node == nullptr)
            return;

        display(node->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << "|-- " << node->name << endl;

        display(node->left, level + 1);
    }

public:
    TourTree() {
        root = nullptr;
    }

    void createRoot(string packageName) {
        if (root == nullptr)
            root = new TourPackage(packageName);
        else
            cout << "Root already exists!\n";
    }

    void addPackage(string packageName) {
        if (root == nullptr) {
            cout << "Please create the root package first.\n";
            return;
        }
        root = insert(root, packageName);
    }

    void showTree() {
        cout << "\n==== TOUR PACKAGE TREE ====\n\n";
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else
            display(root);
    }
};

int main() {
    TourTree tree;
    int choice;
    string packageName;

    do {
        cout << "\n--- TOUR PACKAGE MANAGEMENT ---\n";
        cout << "1. Create Root Package\n";
        cout << "2. Add Sub Package\n";
        cout << "3. Display Package Hierarchy\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter root package name: ";
                getline(cin, packageName);
                tree.createRoot(packageName);
                break;

            case 2:
                cout << "Enter package name to add: ";
                getline(cin, packageName);
                tree.addPackage(packageName);
                break;

            case 3:
                tree.showTree();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
