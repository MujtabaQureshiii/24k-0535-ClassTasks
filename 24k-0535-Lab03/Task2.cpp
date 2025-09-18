#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* next;

    Node(string n, int p) : name(n), price(p), next(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(nullptr) {}

    void addTail(string name, int price) {
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

    void deleteFront() {
        if (!head) {
            cout << "Cart is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->name << " $" << temp->price << endl;
        delete temp;
    }

    void searchByName(const string& name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "Item found: " << temp->name << " $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item \"" << name << "\" not found in the cart.\n";
    }

    void searchByPosition(int pos) {
        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int index = 1;
        while (temp) {
            if (index == pos) {
                cout << "Position " << pos << ": " << temp->name << " $" << temp->price << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "No item found at position " << pos << ".\n";
    }

    void displayCart() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nShopping Cart Items:\n";
        while (temp) {
            cout << "- " << temp->name << " $" << temp->price << endl;
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

    cart.addTail("Laptop", 1000);
    cart.addTail("Phone", 700);
    cart.addTail("Tablet", 400);
    cart.addTail("Headphones", 150);

    cart.displayCart();

    cart.deleteFront();
    cart.displayCart();

    cart.searchByName("Tablet");
    cart.searchByName("Keyboard");

    cart.searchByPosition(2);
    cart.searchByPosition(5);

    return 0;
}
