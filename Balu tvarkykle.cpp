#include <iostream>
#include <string>
#include <iomanip>
#include <vector> 
#include <algorithm>
#include <sstream>

using namespace std;


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


int main()
{

    cout << "Iveskite varda: ";
    string firstName;
    cin >> firstName;

    cout << "Iveskite pavarde: ";
    string lastName;
    cin >> lastName;
    cin.ignore();

    cout << "Iveskite namu darbu balus (pvz: 10 7 5) ir spauskite enter: ";
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

    cout << "Skaiciuoti vidurki = 0, skaiciuoti mediana = 1: ";
    string calculationTypeText;
    int calculationTypeNumber;
    cin >> calculationTypeNumber;
    if (calculationTypeNumber == 0) {
        calculationTypeText = "Galutinis (vid.)";
    }
    else {
        calculationTypeText = "Galutinis (med.)";
    }

    cout << endl;
    cout << "Pavarde    Vardas    " << calculationTypeText << endl;
    cout << "------------------------------------------" << endl;
    //vector<int> homeworkGrades{7, 10, 6};
    Student s(firstName, lastName, homeworkGrades, examGrade);
    s.printStudentData(calculationTypeNumber);
}

