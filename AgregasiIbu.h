#ifndef IBU_H
#define IBU_H
#include <vector>

class Ibu {
public:
    string nama;
    vector<Anak*> anak;

    ibu(string pnama) :nama(pnama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }
    ~ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }
     void tambahAnak(Anak*);
     void cetakAnak();   
};
