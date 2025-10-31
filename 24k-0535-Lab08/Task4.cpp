#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insertLevelOrder(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < n) {
        Node* temp = q.front();
        q.pop();
        if (i < n) {
            temp->left = new Node(arr[i++]);
            q.push(temp->left);
        }
        if (i < n) {
            temp->right = new Node(arr[i++]);
            q.push(temp->right);
        }
    }
    return root;
}

int findSubtreeSum(Node* root, int target, bool &found) {
    if (root == nullptr) return 0;
    int left = findSubtreeSum(root->left, target, found);
    int right = findSubtreeSum(root->right, target, found);
    int total = left + right + root->data;
    if (total == target) found = true;
    return total;
}

void printTree(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of sections in warehouse: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter number of items in each section: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = insertLevelOrder(arr, n);

    cout << "\nWarehouse Inventory Tree (Level Order):" << endl;
    printTree(root);

    int target;
    cout << "\nEnter target sum to check: ";
    cin >> target;

    bool found = false;
    findSubtreeSum(root, target, found);

    if (found)
        cout << "\nA subtree with total quantity " << target << " exists in the inventory.\n";
    else
        cout << "\nNo subtree with total quantity " << target << " found.\n";

    delete[] arr;
    return 0;
}
