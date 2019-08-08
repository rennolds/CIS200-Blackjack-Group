#include<iostream>
#include<stack>
#include<string>
#include"Blackjack.h"

using namespace std;

int main()
{
	Deck exampleDeck;
	Hand exampleHand;
	exampleHand.addCard(exampleDeck);
	exampleHand.addCard(exampleDeck);
	exampleHand.addCard(exampleDeck);

	cout << exampleHand.getHandSize() << endl;

	exampleHand.removeCard();
	exampleHand.removeCard();

	cout << exampleHand.getHandSize() << endl;

	int numberOfPlayers;
	cout << "Blackjack Group 7 Represent" << endl;

	cout << "How many human players do you want to play with?" << endl;
	cin >> numberOfPlayers;

	Blackjack blackjackGame(numberOfPlayers);
	blackjackGame.play();





	system("pause");
	return 0;
}