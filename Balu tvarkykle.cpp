#include <iostream>
#include "StudentFileProcessor.h"
#include "StudentConsoleInputProcessor.h"
#include "StudentFIleGenerator.h"
#include <chrono>

using namespace std::chrono;

int main()
{

    StudentFileGenerator generator;

    auto start = high_resolution_clock::now();
    generator.createStudentFile(10000000);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Student file generation in milliseconds: " << duration.count() << endl;

    StudentFileProcessor studentFileProcessor;
    studentFileProcessor.processStudentsFromFile("generatedStudentFile.txt", true);


    /*cout << "Apdoroti studentus is failo? y - TAIP, n -NE: ";
    char fileAnswer;
    cin >> fileAnswer;
    if (fileAnswer == 'y') {
        StudentFileProcessor studentFileProcessor;
        studentFileProcessor.processStudentsFromFile();
    }
    else {
        StudentConsoleInputProcessor studentConsoleInputProcessor;
        studentConsoleInputProcessor.processStudentsFromInput();
    }*/
}
