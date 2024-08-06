#ifndef FINALPROJECT_UTILS_H
#define FINALPROJECT_UTILS_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "../Header Files/School.h"
#include "../Header Files/Student.h"
#include "../Header Files/Course.h"


class School;
class Student;
class Course;

using namespace std;

vector <string> extractData(const string&);

void printCourseInfo(const School& schoolObject);

void printStudentInfo(const School& schoolObject);

void printCourseRosters(const School& schoolObject);

void printStudentSchedules(const School& schoolObject);

void printRegistrationEventHeader();




#endif //FINALPROJECT_UTILS_H