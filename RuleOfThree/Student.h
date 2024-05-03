#pragma once
#include "Base.h"
class Student : public Base
{
private:
    float GPA;

public:
    Student();
    Student(const char* name, float gpa);
    void SetGPA(float newGPA);
    void DisplayRecord() override;
};

