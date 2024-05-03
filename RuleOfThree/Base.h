#pragma once
#include <iostream>
#include <cstring>
class Base
{
private:
    char* name;

public:
    Base();
    Base(const char* newName);
    Base(const Base& other);
    ~Base();
    Base& operator=(const Base& other);
    void SetName(const char* newName);
    const char* GetName() const;
    virtual void DisplayRecord() = 0;
};

