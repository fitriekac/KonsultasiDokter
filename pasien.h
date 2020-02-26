#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include "mainHead.h"

struct infotypeC {
        string namaC;
        int umurC;
        string sakitC;
        string hariC;
        string klmnC;
        string rpenyakitC;
        string lahirC;
};
typedef struct ElmList *addressC;
struct ElmList {
    infotypeC info;
    addressC next;
};
struct ListC {
    addressC first;
    addressC last;
};

void CreatListC(ListC &LC);
addressC alokasiC(infotypeC x);

void insertFirstC(ListC &LC,addressC X);
void insertAfterC(ListC &LC,addressC Prec,addressC X);
void insertLastC(ListC &LC,addressC X);
void deleteFirstC(ListC &LC, addressC &X);
void deleteAfterC(ListC &LC,addressC Prec,addressC &P);
void deleteLastC (ListC &LC,addressC A);
void dealokasiC(addressC &X);
addressC FindelmC(ListC LC,string X);
addressC deleteSearchPasien(ListC &LC, infotypeC x);
void printInfoC(ListC LC);
void deletePasiennih(ListC &LC,infotypeC x);
void cariPasienNih(ListC &LC,infotypeC X);
#endif // PASIEN_H_INCLUDED
