#include "Base.h"
// Default constructor
Base::Base() : name(nullptr) {}

// Constructor with name initialization
Base::Base(const char* newName) : name(nullptr) {
    SetName(newName);
}

// Copy constructor
Base::Base(const Base& other) : name(nullptr) {
    *this = other;
}

// Destructor
Base::~Base() {
    delete[] name;
}

// Assignment operator
Base& Base::operator=(const Base& other) {
    if (this != &other) {
        delete[] name;
        name = nullptr;
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
    }
    return *this;
}

// Setter for name
void Base::SetName(const char* newName) {
    if (newName != nullptr) {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    else {
        name = nullptr;
    }
}

// Getter for name
const char* Base::GetName() const {
    return name;
}