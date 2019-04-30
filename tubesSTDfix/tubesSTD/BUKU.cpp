#include "BUKU.h"

void createListBuku (listBuku &LB)
{
    firstBuku(LB) = NULL;
    lastBuku(LB) = NULL;
}

addressBuku alokasiBuku (infotypeBuku B)
{
    addressBuku P = new elmListBuku;
    infoBuku(P) = B;
    nextBuku(P) = NULL;
    prevBuku(P) = NULL;
    return P;
}

void dealokasiBuku (addressBuku &B)
{
    delete B;
}

void tambahBuku (listBuku &LB, addressBuku B)
{
    if (firstBuku(LB) == NULL)
    {
        firstBuku(LB) = B;
        lastBuku(LB) = B;
    }
    else
    {
        prevBuku(B) = lastBuku(LB);
        nextBuku(lastBuku(LB)) = B;
        lastBuku(LB) = B;
    }
}

void hapusBuku (listBuku &LB, addressBuku B)
{
    addressBuku P = firstBuku(LB);
    if(P == NULL)
    {
        cout << "LIST BUKU KOSONG!" << endl;
    }
    else
    {
        if((firstBuku(LB) == B)&& (lastBuku(LB) == B))
        {
            firstBuku(LB) = NULL;
            lastBuku(LB) = NULL;
        }
        else if(firstBuku(LB) == B)
        {
            firstBuku(LB) = nextBuku(B);
            prevBuku(B) = NULL;
        }
        else if(lastBuku(LB) == B)
        {
            lastBuku(LB) = prevBuku(lastBuku(LB));
            nextBuku(lastBuku(LB)) = NULL;

        }
        else
        {
            nextBuku(prevBuku(B)) = nextBuku(B);
            prevBuku(nextBuku(B)) = prevBuku(B);
        }

    }
}

void PrintListBuku (listBuku LB)
{
    addressBuku B = firstBuku(LB);
    int i = 1;
    cout << "\nLIST BUKU" << endl;
    if(B == NULL)
    {
        cout << "BUKU KOSONG! " << endl;
    }
    while(B != NULL)
    {
        cout << i <<". Kode Buku \t\t: " << infoBuku(B).kodeBuku << endl;
        cout << "   Nama Buku \t\t: " << infoBuku(B).namaBuku << endl;
        cout << "   Penulis Buku \t: " << infoBuku(B).namaPenulis << endl;
        cout << "   Banyak Halaman \t: " <<infoBuku(B).halamanBuku << endl;
        i++;
        B = nextBuku(B);
    }
}

bool cekDuplikatBuku (listBuku LB, string dicari)
{
    addressBuku B = cariBuku(LB, dicari);
    if(B == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

addressBuku cariBuku (listBuku LB, string dicari)
{
    addressBuku B = firstBuku(LB);
    addressBuku output = NULL;
    bool ditemukan = false;
    while(B != NULL && !ditemukan)
    {
        if(infoBuku(B).kodeBuku == dicari)
        {
            output = B;
            ditemukan = true;
        }
        B = nextBuku(B);
    }
    return output;
}


