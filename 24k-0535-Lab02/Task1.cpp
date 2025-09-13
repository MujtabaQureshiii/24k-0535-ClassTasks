#include <iostream> 
using namespace std; 
 
class DynamicArray { 
private: 
    int* data; 
    int size; 
    int capacity; 
 
    void resize() { 
        int newCapacity = capacity * 2; 
        int* newData = new int[newCapacity]; 
 
        for (int i = 0; i < size; ++i) { 
            newData[i] = data[i]; 
        } 
 
        delete[] data; 
        data = newData; 
        capacity = newCapacity; 
    } 
 
public: 
    DynamicArray(int initialCapacity = 2) 
        : size(0), capacity(initialCapacity) { 
        data = new int[capacity]; 
        cout << "DynamicArray created with capacity " << capacity << endl; 
    } 
 
    ~DynamicArray() { 
        delete[] data; 
        cout << "DynamicArray destroyed and memory deallocated" << endl; 
    } 
 
    void push_back(int value) { 
        if (size == capacity) { 
            resize(); 
        } 
        data[size++] = value; 
    } 
 
    void print() const { 
        for (int i = 0; i < size; ++i) { 
            cout << data[i] << " "; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    { 
        DynamicArray arr; 
 
        arr.push_back(10); 
        arr.push_back(20); 
        arr.push_back(30); 
        arr.push_back(40); 
 
        cout << "Array elements: "; 
        arr.print(); 
 
    }  
 
    cout << "After the array object is out of scope." << endl; 
 
    return 0; 
} 
