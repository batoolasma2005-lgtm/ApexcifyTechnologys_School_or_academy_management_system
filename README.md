# School or academy management system
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
## 👤 Author

**Name:** Asma Batool
**Internship:** Apexcify Technologys  
**GitHub:** (https://github.com/batoolasma2005-lgtm)  
**Role:** C++ programing
