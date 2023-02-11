#include <stdio.h>
#include <string.h>
#include "history.h"

void scanInt(int *input) {
    char angka[10];
    int i, isDigit = 0;
    fgets(angka, 10, stdin);
    angka[strcspn(angka, "\n")] = '\0';

    // cek apakah semua karakter dalam string merupakan digit
    for (i = 0; i < strlen(angka); i++) {
        if (angka[i] < 48 || angka[i] > 57) {
            isDigit++;
        }
    }

    // jika semua karakter berupa digit, maka dikonversi ke int
    // jika tidak maka nilai input menjadi 0
    if (isDigit == 0) {
        *input = atoi(angka);
    }
    else {
        *input = 0;
    }
}

void order(Menu MENU, Riwayat *History, char* name) {
    int inputID, quantity;
    char temp[10];

    printf("ID Makanan/Minuman: ");
    scanInt(&inputID);
    if (inputID < 1 || inputID > MENU.Count) {
        printf("Menu belum terdaftar.\n");
    }
    else {
        printf("Jumlah: ");
        scanInt(&quantity);
        if (quantity <= 0) {
            printf("Jumlah menu yang dipesan harus berupa angka dan lebih dari 0. Mohon ulangi.\n");
        }
        else {
            addToHistory(MENU, History, inputID-1, quantity, name);
            printf("Menu berhasil dipesan!\n");
        }
    }
}

void addToHistory(Menu MENU, Riwayat *History, int ID, int quantity, char* name) {
    int i = History->Count;
    strcpy(History->Elements[i].custName, name);
    strcpy(History->Elements[i].itemName, MENU.Elements[ID].itemName);
    History->Elements[i].quantity = quantity;
    History->Elements[i].total = MENU.Elements[ID].price * quantity;
    History->Count++;
}

void riwayat(Riwayat *History) {
    char input[10];
    if (History->Count == 0) {
        printf("Tidak Ada Penjualan.\n");
    }
    else {
        printf("----------------------------\n");
        printf("      Riwayat Penjualan     \n");
        printf("----------------------------\n");
        printf("|  Nama Pelanggan  |  Nama Menu  |  Jumlah  |  Total Harga  |\n");
        printf("-------------------------------------------------------------\n");
        int i;
        for (i = 0; i < History->Count; i++) {
            printf("|     %s     |  %s  |  %d  |  %d  |\n", History->Elements[i].custName, History->Elements[i].itemName, History->Elements[i].quantity, History->Elements[i].total);
        }
        printf("Simpan Riwayat Transaksi? (YA/TIDAK): ");

        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0';     // replace karakter "\n" dari hasil stdin

        // strcmp membandingkan 2 string, menghasilkan 0 jika sama
        if (strcmp(input, "YA") == 0) {
            saveHistory(History);
        }
        else if (strcmp(input, "TIDAK") == 0) {
            printf("File tidak disimpan.\n");
        }
        else {
            printf("File tidak disimpan karena masukan salah.\n");
        }
    }
}

void saveHistory(Riwayat *History) {
    char filename[100];
    char file[100] = "../data/";
    
    printf("Masukkan nama file txt (contoh: transaksi.txt): ");
    scanf("%s", &filename);
    strcat(file, filename);

    FILE *fp = fopen(file, "w+");
    if (fp != NULL) {
        int i;
        for (i = 0; i < History->Count; i++) {
            fprintf(fp, "%s\n", History->Elements[i].custName);
            fprintf(fp, "%s\n", History->Elements[i].itemName);
            fprintf(fp, "%d\n", History->Elements[i].quantity);
            fprintf(fp, "%d\n", History->Elements[i].total);
        }
        printf("File berhasil disimpan!\n");
    }
    else {
        printf("File gagal disimpan.\n");
    }
}