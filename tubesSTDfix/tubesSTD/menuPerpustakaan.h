#ifndef MENUPERPUSTAKAAN_H_INCLUDED
#define MENUPERPUSTAKAAN_H_INCLUDED
#include <stdlib.h>
#include <conio.h>
#include "GENRE.h"

void menuTambahGenre(listGenre &LG);
void menuTambahBuku(listGenre &LG);
void menuDetailGenre(listGenre LG);
void menuHapusBuku(listGenre &LG);
void menuHapusGenre(listGenre &LG);
void menuBukuTerbanyak(listGenre &LG);
void menuGenreTerbanyak(listGenre &LG);
void menuHalamanTerbanyak(listGenre &LG);

#endif // MENUPERPUSTAKAAN_H_INCLUDED
