#ifndef GENRE_H_INCLUDED
#define GENRE_H_INCLUDED

#include <iostream>
#include <string.h>

#define infoGenre(G) (G)->infoGenre
#define nextGenre(G) (G)->nextGenre
#define prevGenre(G) (G)->prevGenre
#define firstGenre(G) (G).firstGenre
#define lastGenre(G) (G).lastGenre
#define isi(G) (G)->isi

#include "BUKU.h"

using namespace std;

struct dataGenre
{
    string kodeGenre;
    string namaGenre;
    string deskripsiGenre;
    int banyakBuku = 0;
    int totalHalaman = 0;
};

typedef dataGenre infotypeGenre;
typedef struct elmListGenre *addressGenre;

struct elmListGenre
{
    infotypeGenre infoGenre;
    addressGenre nextGenre;
    addressGenre prevGenre;
    listBuku isi;
};

struct listGenre
{
    addressGenre firstGenre;
    addressGenre lastGenre;
};

bool isEmptyGenre(listGenre LG);
void createListGenre (listGenre &LG);
addressGenre alokasiGenre (infotypeGenre G);
void dealokasiGenre (addressGenre &G);
void tambahGenre (listGenre &LG, addressGenre G);
void hapusGenre (listGenre &LG, addressGenre G);
bool cekDuplikatGenre (listGenre LG, string dicari);
addressGenre cariGenre (listGenre LG, string dicari);
addressGenre genreTerbanyak(listGenre LG);
void printListGenre (listGenre LG);
void printDetailGenre(addressGenre G);
addressGenre halamanTerbanyak (listGenre LG);

#endif // GENRE_H_INCLUDED
