#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include <string.h>

#define infoBuku(B) (B)->infoBuku
#define nextBuku(B) (B)->nextBuku
#define prevBuku(B) (B)->prevBuku
#define firstBuku(B) (B).firstBuku
#define lastBuku(B) (B).lastBuku

using namespace std;

struct dataBuku
{
    string namaBuku;
    string namaPenulis;
    string kodeBuku;
    int halamanBuku;
    int banyakBuku;
};

typedef dataBuku infotypeBuku;
typedef struct elmListBuku *addressBuku;

struct elmListBuku
{
    infotypeBuku infoBuku;
    addressBuku nextBuku;
    addressBuku prevBuku;
};

struct listBuku
{
    addressBuku firstBuku;
    addressBuku lastBuku;
};

void createListBuku (listBuku &LB);
addressBuku alokasiBuku (infotypeBuku B);
void dealokasiBuku (addressBuku &B);
void tambahBuku (listBuku &LB, addressBuku B);
void hapusBuku (listBuku &LB, addressBuku B);
void PrintListBuku (listBuku LB);
bool cekDuplikatBuku (listBuku LB, string dicari);
addressBuku cariBuku (listBuku LB, string dicari);

#endif // BUKU_H_INCLUDED
