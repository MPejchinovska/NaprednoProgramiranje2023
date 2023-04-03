//Marijana Pejchinovska INKI1003
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;


struct Card {
    string num;
    string suit;
};


class Deck {
public:
    Deck() {
        string num[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        string suits[] = {"\u2660", "\u2663", "\u2665", "\u2666", "\U0001F0BF", "\U0001F0CF"};

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                Card card;
                card.num = num[i];
                card.suit = suits[j];
                deck.push_back(card);
            }
        }


        Card joker1;
        joker1.suit = "\U0001F0BF";
        deck.push_back(joker1);

        Card joker2;
        joker2.suit = "\U0001F0CF";
        deck.push_back(joker2);
    }

    void shuffleDeck() {
        srand(time(0));
        random_shuffle(deck.begin(), deck.end());
    }

    void dealCards() {
        int numPlayers = 4;
        int numCardsPerPlayer = 52 / numPlayers;
        int cardIndex = 0;

        for (int i = 0; i < numPlayers; i++) {
            cout << "Igrach " << i + 1 << " " << endl;
            for (int j = 0; j < numCardsPerPlayer; j++) {
                cout << deck[cardIndex].num << " " << deck[cardIndex].suit << endl;
                cardIndex++;
            }
            cout << endl;
        }
    }

    void displayDeck() {
        for (int i = 0; i < deck.size(); i++) {
            cout << deck[i].num << " " << deck[i].suit << endl;
        }
    }

private:
    vector<Card> deck;
};

int main() {
    Deck deck;


    cout << "Kartite podredeni po red:" << endl;
    deck.displayDeck();
    cout << endl;


    deck.shuffleDeck();


    cout << "Izmeshani:" << endl;
    deck.displayDeck();
    cout << endl;


    deck.dealCards();

    return 0;
}
