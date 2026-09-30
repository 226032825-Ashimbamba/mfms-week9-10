#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void) {
    printf("\nEmployee Report\n");
    listEmployees();
    printf("Total payroll: %.2f\n", calculatePayrollTotal());
}

void budgetReport(void) {
    printf("\nBudget Report\n");
    listBudgets();
    printf("Total budget amount: %.2f\n", calculateBudgetBalance());
}

void fullReport(void) {
    employeeReport();
    budgetReport();
}
