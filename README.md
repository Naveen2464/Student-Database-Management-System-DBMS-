# Student Record Management System

## Overview

The Student Record Management System is a menu-driven application developed in C for managing student information efficiently. The system uses dynamic memory allocation to store records and provides file handling capabilities to save and retrieve data from both text and binary files.

This project demonstrates the practical implementation of data structures, dynamic memory management, file operations, and modular programming concepts in C.

---

## Problem Statement

Develop a Student Record Management System that dynamically manages student records and provides persistent storage using text and binary files. The system should support adding, displaying, searching, deleting, saving, and loading student information while efficiently managing memory resources.

---

## Features

* Add new student records
* Display all student records
* Search student records using Roll Number
* Delete student records
* Save records to a text file
* Load records from a text file
* Save records to a binary file
* Load records from a binary file
* Dynamic memory allocation using malloc() and realloc()
* Proper memory deallocation using free()

---

## Student Information Stored

Each student record contains:

* Roll Number
* Name
* Age
* Marks

---

## Technologies Used

* Programming Language: C
* Dynamic Memory Allocation
* Structures
* File Handling
* Modular Programming

---

## Files Used

### Text File

student_records.txt

Used for storing student records in human-readable format.

### Binary File

student_records.bin

Used for storing student records in binary format for efficient storage and retrieval.

---

## Functions Implemented

### init_sl()

Initializes the student list and allocates initial memory.

### resize_sl()

Dynamically increases storage capacity when the list becomes full.

### add_sr()

Adds a new student record.

### display_srs()

Displays all student records.

### search_sr()

Searches for a student using Roll Number.

### delete_sr()

Deletes a student record using Roll Number.

### save_srs()

Saves records to a text file.

### load_srs()

Loads records from a text file.

### save_srs_bin()

Saves records to a binary file.

### load_srs_bin()

Loads records from a binary file.

### free_sl()

Releases dynamically allocated memory.

---

## Menu Options

1. Add Student Record
2. Display All Student Records
3. Search Student Record by Roll Number
4. Delete Student Record by Roll Number
5. Save Student Records to Text File
6. Load Student Records from Text File
7. Save Student Records to Binary File
8. Load Student Records from Binary File
9. Exit

---

## Compilation

Using GCC Compiler:

```bash
gcc student_record_management.c -o student_record_management
```

---

## Execution

```bash
./student_record_management
```

For Windows:

```bash
student_record_management.exe
```

---

## Concepts Demonstrated

* Structures
* Dynamic Memory Allocation
* Dynamic Arrays
* File Handling
* Binary File Operations
* Searching Techniques
* Memory Management
* Menu-Driven Programming

---

## Future Enhancements

* Record Update Functionality
* Sorting Student Records
* Multiple Search Criteria
* Data Validation
* Password Protection
* Graphical User Interface

---

## Author

Developed as a C Programming Project for demonstrating dynamic memory allocation and file handling concepts.
