#include "pasien.h"
#include <iostream>
#include<windows.h>
void CreatListC(ListC &LC){
    first(LC) = NULL;
    last (LC) = NULL;
}

addressC alokasiC(infotypeC x){
    addressC P = new ElmList;
    info(P).namaC = x.namaC;
    info(P).umurC = x.umurC;
    info(P).sakitC = x.sakitC;
    info(P).hariC = x.hariC;
    info(P).klmnC = x.klmnC;
    info(P).lahirC = x.lahirC;
    info(P).rpenyakitC = x.rpenyakitC;
    next(P) = NULL;
    return P;
}
void insertFirstC(ListC &LC,addressC X) {
    if (first(LC) == NULL ){
        first(LC) = X;
        last(LC) = X;
        next(X) = X;
    }
    else {
        next(X) = first(LC);
        next(last(LC)) = X;
        first(LC) = X;
    }
}
void insertAfterC(ListC &LC,addressC Prec,addressC X){
    if (next(Prec) == first(LC)) {
        insertLastC(LC, X);
    }
    else {
        next(X) = next(Prec);
        next(Prec) = X;
    }
}
void insertLastC(ListC &LC,addressC X){
    if (first(LC) == NULL) {
        first(LC) = X;
        last(LC) = X;
        next(X) = X;
    }
    else {
        next(X) = first(LC);
        next(last(LC)) = X;
        last(LC) = X;
    }
}
void deleteFirstC(ListC &LC, addressC &X){
    if (first(LC) == NULL) {
        X = NULL;
    }
    else if (next(first(LC)) == first(LC)) {
        X = first(LC);
        first(LC) = NULL;
    }
    else {
        X = first(LC);
        first(LC) = next(X);
        next(last(LC)) = first(LC);
        next(X) = NULL;
    }
}
void deleteAfterC(ListC &LC,addressC Prec,addressC &P){
    if (first(LC) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
    else {
        deleteFirstC(LC,P);
    }
}
void deleteLastC (ListC &LC,addressC A){
    if (first(LC) == NULL) {
        A = NULL;
    }
    else if (next(first(LC)) == first(LC)) {
        A = first(LC);
        first(LC) = NULL;
    }
    else {
        addressC Q = first(LC);
        while (next(Q) != last(LC)) {
            Q = next(Q);
        }
        A = last(LC);
        last(LC) = Q;
        next(Q) = first(LC);
        next(A) = NULL;
    }
}


addressC deleteSearchPasien(ListC &LC, infotypeC x)
{
    addressC P;
    P =FindelmC(LC,x.namaC);
    if (first(LC)== NULL)
    {
        cout << "Tidak Dapat Menghapus"<<endl;
        cout << "LIST KOSONG"<<endl;
        return NULL;
    }
    if (P != NULL)
    {
         if (P==first(LC))
         {
             deleteFirstC(LC,P);
             cout<<"BERHASIL"<<endl;
             return P;
         }
         else if (next(P)==NULL)
         {
             deleteLastC(LC,P);
             cout<<"BERHASIL"<<endl;
             return P;
         }
         else {
            addressC Q = first(LC);
            while (next(Q)!= NULL)
            {
                Q=next(Q);
            }
            Q=next(Q);
            deleteAfterC(LC,Q,P);
            cout<<"BERHASIL"<<endl;
            return P;
         }
        cout <<"TDK ADA"<<endl;
        return NULL;
    }
}

addressC FindelmC(ListC LC,string X)
{
    addressC Q = first(LC);
    while (info(Q).namaC != X && next(Q) != first(LC)) {
        Q = next(Q);
    }
    if (info(Q).namaC == X) {
       return Q;
    }
    return NULL;
}
void dealokasiC(addressC &X)
{
    delete X;
}
void printInfoC(ListC LC)
{
    if (first(LC) == NULL) {
        cout << "LIST KOSONG    ";
        return;
    }
    addressC Q = first(LC);
    while (next(Q) != first(LC)) {
        cout <<"NAMA : " <<info(Q).namaC << endl;
        cout <<"UMUR : " << info(Q).umurC << endl;
        cout <<"SAKIT : "<< info(Q).sakitC << endl;
        cout <<"UMUR : "<< info(Q).umurC <<endl;
        cout <<"LAMA MENGINAP : " << info(Q).hariC << endl;
        cout <<"KELAMIN : "<<info(Q).klmnC << endl;
        cout <<"TTL : " <<info(Q).lahirC<<endl;
        cout <<"RIWAYAT PENYAKIT : " << info(Q).rpenyakitC<<endl << endl;
        Q = next(Q);
    }
    cout <<"NAMA : " <<info(Q).namaC << endl;
    cout <<"UMUR : " << info(Q).umurC << endl;
    cout <<"SAKIT : "<< info(Q).sakitC << endl;
    cout <<"UMUR : "<< info(Q).umurC <<endl;
    cout <<"LAMA MENGINAP : " << info(Q).hariC << endl;
    cout <<"KELAMIN : "<<info(Q).klmnC << endl;
    cout <<"TTL : " <<info(Q).lahirC<<endl;
    cout <<"RIWAYAT PENYAKIT : " << info(Q).rpenyakitC<<endl;
}

void deletePasiennih(ListC &LC,infotypeC x)
{
    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   MASUKKAN NAMA PASIEN : " ; cin >> x.namaC ;
    deleteSearchPasien(LC,x);

}

void cariPasienNih(ListC &LC,infotypeC X)
{
    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   CARI NAMA PASIEN : " ;
    cin>> X.namaC;
    addressC P =FindelmC(LC,X.namaC);
    if ( P != NULL){
        cout<<" NAMA : "<< info(P).namaC <<endl;
        cout<< "UMUR : "<<info(P).umurC<<endl;
        cout<< " TTL : "<<info(P).lahirC<<endl;
        cout<< "SAKIT : "<<info(P).sakitC<<endl;
        cout<< "KELAMIN : "<< info(P).klmnC<<endl;
        cout<< "LAMA DIRAWAT : "<< info(P).hariC<<endl;
        cout<< "RIWAYAT PENYAKIT : "<<info(P).rpenyakitC<<endl;

        }
    else {
        cout<<"ko";
    }
}
