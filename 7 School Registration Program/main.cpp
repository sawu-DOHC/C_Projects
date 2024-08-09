#include <string>
#include <vector>
#include "Header Files/Utils.h"
#include "Header Files/School.h"


using namespace std;

int main() {

    School newSchool;

    string courseDataPath;
    string studentDataPath;


    studentDataPath = "C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/7 School Registration Program/Test Data/students.txt";
    courseDataPath = "C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/7 School Registration Program/Test Data/courses.txt";


    // these methods extract course and student data and it is broken down line by line and inserted into a string vector
    vector <string> rawCourseData = extractData( courseDataPath );
    vector <string> rawStudentData = extractData( studentDataPath );


    // once the student and course data is in a managable form i pass it to the school object for processing
    // these methods create unique course and student objects
    newSchool.createUniqueCourseObjects( rawCourseData );
    newSchool.createUniqueStudentObjects( rawStudentData );

    // for simplicty and ease of debugging i separated calculating "attemptedHours", or hours prior
    // to registration, from creation of unique student and course objects
    // although it is not efficent i go over the raw course data again to determine what all the they are signed up for
    newSchool.calculateStudentsAttemptedHours( rawStudentData );

    // i did my best to reuse this method to print before and after the scheduling event
    printCourseInfo( newSchool );


    // this method too is re used after the scheduling event.
    printStudentInfo(newSchool);


    printRegistrationEventHeader();// just prints a visual barrier for easier reading
    //scheduling
    // this method looks at the raw data again and determines the order in which students are assigned to course objects
    // their order is maintained with a queue since it works in the interest of fairness
    newSchool.enrollStudentsInClasses(rawStudentData);
    
    
    // this method iterates through the schools course objects and prints their student objects names
    printCourseRosters(newSchool);


    // this method iterates through the schools student objects and prints their course objects courseIDs
    printStudentSchedules(newSchool);


    // reuse of previous print method now that registration method has been executed the results are different
    printStudentInfo(newSchool);


    // same situation here, reusing one of the first methods, this time its highlighting the differences in course info
    printCourseInfo(newSchool);

    return 0;
}
