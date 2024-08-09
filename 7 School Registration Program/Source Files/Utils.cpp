#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "../Header Files/school.h"

using namespace std;

vector<string> extractData(const string& filePath) {
    vector<string> data;
    ifstream inputFileStream(filePath);
    string line;

    while (getline(inputFileStream, line)) {
        data.push_back(line);
    }

    inputFileStream.close();
    return data;
}

void printCourseInfo(const School& schoolObject) {
    cout << "===================================================================" << endl;
    if (schoolObject.getEnrollmentOccurred()) {
        cout << "           ~~ STUDENT INFORMATION AFTER SCHEDULING ~~" << endl;
    }
    else {
        cout << "           ~~ STUDENT INFORMATION BEFORE SCHEDULING ~~" << endl;
    }
    cout << "===================================================================" << endl;
    cout << left << setw(14) << "Course Name" << setw(15) << "Credit Hours" << setw(11) << "Enrolled" << setw(11) << "Capacity" << setw(20) << "Address" << endl;
    cout << "===================================================================" << endl;

    // Print course details
    for (const auto& courseElement : schoolObject.getCourseMap()) {
        const Course* course = courseElement.second; // Dereference the pointer
        cout << left << setw(14) << course->getCourseID() << setw(15) << course->getCreditHours() << setw(11) << course->getStudentSet().size() << setw(11) << course->getCapacity() << setw(20) << course << endl;
    }
    cout << endl << endl;
}

void printStudentInfo(const School& schoolObject) {
    cout << "===================================================================" << endl;
    if (schoolObject.getEnrollmentOccurred()) {
        cout << "           ~~ STUDENT INFORMATION AFTER SCHEDULING ~~" << endl;
    }
    else {
        cout << "           ~~ STUDENT INFORMATION BEFORE SCHEDULING ~~" << endl;
    }
    cout << "===================================================================" << endl;
    cout << left << setw(25) << "Last Name, First Name" << setw(15) << "Student ID" << setw(11) << "Hours" << "Address" << endl;
    cout << "===================================================================" << endl;

    // Iterating through the student map
    for (const auto& studentPair : schoolObject.getStudentMap()) {
        const Student* currentStudent = studentPair.second;

        cout << left << setw(25) << (currentStudent->getLastName() + ", " + currentStudent->getFirstName()) << setw(15) << currentStudent->getStudentID();

        if (schoolObject.getEnrollmentOccurred()) {
            cout << setw(11) << currentStudent->getRegisteredHours() << currentStudent << endl;
        }
        else {
            cout << setw(11) << currentStudent->getAttemptedHours() << currentStudent << endl;
        }
    }
    cout << endl << endl;
}


void printCourseRosters(const School& schoolObject) {
    cout << "===================================================================" << endl;
    cout << "                         All Course Rosters" << endl;
    cout << "===================================================================" << endl;

    // Cycle through the course map object and print all the students that got enrolled or added to the course
    for (const auto& courseElement : schoolObject.getCourseMap()) {
        const Course* course = courseElement.second;

        cout << "Course Title: " << course->getCourseID() << endl;
        cout << "Address: " << course << endl;
        cout << "===================================================================" << endl;
        cout << setw(2) << "#" << setw(25) << "Name" << setw(24) << "Student ID" << setw(22) << "Address" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        if (course->getStudentSet().empty()) {
            cout << "No students registered" << endl;
        }
        else {
            int count = 1;
            for (const Student* studentElement : course->getStudentSet()) {
                cout << setw(2) << count << setw(25) << (studentElement->getLastName() + ", " + studentElement->getFirstName()) << setw(24) << studentElement->getStudentID() << studentElement << endl;
                count++;
            }
            cout << "===================================================================" << endl;
        }
        cout << endl << endl;
    }
}


void printStudentSchedules(const School& schoolObject) {
    cout << "\n" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ All Student Schedules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    cout << "\n" << endl;

    // Iterate through the student map and print each student's schedule
    for (const auto& studentPair : schoolObject.getStudentMap()) {
        const Student* currentStudent = studentPair.second;

        cout << currentStudent->getLastName() << ", " << currentStudent->getFirstName() << "'s Schedule" << endl;
        cout << "ID: " << currentStudent->getStudentID() << endl;
        cout << "Hours: " << currentStudent->getRegisteredHours() << endl;
        cout << "Address: " << currentStudent << endl;
        cout << "========================================" << endl;

        if (!currentStudent->getCourseSet().empty()) {
            // Print the header for the courses section
            cout << left << setw(25) << "Course Title" << "Address" << endl;
            cout << "----------------------------------------" << endl;

            // Print the student's courses
            for (const Course* studentCourse : currentStudent->getCourseSet()) {
                cout << left << setw(25) << studentCourse->getCourseID() << studentCourse << endl;
            }
        }
        else {
            cout << "No Schedule" << endl;
        }
        cout << endl;
    }

    cout << endl;
}


void printRegistrationEventHeader() {
    cout << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + " << endl;
    cout << "! ! ! ! ! ! ! ! ! ! ! ! REGISTRATION EVENT ! ! ! ! ! ! ! ! ! ! ! ! !" << endl;
    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << endl << endl << endl;
}
