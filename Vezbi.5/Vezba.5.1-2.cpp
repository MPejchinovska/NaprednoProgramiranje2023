#include <iostream>

using namespace std;

//Ovaa funkcija dobiva pointer na nizata namesto samata niza.
void modifyFirst4Chars(char* str, char c1, char c2, char c3, char c4) {
    *str = c1; //Go koristime pointerot za da pristapime do znacite vo nizata.
    str++; //Go zgolemuvame pokazuvacot za da pristapime do naredniot znak vo nizata.
    *str = c2;
    str++;
    *str = c3;
    str++;
    *str = c4;
}

int main() {

    char ime[] = "Marijana";
    char prezime[] = "Pejchinovska";


    char imeChar1 = '^';
    char imeChar2 = '`';
    char imeChar3 = '@';
    char imeChar4 = '%';
    char prezimeChar1 = '!';
    char prezimeChar2 = '*';
    char prezimeChar3 = '$';
    char prezimeChar4 = '~';

    cout << " \n" << ime << endl;

    modifyFirst4Chars(ime, imeChar1, imeChar2, imeChar3, imeChar4);

    cout <<" \n" << ime << endl;

    cout<< " \n" << prezime << endl;

    modifyFirst4Chars(prezime, prezimeChar1, prezimeChar2, prezimeChar3, prezimeChar4);

   cout << " \n" << prezime << endl;

    return 0;
}
//Marijana Pejchinovska
