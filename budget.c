#include <stdio.h>
#include "budget.h"
#include "utilities.h"

static Budget budgets[MAX_BUDGETS];
static int budgetCount = 0;

void addBudget(void) {
    Budget *b;
    if (budgetCount >= MAX_BUDGETS) { printf("Budget limit reached.\n"); return; }
    b = &budgets[budgetCount];
    b->id = readInt("Budget ID: ");
    readString("Budget description: ", b->description, DESC_LEN);
    b->amount = readDouble("Budget amount: ");
    budgetCount++;
    printf("Budget added successfully.\n");
}

void listBudgets(void) {
    int i;
    if (budgetCount == 0) { printf("No budgets loaded.\n"); return; }
    printf("\n%-8s %-35s %12s\n", "ID", "Description", "Amount");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < budgetCount; i++)
        printf("%-8d %-35s %12.2f\n", budgets[i].id, budgets[i].description, budgets[i].amount);
}

double calculateBudgetBalance(void) {
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++) total += budgets[i].amount;
    return total;
}

int saveBudgetsText(void) {
    FILE *fp = fopen(DATA_DIR "budgets.txt", "w");
    int i;
    if (fp == NULL) { perror(DATA_DIR "budgets.txt"); return 0; }
    for (i = 0; i < budgetCount; i++)
        fprintf(fp, "%d|%s|%.2f\n", budgets[i].id, budgets[i].description, budgets[i].amount);
    fclose(fp);
    return budgetCount;
}

int loadBudgetsText(void) {
    FILE *fp = fopen(DATA_DIR "budgets.txt", "r");
    Budget b;
    int loaded = 0;
    if (fp == NULL) { perror(DATA_DIR "budgets.txt"); return 0; }
    budgetCount = 0;
    while (budgetCount < MAX_BUDGETS && fscanf(fp, "%d|%99[^|]|%lf\n", &b.id, b.description, &b.amount) == 3) {
        budgets[budgetCount++] = b;
        loaded++;
    }
    fclose(fp);
    return loaded;
}
