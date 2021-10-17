#ifndef UNTITLED_STUDENTFILEPROCESSOR_H
#define UNTITLED_STUDENTFILEPROCESSOR_H

#include <string>
#include <sstream>
#include <fstream>
#include <deque>
#include <list>
#include "Student.h"

using namespace std;

class StudentFileProcessor {
public:
    void processStudentsFromFile(string fileName, bool createFiles);

    void printHeadlineWithAverageAndMedian();

    void differentiateStudentsToFiles(vector<Student>& students);

    void sortAndPrintStudentsToConsole(vector<Student> students);
};

#endif //UNTITLED_STUDENTFILEPROCESSOR_H
