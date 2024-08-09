#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>
#include <queue>
#include <set>

#include "School.h"
#include "Student.h"
#include "Utils.h"

class School;
class Student;

using namespace std;

class Course {

private:
    // Data members
    string courseID;
    int creditHours;
    size_t capacity;
    set <Student*> studentPtrSet; // using pointers to avoid duplicaitng objects but i end up duplicating objects anyway before printing

public:
    // Constructors
    Course(const string& newCourseName, const int& newCreditHours, const int& newCapacity);

    // Accessor methods (getters)
    string getCourseID() const;
    int getCreditHours() const;
    size_t getCapacity() const;
    const set <Student*>& getStudentSet() const;

    // Mutator methods (setters)
    void setCourseID(const string& newCourseID);
    void setCreditHours(const int& newCreditHours);
    void setCapacity(const size_t& newCapacity);
    void setStudentSet(const set <Student*>& newStudentSet);

    // Comparison operators required to work with sets and creation of unique objects
    bool operator < (const Course& other) const;
    bool operator > (const Course& other) const;
    bool operator == (const Course& other) const;

    // Helper methods
    void insertStudent(Student*& newStudentPtr);
};

#endif // COURSE_H
