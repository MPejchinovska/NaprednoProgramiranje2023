#include <iostream>
#include <vector>
#include <algorithm>

// Започнавме со тоа што зададовме стрингови за бројот и знаците тоест за елементите од кои се состои шпилот карти.
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


// Овде ги објаснуваме стринговите односно колку знаци имаме или suits и колку броеви.
class Deck : public Card{
	std::vector<Card> *deckOfCards;
	const std::string SUITS[5] = {"CLUBS","DIAMONDS","HEARTS","SPADES","JOKER"}; // Го ставив ЈОКЕР како SUIT затоа што Јокерот може да биде било која карта во штилот со рандом влечење.
	const std::string TYPE[13] = {"ACE","2","3","4","5","6","7","8","9","10","JACK","QUEEN","KING"};
	public:
	Deck();
	void show();
	void shuffle();
	~Deck();
};

// Овој алгоритам започнува нов дек со карти и ги распоредува во низа, точно подредени по ред.
Deck::Deck() {
	deckOfCards = new std::vector<Card>();
	deckOfCards->reserve(54);
	for(int i = 0 ; i < 5 ; ++i)
		for(int j = 0 ; j < 13 ; ++j)
			deckOfCards->emplace_back(Card(SUITS[i],TYPE[j]));
}


void Deck::show() {  // Со ова се прикажуваат картите.
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

//Оваа команда ќе ги измеша картите.
void Deck::shuffle() {
	srand(time(NULL));
	std::random_shuffle(deckOfCards->begin(),deckOfCards->end());
}

//Со ова се брише или уништува штилот на карти за да се измешаат и постават пак во нов редослед картите кога пак ќе го пуштиме кодот.
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
	cout<<"Marijana Pejchinovska"<<endl;
	}
	//Marijana Pejchinovska
