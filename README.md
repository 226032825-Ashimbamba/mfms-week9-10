# MFMS – Week 9 & 10 Practical

This project implements the Week 9 multi-file programming and Week 10 file-handling requirements from PAP521S.

## Modules
- `main.c/main.h` – application flow and menu.
- `employees.c/employees.h` – employee operations and persistence.
- `budget.c/budget.h` – budget operations and persistence.
- `utilities.c/utilities.h` – reusable input/helper functions.
- `reports.c/reports.h` – reports and summaries.
- `suppliers.c/suppliers.h` – supplier records and text persistence.
- `assets.c/assets.h` – asset records and text persistence.
- `mfms.h` – shared record definitions and constants.
- `data/` – persistent text/binary files created by the program.

## Compile separately
```bash
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c
gcc main.o employees.o budget.o utilities.o reports.o suppliers.o assets.o -o mfms
```

## Or build with Make
```bash
make
./mfms
```

## File handling
Text files:
- `data/employees.txt`
- `data/budgets.txt`
- `data/suppliers.txt`
- `data/assets.txt`

Binary file:
- `data/employees.dat`

The program checks `fopen()` results and uses `fprintf()`, `fscanf()`, `fwrite()` and `fread()` as required by the practical.

## Test runs
1. Add employee(s), list/search them, and generate the employee report.
2. Add budget(s), list them, and generate the budget report.
3. Save text data, exit, reopen, then load text data and verify records return.
4. Save employee records to binary, exit, reopen, load binary data and verify records.
