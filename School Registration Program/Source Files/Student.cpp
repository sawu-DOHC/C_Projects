#include <string>
#include <set>

#include "../Header Files/Student.h"


// Constructors
Student::Student(string& newFirstName, string& newLastName, string& newStudentID) {
    this->firstName = newFirstName;
    this->lastName = newLastName;
    this->studentID = newStudentID;
}

// Accessor methods (getters)
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
string Student::getStudentID() const {
    return studentID;
}
int Student::getAttemptedHours() const {
    return attemptedHours;
}
int Student::getRegisteredHours() const {
    return registeredHours;
}
const set<Course*>& Student::getCourseSet() const {
    return coursePtrSet;
}

// Setters
void Student::setFirstName(const string& newFirstName) {
    firstName = newFirstName;
}
void Student::setLastName(const string& newLastName) {
    lastName = newLastName;
}
void Student::setStudentID(const string& newStudentID) {
    studentID = newStudentID;
}
void Student::setAttemptedHours(const int& newAttemptedHours) {
    attemptedHours = newAttemptedHours;
}
void Student::setRegisteredHours(const int& newRegisteredHours) {
    registeredHours = newRegisteredHours;
}
void Student::setCourseSet(const set<Course*>& newCourseSet) {
    coursePtrSet = newCourseSet;
}

// Comparison operators
bool Student::operator < (const Student& other) const {

    bool isLessThan;

    if (lastName == other.lastName) {
        isLessThan = firstName < other.firstName;
    }
    else {
        isLessThan = lastName < other.lastName;
    }

    return isLessThan;
}
bool Student::operator > (const Student& other) const {

    bool isGreaterThan;

    if (lastName == other.lastName) {
        isGreaterThan = firstName > other.firstName;
    }
    else {
        isGreaterThan = lastName > other.lastName;
    }

    return isGreaterThan;
}
bool Student::operator == (const Student& other) const {

    bool isEqual;
    // this was required to deal with errors in studentID number data where students had the same
    // id but different names. instead of just purging them or overriding this makes sure both objects can exist
    // and be differentiated. otherwise i would have had a set or map with student ID as the key
    if ((lastName == other.lastName) && (firstName == other.firstName) && (studentID == other.studentID)) {
        isEqual = true;
    }
    else {
        isEqual = false;
    }

    return isEqual;
}

// Helper methods
void Student::insertCourse(Course*& newCoursePtr) {
    coursePtrSet.insert(newCoursePtr);
}
