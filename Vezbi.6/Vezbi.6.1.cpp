//Marijana Pejchinovska INKI1003
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

//Ovde se definira 'card' i sodrzi dva pokazuvaci ili pointers face i suit.
struct card {
   const char *face;
   const char *suit;
};

typedef struct card Card;

//Se koristat dvata pointers koi ja povikuvaat nizata na broevi i znaci.
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
   Card deck[ CARDS ];

   //So ovie dve konstanti se definiraat dvete nizi face i suit.
   //Face go sodrzhi imeto ili brojot na kartite vo spilot.
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   //Suit gi sodrzhi znacite na kartite.
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand( time( NULL ) ); //Go povrzuva generatorot na random broj, za sekogash koga ke bide izvrshena programata nizata da bide razlicna so random generirani broevi.

   fillDeck( deck, face, suit );
   shuffle( deck );
   deal( deck );
}


void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] )
{
   size_t i;


   for ( i = 0; i < CARDS; ++i ) {
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   }
}


void shuffle( Card * const wDeck ) //Gi mesha random kartite.
{
   size_t i; // 'i' e promenliva od tipot size_t i se koristi kako brojac-promenliva vo for-jamkata.Se povtoruva niz site karti od dekot.
   size_t j; // 'j' e promenliva od tipot size_t i se koristi kako indeks za izbor na random karta.Negovata vrednost se dvizi so generiranje na random broj od 0-51 so pomos na funkcijata rand() a posle go zema modulot(%) na taa vrednost so 52.
   Card temp;


   for ( i = 0; i < CARDS; ++i ) {
      j = rand() % CARDS; //
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   }
}


void deal( const Card * const wDeck ) //Go pokazuva spilot na karti. So pomosh na printf() funkcijata za da se prikazhat site karti vo spilot.
{
   size_t i;


   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   }
}
