#include <iostream>
#include <vector>
using namespace std;

// Template class for student
template <class T1, class T2>
class MemoryCalculate {
public:
    T1 id;
    T2 name;

    // Constructor
    MemoryCalculate(T1 i, T2 n) {
        id = i;
        name = n;
    }

    // Display function
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int, string>> students;
    int choice;

    while (true) {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;

            MemoryCalculate<int, string> s(id, name);
            students.push_back(s);
            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {
            cout << "\nAll Students:\n";
            for (int i = 0; i < students.size(); i++) {
                students[i].display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    students.erase(students.begin() + i);
                    cout << "Student removed.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    cout << "Student found:\n";
                    students[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "Thank you!\n";
            break;
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}