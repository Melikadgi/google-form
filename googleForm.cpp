#include <iostream>
#include <fstream>

using namespace std;

char googleFormDashboard() {
    char cmd;
    cout << "Google Form Dashboard:" << endl;
    cout << "1. Add new exam." << endl;
    cout << "2. Last exams history." << endl;
    cout << "3. Exams pending to be marked." << endl;
    cout << "4. List of the current students." << endl;
    cout << "5. Add new students to the list." << endl;
    cout << "6. Exit." << endl;
    cout << "Enter a command (number): ";
    cin >> cmd;
    return cmd;
}

int main() {
    do {
        char cmd = googleFormDashboard();
        fstream studentFile = fstream("students.txt");
        fstream examFile = fstream("exams.txt");
        if (cmd == '1') {
            // Add new exam
        } else if (cmd == '2') {
            // Last exams history
        } else if (cmd == '3') {
            // Exams pending to be marked
        } else if (cmd == '4') {
            string ID, name, email;
            while (studentFile >> ID >> name >> email) {
                cout << "StudentID: " << ID << " ___Name: " << name << " ___Email: " << email << endl;
            }
        } else if (cmd == '5') {
            cout << "1. Add a student from console." << endl;
            cout << "2. Add list of students from a file." << endl;
            cout << "Enter a command (number): ";
            cin >> cmd;
            if (cmd == '1') {
                string ID, name, email;
                cout << "Enter StudentID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Email: ";
                cin >> email;
                studentFile << ID << " " << name << " " << email << endl;
            }
            if (cmd == '2') {
                string filePath;
                cout << "Enter file path (note that in that file students must be like this: StudentID Name Email, if the format is not met the program won't work properly and everything will break.): ";
                cin >> filePath;
                ifstream file(filePath);
                if (file.is_open()) {
                    string ID, name, email;
                    while (file >> ID >> name >> email) {
                        studentFile << ID << " " << name << " " << email << endl;
                    }
                    file.close();
                }
                else {
                    cout << "File not found. Please try again." << endl;
                }
            }
            else {
                cout << "Invalid command. Please try again." << endl;
            }
        } else if (cmd == '6') {
            cout << "Thank you for chosing out service. Good bye!" << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    } while (true); 
}