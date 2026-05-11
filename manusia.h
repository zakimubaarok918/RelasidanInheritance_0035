#ifndef MANUSIA_H
#define MANUSIA_H
using namespace std;

class Manusia {
public:
    string name;
    jantung varJantung;

    Manusia(string pname) 
         :name(pname) {
        cout << name << " hidup\n";
    }
    ~Manusia() {
        cout << name << " mati\n";
    }
};
#endif    