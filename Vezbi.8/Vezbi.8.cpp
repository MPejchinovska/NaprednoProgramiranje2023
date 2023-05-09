//Marijana Pejchinovska INKI1003
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct student{
    string ime;
    string prezime;
    string indeks;
};

char tocniPrvi[4]={'b', 'a', 'c', 'c'};
char tocniVtori[4]={'c', 'a', 'b', 'b'};
char tocniTreti[4][2]={{'a', 'c'}, {'c', 'd'}, {'c', 'd'}, {'a', 'd'}};

void loadAnswerKey() {
    ifstream answer_key_file("answer_key.txt");
    if (!answer_key_file) {
        cerr << "Greska: odgovorite od testot ne se vcitani." << endl;
        exit(1);
    }

    for (int i = 0; i < 4; ++i) {
        answer_key_file >> tocniPrvi[i];
    }

    for (int i = 0; i < 4; ++i) {
        answer_key_file >> tocniVtori[i];
    }

    for (int i = 0; i < 4; ++i) {
        answer_key_file >> tocniTreti[i][0] >> tocniTreti[i][1];
    }

    answer_key_file.close();
}


void studentInput(student &lice){
    cout << "Vnesete go imeto na studentot: ";
    cin >> lice.ime;
    cout << "Vnesete go prezimeto na studentot: ";
    cin >> lice.prezime;

    do{
        cout << "Vnesete go indeksot na studentot: ";
        cin >> lice.indeks;
    } while(lice.indeks.size()!=4);
}

void writeOdgovor(fstream &file, char odg, char odg2, int br) {
    file << br << ". " << odg << " " << odg2 << endl;
}

float checkOdgovor(int brojnaprasanje, char answer, char answer2){

    if (brojnaprasanje <= 4){
        if (answer == tocniPrvi[brojnaprasanje-1])
            return 1.5;
    }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8 ){
        if (answer == tocniVtori[brojnaprasanje-5])
            return 3;
    }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 12 ){
        if (((answer == tocniTreti[brojnaprasanje-9][0]) && (answer2 == tocniTreti[brojnaprasanje-9][1])) ||
            ((answer == tocniTreti[brojnaprasanje-9][1]) && (answer2 == tocniTreti[brojnaprasanje-9][0])))
            return 8;
    }
    return 0;
}

float handleInput(int brojprasanje, fstream &file) {

    char odgovor, odgovor2;
    if (brojprasanje <= 4) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c');
        writeOdgovor(file, odgovor, ' ', brojprasanje);
    } else if (brojprasanje > 4 && brojprasanje <= 8) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd');
        writeOdgovor(file, odgovor, ' ', brojprasanje);
    } else if (brojprasanje > 8 && brojprasanje <= 12) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' && odgovor != 'e');
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor2;
        } while ((odgovor2 == odgovor) ||
                 (odgovor2 != 'a' && odgovor2 != 'b' && odgovor2 != 'c' && odgovor2 != 'd' && odgovor2 != 'e'));
        writeOdgovor(file, odgovor, odgovor2, brojprasanje);
    }
    return checkOdgovor(brojprasanje, odgovor, odgovor2);
}
int score(float poeni){
    if ( poeni >= 0 && poeni <= 24 )
        return 5;
    else if ( poeni >= 25 && poeni <= 32 )
        return 6;
    else if ( poeni >= 32.5 && poeni <= 37 )
        return 7;
    else if ( poeni >= 37.5 && poeni <= 40.5 )
        return 8;
    else if ( poeni >= 41 && poeni <= 45 )
        return 9;
    else if ( poeni >= 45.5 && poeni <= 50 )
        return 10;
}

void answersTable(){
    cout << "Tocni odgovori na prasanjata se:" << endl;
    for(int i=1; i<=12; i++){
        if (i <= 4)
            cout << i << ". " << tocniPrvi[i-1] << endl;
        else if (i > 4 && i <= 8 )
            cout << i << ". " << tocniVtori[i-5] << endl;
        else if (i > 8 && i <= 12 )
            cout << i << ". " << tocniTreti[i-9][0] << " " << tocniTreti[i-9][1] << endl;
    }
}



string getCurrentTimeStamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ltm);
    return string(timestamp);
}

int main(){
        loadAnswerKey();
        fstream file, test, student_log;
        student lice;
        string prasanje;
        int brojnaprasanje = 1;
        float poeni = 0;
        studentInput(lice);

        const string filename = lice.ime + lice.prezime + "INKI" + lice.indeks;


        ifstream check_file(filename.c_str());
        if (check_file.good()) {
            cout << "Nemate Pravo Povtorno da go pravite testot" << endl;
            check_file.close();
            return 0;
        }
        check_file.close();

        file.open(filename.c_str(), ios::out);
        file.close();

        test.open("prasanja.txt", ios::in);

        std::time_t start_time = time(0);


    file.open(filename.c_str(), ios::app);
    file << "-------------------------------------------------------------" << endl;
    file << "Odgovori:" << endl;
    file.close();
    while(getline(test, prasanje)){
        for (int i=0; i < prasanje.size(); i++){
            if (prasanje[i] == ';'){
                cout << endl;
                i++;
            }
            else
                cout << prasanje[i];
        }
        cout << endl;

        file.open(filename.c_str(), ios::app);
        poeni += handleInput(brojnaprasanje, file);
        file.close();
        brojnaprasanje++;
    }

    test.close();
    file.open(filename.c_str(), ios::app);
    file << "-------------------------------------------------------------" << endl;
    file.close();
    time_t end_time = time(0);


    int final_grade = score(poeni);
    file.open(filename.c_str(), ios::app);
    file << "Ime: " << lice.ime << endl;
    file << "Prezime: " << lice.prezime << endl;
    file << "Indeks: " << "INKI" << lice.indeks << endl;
    file << "Vreme na start: " << asctime(localtime(&start_time));
    file << "Vreme na kraj: " << asctime(localtime(&end_time));
    file <<" "<<endl;
    file << "Vkupno poeni: " << poeni << endl;
    file << "Ocenka: " << final_grade << endl;
    file.close();

    student_log.open("student_log.txt", ios::app);

    student_log << getCurrentTimeStamp() << " - " << lice.ime << " " << lice.prezime << " (INDEKS: " << lice.indeks << ") - Poeni: " << poeni << " - Ocenka: " << final_grade << endl;
    student_log.close();


    cout << "Vkupno poeni: " << poeni << endl;
    cout << "Ocenka: " << final_grade << endl;
    answersTable();

    return 0;


}
