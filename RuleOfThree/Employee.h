#pragma once
#include "Base.h"
class Employee : public Base
{
private:
    int salary;

public:
    Employee();
    Employee(const char* name, int salary);
    void SetSalary(int newSalary);
    void DisplayRecord() override;
};

