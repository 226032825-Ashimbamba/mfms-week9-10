#ifndef MFMS_H
#define MFMS_H

#define MAX_EMPLOYEES 100
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100
#define MAX_BUDGETS 100
#define NAME_LEN 50
#define DESC_LEN 100
#define DATA_DIR "data/"

/* Shared records used by the MFMS modules. */
typedef struct {
    int id;
    char name[NAME_LEN];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[NAME_LEN];
    char contact[NAME_LEN];
} Supplier;

typedef struct {
    int id;
    char description[DESC_LEN];
    double value;
} Asset;

typedef struct {
    int id;
    char description[DESC_LEN];
    double amount;
} Budget;

#endif
