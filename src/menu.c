#include <stdio.h>
#include "menu.h"

void createMenu(Menu *MENU) {
    int i;
    infotype item;
    char temp;

    (*MENU).Count = 0;
    FILE *fp = fopen("../data/menu.txt", "r");
    for (i = 0; i < totalMenu; i++) {
        fscanf(fp, "%d", &item.ID);
        fscanf(fp, "%c", &temp);
        fscanf(fp,"%[^\n]", &item.itemName);
        fscanf(fp, "%s", &item.category);
        fscanf(fp, "%d", &item.price);
        addToMenu(MENU, item);
    }
    fclose(fp);
}

void addToMenu(Menu *MENU, infotype item) {
    int i = MENU->Count;
    MENU->Elements[i] = item;
    MENU->Count++;
}

void displayMenu(Menu MENU) {
    printf("--------------------------------------\n");
    printf("              DAFTAR MENU             \n");
    printf("--------------------------------------\n");
    printf("[ ID ]  Nama  |  Kategori  |  Harga  |\n");
    int i;
    for (i = 0; i < MENU.Count; i++) {
        printf("[ %d ]  %s  |  %s  |  %d  |\n", MENU.Elements[i].ID, MENU.Elements[i].itemName, MENU.Elements[i].category, MENU.Elements[i].price);
    }
    printf("\n");
}