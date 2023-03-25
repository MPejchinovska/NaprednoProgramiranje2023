#include <iostream>
#include <string>
using namespace std;

int main() {
    string pesna = "Visiting Hours - Ed Sheeran";
    char *p = &pesna[0];

    cout << "Pesna: " << pesna << endl;
    cout << "Cela sodrzina: " << p << endl;
    cout << "*pocetna tocka: " << *p << endl;
    cout << "Adresa od pocetnata tocka: " << reinterpret_cast<void*>(p) << endl;

    p += 17;
    cout << "premestuvanje do imeto na izveduvacot p + 17: " << endl;
    cout << "Sodrzina do premestuvanjeto: " << p << endl;
    cout << "*pocetna bukva od premestuvanjeto: " << *p << endl;
    cout << "Adresa od tockata na premestuvanjeto: " << reinterpret_cast<void*>(p) << endl;

    return 0;
}
//Marijana Pejchinovska
