#ifndef ANAK_H
#define ANAK_H

class Anak {
public:
    string nama;
    anak(string pnama) :nama(pnama) {
        cout << "Anak \"" << nama << "\" ada\n;
    }
    ~anak() {
        cout << "Anak \"" << nama << "\" tidak ada\n";
    }    
};
#endif