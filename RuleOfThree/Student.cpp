#include "Student.h"

// Default constructor
Student::Student() : Base(), GPA(0.0f) {}

// Constructor with name and GPA initialization
Student::Student(const char* name, float gpa) : Base(name), GPA(gpa) {}

// Setter for GPA
void Student::SetGPA(float newGPA) {
    GPA = newGPA;
}

// DisplayRecord implementation
void Student::DisplayRecord() {
    const char* studentName = GetName();
    std::cout << "Name: " << (studentName ? studentName : "N/A") << ", GPA: " << GPA << std::endl;
}