#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int readInt(const char *prompt) {
    int value;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clearInputBuffer();
            return value;
        }
        printf("Invalid integer. Try again.\n");
        clearInputBuffer();
    }
}

double readDouble(const char *prompt) {
    double value;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1) {
            clearInputBuffer();
            return value;
        }
        printf("Invalid number. Try again.\n");
        clearInputBuffer();
    }
}

void readString(const char *prompt, char *buffer, int size) {
    int len;
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    len = (int)strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        clearInputBuffer();
    }
}

void pauseScreen(void) {
    char buffer[8];
    printf("\nPress Enter to continue...");
    fgets(buffer, sizeof buffer, stdin);
}
