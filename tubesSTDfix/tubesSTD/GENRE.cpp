#include "GENRE.h"

bool isEmptyGenre(listGenre LG)
{
    addressGenre P = firstGenre(LG);
    if  (P == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListGenre(listGenre &LG)
{
    firstGenre(LG) = NULL;
    lastGenre(LG) = NULL;
}

addressGenre alokasiGenre (infotypeGenre G)
{
    addressGenre E = new elmListGenre;
    infoGenre(E) = G;
    nextGenre(E) = NULL;
    prevGenre(E) = NULL;
    return E;
}

void dealokasiGenre (addressGenre &G)
{
    delete G;
}

void tambahGenre (listGenre &LG, addressGenre G)
{
    if (firstGenre(LG) == NULL)
    {
        firstGenre(LG) = G;
        lastGenre(LG) = G;
    }
    else
    {
        prevGenre(G) = lastGenre(LG);
        nextGenre(lastGenre(LG)) = G;
        lastGenre(LG) = G;
    }
}

void hapusGenre(listGenre &LG, addressGenre G)
{
    addressGenre E = firstGenre(LG);
    if(E == NULL)
    {
        cout << "LIST GENRE KOSONG!" << endl;
    }
    else
    {
        if((firstGenre(LG) == G)&& (lastGenre(LG) == G))
        {
            firstGenre(LG) = NULL;
            lastGenre(LG) = NULL;
        }
        else if(firstGenre(LG) == G)
        {
            firstGenre(LG) = nextGenre(G);
            prevGenre(G) = NULL;
        }
        else if(lastGenre(LG) == G)
        {
            lastGenre(LG) = prevGenre(lastGenre(LG));
            nextGenre(lastGenre(LG)) = NULL;

        }
        else
        {
            nextGenre(prevGenre(G)) = nextGenre(G);
            prevGenre(nextGenre(G)) = prevGenre(G);
        }

    }
}

bool cekDuplikatGenre (listGenre LG, string dicari)
{
    addressGenre G = cariGenre(LG, dicari);
    if(G == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

addressGenre cariGenre (listGenre LG, string dicari)
{
    addressGenre G = firstGenre(LG);
    addressGenre output = NULL;
    bool ditemukan = false;
    while(G != NULL && !ditemukan)
    {
        if(infoGenre(G).namaGenre == dicari)
        {
            output = G;
            ditemukan = true;
        }
        G = nextGenre(G);
    }
    return output;
}

addressGenre genreTerbanyak(listGenre LG)
{
    addressGenre G = firstGenre(LG);
    addressGenre maxGenre = G;
    while(G != NULL)
    {
        if(infoGenre(maxGenre).banyakBuku <= infoGenre(G).banyakBuku)
        {
            maxGenre = G;
        }
        G = nextGenre(G);
    }
    return maxGenre;
}

void printListGenre(listGenre LG)
{
    addressGenre G = firstGenre(LG);
    int i = 1;
    cout << "LIST GENRE" << endl;
    cout << endl;
    if (G == NULL)
    {
        cout << "GENRE KOSONG! " << endl;
    }
    while (G != NULL)
    {
        cout << i << ". Nama Genre\t\t: " << infoGenre(G).namaGenre << endl;
        cout << "   Deskripsi Genre\t: " << infoGenre(G).deskripsiGenre << endl;
        i++;
        G = nextGenre(G);
    }
}

void printDetailGenre(addressGenre G)
{
    cout << "DETAIL GENRE" << endl;
    cout << "Nama Genre \t\t: " << infoGenre(G).namaGenre << endl;
    cout << "Deskripsi Genre \t: " << infoGenre(G).deskripsiGenre << endl;
    cout << "Banyak Buku \t\t: " << infoGenre(G).banyakBuku << endl;
    listBuku(LB) = isi(G);
    PrintListBuku(LB);
}

addressGenre halamanTerbanyak(listGenre LG)
{
    addressGenre G = firstGenre(LG);
    addressGenre Banyak = G;
    while (G != NULL)
    {
        if (infoGenre(Banyak).totalHalaman <= infoGenre(G).totalHalaman)
        {
            Banyak = G;
        }
        G = nextGenre(G);
    }
    return Banyak;
}
