#ifndef UNTITLED_STUDENTCONSOLEINPUTPROCESSOR_H
#define UNTITLED_STUDENTCONSOLEINPUTPROCESSOR_H

#include "Student.h"

class StudentConsoleInputProcessor {
    int getHomeworkGradeCalculationType() ;
    Student executeGeneratedGradesPath();
    string getInputFirstName();
    string getInputLastName();
    vector<int> getHomeworkGradesFromInput();
    Student executeInputGradesPath();
    void printHeadline(string homeworkCalculationTypeText);

public:
    void processStudentsFromInput();
};
#endif //UNTITLED_STUDENTCONSOLEINPUTPROCESSOR_H
