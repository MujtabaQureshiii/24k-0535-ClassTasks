#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* next;

    Node(string n, int p) {
        name = n;
        price = p;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(nullptr) {}

    void addFront(string name, int price) {
        Node* newNode = new Node(name, price);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(string name, int price) {
        Node* newNode = new Node(name, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(string target, string name, int price) {
        Node* temp = head;
        while (temp) {
            if (temp->name == target) {
                Node* newNode = new Node(name, price);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Item \"" << target << "\" not found in the cart.\n";
    }

    void searchItem(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << name << " found! Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in the cart.\n";
    }

    void displayCart() {
        Node* temp = head;
        cout << "\nShopping Cart Items:\n";
        while (temp) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    ~ShoppingCart() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ShoppingCart cart;

    cart.addEnd("Laptop", 1000);
    cart.addEnd("Phone", 700);
    cart.addEnd("Tablet", 400);
    cart.addEnd("Headphones", 150);

    cart.addFront("Smartwatch", 200);
    cart.addEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);

    cart.searchItem("Tablet");
    cart.displayCart();

    return 0;
}
