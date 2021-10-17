#include "StudentFileProcessor.h"
#include "Student.h"
#include "GeneralUtils.h"
#include <chrono>
#include <deque>
#include <list>

using namespace std::chrono;

void StudentFileProcessor::processStudentsFromFile(string fileName, bool createFiles) {
    ifstream file(fileName);
    string firstName;
    string lastName;
    int nd1;
    int nd2;
    int nd3;
    int nd4;
    int nd5;
    int exam;
    int lineNumber = 0;
    list<Student> students;

    auto start = high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Student file processing in milliseconds: " << duration.count() << endl;

    if (createFiles) {
      differentiateStudentsToFiles(students);

    } else {

      //sortAndPrintStudentsToConsole(students);
    }
}

void StudentFileProcessor::printHeadlineWithAverageAndMedian() {
    cout << endl;
    cout << "Pavarde    Vardas    Galutinis (vid.)    Galutinis(med.)" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void StudentFileProcessor::differentiateStudentsToFiles(list<Student>& students) {
    auto start = high_resolution_clock::now();
    list<Student> lopukai;

    auto i = std::begin(students);
    while (i != std::end(students)) {
        if (i->getFinalGrade() < 5) {
            lopukai.push_back(i->getStudent());
            i = students.erase(i);
        }
        else {
            ++i; }

    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Student file sorting in 2 groups in milliseconds: " << duration.count() << endl;
    
    auto start1 = high_resolution_clock::now();
    ofstream kietekuFailas ("kietekai.txt");
    kietekuFailas << setw(50) << left <<"Vardas"<< setw(50) << left <<"Pavarde"<< setw(50) << left <<"Galutinis"<< endl;
    for(Student student : students) {
        kietekuFailas << setw(50) << left <<student.getFirstName()<< setw(50) << left <<student.getLastName()<< setw(50) << left<< fixed << setprecision(2) <<student.getFinalGrade()<< endl;
    }
    kietekuFailas.close();

    ofstream lopukuFailas ("lopukai.txt");
    lopukuFailas << setw(50) << left <<"Vardas"<< setw(50) << left <<"Pavarde"<< setw(50) << left <<"Galutinis"<<endl;
    for(Student student : lopukai) {
        lopukuFailas << setw(50) << left <<student.getFirstName()<< setw(50) << left <<student.getLastName()<< setw(50) << left << fixed << setprecision(2) <<student.getFinalGrade()<< endl;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Student 2 groups write in 2 files in milliseconds: " << duration1.count() << endl;
    lopukuFailas.close();
}

void StudentFileProcessor::sortAndPrintStudentsToConsole(vector<Student> students) {
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
