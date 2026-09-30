#include <stdio.h>
#include "suppliers.h"
#include "utilities.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void) {
    Supplier *s;
    if (supplierCount >= MAX_SUPPLIERS) { printf("Supplier limit reached.\n"); return; }
    s = &suppliers[supplierCount];
    s->id = readInt("Supplier ID: ");
    readString("Supplier name: ", s->name, NAME_LEN);
    readString("Supplier contact: ", s->contact, NAME_LEN);
    supplierCount++;
    printf("Supplier added successfully.\n");
}

void listSuppliers(void) {
    int i;
    if (supplierCount == 0) { printf("No suppliers loaded.\n"); return; }
    printf("\n%-8s %-30s %-30s\n", "ID", "Name", "Contact");
    for (i = 0; i < supplierCount; i++)
        printf("%-8d %-30s %-30s\n", suppliers[i].id, suppliers[i].name, suppliers[i].contact);
}

int saveSuppliersText(void) {
    FILE *fp = fopen(DATA_DIR "suppliers.txt", "w");
    int i;
    if (fp == NULL) { perror(DATA_DIR "suppliers.txt"); return 0; }
    for (i = 0; i < supplierCount; i++)
        fprintf(fp, "%d|%s|%s\n", suppliers[i].id, suppliers[i].name, suppliers[i].contact);
    fclose(fp);
    return supplierCount;
}

int loadSuppliersText(void) {
    FILE *fp = fopen(DATA_DIR "suppliers.txt", "r");
    Supplier s;
    int loaded = 0;
    if (fp == NULL) { perror(DATA_DIR "suppliers.txt"); return 0; }
    supplierCount = 0;
    while (supplierCount < MAX_SUPPLIERS && fscanf(fp, "%d|%49[^|]|%49[^\n]\n", &s.id, s.name, s.contact) == 3) {
        suppliers[supplierCount++] = s;
        loaded++;
    }
    fclose(fp);
    return loaded;
}
