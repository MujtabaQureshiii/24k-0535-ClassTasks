#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    Node* getTail(Node* start) {
        while (start != nullptr && start->next != nullptr)
            start = start->next;
        return start;
    }

    Node* partition(Node* start, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr;
        Node* cur = start;
        Node* tail = pivot;
        Node* pHead = nullptr;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (!pHead)
                    pHead = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* tmp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!pHead)
            pHead = pivot;

        *newHead = pHead;
        *newEnd = tail;

        return pivot;
    }

    Node* quickSortRecur(Node* start, Node* end) {
        if (!start || start == end)
            return start;

        Node *newHead = nullptr, *newEnd = nullptr;
        Node* pivot = partition(start, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quickSortRecur(newHead, temp);
            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);
        return newHead;
    }

public:
    LinkedList() { head = nullptr; }

    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void quickSort() {
        Node* tail = getTail(head);
        head = quickSortRecur(head, tail);
    }

    void display() {
        Node* temp = head;
        cout << "[ ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
};

int main() {
    LinkedList list;

    int values[] = {25, 10, 15, 30, 5, 20};
    for (int x : values)
        list.insertEnd(x);

    cout << "Original Linked List: ";
    list.display();

    list.quickSort();

    cout << "Sorted Linked List:   ";
    list.display();

    return 0;
}
