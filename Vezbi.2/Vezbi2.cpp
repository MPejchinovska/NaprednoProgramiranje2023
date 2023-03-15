#include <iostream>
#include <vector>
#include <algorithm>

// Zapocnavme so toa sto zadadovme stringovi za brojot i znacite toest za elementite od koi se sostoi spilot karti.
class Card {
	public :
		std::string suit;
		std::string number;
		Card();
		Card(std::string s, std::string num);

};

Card::Card() {

}

Card::Card(const std::string s,const std::string num) : suit(s),number(num) {
}


// Ovde gi objasnuvame stringovite odnosno kolku znaci imame ili suits i kolku broevi.
class Deck : public Card{
	std::vector<Card> *deckOfCards;
	const std::string SUITS[5] = {"CLUBS","DIAMONDS","HEARTS","SPADES","JOKER"}; // Go staviv JOKER kako SUIT zatoa sto Jokerot moze da bide bilo koja karta vo spilot so random vlecenje.
	const std::string TYPE[13] = {"ACE","2","3","4","5","6","7","8","9","10","JACK","QUEEN","KING"};
	public:
	Deck();
	void show();
	void shuffle();
	~Deck();
};

// Ovoj algoritam zapocnuva nov dek so karti i gi rasporeduva vo niza, tocno podredeni po red.
Deck::Deck() {
	deckOfCards = new std::vector<Card>();
	deckOfCards->reserve(54);
	for(int i = 0 ; i < 5 ; ++i)
		for(int j = 0 ; j < 13 ; ++j)
			deckOfCards->emplace_back(Card(SUITS[i],TYPE[j]));
}


void Deck::show() {  // So ova se prikazuvaat kartite.
	std::string showCard("");
	auto it = deckOfCards->begin();
	while (it != deckOfCards->end()) {
		showCard.append((it->suit));
		showCard.append(" of ");
		showCard.append((it->number));
		showCard.append("\n");
		it = std::next(it);
	}
	std::cout << showCard <<std::endl;

}

//Ovaa komanda ke gi izmesa kartite.
void Deck::shuffle() {
	srand(time(NULL));
	std::random_shuffle(deckOfCards->begin(),deckOfCards->end());
}

//So ova se brise ili unistuva spilot na karti za da se izmesaat i postavat pak vo nov redosled kartite koga pak ke go pustime kodot.
Deck::~Deck() {
	delete deckOfCards;
}


int main() {
	Deck d;
	std::cout << "Шпилот подреден по ред:" << std::endl;
	d.show();
	std::cout << "Мешање на картите: " << std::endl;
	d.shuffle();
	std::cout << " " << std::endl;
	d.show();
}
//Marijana Pejchinovska
