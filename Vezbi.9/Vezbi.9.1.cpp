//Marijana Pejchinovska INKI1003
#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    cout << "Vnesi Recenica: ";
    getline(cin, sentence);

    int num_chars = sentence.length();
    int num_lowercase = 0;
    int num_uppercase = 0;
    int num_digits = 0;
    int num_special_chars = 0;

    for (int i = 0; i < num_chars; i++) {
        char ch = sentence[i];
        if (islower(ch)) {
            num_lowercase++;
        } else if (isupper(ch)) {
            num_uppercase++;
        } else if (isdigit(ch)) {
            num_digits++;
        } else {
            num_special_chars++;
        }
    }

    cout << "Broj na mali bukvi: " << num_lowercase << endl;
    cout << "Broj na golemi bukvi: " << num_uppercase << endl;
    cout << "Broj na broevi: " << num_digits << endl;
    cout << "Broj na specijalni znaci: " << num_special_chars << endl;
    cout << "Broj na karakteri: " << num_chars << endl;

    return 0;
}
