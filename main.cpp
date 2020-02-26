#include "mainHead.h"
#include "relasi.h"
#include "dokter.h"
#include "pasien.h"

void InputC(ListC &LC, ListP LP, ListR &LR);
void cariPasien(ListR LR);

int main()
{
    ListP LP;
    ListC LC;
    ListR LR;
    createListR(LR);
    CreatListC(LC);
    CreatListP(LP);
    int pil;

    pulang:
    system("CLS");
    cout << "   ======================================================================================= "<<endl;
    cout << " ==========================================================================================="<<endl;
    cout << "                            SELAMAT DATANG DIRUMAH SAKIT ASD"<<endl;
    cout << "                        Jalan Abang Ade no.100;Telp : 0213456789"<<endl;
    cout << "                                   Bandung,Jawa Barat"<<endl;
    cout << "============================================================================================"<<endl;
    cout << "============================================================================================"<<endl;


    cout << "\n\t\t             1. DAFTAR DOKTER" << endl;
    cout << "\n\t\t             2. DAFTAR PASIEN "<< endl;
    cout << "\n\t\t             3. HAPUS DATA DOKTER "<< endl;
    cout << "\n\t\t             4. HAPUS DATA PASIEN "<< endl;
    cout << "\n\t\t             5. CARI DATA PASIEN"<< endl;
    cout << "\n\t\t             6. CARI DATA DOKTER"<< endl;
    cout << "\n\t\t             7. DAFTAR DOKTER YANG TERSEDIA"<< endl;
    cout << "\n\t\t             8. LIHAT DATA DOKTER"<< endl;
    cout << "\n\t\t             9. LIHAT DATA PASIEN"<< endl;
    cout << "\n\t\t             10. LIHAT RELASI PASIEN DOKTER"<< endl;
    cout << "\n\t\t             11. CARI RELASI PASIEN - DOKTER"<< endl;
    cout << "\n\t\t             12. CARI DOKTER DENGAN PASIENNYA"<< endl;
    cout << "\n\t\t             13. HAPUS RELASI"<<endl;
    cout << "\n\t\t             14. EXIT" <<endl;
    if (first(LR) != NULL){
        cout<<info(toC(first(LR))).namaC<<" "<<info(toC(next(first(LR)))).namaC;
    }
    cout << "\n\t\t         Masukan Pilihan Anda ";
    cout << "\n\t\t         MENU UTAMA : ";
    cin >> pil;
    if (pil == 1){
            infotypeP x;
            InputP(LP);
            goto pulang;
        }
    else if (pil == 2){
            infotypeC a;
            InputC(LC, LP, LR);
            goto pulang;
    }
    else if ( pil == 3)
    {
        infotypeP x;
        deleteDokternih(LP,x);
        _getch();
        goto pulang;
    }
    else if (pil==4)
    {
        infotypeC x;
        deletePasiennih(LC,x);
        _getch();
        goto pulang;
    }
    else if (pil==5)
    {
        infotypeC X;
        cariPasienNih(LC,X);
        _getch();
        goto pulang;
    }
    else if (pil==6)
    {
        infotypeP X;
        CariDokter(LP,X);
        _getch();
        goto pulang;
    }
    else if (pil==7)
    {
        infotypeP X;
        CariJadwal(LP,X);
        _getch();
        goto pulang;
    }
    else if (pil == 8)
    {
        system("CLS");
        Tampldata(LP);
        _getche();
        goto pulang;
    }
    else if (pil == 9) {
        system("CLS");
        printInfoC(LC);
        _getche();
        goto pulang;
    }
    else if (pil == 10) {
        system("CLS");
        printINFOR(LR);
        _getche();
        goto pulang;
    }
	else if (pil == 11) {
		system("CLS");
		cariPasien(LR);
		_getche();
		goto pulang;
	}
	else if (pil == 12) {
        system("CLS");
		pasientodokter(LR);
		_getche();
		goto pulang;
	}
}

void cariPasien(ListR LR) {
	string nama;
	cout << "Input nama Pasien : "; cin >> nama;
	addressR P = first(LR);
	while (next(P) != NULL && info(toC(P)).namaC != nama) {
		P = next(P);
	}
	if (info(toC(P)).namaC == nama) {
		cout << "Nama Pasien : " << info(toC(P)).namaC << endl;
		cout << "Nama Dokter : " << info(toP(P)).namaP << endl;
		cout << "Penyakit    : " << info(toC(P)).sakitC << endl;
	}
	else {
		cout << "Relasi Pasien dengan Dokter tidak ditemukan!";
	}
}

void InputC(ListC &LC, ListP LP, ListR &LR)
{
    system("CLS");
    cout << "======================================================================================="<<endl;
    cout << "                            INPUT DATA PASIEN" << endl;
    cout <<endl;
    cout << endl;
    infotypeC x;
    cout << "\n      NAMA : "; cin >> x.namaC;
    cout << "\n      UMUR : ";cin >> x.umurC;
    cout << "\n      SAKIT : ";cin >> x.sakitC;
    cout << "\n      LAMA DIRAWAT (HARI) : ";cin >> x.hariC;
    cout << "\n      JENIS KELAMIN : ";cin >> x.klmnC;
    cout << "\n      TTL(h/b/t) : ";cin >> x.hariC;
    cout << "\n      RIWAYAT PENYAKIT : ";cin >> x.rpenyakitC;
    cout << "\n      1. Tambah di awal" << endl;
    cout << "\n      2. Tambah di akhir" << endl;
    int pilih;
    cout << endl << "Pilihan : "; cin >> pilih;
    addressC C = alokasiC(x);
    if (pilih == 1) {
        insertFirstC(LC, C);
    }
    else {
        insertLastC(LC, C);
    }
    addressP P = first(LP);
    while (next(P) != NULL && info(P).spesialisP != x.sakitC) {
        P = next(P);
    }
    if (info(P).spesialisP == x.sakitC) {
        InsertLastR(LR, alokasiR(P, C));
		cout << "Selamat! spesialis ditemukan";
		_getche();
    }
    else {
        cout << "Spesialis tidak ditemukan";
        _getche();
    }
    cout<<"Pilihan Anda Berhasil";
}
