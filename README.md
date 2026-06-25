# Student Data Management using Single Linked List

This repository contains a C program for managing student records using a singly linked list.

## Main file
- `student data managment using single linked list.c`

## Features
- Load student records from `student.csv`
- Add a new student record
- Delete a student record by roll number or by name
- Modify student details (roll number, name, marks)
- Display all student records
- Save the linked list back to `student.csv`

## Program structure
- `struct stu`: Represents a student record with `rollno`, `name`, `marks`, and `next` pointer.
- `main()`: Reads existing records from `student.csv`, builds the linked list, and enters an interactive menu loop.
- `add()`: Appends a new student node to the linked list.
- `delete()`: Removes a node either by roll number or after choosing from matching names.
- `modify()`: Updates a record's roll number or name and marks.
- `save()`: Writes the current linked list back to `student.csv`.
- `show()`: Prints all student records to the console.

## Usage
1. Compile the program with a C compiler such as `gcc`:
   ```bash
   gcc "student data managment using single linked list.c" -o student_data_management
   ```
2. Run the compiled executable:
   ```bash
   ./student_data_management
   ```
3. Use the menu options to add, delete, show, modify, or save records.

## Notes
- The program expects `student.csv` to exist and contain a header row.
- There is minimal input validation and error handling.
- Deleting a record can reuse the deleted roll number for the next added student.
- The program currently does not free all allocated memory on exit.

## Repository
This repository was created remotely as `Student-Data-Management` and includes the source file with linked list-based student management.
