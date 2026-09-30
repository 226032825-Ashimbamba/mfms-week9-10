#include <stdio.h>
#include "assets.h"
#include "utilities.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void) {
    Asset *a;
    if (assetCount >= MAX_ASSETS) { printf("Asset limit reached.\n"); return; }
    a = &assets[assetCount];
    a->id = readInt("Asset ID: ");
    readString("Asset description: ", a->description, DESC_LEN);
    a->value = readDouble("Asset value: ");
    assetCount++;
    printf("Asset added successfully.\n");
}

void listAssets(void) {
    int i;
    if (assetCount == 0) { printf("No assets loaded.\n"); return; }
    printf("\n%-8s %-45s %12s\n", "ID", "Description", "Value");
    for (i = 0; i < assetCount; i++)
        printf("%-8d %-45s %12.2f\n", assets[i].id, assets[i].description, assets[i].value);
}

int saveAssetsText(void) {
    FILE *fp = fopen(DATA_DIR "assets.txt", "w");
    int i;
    if (fp == NULL) { perror(DATA_DIR "assets.txt"); return 0; }
    for (i = 0; i < assetCount; i++)
        fprintf(fp, "%d|%s|%.2f\n", assets[i].id, assets[i].description, assets[i].value);
    fclose(fp);
    return assetCount;
}

int loadAssetsText(void) {
    FILE *fp = fopen(DATA_DIR "assets.txt", "r");
    Asset a;
    int loaded = 0;
    if (fp == NULL) { perror(DATA_DIR "assets.txt"); return 0; }
    assetCount = 0;
    while (assetCount < MAX_ASSETS && fscanf(fp, "%d|%99[^|]|%lf\n", &a.id, a.description, &a.value) == 3) {
        assets[assetCount++] = a;
        loaded++;
    }
    fclose(fp);
    return loaded;
}
