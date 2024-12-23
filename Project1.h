// Employee Struct
typedef struct
{
    char *employeeName;
    char *employeeSurname;
    unsigned short int departmentCode;
    float salary;
    int hireYear;
} Employee;

// Department Struct
typedef struct
{
    char *departmentName;
    unsigned short int departmentCode;
    Employee **departmentEmployees;
    // Variable to keep the employee count for each department.
    int employeeCount;
} Department;

// A function that takes the relevant values and returns a Department struct.
Department *createDepartment(char *departmentName, unsigned short int departmentCode);

// A function that takes the relevant values and returns an Employee struct.
Employee *createEmployee(char *employeeName, char *employeeSurname, unsigned short int departmentCode, float salary, int hireYear);

// Funciton to add an employee to a department one by one.

void addEmployeeToDepartment(Employee *employee, Department *department);

// A function that adds the newly created struct objects to an array.

void addEmployeeToArray(Employee *employee, Employee ***employees);

void addDepartmentToArray(Department *department, Department ***departments);

// A function that takes an Employee object as a parameter and prints its information.
void printEmployeeInfo(Employee employee);

// A function that takes a Department object as a parameter and prints its information.
void printDepartmentInfo(Department department);

// A function that takes a dynamic array of Department objects as a parameter and prints their information.
void printAllDepartmentsInfo(Department **departments);

// A function that calculates the average salary of employees in a given department.
float calculateDepartmentAverageSalary(Department department);

// A function that lists employees in a given department with salaries above the average.
void listAboveAverageSalaryEmployees(Department department);

// A function that prints the employee with the highest salary in each department.
void printHighestSalaryEmployees(Department **departments);

// A function that takes a salary value as a parameter and updates the salaries of employees
// who have worked for more than 10 years and earn less than this salary to the given value.
void updateSalary(float newSalary, Employee **employees);

// A function that writes all Department and Employee information to a file.
void writeToFile(const char *employeesFileName, const char *departmentsFileName, Employee **employees, Department **departments);

// A function that reads all Department and Employee information from a file into arrays.
void readFromFile(const char *employeesFileName, const char *departmentsFileName, Employee ***employees, Department ***departments);

// Free memory allocated for Departments, Employees, and Employees within Departments.
void freeMemory(Department **departments, Employee **employees);