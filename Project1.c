
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Project1.h"

// Total employee and department count for adding to arrays.
int totalEmployeeCount = 0;
int totalDepartmentCount = 0;

// A function that takes the relevant values and returns a Department struct.
Department *createDepartment(char *departmentName, unsigned short int departmentCode)
{
    // Allocate memory for the new department.
    Department *newDepartment = malloc(sizeof(Department));
    // Allocate memory for the provided string and assign it.
    newDepartment->departmentName = strdup(departmentName);
    newDepartment->departmentCode = departmentCode;
    // Allocate space for up to 20 Employees for each department using calloc.
    newDepartment->departmentEmployees = calloc(20, sizeof(Employee));
    // Keep track of each department's employee count.
    newDepartment->employeeCount = 0;
    return newDepartment;
}

// A function that takes the relevant values and returns an Employee struct.
Employee *createEmployee(char *employeeName, char *employeeSurname, unsigned short int departmentCode, float salary, int hireYear)
{
    // Allocate memory for the new employee.
    Employee *newEmployee = malloc(sizeof(Employee));
    // Allocate memory for the provided strings and assign them.
    newEmployee->employeeName = strdup(employeeName);
    newEmployee->employeeSurname = strdup(employeeSurname);
    newEmployee->departmentCode = departmentCode;
    newEmployee->salary = salary;
    newEmployee->hireYear = hireYear;
    return newEmployee;
}

// Function to add an employee to a department.
void addEmployeeToDepartment(Employee *employee, Department *department)
{
    // If the department codes match, add the employee to the department.
    if (employee->departmentCode == department->departmentCode)
    {
        department->departmentEmployees[department->employeeCount] = employee;
        department->employeeCount++;
    }
    else
    {
        printf("Error: \n");
        printf("Add the employee to their correct department!\n");
        printf("Employee's department code: %d, target department code: %d\n", employee->departmentCode, department->departmentCode);
    }
}

// A function to add the newly created structs to an array.
// Add the employee to the array.
void addEmployeeToArray(Employee *employee, Employee ***employees)
{
    // Reallocate memory for the employees array to add a new employee.
    *employees = realloc(*employees, (totalEmployeeCount + 1) * sizeof(Employee *));
    if (*employees == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    (*employees)[totalEmployeeCount] = employee;
    totalEmployeeCount++;
}

void addDepartmentToArray(Department *department, Department ***departments)
{
    *departments = realloc(*departments, (totalDepartmentCount + 1) * sizeof(Department *));
    if (*departments == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    (*departments)[totalDepartmentCount] = department;
    totalDepartmentCount++;
}

// A function that takes an Employee variable as a parameter and prints its information.
void printEmployeeInfo(Employee employee)
{
    printf("-------------------------------\n");
    printf("\t----Employee Info----\n");
    printf("-------------------------------\n");
    printf("- ");
    printf("Employee Name: %s\n", employee.employeeName);
    printf("Employee Surname: %s\n", employee.employeeSurname);
    printf("Employee Department Code: %d\n", employee.departmentCode);
    printf("Employee Salary: %.2f\n", employee.salary);
    printf("Employee Hire Year: %d\n", employee.hireYear);
}

// A function that takes a Department variable as a parameter and prints its information.
void printDepartmentInfo(Department department)
{
    printf("-------------------------------\n");
    printf("\t----Department Info----\n");
    printf("-------------------------------\n");
    printf("Department Name: %s\n", department.departmentName);
    printf("Department Code: %d\n", department.departmentCode);
    printf("Department Employees Info:\n");
    for (int i = 0; i < department.employeeCount; i++)
    {
        printEmployeeInfo(*(department.departmentEmployees[i]));
    }
    printf("-------------------------------\n");
}

// A function that takes a dynamic array of Department variables and prints their information.
void printAllDepartmentsInfo(Department **departments)
{
    for (size_t i = 0; i < totalDepartmentCount; i++)
    {
        printDepartmentInfo(*departments[i]);
    }
}

// A function that calculates the average salary of employees in a given department.
float calculateDepartmentAverageSalary(Department department)
{
    float salarySum = 0;
    for (size_t i = 0; i < department.employeeCount; i++)
    {
        salarySum += department.departmentEmployees[i]->salary;
    }
    return salarySum / department.employeeCount;
}

// A function that lists employees in a given department with salaries above the average.
void listAboveAverageSalaryEmployees(Department department)
{
    printf("-------------------------------\n");
    printf("\t----Above Average Salaries----\n");
    printf("\t----Department: %d----\n", department.departmentCode);
    printf("  Department Average Salary: %.2f\n", calculateDepartmentAverageSalary(department));
    printf("-------------------------------\n");
    float averageSalary = calculateDepartmentAverageSalary(department);
    for (size_t i = 0; i < department.employeeCount; i++)
    {
        if (department.departmentEmployees[i]->salary > averageSalary)
        {
            printEmployeeInfo(*(department.departmentEmployees[i]));
            printf("-------------------------------\n");
        }
    }
}

// A function that prints the employee with the highest salary in each department.
void printHighestSalaryEmployees(Department **departments)
{
    printf("-------------------------------\n");
    printf("\t----Highest Salaries----\n");
    printf("-------------------------------\n");

    for (size_t i = 0; i < totalDepartmentCount; i++)
    {
        printf("Department Name: %s\n", departments[i]->departmentName);
        printf("Department Code: %d\n", departments[i]->departmentCode);
        printf("Highest Paid Employee(s):\n");
        printf("-------------------------------\n");

        float highestSalary = 0;
        for (size_t j = 0; j < departments[i]->employeeCount; j++)
        {
            if (departments[i]->departmentEmployees[j]->salary > highestSalary)
            {
                highestSalary = departments[i]->departmentEmployees[j]->salary;
            }
        }

        for (size_t j = 0; j < departments[i]->employeeCount; j++)
        {
            if (departments[i]->departmentEmployees[j]->salary == highestSalary)
            {
                printEmployeeInfo(*(departments[i]->departmentEmployees[j]));
            }
        }
        printf("-------------------------------\n");
    }
}

// A function that takes a salary value as a parameter and updates the salary
// of employees who have worked for more than 10 years and are earning less
// than the given salary to match the provided salary.
void updateSalary(float newSalary, Employee **employees)
{
    // Current year information.
    int year = 2024;
    // Iterate through all employees.
    for (size_t i = 0; i < totalEmployeeCount; i++)
    {
        // If the i-th employee has worked for more than 10 years and earns less than the new salary, update their salary.
        if (year - employees[i]->hireYear > 10 && employees[i]->salary < newSalary)
        {
            employees[i]->salary = newSalary;
        }
    }
}

// A function that writes all Department and Employee information to a file.
void writeToFile(const char *employeesFileName, const char *departmentsFileName, Employee **employees, Department **departments)
{
    // Notify that the file writing process has started.
    printf("-------------------------------\n");
    printf("Starting the file writing process...\n");

    // File pointers.
    FILE *employeesFile = fopen(employeesFileName, "w");
    FILE *departmentsFile = fopen(departmentsFileName, "w");

    // Return an error if the files cannot be opened.
    if (employeesFile == NULL || departmentsFile == NULL)
    {
        perror("Files Could Not Be Opened");
        return;
    }

    // Loop to write all employees to the file.
    for (int i = 0; i < totalEmployeeCount; i++)
    {
        if (employees[i] != NULL)
        {
            fprintf(employeesFile, "%s;%s;%d;%.2f;%d;\n",
                    employees[i]->employeeName,
                    employees[i]->employeeSurname,
                    employees[i]->departmentCode,
                    employees[i]->salary,
                    employees[i]->hireYear);
        }
    }

    // Close the file after writing is complete.
    fclose(employeesFile);

    // Loop to write all Departments to the file.
    for (int i = 0; i < totalDepartmentCount; i++)
    {
        if (departments[i] != NULL)
        {
            fprintf(departmentsFile, "%s;%d;\n", departments[i]->departmentName, departments[i]->departmentCode);
        }
    }

    // Close the file after writing is complete.
    fclose(departmentsFile);

    // Notify that the information was successfully written.
    printf("Information has been successfully written to the files!\n");
    printf("-------------------------------\n");
}

/*
    12. A function that reads all Department and Employee information from files and transfers it to arrays.
*/
void readFromFile(const char *employeesFileName, const char *departmentsFileName, Employee ***employees, Department ***departments)
{
    // Notify that the file reading process has started.
    printf("-------------------------------\n");
    printf("Starting the file reading process...\n");

    // File pointers.
    FILE *employeesFile = fopen(employeesFileName, "r");
    FILE *departmentsFile = fopen(departmentsFileName, "r");

    // Return an error if the files cannot be opened.
    if (employeesFile == NULL || departmentsFile == NULL)
    {
        perror("Files Could Not Be Opened");
        return;
    }

    // Variable to hold each line.
    char line[256];

    // Read Departments from the file.
    while (fgets(line, sizeof(line), departmentsFile))
    {
        char departmentName[256];
        int departmentCode;
        // Parse using sscanf.
        if (sscanf(line, "%[^;];%d;", departmentName, &departmentCode) == 2)
        {
            // If parsing is successful, create a new Department and add it to the Departments array.
            Department *newDepartment = createDepartment(departmentName, departmentCode);
            addDepartmentToArray(newDepartment, departments);
        }
    }

    // Close the file after reading is complete.
    fclose(departmentsFile);

    // Read employees from the file.
    while (fgets(line, sizeof(line), employeesFile))
    {
        char employeeFirstName[256];
        char employeeLastName[256];
        int departmentCode;
        float salary;
        int hireDate;

        // Parse using sscanf.
        if (sscanf(line, "%[^;];%[^;];%d;%f;%d;", employeeFirstName, employeeLastName, &departmentCode, &salary, &hireDate) == 5)
        {
            // If parsing is successful, create a new employee and add it to the employees array.
            Employee *newEmployee = createEmployee(employeeFirstName, employeeLastName, departmentCode, salary, hireDate);
            addEmployeeToArray(newEmployee, employees);
        }
    }

    // Close the file after reading is complete.
    fclose(employeesFile);

    // Add employees to their respective Departments.
    for (int i = 0; i < totalDepartmentCount; i++)
    {
        for (int j = 0; j < totalEmployeeCount; j++)
        {
            // If the i-th Department's code matches the j-th employee's Department code, add the employee to the Department.
            if ((*departments)[i]->departmentCode == (*employees)[j]->departmentCode)
            {
                addEmployeeToDepartment((*employees)[j], (*departments)[i]);
            }
        }
    }

    // Notify that the file reading process was successful.
    printf("File reading process completed successfully!\n");
    printf("-------------------------------\n");
}

// Free memory for Departments, Employees, and Employees within Departments.
void freeMemory(Department **departments, Employee **employees)
{
    for (int i = 0; i < totalDepartmentCount; i++)
    {
        free(departments[i]->departmentName);      // Free memory allocated for Department name
        free(departments[i]->departmentEmployees); // Free memory allocated for Department employees
        free(departments[i]);                      // Free the Department object in the Departments array
    }
    free(departments); // Free the Departments array.

    for (int i = 0; i < totalEmployeeCount; i++)
    {
        free(employees[i]->employeeName);    // Free memory allocated for employee first name
        free(employees[i]->employeeSurname); // Free memory allocated for employee last name
        free(employees[i]);                  // Free the employee object in the employees array
    }
    free(employees); // Free the employees array.
}