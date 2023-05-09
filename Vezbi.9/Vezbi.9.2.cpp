//Marijana Pejchinovska INKI1003
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string fileName = "text.txt";
    string textToWrite = "True love is always priceless and selfless./n";

    ofstream outputFile(fileName, ios_base::app);

    if (outputFile.is_open()) {
        outputFile << textToWrite << endl;

        outputFile.close();

        cout << "Text added to file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }

    return 0;
}
