#include "mainHead.h"
#include "dokter.h"
#include<windows.h>
#include<iostream>

using namespace std;
void CreatListP(ListP &LP) {
    first(LP) = NULL;
}

addressP alokasiP(infotypeP x){
    addressP P = new ElmListP;
    info(P).namaP = x.namaP;
    info(P).umurP = x.umurP;
    info(P).spesialisP = x.spesialisP;
    info(P).NIKP = x.NIKP;
    info(P).jdwl = x.jdwl;
    info(P).lhr = x.lhr;
    next(P) = NULL;
    return P;
}
void insertFirstP(ListP &LP,addressP A){
    if (first(LP) == NULL) {
        first(LP) = A;
    }
    else
    {
        next(A) = first(LP);
        first(LP) = A;
    }
}

void insertAfterP(ListP &LP, addressP Prec, addressP A)
{
    if (next(Prec) == NULL) {
        insertLastP(LP, A);
    }
    else {
        next(A) = next(Prec);
        next(Prec) = A;
    }
}
void insertLastP(ListP &LP, addressP A){
    if (first(LP) == NULL) {
        first(LP) = A;
    }
    else {
        addressP P = first(LP);
        while (next(P) != NULL) {
            P = next(P);
        }
        next(P) = A;
    }
}
void deleteFirstP(ListP &LP,addressP &A){
    if (first(LP) == NULL) {
        A = NULL;
    }
    else if (next(first(LP)) == NULL) {
        A = first(LP);
        first(LP) = NULL;
    }
    else {
        A = first(LP);
        first(LP) = next(A);
        next(A) = NULL;
    }
}
void deleteLastP(ListP &LP, addressP &A){
    if (first(LP) == NULL) {
        A = NULL;
    }
    else if (next(first(LP)) == NULL) {
        A = first(LP);
        first(LP) = NULL;
    }
    else {
        addressP Q = first(LP);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        A = next(Q);
        next(Q) = NULL;
    }
}
void deleteAfterP(ListP &LP,addressP Prec,addressP &A){
    if (next(Prec) == NULL) {
        deleteFirstP(LP, A);
    }
    else {
        A = next(Prec);
        next(Prec) = next(A);
        next(A) = NULL;
    }
}
addressP FindElmP(ListP LP,string X)
{
    addressP Q = first(LP);
    while (info(Q).NIKP != X && next(Q) != NULL) {
        Q = next(Q);
    }
    if (info(Q).NIKP == X) {
       return Q;
    }
    return NULL;
}
void dealokasiP(addressP &A){
    delete A;
}
void Tampldata(ListP LP)
{
    if (first(LP)== NULL){
        cout << "LIST KOSONG";
        return;
    }
    addressP P = first(LP);
    while (next(P) != NULL) {
        cout << "Nama      : " << info(P).namaP << endl;
        cout << "Umur      : " << info(P).umurP << endl;
        cout << "Spesialis : " << info(P).spesialisP << endl;
        cout << "NIKP      : " << info(P).NIKP << endl;
        cout << "TTL       : " << info(P).lhr << endl;
        cout << "Jadwal    : " << info(P).jdwl << endl << endl;
        P = next(P);
    }
    cout << "Nama      : " << info(P).namaP << endl;
    cout << "Umur      : " << info(P).umurP << endl;
    cout << "Spesialis : " << info(P).spesialisP << endl;
    cout << "NIKP      : " << info(P).NIKP << endl;
    cout << "TTL       : " << info(P).lhr << endl;
    cout << "Jadwal    : " << info(P).jdwl << endl;
}

void InputP (ListP &LP)
{
    system("CLS");
    int K;
    int n;
    cout << "======================================================================================="<<endl;
    cout << "                                 INPUT DATA DOKTER" << endl;
    cout << "======================================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout <<"                     MASUKA JUMLAH DATA YANG INGIN DIINPUT : ";cin>>K;
    cout <<endl;
    cout << endl;
    infotypeP x;
    for (int i = 1;i<=K;i++){
        cout << "\n                     NAMA                 : ";cin >> x.namaP;
        cout << "\n                     UMUR                 : ";cin >> x.umurP;
        cout << "\n                     SPESIALIS            : ";cin >> x.spesialisP;
        cout << "\n                     NIK                  : ";cin >> x.NIKP;
        cout << "\n                     JADWAL YANG TERSEDIA : ";cin >> x.jdwl;
        cout << "\n                     TTL                  : ";cin.ignore(); cin >> x.lhr;
        addressP Q = first(LP);
        if (Q != NULL){
            while (next(Q) != NULL && info(Q).spesialisP != x.spesialisP){
                Q = next(Q);
            }
            if (info(Q).spesialisP != x.spesialisP){
                insertFirstP(LP, alokasiP(x));
            }
            else{
                cout<<"\n\t\t     Maaf Spesialis Sudah Ada";
                getch();
            }
        }
        else{
            insertFirstP(LP, alokasiP(x));
        }
        cout << "*************************************************************************"<<endl;
    }
}
addressP deleteSearchDokter(ListP &LP, infotypeP x)
{
    addressP P;
    P =FindElmP(LP,x.NIKP);
    if (first(LP)== NULL)
    {
        cout << "Tidak Dapat Menghapus"<<endl;
        cout << "LIST KOSONG"<<endl;
        return NULL;
    }
    if (P != NULL)
    {
         if (P==first(LP))
         {
             deleteFirstP(LP,P);
             cout<<"BERHASIL"<<endl;
             return P;
         }
         else if (next(P)==NULL)
         {
             deleteLastP(LP,P);
             cout<<"BERHASIL"<<endl;
             return P;
         }
         else {
            addressP Q = first(LP);
            while (next(Q)!= NULL)
            {
                Q=next(Q);
            }
            Q=next(Q);
            deleteAfterP(LP,Q,P);
            cout<<"BERHASIL"<<endl;
            return P;
         }
        cout <<"TDK ADA"<<endl;
        return NULL;
    }
}
void deleteDokternih(ListP &LP,infotypeP x)
{
    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   MASUKKAN NIK DOKTER : " ; cin >> x.NIKP ;
    deleteSearchDokter(LP,x);

}

void CariDokter(ListP &LP,infotypeP X)
{
    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   MASUKKAN NIK DOKTER : " ;
    cin>> X.NIKP;
    addressP P =FindElmP(LP,X.NIKP);
    if ( P != NULL){
        cout<<" NAMA : "<< info(P).namaP<<endl;
        cout<< " NIK : "<<info(P).NIKP<<endl;
        cout<< " TTL : "<<info(P).lhr<<endl;
        cout<< "UMUR : "<<info(P).umurP<<endl;
        cout<< "SPESIALIS : "<< info(P).spesialisP<<endl;
        cout<< "JADWAL : "<< info(P).jdwl<<endl;

        }
    else {
        cout<<"ko";
    }
}

void CariJadwal(ListP &LP,infotypeP X)
{
    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   MASUKKAN HARI DOKTER : " ;
    cin>> X.jdwl;
    addressP Q = first(LP);
    addressP P =FindElmP(LP,X.jdwl);
    while (Q != NULL){
        if ( P != NULL){
            cout<<" NAMA : "<< info(P).namaP<<endl;
            cout<< " NIK : "<<info(P).NIKP<<endl;
            cout<< " TTL : "<<info(P).lhr<<endl;
            cout<< "UMUR : "<<info(P).umurP<<endl;
            cout<< "SPESIALIS : "<< info(P).spesialisP<<endl;
            cout<< "JADWAL : "<< info(P).jdwl<<endl;

        }
        Q = next(Q);
        }
    }
