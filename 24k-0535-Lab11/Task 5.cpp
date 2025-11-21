#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    Student() {
        roll = -1;
        name = "";
    }
};

class DoubleHash {
private:
    Student table[15];

    int h1(int r) {
        return r % 15;
    }

    int h2(int r) {
        return 7 - (r % 7);
    }

public:
    void InsertRecord(int roll, string name) {
        int index = h1(roll);
        int step = h2(roll);
        int i = 0;

        while(table[index].roll != -1) {
            i++;
            index = (h1(roll) + i * step) % 15;
            if(i > 15) return;
        }

        table[index].roll = roll;
        table[index].name = name;
    }

    void SearchRecord(int roll) {
        int index = h1(roll);
        int step = h2(roll);
        int i = 0;

        while(table[index].roll != -1) {
            if(table[index].roll == roll) {
                cout << table[index].name << endl;
                return;
            }
            i++;
            index = (h1(roll) + i * step) % 15;
            if(i > 15) break;
        }

        cout << "Record not found" << endl;
    }

    void Display() {
        for(int i=0; i<15; i++) {
            if(table[i].roll != -1)
                cout << i << ": " << table[i].roll << " " << table[i].name << endl;
            else
                cout << i << ": NULL" << endl;
        }
    }
};

int main() {
    DoubleHash h;

    h.InsertRecord(11, "Ali");
    h.InsertRecord(26, "Sara");
    h.InsertRecord(41, "Zain");
    h.InsertRecord(56, "Omar");

    h.Display();

    cout << endl;

    h.SearchRecord(26);
    h.SearchRecord(90);

    return 0;
}
