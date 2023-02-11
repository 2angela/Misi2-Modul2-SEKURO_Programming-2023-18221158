#include "menu.h"

#define MaxElmt 100

typedef struct {
    char custName[100];
    char itemName[100];
    int quantity;
    int total;
} infotype2;

typedef struct {
    infotype2 Elements[MaxElmt];
    int Count;
} Riwayat;

// Prosedur membaca masukan dari pengguna. Masukan berupa int disimpan pada variabel input.
void scanInt(int *input);

// Prosedur membeli makanan/minuman
void order(Menu MENU, Riwayat *History, char* name);

// Prosedur menambahkan pesanan ke riwayat penjualan
void addToHistory(Menu MENU, Riwayat *History, int ID, int quantity, char* name);

// Prosedur menampilkan daftar riwayat pesanan dari semua pelanggan
void riwayat(Riwayat *History);

// Prosedur menyimpan riwayat pesanan ke sebuah file txt. File riwayat pesanan disimpan pada folder data.
void saveHistory(Riwayat *History);