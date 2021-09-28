#include "StudentConsoleInputProcessor.h"
#include "Student.h"
#include "GeneralUtils.h"
#include <iostream>
#include <string>
#include <sstream>

int getHomeworkGradeCalculationType();
string getInputFirstName();
string getInputLastName();
Student executeGeneratedGradesPath();
Student executeInputGradesPath();
void printHeadline(string);
vector<int> getHomeworkGradesFromInput();

using namespace std;

void StudentConsoleInputProcessor::processStudentsFromInput() {
    cout << "Ar balai turi buti sugeneruoti? y - taip, n - ne: ";
    char answer;
    cin >> answer;
    int calculationTypeNumber = getHomeworkGradeCalculationType();
    cout << "Iveskite studentu skaiciu, kuriuos noresite suvesti: ";
    int studentCount;
    cin >> studentCount;

    vector<Student> students;

    if (answer == 'y') {
        for (int i = 0; i < studentCount; i++) {
            students.push_back(executeGeneratedGradesPath());
        }
    } else if (answer == 'n') {
        for (int i = 0; i < studentCount; i++) {
            students.push_back(executeInputGradesPath());
        }
    } else {
        cout << "Ivestas netinkamas simbolis";
        return;
    }

    GeneralUtils generalUtils;
    string calculationTypeText = generalUtils.resolveCalculationType(calculationTypeNumber);
    printHeadline(calculationTypeText);
    for (int i = 0; i < students.size(); i++) {
        students[i].printStudentData(calculationTypeNumber);
    }
}

int StudentConsoleInputProcessor::getHomeworkGradeCalculationType() {
    cout << "Skaiciuoti vidurki = 0, skaiciuoti mediana = 1: ";
    int calculationTypeNumber;
    cin >> calculationTypeNumber;
    return calculationTypeNumber;
}

Student StudentConsoleInputProcessor::executeGeneratedGradesPath() {
    srand(time(NULL));

    string firstName = getInputFirstName();
    string lastName = getInputLastName();

    vector<int> homeworkGrades = getHomeworkGradesFromInput();

    int examGrade = rand() % 10 + 1;

    Student s(firstName, lastName, homeworkGrades, examGrade);
    return s;
}

string StudentConsoleInputProcessor::getInputFirstName() {
    string firstName;
    cout << "Iveskite varda: ";
    cin >> firstName;
    return firstName;
}

string StudentConsoleInputProcessor::getInputLastName() {
    string lastName;
    cout << "Iveskite pavarde: ";
    cin >> lastName;
    return lastName;
}

vector<int> StudentConsoleInputProcessor::getHomeworkGradesFromInput() {
    cout << "Iveskite namu darbu kieki (balai bus sugeneruoti): ";
    vector<int> homeworkGrades;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        homeworkGrades.push_back(rand() % 10 + 1);
    }
    cout << "Generated homework grades: ";
    for (int j = 0; j < homeworkGrades.size(); j++) {
        cout << homeworkGrades[j];
        cout << " ";
    }
    cout << endl;
    return homeworkGrades;
}

Student StudentConsoleInputProcessor::executeInputGradesPath() {

    string firstName = getInputFirstName();
    string lastName = getInputLastName();
    cin.ignore();

    cout << "Iveskite namu darbu balus (pvz: 10 8 5): ";
    string line;
    vector<int> homeworkGrades;
    getline(cin, line);
    istringstream iss(line);
    int grade;
    while (iss >> grade)
    {
        homeworkGrades.push_back(grade);
    }

    cout << "Iveskite egzamino rezultata: ";
    int examGrade;
    cin >> examGrade;

    Student s(firstName, lastName, homeworkGrades, examGrade);
    return s;
}

void StudentConsoleInputProcessor::printHeadline(string homeworkCalculationTypeText) {
    cout << endl;
    cout << setw(10) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(10) << left <<  homeworkCalculationTypeText << endl;
    cout << "------------------------------------------" << endl;
}