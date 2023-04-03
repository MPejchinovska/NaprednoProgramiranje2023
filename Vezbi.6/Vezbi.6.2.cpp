//Marijana Pejchinovska INKI1003
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
//Kodot e igra so kocki pomegju userot i kompjuterot.Simulira frlanje po dve kocki za dvata igrachi.
//Toj igrach shto ima povisoki broevi toj dobiva poen i taka se duri korisnikot ne se otkazi so opcijata 'q'.

//Ovie funkcii podolu vo slucajot gi koristime za da gi prikazheme licata na kockite shto ke se padnat na ekranot.
void one();
void two();
void three();
void four();
void five();
void six();
//Programata zapocnuva so deklariranje na promenlivite za da go sledi rezultatot i kockite.
int main()
{
short unsigned int score = 0;
short unsigned int compScore = 0;
short unsigned int num = 0;
short unsigned int num2 = 0;
short unsigned int compNum = 0;
short unsigned int compNum2 = 0;
short unsigned int sum = 0;
short unsigned int compSum = 0;
char letter;

srand(time(NULL));
while (letter != 'q') //Vleguva vo 'while' se dodeka igrachot user ne pritisni opcija 'q'.
{ //Vnatre, programata go tera korisnikot da gi frli kockite ili da se otkazhi i generira random broevi na kockite za igrachite.
cout << "Your Score: " << score << endl;
cout << "computer's Score: " << compScore << endl << endl;
cout << "Press r to roll or q to quit: ";
cin >> letter;
num = 1 + rand()%6;
num2 = 1 + rand() %6;
compNum = 1 + rand() %6;
compNum2 = 1 + rand() %6;
//Generiraat random broevi pomegju 1-6 i gi davaat na promenlivite.
//Odnosno funkcijata 'rand'generira random broj 0 do maksimalnata zadadena vrednost.
//Operatorot na modulot(% 6) ni kazuva deka rezultatot ke bide pomegju 0-5.
//So toa shto dodavame 1 znaci deka vrednostite se pomegju 1 i 6.
//Promenlivite ke imaat random generiran broj pomegju 1-6 vklucuvajki gi i 1 i 6.

sum = num + num2;
compSum = compNum + compNum2;

//Calculate Sums

if (letter == 'q')
break;
if (letter != 'r')
{
system("cls");
continue;
}
//Koristime switch za programata da gi prikazhe kockite na dvata igrachi.
switch (num)
{
case 1:
one();
break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
default: //Ne se neophodni bidejki nikogash nema da bidat izvrsheni. Tie se tamu vo slucaj kodot vo idnina da treba da se spravi so neocekuvani vrednosti.
cout << "Error...";
break;
}

switch (num2)
{
case 1:
one();
break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
default:
cout << "Error...";
break;
}

cout << endl << "Yours: " << num << ", " << num2 << endl;
cout << "Computer's: " << compNum << ", " << compNum2 << "\n\n";

//Gi sporeduva zbirot na kockite na dvata igrachi i go kazhuva pobednikot na partijata i vkupniot rezultat.

if (sum > compSum)
{
cout << "You won!!" << endl << endl;
score++;
}
else
{
compScore++;
cout << "you lost..." << endl << endl;
}

//Ovie linii ja pauziraat programata i cekaat korisnikot da pritisni kopche pred da se ischisti ekranot i da pocni slednata partija.

system("pause");
system("cls");


}
return 0;
}

void one()
{
cout << "-----" << endl;
cout << "|   |" << endl;
cout << "| O |" << endl;
cout << "|   |" << endl;
cout << "-----" << endl;
}
void two()
{
cout << "-----" << endl;
cout << "| O |" << endl;
cout << "|   |" << endl;
cout << "| O |" << endl;
cout << "-----" << endl;
}
void three()
{
cout << "-----" << endl;
cout << "| O |" << endl;
cout << "| O |" << endl;
cout << "| O |" << endl;
cout << "-----" << endl;
}
void four()
{
cout << "-----" << endl;
cout << "|O O|" << endl;
cout << "|   |" << endl;
cout << "|O O|" << endl;
cout << "-----" << endl;
}
void five()
{
cout << "-----" << endl;
cout << "|O O|" << endl;
cout << "| O |" << endl;
cout << "|O O|" << endl;
cout << "-----" << endl;
}
void six()
{
cout << "-----" << endl;
cout << "|O O|" << endl;
cout << "|O O|" << endl;
cout << "|O O|" << endl;
cout << "-----" << endl;
}
