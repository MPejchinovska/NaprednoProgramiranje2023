//Marijana Pejchinovska INKI1003
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int me;
    int computer;
    int random_number;

    srand(time(NULL));

    cout << "Igraj!" << endl;
    cout << "1. \u270A" << endl;
    cout << "2. \u270B" << endl;
    cout << "3. \u270C" << endl;
    cout << " ";
    cin >> me;


    random_number = rand() % 3 + 1;

    if (random_number == 1) {
        computer = 1;
        cout << "Computer izbra \u270A." << endl;
    } else if (random_number == 2) {
        computer = 2;
        cout << "Computer izbra \u270B" << endl;
    } else {
        computer = 3;
        cout << "Computer izbra \u270C" << endl;
    }

    if (me == computer) {
        cout << "Neresheno!" << endl;
    } else if (me == 1 && computer == 3 ||
               me == 2 && computer == 1 ||
               me == 3 && computer == 2) {
        cout << "Ti pobedi!" << endl;
    } else {
        cout << "Computer pobedi!" << endl;
    }

    return 0;
}
