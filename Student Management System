#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student Class
class Student {
private:
    int rollNo;
    string name;
    int age;
    string course;

public:

    // Add Student
    void addStudent() {

        ofstream file("students.txt", ios::app);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        file << rollNo << endl;
        file << name << endl;
        file << age << endl;
        file << course << endl;

        file.close();

        cout << "\nStudent Record Added Successfully!\n";
    }

    // Display Students
    void displayStudents() {

        ifstream file("students.txt");

        int rNo, sAge;
        string sName, sCourse;

        cout << "\n========== STUDENT RECORDS ==========\n";

        while (file >> rNo) {

            file.ignore();

            getline(file, sName);

            file >> sAge;

            file.ignore();

            getline(file, sCourse);

            cout << "Roll Number : " << rNo << endl;
            cout << "Name        : " << sName << endl;
            cout << "Age         : " << sAge << endl;
            cout << "Course      : " << sCourse << endl;
            cout << "----------------------------------\n";
        }

        file.close();
    }

    // Search Student
    void searchStudent() {

        int searchRoll;
        bool found = false;

        cout << "Enter Roll Number to Search: ";
        cin >> searchRoll;

        ifstream file("students.txt");

        int rNo, sAge;
        string sName, sCourse;

        while (file >> rNo) {

            file.ignore();

            getline(file, sName);

            file >> sAge;

            file.ignore();

            getline(file, sCourse);

            if (rNo == searchRoll) {

                cout << "\nStudent Found!\n";
                cout << "Roll Number : " << rNo << endl;
                cout << "Name        : " << sName << endl;
                cout << "Age         : " << sAge << endl;
                cout << "Course      : " << sCourse << endl;

                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Student Record Not Found.\n";
        }
    }

    // Update Student
    void updateStudent() {

        int updateRoll;
        bool found = false;

        cout << "Enter Roll Number to Update: ";
        cin >> updateRoll;

        ifstream inFile("students.txt");
        ofstream outFile("temp.txt");

        int rNo, sAge;
        string sName, sCourse;

        while (inFile >> rNo) {

            inFile.ignore();

            getline(inFile, sName);

            inFile >> sAge;

            inFile.ignore();

            getline(inFile, sCourse);

            if (rNo == updateRoll) {

                found = true;

                cout << "\nEnter New Details\n";

                cout << "Enter Name: ";
                getline(cin, sName);

                cout << "Enter Age: ";
                cin >> sAge;

                cin.ignore();

                cout << "Enter Course: ";
                getline(cin, sCourse);

                cout << "\nStudent Record Updated Successfully!\n";
            }

            outFile << rNo << endl;
            outFile << sName << endl;
            outFile << sAge << endl;
            outFile << sCourse << endl;
        }

        inFile.close();
        outFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found) {
            cout << "Student Record Not Found.\n";
        }
    }

    // Delete Student
    void deleteStudent() {

        int deleteRoll;
        bool found = false;

        cout << "Enter Roll Number to Delete: ";
        cin >> deleteRoll;

        ifstream inFile("students.txt");
        ofstream outFile("temp.txt");

        int rNo, sAge;
        string sName, sCourse;

        while (inFile >> rNo) {

            inFile.ignore();

            getline(inFile, sName);

            inFile >> sAge;

            inFile.ignore();

            getline(inFile, sCourse);

            if (rNo == deleteRoll) {

                found = true;
                cout << "\nStudent Record Deleted Successfully!\n";

                continue;
            }

            outFile << rNo << endl;
            outFile << sName << endl;
            outFile << sAge << endl;
            outFile << sCourse << endl;
        }

        inFile.close();
        outFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found) {
            cout << "Student Record Not Found.\n";
        }
    }
};

// Main Function
int main() {

    Student s;
    int choice;

    do {

        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            s.addStudent();
            break;

        case 2:
            s.displayStudents();
            break;

        case 3:
            s.searchStudent();
            break;

        case 4:
            s.updateStudent();
            break;

        case 5:
            s.deleteStudent();
            break;

        case 0:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}
