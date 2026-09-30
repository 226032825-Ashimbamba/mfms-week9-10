#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void) {
    Employee *e;
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached.\n");
        return;
    }
    e = &employees[employeeCount];
    e->id = readInt("Employee ID: ");
    readString("Employee name: ", e->name, NAME_LEN);
    e->salary = readDouble("Salary: ");
    employeeCount++;
    printf("Employee added successfully.\n");
}

void listEmployees(void) {
    int i;
    if (employeeCount == 0) {
        printf("No employees loaded.\n");
        return;
    }
    printf("\n%-8s %-30s %12s\n", "ID", "Name", "Salary");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < employeeCount; i++) {
        printf("%-8d %-30s %12.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void searchEmployee(void) {
    int id = readInt("Enter employee ID to search: ");
    int i;
    for (i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Found: ID=%d | Name=%s | Salary=%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

double calculatePayrollTotal(void) {
    double total = 0.0;
    int i;
    for (i = 0; i < employeeCount; i++) total += employees[i].salary;
    return total;
}

int saveEmployeesText(void) {
    FILE *fp = fopen(DATA_DIR "employees.txt", "w");
    int i;
    if (fp == NULL) { perror(DATA_DIR "employees.txt"); return 0; }
    for (i = 0; i < employeeCount; i++)
        fprintf(fp, "%d|%s|%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    fclose(fp);
    return employeeCount;
}

int loadEmployeesText(void) {
    FILE *fp = fopen(DATA_DIR "employees.txt", "r");
    Employee e;
    int loaded = 0;
    if (fp == NULL) { perror(DATA_DIR "employees.txt"); return 0; }
    employeeCount = 0;
    while (employeeCount < MAX_EMPLOYEES && fscanf(fp, "%d|%49[^|]|%lf\n", &e.id, e.name, &e.salary) == 3) {
        employees[employeeCount++] = e;
        loaded++;
    }
    fclose(fp);
    return loaded;
}

int saveEmployeesBinary(void) {
    FILE *fp = fopen(DATA_DIR "employees.dat", "wb");
    size_t written;
    if (fp == NULL) { perror(DATA_DIR "employees.dat"); return 0; }
    written = fwrite(employees, sizeof employees[0], (size_t)employeeCount, fp);
    fclose(fp);
    return (int)written;
}

int loadEmployeesBinary(void) {
    FILE *fp = fopen(DATA_DIR "employees.dat", "rb");
    size_t loaded;
    if (fp == NULL) { perror(DATA_DIR "employees.dat"); return 0; }
    loaded = fread(employees, sizeof employees[0], MAX_EMPLOYEES, fp);
    employeeCount = (int)loaded;
    fclose(fp);
    return employeeCount;
}
