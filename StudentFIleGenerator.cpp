#include "StudentFIleGenerator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
void StudentFileGenerator::createStudentFile(int studentCount) {

    ofstream outfile ("generatedStudentFile.txt");

    outfile << setw(10) << left <<"Vardas"<< setw(10) << left <<"Pavarde"<< setw(10) << left <<"ND1"<< setw(10) <<
    left <<"ND2"<< setw(10) << left <<"ND3"<< setw(10) << left <<"ND4"<< setw(10) << left <<"ND5"<< setw(10) << left <<"Egzaminas"<< endl;

    string firstName = "Vardas";
    string lastName = "Pavarde";

    for (long i = 1; i <= studentCount; i++) {
        outfile << setw(10) << left <<firstName + to_string(i)<< setw(10) << left <<lastName + to_string(i)<< setw(10) << left << generateGrade()<< setw(10) << left <<generateGrade()
                << setw(10) << left <<generateGrade() << setw(10) << left <<generateGrade() << setw(10) << left <<generateGrade()<< setw(10) << left <<generateGrade() << endl;
    }

    outfile.close();
}

int StudentFileGenerator::generateGrade() {
    return rand() % 10 + 1;
}