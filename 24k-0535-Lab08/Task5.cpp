#include <iostream>
using namespace std;

struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;
    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int id, int qty) {
    if (root == nullptr)
        return new Node(id, qty);

    if (id < root->productID)
        root->left = insert(root->left, id, qty);
    else if (id > root->productID)
        root->right = insert(root->right, id, qty);
    else
        root->quantity += qty;

    return root;
}

Node* search(Node* root, int id) {
    if (root == nullptr || root->productID == id)
        return root;
    if (id < root->productID)
        return search(root->left, id);
    else
        return search(root->right, id);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << "Product ID: " << root->productID 
         << " | Quantity: " << root->quantity << endl;
    inorder(root->right);
}

void findMaxQuantity(Node* root, int &maxQty, int &maxID) {
    if (root == nullptr) return;
    if (root->quantity > maxQty) {
        maxQty = root->quantity;
        maxID = root->productID;
    }
    findMaxQuantity(root->left, maxQty, maxID);
    findMaxQuantity(root->right, maxQty, maxID);
}

int main() {
    Node* root = nullptr;
    int choice, id, qty;

    while (true) {
        cout << "\n--- Product Inventory Menu ---\n";
        cout << "1. Add or Update Product\n";
        cout << "2. Search Product\n";
        cout << "3. Display All Products\n";
        cout << "4. Show Product with Highest Quantity\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Product ID and Quantity: ";
            cin >> id >> qty;
            root = insert(root, id, qty);
        }
        else if (choice == 2) {
            cout << "Enter Product ID to Search: ";
            cin >> id;
            Node* result = search(root, id);
            if (result != nullptr)
                cout << "Product Found | ID: " << result->productID 
                     << " | Quantity: " << result->quantity << endl;
            else
                cout << "Product not found.\n";
        }
        else if (choice == 3) {
            if (root == nullptr)
                cout << "No products available.\n";
            else {
                cout << "\nProduct List:\n";
                inorder(root);
            }
        }
        else if (choice == 4) {
            int maxQty = -1, maxID = -1;
            findMaxQuantity(root, maxQty, maxID);
            if (maxID != -1)
                cout << "Product with Highest Quantity -> ID: " 
                     << maxID << ", Quantity: " << maxQty << endl;
            else
                cout << "No products in inventory.\n";
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
