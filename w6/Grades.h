//Grades.h
#ifndef GRADES_H
#define GRADES_H

#include <fstream>

class Grades {
private:
    long* student_id;
    float* grades;
    int num_of_records;

public:
    Grades();
    Grades(const char*);
    void displayGrades(std::ostream& os, std::function<std::string(float)> letters) const;
};

#endif