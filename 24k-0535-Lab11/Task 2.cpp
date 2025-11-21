#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) {
        word = w;
        next = nullptr;
    }
};

class Dictionary {
private:
    Node* table[100];

    int hashFunc(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += s[i];
        return sum % 100;
    }

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = nullptr;
    }

    void Add_Record(string w) {
        int index = hashFunc(w);
        Node* newNode = new Node(w);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void Word_Search(string w) {
        int index = hashFunc(w);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->word == w) {
                cout << w << " Found in Dictionary" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << w << " Not Found in Dictionary" << endl;
    }

    void Print_Dictionary() {
        cout << "Dictionary Contents:" << endl;
        for (int i = 0; i < 100; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];

            if (!temp) {
                cout << "NULL" << endl;
            } else {
                while (temp != nullptr) {
                    cout << temp->word << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main() {
    Dictionary D;

    D.Add_Record("apple");
    D.Add_Record("mango");
    D.Add_Record("orange");
    D.Add_Record("peach");
    D.Add_Record("banana");

    D.Print_Dictionary();

    cout << endl;
    D.Word_Search("mango");
    D.Word_Search("grapes");

    return 0;
}
