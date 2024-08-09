#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <set>

#include "../Header Files/course.h"
#include "../Header Files/school.h"
#include "../Header Files/student.h"



// Constructors
Course::Course(const string& newCourseName, const int& newCreditHours, const int& newCapacity) {
    courseID = newCourseName;
    creditHours = newCreditHours;
    capacity = newCapacity;
}


// Accessor methods (getters)
string Course::getCourseID() const {
    return courseID;
}
int Course::getCreditHours() const {
    return creditHours;
}
size_t Course::getCapacity() const {
    return capacity;
}
const set <Student*>& Course::getStudentSet()const {
    return studentPtrSet;
}


// Mutator methods (setters)
void Course::setCourseID(const string& newCourseID) {
    courseID = newCourseID;
}
void Course::setCreditHours(const int& newCreditHours) {
    creditHours = newCreditHours;
}
void Course::setCapacity(const size_t& newCapacity) {
    capacity = newCapacity;
}
void Course::setStudentSet(const set <Student*>& newStudentSet) {
    studentPtrSet = newStudentSet;
}


// Comparison operators
bool Course::operator < (const Course& other) const {
    return courseID < other.courseID;
}
bool Course::operator > (const Course& other) const {
    return courseID > other.courseID;
}
bool Course::operator == (const Course& other) const {
    return courseID == other.courseID;
}


// Helper methods
void Course::insertStudent(Student*& newStudentPtr) {
    studentPtrSet.insert(newStudentPtr);
}