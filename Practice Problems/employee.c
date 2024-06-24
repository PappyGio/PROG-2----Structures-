/*
Create a structure named "Employee" to store employee details such as employee ID, name, and salary. 
Write a program to input data for three employees, find the highest salary employee, and display their information.

*/


#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int employeeID;
    char name[100];
    float salary;
};

// Function to input data for an employee
void inputEmployeeData(struct Employee *emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &emp->employeeID);
    printf("Enter Employee Name: ");
    getchar(); // To consume the newline character left in the input buffer
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0'; // Remove the trailing newline character
    printf("Enter Employee Salary: ");
    scanf("%f", &emp->salary);
}

// Function to display employee data
void displayEmployeeData(struct Employee emp) {
    printf("Employee ID: %d\n", emp.employeeID);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);
}

int main() {
    // Array to hold three employees
    struct Employee employees[3];

    // Input data for three employees
    for (int i = 0; i < 3; ++i) {
        printf("Enter details for employee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
    }

    // Find the employee with the highest salary
    int highestSalaryIndex = 0;
    for (int i = 1; i < 3; ++i) {
        if (employees[i].salary > employees[highestSalaryIndex].salary) {
            highestSalaryIndex = i;
        }
    }

    // Display the employee with the highest salary
    printf("\nEmployee with the highest salary:\n");
    displayEmployeeData(employees[highestSalaryIndex]);

    return 0;
}
