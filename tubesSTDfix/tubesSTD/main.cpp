#include "menuPerpustakaan.h"

using namespace std;

int main()
{
    listGenre LG;
    createListGenre(LG);

    int menu;

    while (menu != 0)
    {
        system("cls");
        cout << " = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << " |                DATA PERPUSTAKAAN              |" << endl;
        cout << " = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "" << endl;
        cout << "1. Tambah Genre " << endl;
        cout << "2. Tambah Buku " << endl;
        cout << "3. Lihat List Genre " << endl;
        cout << "4. Lihat Detail Genre " << endl;
        cout << "5. Hapus Genre " << endl;
        cout << "6. Hapus Buku" << endl;
        cout << "7. Lihat Genre Dengan Buku Terbanyak " << endl;
        cout << "8. Lihat Genre Dengan Halaman Buku Terbanyak " << endl;
        cout << "0. Keluar Program "<< endl;
        cout << "\n\nPilih menu : ";
        cin >> menu;

        switch(menu)
        {

        case(1):
            system("cls");
            menuTambahGenre(LG);
            getch();
            break;

        case(2):
            system("cls");
            menuTambahBuku(LG);
            getch;
            break;

        case(3):
            system("cls");
            printListGenre(LG);
            getch();
            break;

        case(4):
            system("cls");
            menuDetailGenre(LG);
            getch();
            break;

        case(5):
            system("cls");
            menuHapusGenre(LG);
            getch();
            break;

        case(6):
            system("cls");
            menuHapusBuku(LG);
            getch();
            break;

        case(7):
            system("cls");
            menuGenreTerbanyak(LG);
            getch();
            break;

        case(8):
            system("cls");
            menuHalamanTerbanyak(LG);
            getch();
            break;

        }
    }
    return 0;
}
