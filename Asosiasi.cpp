#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien { // asosiasi
public:
    string nama;
    vector<dokter*> daftar_Dokter;
    pasien(string pnama) :nama(pnama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    }    
    void tambahDokter(dokter*);
    void cetakDokter();
};

class dokter {
public:
    string nama;
    vector<pasien*> daftar_Pasien;

    dokter(string pnama) :nama(pnama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }
    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }  

    void tambahPasien(pasien*);
    void cetakPasien();
};

void pasien::tambahDokter(dokter* pDokter) {
    daftar_Dokter.push_back(pDokter);
}
void pasien::cetakDokter() {
    cout << "Daftar dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_Dokter) { // auto digunakan dalam perulangan for untuk secara otomatis menentukan tipe data dari elemen yang diiterasi.
        cout <<  daftar_Dokter[i]->nama << endl;
    }
    cout << endl;
}
void dokter::tambahPasien(pasien* pPasien) {
    daftar_Pasien.push_back(pPasien);
    pPasien->tambahDokter(this);
}
void dokter::cetakPasien() {
    cout << "Daftar pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_Pasien) {
        cout <<  daftar_Pasien[i]->nama << endl;
    }
    cout << endl;
}
