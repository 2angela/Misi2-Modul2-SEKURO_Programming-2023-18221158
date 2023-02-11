#define MaxElmt 100
#define totalMenu 10   // total menu di menu.txt

typedef struct {
    int ID;
    char itemName[100];
    char category[100];
    int price;
} infotype;

typedef struct {
    infotype Elements[MaxElmt];
    int Count;
} Menu;

/* Prosedur membaca file menu.txt dan iterasi menambahkan semua
makanan/minuman ke dalam Menu melalui prosedur addToMenu. */
void createMenu(Menu *MENU);

// Prosedur menambahkan satu makanan/minuman ke dalam Menu.
void addToMenu(Menu *MENU, infotype item);

// Prosedur menampilkan daftar menu ke layar.
void displayMenu(Menu MENU);
