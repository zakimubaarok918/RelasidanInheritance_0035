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
void ibu::tambahAnak(Anak* pAnak) {
    daftar_anak.push_back(pAnak);
}
void ibu::cetakAnak() {
    cout << "Daftar anak dari Ibu \"" << this->nama << "\":\n";
    /*for (auto& a : daftar_anak) {
        cout << "- " << a->nama << "\n";
    }*/
    for (int i = 0; i < daftar_anak.size(); ++i) {
        cout <<  daftar_anak[i]->nama << endl;
    }
    cout << endl;
}
#endif