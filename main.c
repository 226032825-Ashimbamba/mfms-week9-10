#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utilities.h"

void displayMainMenu(void) {
    printf("\n========================================\n");
    printf(" Municipal Financial Management System\n");
    printf("========================================\n");
    printf("1. Add employee\n");
    printf("2. List employees\n");
    printf("3. Search employee\n");
    printf("4. Add budget\n");
    printf("5. List budgets\n");
    printf("6. Add supplier\n");
    printf("7. List suppliers\n");
    printf("8. Add asset\n");
    printf("9. List assets\n");
    printf("10. Employee report\n");
    printf("11. Budget report\n");
    printf("12. Save all text data\n");
    printf("13. Load all text data\n");
    printf("14. Save employees as binary\n");
    printf("15. Load employees from binary\n");
    printf("0. Exit\n");
}

int main(void) {
    int choice;
    int count;
    do {
        displayMainMenu();
        choice = readInt("Choose an option: ");
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: addBudget(); break;
            case 5: listBudgets(); break;
            case 6: addSupplier(); break;
            case 7: listSuppliers(); break;
            case 8: addAsset(); break;
            case 9: listAssets(); break;
            case 10: employeeReport(); break;
            case 11: budgetReport(); break;
            case 12:
                printf("Employees saved: %d\n", saveEmployeesText());
                printf("Suppliers saved: %d\n", saveSuppliersText());
                printf("Assets saved: %d\n", saveAssetsText());
                printf("Budgets saved: %d\n", saveBudgetsText());
                break;
            case 13:
                count = loadEmployeesText(); printf("Employees loaded: %d\n", count);
                count = loadSuppliersText(); printf("Suppliers loaded: %d\n", count);
                count = loadAssetsText(); printf("Assets loaded: %d\n", count);
                count = loadBudgetsText(); printf("Budgets loaded: %d\n", count);
                break;
            case 14: printf("Employees written to binary file: %d\n", saveEmployeesBinary()); break;
            case 15: printf("Employees loaded from binary file: %d\n", loadEmployeesBinary()); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);
    return EXIT_SUCCESS;
}
