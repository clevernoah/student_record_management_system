# Student Record Management System

A simple command-line **Student Record Management System** written in **C**. The program allows users to manage student records by adding, searching, updating, deleting, and displaying student information. Records are stored in a file so that they are available even after the program is closed.

## Features

* Add new student records
* Search for a student by name
* Update a student's name and/or marks
* Delete student records
* Display all student records
* Save records to a file
* Load records automatically when the program starts

## Technologies Used

* C Programming Language
* Standard C Libraries

  * `stdio.h`
  * `string.h`
* File Handling
* Structures
* Arrays
* Functions
* Loops
* Conditional Statements

## Project Structure

```
student_record_management_system/
│
├── main.c
├── student_records.txt
└── README.md
```

## How to Compile

Using GCC:

```
gcc main.c -o student_management
```

## How to Run

### Windows

```
student_management.exe
```

### macOS / Linux

```
./student_management
```

## Menu Options

```
1. Add Student Records
2. Search Student Records
3. Update Student Records
4. Delete Student Records
5. Display Student Records
6. Exit
```

## Concepts Demonstrated

This project demonstrates the following C programming concepts:

* Structures
* Arrays
* Functions
* Loops
* File handling
* String manipulation
* User input handling
* Searching algorithms
* Updating and deleting records
* Data persistence using text files

## Future Improvements

Some features planned for future versions include:

* Student ID generation
* Support for more subjects
* Grade and average calculation
* Sorting student records
* Password-protected administrator access
* Better input validation
* Binary file storage for improved performance

## Author

**Clever Muyanja**

GitHub: https://github.com/clevernoah
