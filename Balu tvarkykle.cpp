#include <iostream>
#include "StudentFileProcessor.h"
#include "StudentConsoleInputProcessor.h"

using namespace std;

int main()
{
    cout << "Apdoroti studentus is failo? y - TAIP, n -NE: ";
    char fileAnswer;
    cin >> fileAnswer;
    if (fileAnswer == 'y') {
        StudentFileProcessor studentFileProcessor;
        studentFileProcessor.processStudentsFromFile();
    }
    else {
        StudentConsoleInputProcessor studentConsoleInputProcessor;
        studentConsoleInputProcessor.processStudentsFromInput();
    }
}
