#include "relasi.h"
#include "pasien.h"
#include "dokter.h"

void createListR(ListR &LR)
{
    first(LR) = NULL;
    last(LR) = NULL;
}
addressR alokasiR (addressP P, addressC C)
{
    addressR Q = new ElmListR;
    toP(Q) = P;
    toC(Q) = C;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
void dealokasiR(addressR X)
{
    delete X;
}
void InsertLastR (ListR &LR, addressR R)
{
	if (first(LR) == NULL) {
		first(LR) = R;
		last(LR) = R;
		next(R) = R;
		prev(R) = R;
	}
	else {
		prev(R) = last(LR);
		next(R) = first(LR);
		next(last(LR)) = R;
		prev(first(LR)) = R;
		last(LR) = R;
;	}
}
void deleteFirstR(ListR &LR,addressR &R)
{
    if (first(LR) == NULL)
    {
        R = NULL;
    }
    else if (next(first(LR)) == first(LR))
    {
        R = first(LR);
        first(LR) = NULL;
        next(R) = NULL;
        prev(R) = NULL;
    }
    else
    {
        R = first(LR);

    }

}
void deleteLastR(ListR &LR, addressR &R)
{
    if (next(first(LR)) != first(LR))
    {
        R = last(LR);
        next(prev(last(LR))) = first(LR);
        prev(first(LR)) = prev(last(LR));
        last(LR) = prev(last(LR));
    }
    else
    {
        deleteFirstR(LR,R);
    }
}
void deleteAfterR(ListR &LR,addressR Prec,addressR &R)
{
    if (next(first(LR)) != first(LR))
    {
        next(Prec) =R;
        next(Prec) = next(R);
        prev(next(R)) = Prec;
    }
    else if (next(next(first(LR))) = first(LR))
    {
        deleteLastR(LR,R);
    }
    else
    {
        deleteFirstR(LR,R);
    }

}
void deleteRelasi (ListR &LR,addressR &Q)
{
    if (first(LR)!=NULL)
    {
        if (next(first(LR)) == first(LR))
        {
            Q = first(LR);
            Q = NULL;
        }

        else
    {
        addressR Z = prev(prev(first(LR)));
        Q = next(Z);
        next(Z) = first(LR);
        prev(first(LR))=Z;
        next(Q)= NULL;
        prev(Q) = NULL;
    }}
    else
    {
        cout << "DATA KOSONG"<<endl;
    }
}

void deleteR (ListR &LR,addressR &P)
{
    addressR Q,Prec;
    if ( P!= NULL)
    {
        Q= first(LR);
        while (next(Q)!= first(LR))
        {
            Q = next(Q);
        }
        Q = next(Q);
        if (P==first(LR))
        {
            deleteFirstR(LR,P);
        }
        else if (P==Q)
        {
            deleteLastR(LR,P);
        }
        else
        {
            Prec = prev(P);
            deleteAfterR(LR,Prec,P);
        }
        dealokasiR(P);
    }
}

void deleteSearchR(ListR &LR,addressR &P)
{
    addressR Q,Prec;
    if (P != NULL)
    {
        Q = first(LR);
        while (next(Q)!= first(LR))
        {
            Q= next(Q);
        }
        Q = next(Q);
        if ( P== first(LR))
        {
            deleteFirstR(LR,P);
            P = first(LR);
        }
        else if(P==Q)
        {
            deleteLastR(LR,P);
            P=Q;
        }
        else
        {
            Prec = prev(P);
            deleteAfterR(LR,Prec,P);
            P=Prec;
        }
        dealokasiR(P);
    }
}
addressR SearchRelasi (ListR &LR,addressP P,addressC Q)
{
    addressR R;
    R=first(LR);
    if (first(LR)==NULL)
    {
        return NULL;
    }
    else
    {
        while (next(R) != first(LR))
        {
            if(toP(R) != P && toC(R) != Q)
            {
                R = next(R);
            }
        }
        if(toC(R) == Q && toP(R) == P)
        {
            return R;
        }
        else
        {
            return NULL;
        }
    }
}

void deletePasien (ListR &LR,ListC &LC,addressC &Q)
{
    addressR P = first(LR);
    if (first(LR)!= NULL)
    {
        while (next(P)!= first(LR))
        {
            if(info(toC(P)).namaC == info(Q).namaC)
            {
                deleteSearchR(LR,P);
            }
            P= next(P);
        }
    }
    if (info(toC(P)).namaC == info(Q).namaC)
    {
        deleteSearchR(LR,P);
    }
}

void deleteDokter (ListR &LR,ListP &LP,addressP &PJ)
{
    addressR P =first(LR);
    if (first(LR)!= NULL)
    {
        while (next(P)!= first(LR))
        {
            if (info(toP(P)).namaP== info(PJ).namaP)
            {
                deleteSearchR(LR,P);
            }
            P = next(P);
        }
    }
    if (info(toP(P)).namaP== info(PJ).namaP)
    {
        deleteSearchR(LR,P);
    }
}

void printINFOR(ListR &LR)
{
    addressR P;
    if (first(LR) == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        cout << "=========================================================================" << endl;
        cout << "\t\t  Daftar Pasien Denga Dokter" << endl;
        cout << "=========================================================================" << endl;
        cout << "Nama Pasien \t\t| Penyakit \t\t| Dokter \t\t|" << endl;
        cout << "=========================================================================" << endl;
        P = first(LR);

        do {
            cout << info(toC(P)).namaC << "\t\t "<<info(toC(P)).sakitC<< "\t\t " << info(toP(P)).namaP<<"\t|";
            cout << endl;
            P = next(P);
        } while((P) != first(LR));
    }
}

addressR FindR (ListR &LR, addressP P, addressC C)
{
    addressR Q = first(LR);
    while (next(Q) != first(LR) && P != toP(Q) && C != toC(Q))
    {
        Q = next(Q);
    }
    if (P == toP(Q) && C == toC(Q))
    {
        return Q;
    }
    return NULL;
}

void pasientodokter(ListR LR){
    infotypeP X;

    system("CLS");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "                                   MASUKKAN NAMA DOKTER : " ;
    cin>>X.namaP;
    if (first(LR) != NULL){
        addressR Q = first(LR);
        do{
            if (info(toP(Q)).namaP == X.namaP){
                cout<<"\t\t     "<<info(toP(Q)).namaP;
            }
            Q = next(Q);
        } while ((Q) != first(LR) && info(toP(Q)).namaP != X.namaP);
        if (info(toP(Q)).namaP != X.namaP){
                cout<<"\t\t     Dokter Belum Terdaftar";
            }
        else{
            Q = first(LR);
        do{
            if (info(toP(Q)).namaP == X.namaP){
                cout<<"\t\t     "<<info(toC(Q)).namaC;
            }
            Q = next(Q);
        } while ((Q) != first(LR));
        }
    }
    else{
        cout<<endl<<"         Data Dokter Tidak Ada"<<endl;
    }
}
