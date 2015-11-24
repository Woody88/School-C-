// Workshop 6 - Lambda Expression
 // w6.cpp

 #include <iostream>
#include <cmath>
#include <string>
 #include <functional>
 #include "Grades.h"


 int main(int argc, char* argv[]) {
     if (argc != 2) {
         std::cerr << argv[0] <<
          ": incorrect number of arguments\n";
         std::cerr << "Usage: " << argv[0] << " file_name\n"; 
         return 1;
     }


        Grades grades(argv[1]);
         // define the lambda expression for letter
        std::function<std::string(float)> letter = [] (float f) -> std::string {
             int numGrade = std::nearbyint(f);

                if (numGrade >= 90 && numGrade <= 100) {
                    return "A+";
                } else if (numGrade >= 80 && numGrade <= 89) {
                        return "A";
                } else if (numGrade >= 75 && numGrade <= 79) {
                        return "B+";
                } else if (numGrade >= 70 && numGrade <= 74) {
                        return "B";
                } else if (numGrade >= 65 && numGrade <= 69) {
                        return "C+";
                } else if (numGrade >= 60 && numGrade <= 64) {
                        return "C";
                } else if (numGrade >= 55 && numGrade <= 59) {
                        return "D+";
                } else if (numGrade >=50 && numGrade <= 54) {
                        return "D";
                } else {
                        return "F";
                }
        };


    try {
        Grades grades(argv[1]);
        grades.displayGrades(std::cout, letter);

    } catch (const char* msg) {
        std::cout << msg << std::endl;
        return 1;
    }
    std::cout << "Press any key to continue ... ";
    std::cin.get();
 }