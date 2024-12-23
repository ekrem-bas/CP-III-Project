#include <stdio.h>
#include <stdlib.h>
#include "Project1.h"

int main(int argc, char const *argv[])
{
    // Command Line Parameters.
    if (argc < 3)
    {
        printf("%s <employees_file> <departments_file>\n", argv[0]);
        return 1;
    }

    // Get Employees and Departments file names from Command Line Parameters.
    const char *employeesFile = argv[1];
    const char *departmentsFile = argv[2];

    // Dynamic Arrays for Departments and Employees.
    Department **departments = NULL;
    Employee **employees = NULL;

    // Read Departments and Employees from files.
    readFromFile(employeesFile, departmentsFile, &employees, &departments);

    // Print information for all departments (Department Name, Department Code, and Employees in the Department).
    printAllDepartmentsInfo(departments);

    // Print the highest salaries in each Department.
    printHighestSalaryEmployees(departments);

    // Print the average salary of Department with code 1001.
    printf("-------------------------------\n");
    printf("The average salary of Department %d: %.2f\n", departments[0]->departmentCode, calculateDepartmentAverageSalary(*departments[0]));
    printf("-------------------------------\n");

    // Update the salaries of employees who have worked for more than 10 years and earn less than the new salary.
    // Ahmet Yılmaz is an employee who has worked for more than 10 years and earns less than the new salary.
    float newSalary = 30000;
    printf("-------------------------------\n");
    printf("The salary update function is executed for employees who earn less than %.2f and have worked for more than 10 years.\n", newSalary);
    printf("-------------------------------\n");
    updateSalary(newSalary, employees);

    // Print the average salary of the Department after updating Ahmet Yılmaz's salary.
    printf("-------------------------------\n");
    printf("The average salary of Department %d after the update: %.2f\n", departments[0]->departmentCode, calculateDepartmentAverageSalary(*departments[0]));
    printf("-------------------------------\n");

    // Print Department information after salary update.
    printAllDepartmentsInfo(departments);

    // Print the highest salaried employees after the salary update.
    printHighestSalaryEmployees(departments);

    // Print employees who earn above average salary in each Department.
    printf("-------------------------------\n");
    printf("Printing employees in Department %d who earn above the average salary...\n", departments[1]->departmentCode);
    printf("-------------------------------\n");
    listAboveAverageSalaryEmployees(*departments[1]);

    // Write the final state of employees and departments to the files.
    writeToFile(employeesFile, departmentsFile, employees, departments);

    // Free allocated memory.
    freeMemory(departments, employees);
    return 0;
}