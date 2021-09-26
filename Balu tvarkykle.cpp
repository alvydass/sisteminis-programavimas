#include <iostream>
#include <string>
#include <iomanip>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <stdlib.h>   
#include <time.h>      

using namespace std;

string getInputFirstName();
string getInputLastName();
int getHomeworkGradeCalculationType();
vector<int> getHomeworkGradesFromInput();
string resolveCalculationType(int);
void printHeadline(string);


class Student {

private: 
    string firstName;
    string lastName;
    vector<int> homeworkGrades;
    int examGrade;
    int finalGrade;

public:
    Student(string firstName, string lastName, vector<int> homeworkGrades, int examGrade) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->homeworkGrades = homeworkGrades;
        this->examGrade = examGrade;
    }

    Student(const Student &student) {
        firstName = student.firstName;
        lastName = student.lastName;
        homeworkGrades = student.homeworkGrades;
        examGrade = student.examGrade;
        finalGrade = student.examGrade;
    }

    ~Student() {

    }

    double calculateHomeworkAverage() {
        int gradeSum = 0;
        for (int homeworkGrade : homeworkGrades) {
            gradeSum += homeworkGrade;
        }
       return gradeSum / (double)homeworkGrades.size();
    }

    double calculateHomeworkMedian() {
        sort(homeworkGrades.begin(), homeworkGrades.end());
        if (homeworkGrades.size() % 2 == 0) {
            return (homeworkGrades[homeworkGrades.size() / 2 - 1] + homeworkGrades[homeworkGrades.size() / 2]) / 2;
        }
        else {
            return homeworkGrades[homeworkGrades.size() / 2];
        }
    }

    double calculateFinal(int calculationType) {
        if (0 == calculationType) {
            return 0.4 * calculateHomeworkAverage() + 0.6 * examGrade;
        }
        else {
            return 0.4 * calculateHomeworkMedian() + 0.6 * examGrade;
        }
       
    }

    void printStudentData(int calculationType) {
        cout << firstName <<"    " << lastName << "    " << fixed << setprecision(2) << calculateFinal(calculationType) << endl;
    }

};

Student executeGeneratedGradesPath();
Student executeInpuGradesPath();

int main()
{

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
    }
    else if (answer == 'n') {
        for (int i = 0; i < studentCount; i++) {
            students.push_back(executeInpuGradesPath());
        }
    }
    else {
        cout << "Ivestas netinkamas simbolis";
        return 0;
    }

    string calculationTypeText = resolveCalculationType(calculationTypeNumber);
    printHeadline(calculationTypeText);
    for (int i = 0; i < students.size(); i++) {
        students[i].printStudentData(calculationTypeNumber);
    }
}

Student executeInpuGradesPath() {

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

Student executeGeneratedGradesPath() {
    srand(time(NULL));

    string firstName = getInputFirstName();
    string lastName = getInputLastName();

    vector<int> homeworkGrades = getHomeworkGradesFromInput();

    int examGrade = rand() % 10 + 1;

    Student s(firstName, lastName, homeworkGrades, examGrade);
    return s;
}

string getInputFirstName() {
    string firstName;
    cout << "Iveskite varda: ";
    cin >> firstName;
    return firstName;
}

string getInputLastName() {
    string lastName;
    cout << "Iveskite pavarde: ";
    cin >> lastName;
    return lastName;
}

int getHomeworkGradeCalculationType() {
    cout << "Skaiciuoti vidurki = 0, skaiciuoti mediana = 1: ";
    int calculationTypeNumber;
    cin >> calculationTypeNumber;
    return calculationTypeNumber;
}

vector<int> getHomeworkGradesFromInput() {
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

string resolveCalculationType(int calculationTypeNumber) {
    string calculationTypeText;
    if (calculationTypeNumber == 0) {
        calculationTypeText = "Galutinis (vid.)";
    }
    else {
        calculationTypeText = "Galutinis (med.)";
    }
    return calculationTypeText;
}

void printHeadline(string homeworkCalculationTypeText) {
    cout << endl;
    cout << "Pavarde    Vardas    " << homeworkCalculationTypeText << endl;
    cout << "------------------------------------------" << endl;
}

