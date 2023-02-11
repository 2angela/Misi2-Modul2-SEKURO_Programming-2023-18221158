#include "console.h"

void home(Menu M, Riwayat *H) {
    int option;
    printf("----------------------------\n");
    printf("     Warung Kang Roger      \n");
    printf("          Welcome           \n");
    printf("----------------------------\n");
    printf("1. TUTUP\n");
    printf("2. PELANGGAN MASUK\n");
    printf("Masukkan Opsi (1 atau 2): ");
    
    scanInt(&option);
    // tutup
    if (option == 1) {
        riwayat(H);
        printf("Bye, thanks for your visit!\n");
    }
    // pelanggan masuk
    else if (option == 2) { 
        char name[100], temp;
        int input;
        printf("Nama Customer: ");
        // input nama pelanggan
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = '\0';   // replace karakter "\n" dari hasil stdin
        customer(name, M, H);
    }
    else {
        printf("Masukan Anda salah, mohon ulangi.\n");
        home(M, H);
    }
}

void customer(char* name, Menu M, Riwayat *H) {
    printf("--------------------------------------\n");
    printf("Selamat Datang %s!\n", name);
    printf("1. View Menu\n");
    printf("2. Place Order\n");
    printf("3. Exit\n");
    printf("Masukkan Opsi (1, 2, atau 3): ");

    int input;
    scanInt(&input);
    // lihat menu
    if (input == 1) {
        displayMenu(M);
        customer(name, M, H);
    }
    // order
    else if (input == 2) {
        order(M, H, name);
        customer(name, M, H);
    }
    // keluar
    else if (input == 3) {
        home(M, H);
    }
    else {
        printf("Masukan Anda salah, mohon ulangi.\n");
        home(M, H);
    }
}

