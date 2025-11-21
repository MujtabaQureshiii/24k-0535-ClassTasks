#include <iostream>
using namespace std;

class Hash {
private:
    int arr[10];
    int size;

    int hashFunc(int key) {
        return key % 10;
    }

public:
    Hash() {
        for(int i=0;i<10;i++)
            arr[i] = -1;
        size = 0;
    }

    void insertKey(int key) {
        int index = hashFunc(key);
        while(arr[index] != -1)
            index = (index + 1) % 10;
        arr[index] = key;
        size++;
    }

    void deleteKey(int key) {
        int index = hashFunc(key);
        int start = index;

        while(arr[index] != -1) {
            if(arr[index] == key) {
                arr[index] = -1;
                cout << "Remove " << key << endl;
                size--;
                return;
            }
            index = (index + 1) % 10;
            if(index == start) break;
        }
    }

    bool searchKey(int key) {
        int index = hashFunc(key);
        int start = index;

        while(arr[index] != -1) {
            if(arr[index] == key)
                return true;
            index = (index + 1) % 10;
            if(index == start) break;
        }
        return false;
    }

    void display() {
        for(int i=0;i<10;i++) {
            if(arr[i] != -1)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Hash h;

    h.insertKey(1);
    h.insertKey(3);
    h.insertKey(4);
    h.insertKey(5);
    h.insertKey(7);

    h.display();

    h.deleteKey(4);

    h.display();

    if(h.searchKey(5)) cout << "5 found" << endl;
    else cout << "5 not found" << endl;

    if(h.searchKey(6)) cout << "6 found" << endl;
    else cout << "6 not found" << endl;

    return 0;
}
