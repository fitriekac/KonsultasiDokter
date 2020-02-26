#ifndef DOKTERR_H_INCLUDED
#define DOKTERR_H_INCLUDED

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

struct infotypeP {
        char namaP;
        int umurP;
        char spesialisP;
        char NIKP;
        char lhr;
        char jdwl;
};
typedef struct ElmListP *addressP;
struct ElmListP {
    infotypeP info;
    addressP next;
};
struct ListP {
    addressP first ;
};

void InputP (char namla,int umur,char spsialis,char NIK,char jadwal, char Lahir);
void CreatListP(ListP &LP);
addressP alokasiP(char nama,int umur,char spsialis,char NIK,char jadwal, char Lahir);
void insertFirstP(ListP &LP,addressP A);
void insertAfterP(ListP &LP,addressP Prec,addressP A);
void insertLastP(ListP &LP, addressP A);
void deleteFirstP(ListP &LP,addressP &A);
void deleteLastP(ListP &LP, addressP &A);
void deleteAfterP(ListP &LP,addressP Prec,addressP &A);
void FindElmP(ListP LP,char A);
void dealokasiP(addressP &A);
void Tampldata(ListP L);
#endif // DOKTER_H_INCLUDED


#endif // DOKTERR_H_INCLUDED
