#ifndef SCHOOLREGISTRATIONPROGRAM_STUDENT_H
#define SCHOOLREGISTRATIONPROGRAM_STUDENT_H

#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>

#include "../Header Files/School.h"
#include "../Header Files/Course.h"
#include "../Header Files/Utils.h"

class School;
class Course;

using namespace std;

class Student {

private:
    // Data members
    string firstName;
    string lastName;
    string studentID;
    int attemptedHours = 0;
    int registeredHours = 0;
    set <Course*> coursePtrSet; 

public:
    // Constructors
    Student(string& newFirstName, string& newLastName, string& newStudentID);

    // Accessor methods (getters)
    string getFirstName() const;
    string getLastName() const;
    string getStudentID() const;
    int getAttemptedHours() const;
    int getRegisteredHours() const;
    const set <Course*>& getCourseSet() const;

    // Mutator methods (setters)
    void setFirstName(const string& newFirstName);
    void setLastName(const string& newLastName);
    void setStudentID(const string& newStudentID);
    void setAttemptedHours(const int& newAttemptedHours);
    void setRegisteredHours(const int& newRegisteredHours);
    void setCourseSet(const set <Course*>& newCourseSet);

    // Comparison operators
    bool operator < (const Student& other) const;
    bool operator > (const Student& other) const;
    bool operator == (const Student& other) const;

    // Helper methods
    void insertCourse(Course*& newCoursePtr);
};

#endif // FINALPROJECT_STUDENT_H