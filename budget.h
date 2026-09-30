#ifndef BUDGET_H
#define BUDGET_H
#include "mfms.h"

void addBudget(void);
void listBudgets(void);
double calculateBudgetBalance(void);
int saveBudgetsText(void);
int loadBudgetsText(void);

#endif
