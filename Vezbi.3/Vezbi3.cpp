#include <bits/stdc++.h>
#include <string>
using namespace std;

//Definira tip na nabrojuvanje Mesec so vrednosti za sekoj od 12te meseci.
enum Mesec {
    January=1,February,March,April,May,June,July,August,September,October,November,December};
//Definira funkcija 'sezona' koja trae eden mesecen broj i ja vrakja soodvetnata sezona.
std::string sezona(int mesec) {
    switch(mesec) {
        case December:
        case January:
        case February:
           return "Zima";
        case March:
        case April:
        case May:
           return "Prolet";
        case June:
        case July:
        case August:
           return "Leto";
        case September:
        case October:
        case November:
           return "Esen";
        default:
             return "Nepostoi toj mesec";
    }

}
//Funkcijata getOrdinalSuffix se koristi za dodavanje na soodvetnata redovna nastavka.
//Funkcijata getOrdinalSuffix zema cel broj kako vlez i ja vrakja soodvetnata redna nastavka vrz osnova na poslednite dve cifri od brojot.
std::string getOrdinalSuffix(int broj) {
    int Poslednacifra = broj % 10;
    int Predposlednatacifra = (broj / 10) % 10;
    if (Predposlednatacifra == 1) {
        return "ti";
    } else if (Poslednacifra == 1) {
        return "vi";
    } else if (Poslednacifra == 2) {
        return "ri";
    } else if (Poslednacifra == 3) {
        return "ti";
    } else if (Poslednacifra == 7) {
        return "mi";
    } else if (Poslednacifra == 8) {
        return "mi";
    } else {
        return "ti";
    }
}
//Koristi jamka za da otpecati spisok so site meseci, zaedno so nivnata soodvetna sezona i posledovatelen broj na mesec.
int main() {
    std::cout<<"Meseci vo godinata:"<< std::endl;
    int i;
    for (i=January; i<=December; i++) {
        std::cout << i << "." << sezona(i) << " - " << ((i - 1) % 12+1)<< std::endl;
    }

    int Mesec;
    std::cout <<"Vnesi broj na mesec: ";
    std::cin>> Mesec;

    if (Mesec < 1 || Mesec > 12 ) {
        std::cout<< "Nepostoecki broj" <<std::endl;
    } else {
        std::cout<<"Mesecot "<<Mesec <<" e vo " << sezona(Mesec) <<" i e " << Mesec << getOrdinalSuffix(Mesec) << " mesec vo godinata." << std::endl;
    }
    cout<<"Marijana Pejchinovska";
    return 0;
}
//Marijana Pejchinovska
