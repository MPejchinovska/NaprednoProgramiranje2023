//Marijana Pejchinovska INKI1003
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int guess, numAttempts = 0;

    do {
        cout << "Pogodi broj pomegju 1-100: ";
        cin >> guess;
        numAttempts++;

        if (guess < randomNumber) {
            cout << "Brojot e pogolem.Probaj pak" << endl;
        } else if (guess > randomNumber) {
            cout << "Brojot e pomal.Probaj pak" << endl;
        }
    } while (guess != randomNumber);

    cout << "Bravo! Go pogodi brojot vo " << numAttempts << " obidi." << endl;

    return 0;
}
