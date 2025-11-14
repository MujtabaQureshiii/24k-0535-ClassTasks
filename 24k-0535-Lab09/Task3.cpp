#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* n) {
    if (n == nullptr) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (n == nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {

    Node* root = nullptr;

    int arr[] = {10, 5, 15, 3, 7};

    for (int x : arr)
        root = insert(root, x);

    cout << "Before inserting 12 (Inorder): ";
    inorder(root);
    cout << endl;

    root = insert(root, 12);

    cout << "After inserting 12 (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "Height of AVL Tree = " << getHeight(root) << endl;

    return 0;
}
