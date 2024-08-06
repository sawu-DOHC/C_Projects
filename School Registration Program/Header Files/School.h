#ifndef SCHOOLREGISTRATIONPROGRAM_H
#define SCHOOLREGISTRATIONPROGRAM_H

#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

#include "../Header Files/Student.h"
#include "../Header Files/Course.h"
#include "../Header Files/Utils.h"

class Student;
class Course;

using namespace std;

class School {

private:
    // Data members
    map<string, Course*> courseMap;   // Using pointers for courses
    map<string, Student*> studentMap; // Using pointers for students
    bool enrollmentOccurred = false;  // This is for the print methods to determine which stats to print

public:
    // Constructors
    School();
    ~School();

    // Accessor methods (getters)
    map<string, Student*> getStudentMap() const;
    map<string, Course*> getCourseMap() const;
    bool getEnrollmentOccurred() const;

    // Mutator methods (setters)
    void setStudentMap(const map<string, Student*>& newStudentMap);
    void setCourseMap(const map<string, Course*>& newCourseMap);
    void setEnrollmentOccurred(bool enrollmentStatus);

    // Helper methods
    void createUniqueCourseObjects(vector<string> rawCourseData);   // Creates unique course objects
    void createUniqueStudentObjects(vector<string> rawStudentData); // Creates unique student objects
    void enrollStudentsInClasses(const vector<string>& rawStudentData); // This is the scheduling event
    void calculateStudentsAttemptedHours(vector<string> rawStudentData); // This method modifies attempted hours variable
};

#endif // SCHOOL_H
