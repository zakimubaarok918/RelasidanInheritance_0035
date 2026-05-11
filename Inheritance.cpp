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
