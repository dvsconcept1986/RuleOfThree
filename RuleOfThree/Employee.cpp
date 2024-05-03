#include "Employee.h"


// Default constructor
Employee::Employee() : Base(), salary(0) {}

// Constructor with name and salary initialization
Employee::Employee(const char* name, int newSalary) : Base(name), salary(newSalary) {}

// Setter for salary
void Employee::SetSalary(int newSalary) {
    salary = newSalary;
}

// DisplayRecord implementation
void Employee::DisplayRecord() {
    const char* empName = GetName();
    std::cout << "Name: " << (empName ? empName : "N/A") << ", Salary: " << salary << std::endl;
}