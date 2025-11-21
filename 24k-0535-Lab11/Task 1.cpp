#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[10];

    int hashFunc(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s[i];
        }
        return sum % 10;
    }

public:
    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = nullptr;
    }

    void insertString(string s) {
        int index = hashFunc(s);
        Node* newNode = new Node(s);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    bool searchString(string s) {
        int index = hashFunc(s);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->data == s)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void displayTable() {
        cout << "Hash Table:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            if (!temp) {
                cout << "NULL\n";
            } else {
                while (temp != nullptr) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main() {
    HashTable h;

    h.insertString("apple");
    h.insertString("mango");
    h.insertString("apple");
    h.insertString("grapes");
    h.insertString("peach");
    h.insertString("banana");

    h.displayTable();

    cout << "\nSearching 'apple': ";
    if (h.searchString("apple")) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Searching 'orange': ";
    if (h.searchString("orange")) cout << "Found\n";
    else cout << "Not Found\n";

    return 0;
}
