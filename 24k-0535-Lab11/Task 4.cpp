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

class StudentHashTable {
private:
    Student table[15];

    int hashFunc(int r) {
        return r % 15;
    }

public:
    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);
        int attempt = 1;

        while(table[index].roll != -1) {
            index = (hashFunc(roll) + attempt * attempt) % 15;
            attempt++;
            if(attempt > 15) return;
        }

        table[index].roll = roll;
        table[index].name = name;
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 1;

        while(table[index].roll != -1) {
            if(table[index].roll == roll) {
                cout << table[index].name << endl;
                return;
            }
            index = (hashFunc(roll) + attempt * attempt) % 15;
            attempt++;
            if(attempt > 15) break;
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
    StudentHashTable h;

    h.InsertRecord(11, "Ali");
    h.InsertRecord(26, "Sara");
    h.InsertRecord(41, "Zain");
    h.InsertRecord(56, "Omar");

    h.Display();

    cout << endl;

    h.SearchRecord(41);
    h.SearchRecord(90);

    return 0;
}
