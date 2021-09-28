#include "StudentFileProcessor.h"
#include "Student.h"
#include "GeneralUtils.h"

using namespace std;

void StudentFileProcessor::processStudentsFromFile() {
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

    GeneralUtils generalUtils;
    string headline = generalUtils.resolveCalculationType(0);
    printHeadlineWithAverageAndMedian();
    for (int i = 0; i < students.size(); i++) {
        students[i].printStudentDataWithAverageAndMedian();
    }
}

void StudentFileProcessor::printHeadlineWithAverageAndMedian() {
    cout << endl;
    cout << "Pavarde    Vardas    Galutinis (vid.)    Galutinis(med.)" << endl;
    cout << "-------------------------------------------------------------" << endl;
}
