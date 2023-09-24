//Create a program that manages student grades. Allow the user to input student names and their corresponding grades.
//Calculate the average grade and display it along with the highestand lowest grades

#include <iostream>
#include <string>
#include <map>
#include <limits>

int main() {
    // Initialize variables
    std::map<std::string, double> studentGrades; 
    double totalGrades = 0;                      
    double highestGrade = std::numeric_limits<double>::min(); 
    double lowestGrade = std::numeric_limits<double>::max(); 

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numStudents; ++i) {
        std::string studentName;
        double grade;

        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::getline(std::cin, studentName);

        std::cout << "Enter the grade for " << studentName << ": ";
        std::cin >> grade;

        studentGrades[studentName] = grade;
        totalGrades += grade;

        if (grade > highestGrade) {
            highestGrade = grade;
        }
        if (grade < lowestGrade) {
            lowestGrade = grade;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double averageGrade = totalGrades / numStudents;

    std::cout << "\nStudent Grades:" << std::endl;
    for (const auto& pair : studentGrades) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "\nAverage Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade << std::endl;

    return 0;
}
