#include "Student.h"

using namespace std;


Student::Student(string firstName, string lastName, const vector<int>& homeworkGrades, int examGrade) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->homeworkGrades = homeworkGrades;
    this->examGrade = examGrade;
    this->finalGrade = calculateFinalWithAverage();
}

Student::Student(const Student &student) {
    firstName = student.firstName;
    lastName = student.lastName;
    homeworkGrades = student.homeworkGrades;
    examGrade = student.examGrade;
    finalGrade = student.finalGrade;
}

Student::~Student() {

}

double Student::calculateHomeworkAverage() {
    int gradeSum = 0;
    for (int homeworkGrade : homeworkGrades) {
        gradeSum += homeworkGrade;
    }
    double average;
    try {
        average = gradeSum / (double) homeworkGrades.size();
    } catch (exception& e) {
        cout << "Division by zero in average calculation";
        average = 0;
    }
    return average;
}

double  Student::calculateHomeworkMedian() {
    sort(homeworkGrades.begin(), homeworkGrades.end());
    if (homeworkGrades.size() % 2 == 0) {
        return (homeworkGrades[homeworkGrades.size() / 2 - 1] + homeworkGrades[homeworkGrades.size() / 2]) / 2;
    }
    else {
        return homeworkGrades[homeworkGrades.size() / 2];
    }
}

double  Student::calculateFinal(int calculationType) {
    if (0 == calculationType) {
        return calculateFinalWithAverage();
    }
    else {
        return calculateFinalWithMedian();
    }
}

double  Student::calculateFinalWithAverage() {
    return 0.4 * calculateHomeworkAverage() + 0.6 * examGrade;
}

double  Student::calculateFinalWithMedian() {
    return 0.4 * calculateHomeworkMedian() + 0.6 * examGrade;
}

void  Student::printStudentData(int calculationType) {
    cout << setw(10) << left << firstName << setw(10) << left << lastName << setw(20) << left << fixed << setprecision(2) << calculateFinal(calculationType) << endl;
}

void  Student::printStudentDataWithAverageAndMedian() {
    cout << setw(10) << left << firstName << setw(15) << left <<lastName << setw(20) << left << fixed << setprecision(2) << calculateFinalWithAverage() << setw(10) << left << calculateFinalWithMedian() << endl;
}

string  Student::getFirstName() {
    return this->firstName;
}

string  Student::getLastName() {
    return this->lastName;
}

double Student::getFinalGrade() {
    return this->finalGrade;
}
