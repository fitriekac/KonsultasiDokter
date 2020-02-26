#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "pasien.h"
#include "mainHead.h"
#include "dokter.h"

typedef struct ElmListR *addressR;
struct ElmListR {
    addressR next;
    addressR prev;
    addressP toP;
    addressC toC;
};
struct ListR {
    addressR first;
    addressR last;
};
void createListR(ListR &LR);
addressR alokasiR (addressP P,addressC C);
void dealokasiR(addressR X);
void InsertLastR (ListR &LR,addressR R);
void deleteFirstR(ListR &LR,addressR &R);
void deleteLastR(ListR &LR, addressR &R);
void deleteAfterR(ListR &LR,addressR Prec,addressR &R);
void deleteR (ListR &LR,addressR &P);
void deleteRelasi (ListR &LR,addressR &Q);
void deleteSearchR(ListR &LR,addressR &Q);
void printINFOR(ListR &LR);
void deletePasien (ListR &LR,ListC &LC,addressC &Q);
void deleteDokter (ListR &LR,ListP &LP,addressP &PJ);

void SearchPasien(ListC &LC,ListR &LR,addressC Q);
void searchDokter ( ListP &LP,ListR LR,addressP PJ);

addressR FindR (ListR &LR,addressP P,addressC C);

void pasientodokter(ListR LR);

#endif // RELASI_H_INCLUDED
