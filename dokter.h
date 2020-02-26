#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include "mainHead.h"

struct infotypeP {
        string namaP;
        int umurP;
        string spesialisP;
        string NIKP;
        string lhr;
        string jdwl;
};
typedef struct ElmListP *addressP;
struct ElmListP{
    infotypeP info;
    addressP next;
};
struct ListP {
    addressP first;
};

void InputP (ListP &LP);
void CreatListP(ListP &LP);
addressP alokasiP(infotypeP P);
void insertFirstP(ListP &LP,addressP A);
void insertAfterP(ListP &LP,addressP Prec,addressP A);
addressP deleteSearchDokter(ListP &LP,infotypeP x);
void insertLastP(ListP &LP,addressP A);
void deleteDokternih(ListP &LP,infotypeP x);
void deleteFirstP(ListP &LP,addressP &A);
void deleteLastP(ListP &LP,addressP &A);
void deleteAfterP(ListP &LP,addressP Prec,addressP &A);
addressP FindElmP(ListP LP,string X);
void dealokasiP(addressP &A);
void Tampldata(ListP L);
void CariDokter(ListP &LP,infotypeP x);
void CariJadwal(ListP &LP,infotypeP X);
#endif // DOKTER_H_INCLUDED
