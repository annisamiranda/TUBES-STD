#include "menuPerpustakaan.h"

void menuTambahGenre(listGenre &LG)
{
    infotypeGenre X;
    cout << "MENU TAMBAH GENRE\n" << endl;
    cout << "Nama Genre \t: ";
    cin >> X.namaGenre;
    cout << "Deskripsi Genre : ";
    cin >> X.deskripsiGenre;
    if(cekDuplikatGenre(LG, X.kodeGenre))
    {
        cout << "\nKODE GENRE ADA DUPLIKAT!\n" << endl;
    }
    else
    {
        addressGenre P = alokasiGenre(X);
        createListBuku(isi(P));
        tambahGenre(LG, P);
        cout << "\nINPUT SUKSES!" << endl;
    }
}

void menuTambahBuku(listGenre &LG)
{
    printListGenre(LG);
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout<<endl;
        cout << "PILIH GENRE : ";
        cin >> cari;
        cout << endl;
        addressGenre P = cariGenre(LG, cari);
        if(P != NULL)
        {
            infotypeBuku Buku;
            cout << "Tambah Data Buku" << endl;
            cout << "Kode Buku \t: ";
            cin >> Buku.kodeBuku;
            cout << "Nama Buku \t: ";
            cin >> Buku.namaBuku;
            cout << "Nama Penulis \t: ";
            cin >> Buku.namaPenulis;
            cout << "Banyak Halaman \t: ";
            cin >> Buku.halamanBuku;

            if(!cekDuplikatBuku(isi(P), Buku.kodeBuku))
            {
                addressBuku B = alokasiBuku(Buku);
                tambahBuku(isi(P), B);
                infoGenre(P).banyakBuku++;
                infoGenre(P).totalHalaman+=Buku.halamanBuku;
                cout <<"\nINPUT SUKSES!" << endl;
            }
            else
            {
                cout <<"\nBUKU SUDAH ADA !"<<endl;
            }
        }
    }
    getch();
}

void menuDetailGenre(listGenre LG)
{
    printListGenre(LG);
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"\nPILIH GENRE : ";
        cin >> cari;
        cout << endl;
        addressGenre P = cariGenre(LG, cari);
        system("cls");
        if(P != NULL)
        {
            printDetailGenre(P);
        }
        else
        {
            cout << "GENRE TIDAK DITEMUKAN!" << endl;
        }
    }
}

void menuHapusGenre(listGenre &LG)
{
    printListGenre(LG);
    cout << endl;
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"PILIH GENRE : ";
        cin >> cari;
        addressGenre P = cariGenre(LG, cari);
        system("cls");
        if(P != NULL)
        {
            hapusGenre(LG, P);
            cout << "\nGENRE SUKSES DIHAPUS !" << endl;
        }
        else
        {
            cout << "\nKODE TIDAK DITEMUKAN !" << endl;
        }
    }
}

void menuHapusBuku(listGenre &LG)
{
    printListGenre(LG);
    cout << endl;
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"PILIH GENRE : ";
        cin >> cari;
        cout << endl;
        addressGenre P = cariGenre(LG, cari);
        system("cls");
        if(P != NULL)
        {
            printDetailGenre(P);
            string cariBuk;
            cout <<"\nPILIH KODE BUKU YANG AKAN DIHAPUS : ";
            cin >> cariBuk;
            addressBuku PB = cariBuku(isi(P), cariBuk);
            if(PB != NULL)
            {
                infoGenre(P).banyakBuku--;
                hapusBuku(isi(P), PB);
                cout << "\nBUKU SUKSES DIHAPUS!" << endl;
            }
            else
            {
                cout << "\nBUKU TIDAK ADA!" << endl;
            }
        }
        else
        {
            cout << "\nNAMA TIDAK DITEMUKAN!" << endl;
        }
    }
}

void menuGenreTerbanyak(listGenre &LG)
{
    addressGenre P = genreTerbanyak(LG);
    if(P == NULL)
    {
        cout << "\nDATA GENRE KOSONG!" << endl;
    }
    else
    {
        cout << "GENRE DENGAN BUKU TERBANYAK" << endl;
        cout << endl;
        printDetailGenre(P);
    }
}

void menuHalamanTerbanyak(listGenre &LG)
{
    addressGenre G = halamanTerbanyak(LG);
    if (G == NULL)
    {
        cout << "TIDAK ADA BUKU!" << endl;
    }
    else
    {
        cout << "GENRE DENGAN HALAMAN BUKU TERBANYAK" << endl;
        cout << endl;
        printDetailGenre(G);
        cout << endl;
        cout << "TOTAL HALAMAN : " << infoGenre(G).totalHalaman;
    }
}
