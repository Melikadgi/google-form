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
        if (cmd == '1') {
            // Add new exam
        } else if (cmd == '2') {
            // Last exams history
        } else if (cmd == '3') {
            // Exams pending to be marked
        } else if (cmd == '4') {
            // List of the current students
        } else if (cmd == '5') {
            // Add new students to the list
        } else if (cmd == '6') {
            // Exit
            break;
        } else {
            
        }
    } while (true); 
}