#include <iostream>
#include <fstream>
#include <string>

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

void addNewExam() {
    int numberOfQuestions;
    float totalDuration, totalMark;
    cout << "Enter total mark for the exam: ";
    cin >> totalMark;
    cout << "Enter total duration for the exam (in minutes): ";
    cin >> totalDuration;
    cout << "Enter number of questions: ";
    cin >> numberOfQuestions;
    fstream examFile("exams.txt", ios::app);
    if (!examFile) {
        cout << "Error loading the file 'exams.txt'. Please try again." << endl;
        return;
    }
    int checkTotalMark = 0;
    float marks[numberOfQuestions], times[numberOfQuestions];
    string questions[numberOfQuestions], types[numberOfQuestions];
    for (int i = 0;i < numberOfQuestions;i++) {
        float mark, time;
        string question, type;
        cout << "What is the question's mark ? ";
        cin >> mark;
        cout << "What is the question's time (in minutes) ? ";
        cin >> time;
        cout << "What is the question's type (descriptive or D / Multiple Choice or MC) ? ";
        cin >> type;
        cout << "What is the question's content ? ";
        cin.ignore();
        getline(cin, question);
        checkTotalMark += mark;
        marks[i] = mark;
        times[i] = time;
        if (type == "descriptive" || type == "D") {
            type = "Descriptive";
            question += "\n\n\n";
        }
        else if (type == "Multiple Choice" || type == "MC") {
            type = "Multiple Choice";
            string options[4];
            for (int j = 0;j < 4;j++) {
                cout << "Option " << j + 1 << ": ";
                cin.ignore();
                getline(cin, options[j]);
            }
            cout << "What is the right answer (option number) ? ";
            int rightAnswer;
            cin >> rightAnswer;
            question += "\n1." + options[0] + "\n2." + options[1] + "\n3." + options[2] + "\n4." + options[3] + "\nAnswer: " + to_string(rightAnswer);
        }
        else {
            cout << "Invalid type. Please try again." << endl;
            return;
        }
        questions[i] = question;
        types[i] = type;
    }
    if (checkTotalMark != totalMark) {
        cout << "Total mark doesn't match. Please try again." << endl;
        return;
    }
    string file = "";
    while (getline(examFile, file));
    int posToStart = 0, id = 1;
    while(file.find("----------------------", posToStart) != string::npos) {
        id++;
        posToStart = file.find("----------------------", posToStart) + 19;
    }
    examFile << "----------------------" << endl;
    examFile << "ID: " << id << endl;
    examFile << "Status: Not taken" << endl;
    examFile << "Total Mark: " << totalMark << endl;
    examFile << "Total Duration: " << totalDuration << " minutes" << endl;
    examFile << "Number of Questions: " << numberOfQuestions << endl;
    examFile << "Questions: " << endl;
    for (int i = 0;i < numberOfQuestions;i++) {
        examFile << "Question " << i + 1 << ": " << questions[i] << endl;
        examFile << "Type: " << types[i] << endl;
        examFile << "Mark: " << marks[i] << endl;
        examFile << "Time: " << times[i] << " minutes" << endl;
    }
    examFile.close();
    cout << "Exam added successfully." << endl;
}

void showStudentList() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string ID, name, email;
        while (file >> ID >> name >> email) {
            cout << ID << " " << name << " " << email << endl;
        }
        file.close();
    }
    else {
        cout << "File 'students.txt' not found. Please try again." << endl;
    }
}

void addNewStudents() {
    ofstream studentFile("students.txt", ios::app);
    if (!studentFile) {
        cout << "File 'students.txt' not found. Please try again." << endl;
        return;
    }
    char cmd;
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
}

int main() {
    do {
        char cmd = googleFormDashboard();
        if (cmd == '1') {
            addNewExam();
        } else if (cmd == '2') {
            // Last exams history
        } else if (cmd == '3') {
            // Exams pending to be marked
        } else if (cmd == '4') {
            showStudentList();
        } else if (cmd == '5') {
            addNewStudents();
        } else if (cmd == '6') {
            cout << "Thank you for chosing out service. Good bye!" << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    } while (true); 
}