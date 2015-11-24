#include<iostream>
#include <functional>
#include "Grades.h"

Grades::Grades() {

}

Grades::Grades(const char* file_name) {

    std::ifstream file(file_name);

    if (!file)
        throw "Error, could not open file ";

    int counter = 0;
    std::string tmp;

    while (std::getline(file, tmp)) {
        counter++;
    }

    num_of_records = counter;
    student_id = new long[num_of_records];
    grades = new float[num_of_records];

    file.clear();
    file.seekg(std::ios::beg);

    for (int i = 0; i < num_of_records; i++) {
        file >> student_id[i];
        file >> grades[i];
        file.ignore();
    }

    file.close();
}

void Grades::displayGrades(std::ostream& os, std::function<std::string(float)> letters) const{

    for (int i = 0; i < num_of_records; i++){
        os << student_id[i] << " " << grades[i] << " " << letters(grades[i]) << std::endl;

    }

}
