#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* next;
    Node* prev;

    Node(int i, string n, int p) : id(i), name(n), price(p), next(nullptr), prev(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;
    Node* tail;

public:
    ShoppingCart() : head(nullptr), tail(nullptr) {}

    void insertEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (!head) {
            cout << "Cart is empty!\n";
            return;
        }
        Node* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "First item removed.\n";
    }

    void removeEnd() {
        if (!tail) {
            cout << "Cart is empty!\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        cout << "Last item removed.\n";
    }

    void searchItem(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Item Found: ID=" << temp->id 
                     << ", Name=" << temp->name 
                     << ", Price=$" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                cout << "Price updated for item " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void displayForward() {
        cout << "\nCart Items (Front to End):\n";
        Node* temp = head;
        while (temp) {
            cout << "ID=" << temp->id << ", " << temp->name 
                 << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        cout << "\nCart Items (End to Front):\n";
        Node* temp = tail;
        while (temp) {
            cout << "ID=" << temp->id << ", " << temp->name 
                 << " - $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    int countItems() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void mostExpensiveItem() {
        if (!head) {
            cout << "Cart is empty!\n";
            return;
        }
        Node* temp = head;
        Node* maxItem = head;
        while (temp) {
            if (temp->price > maxItem->price) maxItem = temp;
            temp = temp->next;
        }
        cout << "\nMost Expensive Item: ID=" << maxItem->id 
             << ", Name=" << maxItem->name 
             << ", Price=$" << maxItem->price << endl;
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

    cart.insertEnd(101, "Laptop", 1000);
    cart.insertEnd(102, "Phone", 700);
    cart.insertEnd(103, "Tablet", 400);
    cart.insertFront(100, "Smartwatch", 200);

    cart.displayForward();
    cart.displayBackward();

    cart.removeFront();
    cart.removeEnd();

    cart.displayForward();

    cart.searchItem(102);
    cart.searchItem(105);

    cart.updatePrice(103, 450);
    cart.displayForward();

    cout << "\nTotal items in cart: " << cart.countItems() << endl;
    cart.mostExpensiveItem();

    return 0;
}
