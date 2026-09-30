#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include "mfms.h"

void addEmployee(void);
void listEmployees(void);
void searchEmployee(void);
double calculatePayrollTotal(void);
int saveEmployeesText(void);
int loadEmployeesText(void);
int saveEmployeesBinary(void);
int loadEmployeesBinary(void);

#endif
