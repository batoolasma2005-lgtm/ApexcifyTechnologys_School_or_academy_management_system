# School or Academy Management System
## About the Project

This is a C++ based Registrar Portal System developed as part of my internship at Apexcify Technology.
It simulates a basic university system with user enrollment, login authentication, and grade management using file handling.

The system stores user data in files and allows faculty members to log in and manage student grades.

## Objective

#### The main objective of this project is to:

- Create a simple authentication system
- Allow user enrollment (registration)
- Implement login with password verification
- Track failed login attempts (security lock concept)
- Store and manage student grades
- Display student transcript from file
## Features
- User Enrollment System
- Secure Login System
- Password stored in file
- Failed login attempt counter (lockout logic)
- Faculty dashboard after login
- Add student grades
- Store grades in CSV file (MASTER_GRADES.csv)
- View student transcript by ID
- Session-based system
## Concepts Used
- C++ Programming
- File Handling (ifstream, ofstream)
- String manipulation
- Loops and conditionals
- Struct usage
- Authentication logic
- CSV file storage system
- Basic security logic (login attempts)
## Sample Features Flow
##### Enrollment
-> Create new username<br>
-> Set password<br>
->Data saved in local file<br>
##### Login System
-> Enter ID + password<br>
-> 3 failed attempts → warning lock system<br>
##### Faculty Portal

After login:

->Input student grades<br>
->Store in MASTER_GRADES.csv<br>
->View student transcript by ID<br>
## Files Used
- ID_username.dbf → Stores user login data
- MASTER_GRADES.csv → Stores all student grades

## Authentication
- File-based database handling
- Data logging and retrieval
## Sample Output
----------------------------------------
  REGISTRAR PORTAL - DISTRICT 7 [v2.1]<br>
  1) Enrollment<br>
  2) Faculty Login<br>
  3) Exit System<br>
  Selection > 1<br>

[ENROLLMENT]<br>
Username: ali123<br>
Password (6+ chars): 123456<br>
[+] Account saved.<br>
#### Login Example
Selection > 2<br>

[LOGIN]<br>
ID: ali123<br>
KEY: 123456<br>
Welcome, ali123 | Mon Jan 1 12:00:00 2026<br>
#### Faculty Portal
PORTAL: ali123<br>
 1. Input Grade<br>
 2. View Transcript<br>
 3. Logout<br>
 >> 1<br>

Student ID: S101<br>
Grade: 3.5<br>
>> Grade logged.<br>
#### View Transcript
>> 2<br>
Enter Student ID to view: S101<br>

-- Transcript for S101 --<br>
 > S101,3.5,ali123<br>
#### Exit
Selection > 3<br>
Closing system...<br>
## 👤 Author

**Name:** Asma Batool
**Internship:** Apexcify Technologys  
**GitHub:** (https://github.com/batoolasma2005-lgtm)  
**Role:** C++ programing
