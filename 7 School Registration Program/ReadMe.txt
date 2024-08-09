Student and Course Management Program

Overview

This program manages student and course data, simulating the scheduling and enrollment process in a school environment. 

There are 2 data files, student info and course info. Student info contains which classes students want to register for, it also contains the same student multiple times when they sign up for multiple classes.

There is also the course data which includes a "Hours" variable that represents how many credit hours its worth and its student capacity. 

Each course has a limited capacity, and registration is carried out on a first come, first serve basis. 

Before registration event occurs students can select all the classes they want, but after the registration event occurs, some students may be rejected if the course is at capacity.

This program keeps track of which students are registered for which courses, and vice versa, by using sets of pointers within the Course and Student classes. This minimizes the number of times the data structure is duplicated during use and practices conserving memory.



Program Features

1. Classes: The program uses classes to model students and courses. This object oriented approach provides the structure necessary for the program to function.

2. Use of "getline" Method: The "getline" method reads input data from files, processing data line by line. To use "getline", the "<iostream>", "<string>", and "<fstream>" headers are included.

3. Sets: Sets store unique pointers to "Student" and "Course" objects, ensuring no duplicates and allowing for efficient lookups and insertions.

4. Vector: Initially, students were stored in a vector, but this was changed to a map to allow for more efficient access and manipulation using student IDs as keys.

5. Maps: Maps associate unique keys (such as student IDs and course IDs) with pointers to "Student" and "Course" objects, enabling quick access.

6. Memory Management: By using pointers and dynamic memory allocation, the program conserves memory and minimizes data duplication. The destructor in the "School" class ensures that all dynamically allocated memory is cleaned up when the program ends, preventing memory leaks.

7. Comparison Operators: Custom comparison operators are necessary for using maps and sets with non-primitive data types. Implementing comparison operators for "Student" and "Course" objects allows them to be stored in ordered containers like sets and maps.



Example Output

===================================================================
           ~~ STUDENT INFORMATION BEFORE SCHEDULING ~~
===================================================================
Course Name   Credit Hours   Enrolled   Capacity   Address
===================================================================
ART101        3              0          5          000001D8C371A440
CIS2361       4              0          10         000001D8C3727C80
CIS2362       4              0          10         000001D8C3727B60
HIS213        3              0          5          000001D8C3729DB0
MTH412        3              0          10         000001D8C3729ED0


===================================================================
           ~~ STUDENT INFORMATION BEFORE SCHEDULING ~~
===================================================================
Last Name, First Name    Student ID     Hours      Address
===================================================================
Smith, Amy               000001         10         000001D8C3729C10
Jones, Randy             000002         3          000001D8C3728000
Harris, Mike             000003         4          000001D8C37280E0
Johnson, David           000004         3          000001D8C37281C0
Key, Jason               000005         3          000001D8C37282A0
Thomas, Jackie           000006         3          000001D8C3728380
Green, Robert            000007         3          000001D8C3728460
Gay, Jasmine             000008         4          000001D8C3728540
Cook, Pat                000009         4          000001D8C3728620
Cooperman, Sophia        000010         3          000001D8C3728700
Case, Jan                000011         3          000001D8C37287E0
Smith, Eric              000012         3          000001D8C372C020
Richards, Raymond        000013         3          000001D8C372C100
Boone, Peter             000014         3          000001D8C372C1E0
Davis, Candy             000015         3          000001D8C372E2E0




~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +
! ! ! ! ! ! ! ! ! ! ! ! REGISTRATION EVENT ! ! ! ! ! ! ! ! ! ! ! ! !
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


===================================================================
                         All Course Rosters
===================================================================
Course Title: ART101
Address: 000001D8C371A440
===================================================================
# Name                     Student ID              Address
-------------------------------------------------------------------
1 Key, Jason               000005                  000001D8C37282A0
2 Case, Jan                000011                  000001D8C37287E0
3 Smith, Amy               000001                  000001D8C3729C10
4 Smith, Eric              000012                  000001D8C372C020
5 Richards, Raymond        000013                  000001D8C372C100
===================================================================


Course Title: CIS2361
Address: 000001D8C3727C80
===================================================================
# Name                     Student ID              Address
-------------------------------------------------------------------
1 Harris, Mike             000003                  000001D8C37280E0
2 Gay, Jasmine             000008                  000001D8C3728540
===================================================================


Course Title: CIS2362
Address: 000001D8C3727B60
===================================================================
# Name                     Student ID              Address
-------------------------------------------------------------------
1 Cook, Pat                000009                  000001D8C3728620
2 Smith, Amy               000001                  000001D8C3729C10
===================================================================


Course Title: HIS213
Address: 000001D8C3729DB0
===================================================================
# Name                     Student ID              Address
-------------------------------------------------------------------
1 Jones, Randy             000002                  000001D8C3728000
2 Green, Robert            000007                  000001D8C3728460
===================================================================


Course Title: MTH412
Address: 000001D8C3729ED0
===================================================================
# Name                     Student ID              Address
-------------------------------------------------------------------
1 Johnson, David           000004                  000001D8C37281C0
2 Thomas, Jackie           000006                  000001D8C3728380
3 Cooperman, Sophia        000010                  000001D8C3728700
4 Smith, Amy               000001                  000001D8C3729C10
===================================================================




~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ All Student Schedules ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~


Smith, Amy's Schedule
ID: 000001
Hours: 10
Address: 000001D8C3729C10
========================================
Course Title             Address
----------------------------------------
ART101                   000001D8C371A440
CIS2362                  000001D8C3727B60
MTH412                   000001D8C3729ED0

Jones, Randy's Schedule
ID: 000002
Hours: 3
Address: 000001D8C3728000
========================================
Course Title             Address
----------------------------------------
HIS213                   000001D8C3729DB0

Harris, Mike's Schedule
ID: 000003
Hours: 4
Address: 000001D8C37280E0
========================================
Course Title             Address
----------------------------------------
CIS2361                  000001D8C3727C80

Johnson, David's Schedule
ID: 000004
Hours: 3
Address: 000001D8C37281C0
========================================
Course Title             Address
----------------------------------------
MTH412                   000001D8C3729ED0

Key, Jason's Schedule
ID: 000005
Hours: 3
Address: 000001D8C37282A0
========================================
Course Title             Address
----------------------------------------
ART101                   000001D8C371A440

Thomas, Jackie's Schedule
ID: 000006
Hours: 3
Address: 000001D8C3728380
========================================
Course Title             Address
----------------------------------------
MTH412                   000001D8C3729ED0

Green, Robert's Schedule
ID: 000007
Hours: 3
Address: 000001D8C3728460
========================================
Course Title             Address
----------------------------------------
HIS213                   000001D8C3729DB0

Gay, Jasmine's Schedule
ID: 000008
Hours: 4
Address: 000001D8C3728540
========================================
Course Title             Address
----------------------------------------
CIS2361                  000001D8C3727C80

Cook, Pat's Schedule
ID: 000009
Hours: 4
Address: 000001D8C3728620
========================================
Course Title             Address
----------------------------------------
CIS2362                  000001D8C3727B60

Cooperman, Sophia's Schedule
ID: 000010
Hours: 3
Address: 000001D8C3728700
========================================
Course Title             Address
----------------------------------------
MTH412                   000001D8C3729ED0

Case, Jan's Schedule
ID: 000011
Hours: 3
Address: 000001D8C37287E0
========================================
Course Title             Address
----------------------------------------
ART101                   000001D8C371A440

Smith, Eric's Schedule
ID: 000012
Hours: 3
Address: 000001D8C372C020
========================================
Course Title             Address
----------------------------------------
ART101                   000001D8C371A440

Richards, Raymond's Schedule
ID: 000013
Hours: 3
Address: 000001D8C372C100
========================================
Course Title             Address
----------------------------------------
ART101                   000001D8C371A440

Boone, Peter's Schedule
ID: 000014
Hours: 0
Address: 000001D8C372C1E0
========================================
No Schedule

Davis, Candy's Schedule
ID: 000015
Hours: 0
Address: 000001D8C372E2E0
========================================
No Schedule


===================================================================
           ~~ STUDENT INFORMATION AFTER SCHEDULING ~~
===================================================================
Last Name, First Name    Student ID     Hours      Address
===================================================================
Smith, Amy               000001         10         000001D8C3729C10
Jones, Randy             000002         3          000001D8C3728000
Harris, Mike             000003         4          000001D8C37280E0
Johnson, David           000004         3          000001D8C37281C0
Key, Jason               000005         3          000001D8C37282A0
Thomas, Jackie           000006         3          000001D8C3728380
Green, Robert            000007         3          000001D8C3728460
Gay, Jasmine             000008         4          000001D8C3728540
Cook, Pat                000009         4          000001D8C3728620
Cooperman, Sophia        000010         3          000001D8C3728700
Case, Jan                000011         3          000001D8C37287E0
Smith, Eric              000012         3          000001D8C372C020
Richards, Raymond        000013         3          000001D8C372C100
Boone, Peter             000014         0          000001D8C372C1E0
Davis, Candy             000015         0          000001D8C372E2E0


===================================================================
           ~~ STUDENT INFORMATION AFTER SCHEDULING ~~
===================================================================
Course Name   Credit Hours   Enrolled   Capacity   Address
===================================================================
ART101        3              5          5          000001D8C371A440
CIS2361       4              2          10         000001D8C3727C80
CIS2362       4              2          10         000001D8C3727B60
HIS213        3              2          5          000001D8C3729DB0
MTH412        3              4          10         000001D8C3729ED0