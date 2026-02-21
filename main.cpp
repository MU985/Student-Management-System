#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

Student s[100];
int total = 0;

void addStudent() {
    cout << "\nHow many students you want to add? ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Roll No: ";
        cin >> s[total].roll;

        cout << "Enter Name: ";
        cin >> s[total].name;

        cout << "Enter Marks: ";
        cin >> s[total].marks;

        total++;
    }
}

void displayStudents() {
    if (total == 0) {
        cout << "\nNo record found!\n";
        return;
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < total; i++) {
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;

    for (int i = 0; i < total; i++) {
        if (s[i].roll == roll) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s[i].name << endl;
            cout << "Marks: " << s[i].marks << endl;
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll No to delete: ";
    cin >> roll;

    for (int i = 0; i < total; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < total - 1; j++) {
                s[j] = s[j + 1];
            }
            total--;
            cout << "\nRecord deleted successfully!\n";
            return;
        }
    }

    cout << "\nRecord not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
