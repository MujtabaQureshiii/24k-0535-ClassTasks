#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string d) {
        data = d;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, string value) {
        if (node == nullptr)
            return new Node(value);

        char choice;
        cout << "Where do you want to add \"" << value
             << "\" under \"" << node->data << "\"? (L for left / R for right): ";
        cin >> choice;
        cin.ignore();

        if (choice == 'L' || choice == 'l')
            node->left = insert(node->left, value);
        else if (choice == 'R' || choice == 'r')
            node->right = insert(node->right, value);
        else
            cout << "Invalid choice! Try again.\n";

        return node;
    }

    int countNodes(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeafNodes(Node* node) {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    int treeHeight(Node* node) {
        if (node == nullptr)
            return 0;
        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void display(Node* node, int level = 0) {
        if (node == nullptr)
            return;
        display(node->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << "|-- " << node->data << endl;
        display(node->left, level + 1);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void createRoot(string value) {
        if (root == nullptr)
            root = new Node(value);
        else
            cout << "Root already exists!\n";
    }

    void addNode(string value) {
        if (root == nullptr) {
            cout << "Please create the root node first.\n";
            return;
        }
        root = insert(root, value);
    }

    void showTree() {
        cout << "\n==== TREE STRUCTURE ====\n\n";
        if (root == nullptr)
            cout << "Tree is empty.\n";
        else
            display(root);
    }

    void showProperties() {
        if (root == nullptr) {
            cout << "\nTree is empty.\n";
            return;
        }
        cout << "\n==== TREE PROPERTIES ====\n\n";
        cout << "Total Nodes: " << countNodes(root) << endl;
        cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
        cout << "Height of Tree: " << treeHeight(root) << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice;
    string value;

    do {
        cout << "\n--- BINARY TREE ANALYSIS ---\n";
        cout << "1. Create Root Node\n";
        cout << "2. Add Child Node\n";
        cout << "3. Display Tree Structure\n";
        cout << "4. Show Tree Properties\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter root node value: ";
                getline(cin, value);
                tree.createRoot(value);
                break;

            case 2:
                cout << "Enter node value to add: ";
                getline(cin, value);
                tree.addNode(value);
                break;

            case 3:
                tree.showTree();
                break;

            case 4:
                tree.showProperties();
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
