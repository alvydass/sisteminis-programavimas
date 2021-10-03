#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Student {

private:
    string firstName;
    string lastName;
    vector<int> homeworkGrades;
    int examGrade;
    double finalGrade;

public:
    Student(string firstName, string lastName, const vector<int>& homeworkGrades, int examGrade);

    Student(const Student &student);

    ~Student();

    double calculateHomeworkAverage();

    double calculateHomeworkMedian();

    double calculateFinal(int calculationType);

    double calculateFinalWithAverage();

    double calculateFinalWithMedian();

    void printStudentData(int calculationType);

    void printStudentDataWithAverageAndMedian();

    string getFirstName();

    double getFinalGrade();

    string getLastName();
};

#endif //UNTITLED_STUDENT_H
