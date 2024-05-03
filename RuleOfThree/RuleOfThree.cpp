#include <iostream>
#include <vector>
#include <string> 
#include "Base.h"
#include "Employee.h"
#include "Student.h"

// Function prototypes
void AddRecord(std::vector<Base*>& v);
void DisplayRecords(std::vector<Base*>& v);
void DuplicateRecord(std::vector<Base*>& v);

int main() {
    std::vector<Base*> records;

    int choice;
    do {
        // Display menu
        std::cout << "Menu:\n";
        std::cout << "1. Add a record\n";
        std::cout << "2. Display all records\n";
        std::cout << "3. Duplicate a record\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            AddRecord(records);
            break;
        case 2:
            DisplayRecords(records);
            break;
        case 3:
            DuplicateRecord(records);
            break;
        case 4:
            // Clean up dynamically allocated memory
            for (auto& record : records) {
                delete record;
            }
            records.clear();
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to add a record to the vector
void AddRecord(std::vector<Base*>& v) {
    int type;
    std::cout << "Select record type:\n";
    std::cout << "1. Employee\n";
    std::cout << "2. Student\n";
    std::cout << "Enter your choice: ";
    std::cin >> type;

    const char* name;
    if (type == 1) {
        // For Employee
        name = "Employee";
        int salary;
        std::cout << "Enter employee name: ";
        std::cin.ignore(); // Ignore previous newline character
        std::string employeeName;
        std::getline(std::cin, employeeName); // Corrected getline call
        name = employeeName.c_str(); // Convert string to const char*
        std::cout << "Enter employee salary: ";
        std::cin >> salary;
        v.push_back(new Employee(name, salary));
    }
    else if (type == 2) {
        // For Student
        name = "Student";
        float gpa;
        std::cout << "Enter student name: ";
        std::cin.ignore(); // Ignore previous newline character
        std::string studentName;
        std::getline(std::cin, studentName); // Corrected getline call
        name = studentName.c_str(); // Convert string to const char*
        std::cout << "Enter student GPA: ";
        std::cin >> gpa;
        v.push_back(new Student(name, gpa));
    }
    else {
        std::cout << "Invalid type.\n";
    }
}

// Function to display all records
void DisplayRecords(std::vector<Base*>& v) {
    std::cout << "Records:\n";
    for (const auto& record : v) {
        record->DisplayRecord();
    }
}

// Function to duplicate a record
void DuplicateRecord(std::vector<Base*>& v) {
    int index;
    std::cout << "Enter the index of the record to duplicate: ";
    std::cin >> index;

    if (index >= 0 && index < v.size()) {
        // Retrieve the original record
        Base* original = v[index];
        // Check if it's an Employee
        Employee* emp = dynamic_cast<Employee*>(original);
        if (emp) {
            // If yes, create a copy of Employee
            v.push_back(new Employee(*emp));
        }
        else {
            // If not an Employee, check if it's a Student
            Student* stu = dynamic_cast<Student*>(original);
            if (stu) {
                // If yes, create a copy of Student
                v.push_back(new Student(*stu));
            }
            else {
                std::cout << "Unknown record type.\n";
            }
        }
    }
    else {
        std::cout << "Invalid index.\n";
    }
}
