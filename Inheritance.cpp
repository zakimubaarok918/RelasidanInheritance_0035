#include <iostream>
#include <string>
using namespace std;

class Orang {
public:
    string nama;

    Orang(string pnama) :
        nama(pnama) {
        cout << "Orang dibuat\n" << endl;
    }
    ~Orang() {
        cout << "Orang dihapus\n" << endl;
    }    

     int jumlah(int a, int b) {
        return a + b;
   }

}; 

class pelajar : public Orang {
public:
    string sekolah;

    pelajar(string pnama, string psekolah) : Orang(pnama), sekolah(psekolah) {
        cout << "Pelajar dibuat\n" << endl;
    }
    ~pelajar() {
        cout << "Pelajar dihapus\n" << endl;
    }   
     string perkenalan() {
        return "Nama saya " + nama + " dari sekolah " + sekolah + "\n
\n"}         
};
