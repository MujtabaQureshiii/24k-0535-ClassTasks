#include <iostream>
using namespace std;

struct Node {
    int empID;
    Node* left;
    Node* right;

    Node(int id) {
        empID = id;
        left = right = nullptr;
    }
};

class EmployeeTree {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->empID)
            node->left = insert(node->left, id);
        else if (id > node->empID)
            node->right = insert(node->right, id);

        return node;
    }

    Node* findLCA(Node* node, int id1, int id2) {
        if (node == nullptr)
            return nullptr;

        if (id1 < node->empID && id2 < node->empID)
            return findLCA(node->left, id1, id2);

        if (id1 > node->empID && id2 > node->empID)
            return findLCA(node->right, id1, id2);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->empID << " ";
        inorder(node->right);
    }

public:
    EmployeeTree() {
        root = nullptr;
    }

    void addEmployee(int id) {
        root = insert(root, id);
    }

    void displayTree() {
        if (root == nullptr)
            cout << "No employees in the system.\n";
        else {
            cout << "\nEmployee IDs (Inorder Traversal): ";
            inorder(root);
            cout << endl;
        }
    }

    void findCommonManager(int id1, int id2) {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        Node* lca = findLCA(root, id1, id2);
        if (lca != nullptr)
            cout << "Lowest Common Manager for " << id1 << " and " << id2
                 << " is: " << lca->empID << endl;
        else
            cout << "One or both employee IDs not found.\n";
    }
};

int main() {
    EmployeeTree tree;
    int choice, id, id1, id2;

    do {
        cout << "\n--- EMPLOYEE HIERARCHY SYSTEM ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Find Lowest Common Manager\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                tree.addEmployee(id);
                break;

            case 2:
                tree.displayTree();
                break;

            case 3:
                cout << "Enter two Employee IDs: ";
                cin >> id1 >> id2;
                tree.findCommonManager(id1, id2);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
