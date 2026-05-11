#include <iostream>
using namespace std;

#include "anak.h"
#include "ibu.h"

int main() { // agregasi
    Ibu* ibu1 = new Ibu("dini");
    Anak* anak1 = new Ibu("novi");
    anak* varAnak1 = new Anak("tono");
    anak* varAnak2 = new Anak("rini");
    anak* varAnak3 = new Anak("Dewi");

    varIbu->tambahAnak(varAnak1);
    varIbu->tambahAnak(varAnak2);
    varIbu2->tambahAnak(varAnak3);
    varIbu2->tambahAnak(varAnak1);

    varIbu->cetakAnak();
    varIbu2->cetakAnak();

    delete varIbu;
    delete varIbu2;
    delete varAnak1;
    delete varAnak2;
    delete varAnak3;

    system("pause");

    return 0;
}    