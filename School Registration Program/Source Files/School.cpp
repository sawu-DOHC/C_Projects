#include "../Header Files/school.h"

// Constructors
School::School() {}

// Destructor to clean up dynamically allocated memory
School::~School() {
    for (auto& studentPair : studentMap) {
        delete studentPair.second;
    }
    for (auto& coursePair : courseMap) {
        delete coursePair.second;
    }
}

// Accessor methods (getters)
map<string, Student*> School::getStudentMap() const {
    return studentMap;
}

map<string, Course*> School::getCourseMap() const {
    return courseMap;
}

bool School::getEnrollmentOccurred() const {
    return enrollmentOccurred;
}

// Mutator methods (setters)
void School::setStudentMap(const map<string, Student*>& newStudentMap) {
    studentMap = newStudentMap;
}

void School::setCourseMap(const map<string, Course*>& newCourseMap) {
    courseMap = newCourseMap;
}

void School::setEnrollmentOccurred(bool enrollmentStatus) {
    enrollmentOccurred = enrollmentStatus;
}

// Helper methods
void School::createUniqueCourseObjects(vector<string> rawCourseData) {
    for (const string& row : rawCourseData) {
        stringstream stream1(row);
        string extractedCourseID;
        int extractedCreditHours;
        int extractedCapacity;

        getline(stream1, extractedCourseID, ' ');
        stream1 >> extractedCreditHours;
        stream1 >> extractedCapacity;

        auto courseIterator = courseMap.find(extractedCourseID);

        // If the course does NOT exist in the map, create and add it
        if (courseIterator == courseMap.end()) {
            Course* newCourse = new Course(extractedCourseID, extractedCreditHours, extractedCapacity);
            courseMap[extractedCourseID] = newCourse;
        }
    }
}

void School::createUniqueStudentObjects(vector<string> rawStudentData) {
    for (const string& row : rawStudentData) {
        stringstream stream1(row);
        string extractedFirstName;
        string extractedLastName;
        string extractedStudentID;
        string extractedCourseName;

        getline(stream1, extractedLastName, ',');
        getline(stream1, extractedFirstName, ',');
        getline(stream1, extractedStudentID, ',');
        getline(stream1, extractedCourseName);

        auto studentIterator = studentMap.find(extractedStudentID);

        // Creation of unique student
        if (studentIterator == studentMap.end()) {
            Student* newStudent = new Student(extractedFirstName, extractedLastName, extractedStudentID);
            studentMap[extractedStudentID] = newStudent;
        }
    }
}

void School::enrollStudentsInClasses(const vector<string>& rawStudentData) {
    for (const string& row : rawStudentData) {
        stringstream stream1(row);
        string extractedFirstName;
        string extractedLastName;
        string extractedStudentID;
        string extractedCourseName;

        getline(stream1, extractedLastName, ',');
        getline(stream1, extractedFirstName, ',');
        getline(stream1, extractedStudentID, ',');
        getline(stream1, extractedCourseName);

        auto studentIterator = studentMap.find(extractedStudentID);
        auto courseIterator = courseMap.find(extractedCourseName);

        if (studentIterator != studentMap.end() && courseIterator != courseMap.end()) {
            Student* studentElement = studentIterator->second;
            Course* courseElement = courseIterator->second;

            if (courseElement->getStudentSet().size() < courseElement->getCapacity()) {
                studentElement->insertCourse(courseElement);
                courseElement->insertStudent(studentElement);

                int newRegisteredHours = studentElement->getRegisteredHours() + courseElement->getCreditHours();
                studentElement->setRegisteredHours(newRegisteredHours);
            }
        }
    }
    enrollmentOccurred = true;
}

void School::calculateStudentsAttemptedHours(vector<string> rawStudentData) {
    for (const string& row : rawStudentData) {
        stringstream stream1(row);
        string extractedFirstName;
        string extractedLastName;
        string extractedStudentID;
        string extractedCourseName;

        getline(stream1, extractedLastName, ',');
        getline(stream1, extractedFirstName, ',');
        getline(stream1, extractedStudentID, ',');
        getline(stream1, extractedCourseName);

        auto studentIterator = studentMap.find(extractedStudentID);
        auto courseIterator = courseMap.find(extractedCourseName);

        if (studentIterator != studentMap.end() && courseIterator != courseMap.end()) {
            Student* studentElement = studentIterator->second;
            Course* courseElement = courseIterator->second;

            int attemptedHours = studentElement->getAttemptedHours() + courseElement->getCreditHours();
            studentElement->setAttemptedHours(attemptedHours);
        }
    }
}
