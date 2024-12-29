## Employee and Department Management System

This project is a system designed to manage employees and departments within a company. The program uses dynamic memory management to store information about employees and departments, add new records, write to files, and read from files. It also enables the analysis of various information about departments and employees.

---

## Table of Contents
1. [Features](#features)
2. [File Structure](#file-structure)
3. [Functions Overview](#functions-overview)
4. [Installation](#installation)

---

## Features
1. **Dynamic Data Management:** Manage employee and department information using dynamic arrays.
2. **Data Persistence:** Save employee and department data to files and read them back.
3. **Analysis and Reporting:** Calculate average salaries, list employees with above-average salaries, and identify the highest-paid employees.
4. **Memory Management:** Free all dynamically allocated memory to prevent memory leaks.

---

## File Structure
-`main.c`: Contains the main function and user interface.
-`Project1.c`: Implements functions for managing employees and departments.
-`Project1.h`: Header file with function prototypes used in Project1.c.
-`employees.txt`: Stores employee data.
-`departments.txt`: Stores department data.
-`makefile`: Contains instructions for compiling and running the program.

---

## Functions Overview

### 1. `createDepartment`
- **Purpose:** Creates a new department and returns a `Department` structure.
- **Details:** Allocates memory for department details and initializes its employee array.

### 2. `createEmployee`
- **Purpose:** Creates a new employee and returns an `Employee` structure.
- **Details:** Allocates memory for employee details, including name, salary, and department code.

### 3. `addEmployeeToDepartment`
- **Purpose:** Adds an employee to the appropriate department.
- **Details:** Matches department codes to ensure the employee is correctly assigned.

### 4. `addEmployeeToArray`
- **Purpose:** Adds a new employee to the employees array.
- **Details:** Dynamically reallocates the array to accommodate the new entry.

### 5. `addDepartmentToArray`
- **Purpose:** Adds a new department to the departments array.
- **Details:** Dynamically reallocates the array to accommodate the new entry.

### 6. `printEmployeeInfo`
- **Purpose:** Displays details of a specific employee.

### 7. `printDepartmentInfo`
- **Purpose:** Displays details of a specific department and its employees.

### 8. `printAllDepartmentsInfo`
- **Purpose:** Prints details of all departments and their employees.

### 9. `calculateDepartmentAverageSalary`
- **Purpose:** Computes the average salary of employees in a department.

### 10. `listAboveAverageSalaryEmployees`
- **Purpose:** Lists employees earning above the average salary in their department.

### 11. `printHighestSalaryEmployees`
- **Purpose:** Identifies and prints the highest-paid employee(s) in each department.

### 12. `updateSalary`
- **Purpose:** Updates salaries of employees who have worked for more than 10 years and are earning below a specified amount.

### 13. `writeToFile`
- **Purpose:** Writes all employee and department information to separate files.

### 14. `readFromFile`
- **Purpose:** Reads employee and department information from files and populates the program's arrays.

### 15. `freeMemory`
- **Purpose:** Frees all dynamically allocated memory used by the program.

---

## Installation
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/ekrem-bas/CP-III-Project.git
   cd CP-III-Project
2. **Compile and Run the Project via Makefile:**
   ```bash
   make
3. **File Management:**
   - Employee and department information will be stored in separate files (employees.txt and departments.txt).
   - Ensure these files exist or will be created in the program’s directory.
  
---
