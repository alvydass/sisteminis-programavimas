#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

string getInputFirstName();
string getInputLastName();
int getHomeworkGradeCalculationType();
vector<int> getHomeworkGradesFromInput();
string resolveCalculationType(int);
void printHeadline(string);
void processStudentsFromFile();
void processStudentsFromInput();
void printHeadlineWithAverageAndMedian();


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
            return calculateFinalWithAverage();
        }
        else {
            return calculateFinalWithMedian();
        }
    }

    double calculateFinalWithAverage() {
        return 0.4 * calculateHomeworkAverage() + 0.6 * examGrade;
    }

    double calculateFinalWithMedian() {
        return 0.4 * calculateHomeworkMedian() + 0.6 * examGrade;
    }

    void printStudentData(int calculationType) {
        cout << setw(10) << left << firstName << setw(10) << left << lastName << setw(20) << left << fixed << setprecision(2) << calculateFinal(calculationType) << endl;
    }

    void printStudentDataWithAverageAndMedian() {
        cout << setw(10) << left << firstName << setw(15) << left <<lastName << setw(20) << left << fixed << setprecision(2) << calculateFinalWithAverage() << setw(10) << left << calculateFinalWithMedian() << endl;
    }

    string getFirstName() {
        return this->firstName;
    }
};

Student executeGeneratedGradesPath();
Student executeInputGradesPath();

int main()
{
    cout << "Apdoroti studentus is failo? y - TAIP, n -NE: ";
    char fileAnswer;
    cin >> fileAnswer;
    if (fileAnswer == 'y') {
        processStudentsFromFile();
    }
    else {
        processStudentsFromInput();
    }

}

Student executeInputGradesPath() {

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
    cout << setw(10) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(10) << left <<  homeworkCalculationTypeText << endl;
    cout << "------------------------------------------" << endl;
}

void printHeadlineWithAverageAndMedian() {
    cout << endl;
    cout << "Pavarde    Vardas    Galutinis (vid.)    Galutinis(med.)" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void processStudentsFromFile() {
    ifstream file("kursiokai.txt");
    string firstName;
    string lastName;
    int nd1;
    int nd2;
    int nd3;
    int nd4;
    int nd5;
    int exam;
    int lineNumber = 0;
    vector<Student> students;

    for(string line; getline(file, line);) {
        if (lineNumber == 0) {
            lineNumber++;
            continue;
        }

        stringstream ssin(line);
        ssin >> firstName >> lastName >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> exam;
        vector<int> homeworkGrades;
        homeworkGrades.push_back(nd1);
        homeworkGrades.push_back(nd2);
        homeworkGrades.push_back(nd3);
        homeworkGrades.push_back(nd4);
        homeworkGrades.push_back(nd5);
        Student student(firstName, lastName, homeworkGrades, exam);
        students.push_back(student);
    }

    sort(students.begin(), students.end(), [](Student lhs, Student rhs) {
        return lhs.getFirstName() < rhs.getFirstName();
    });

    string headline = resolveCalculationType(0);
    printHeadlineWithAverageAndMedian();
    for (int i = 0; i < students.size(); i++) {
        students[i].printStudentDataWithAverageAndMedian();
    }
}

void processStudentsFromInput() {
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
            students.push_back(executeInputGradesPath());
        }
    }
    else {
        cout << "Ivestas netinkamas simbolis";
        return;
    }

    string calculationTypeText = resolveCalculationType(calculationTypeNumber);
    printHeadline(calculationTypeText);
    for (int i = 0; i < students.size(); i++) {
        students[i].printStudentData(calculationTypeNumber);
    }
}

