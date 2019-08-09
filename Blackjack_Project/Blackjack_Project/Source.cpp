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

	/*int numberOfDecks = 6;
	Deck multipleDecks(numberOfDecks);
	Hand testHand(2);
	testHand.addCard(multipleDecks);
	testHand.addCard(multipleDecks);
	testHand.getValue();
	cout << testHand.dealerHandInfo() << endl;
	Card testCard('S', '7');
	cout << testCard.getSuit() << " " << testCard.getRank() << endl;
	cout << testCard.cardInfo() << endl; */

	/*  Beginning of Actual Main Program*/

	int numberOfPlayers;

	try {
		cout << "Welcome to the Blackjack Simulation. Please indicate how many players will be playing in this game, from 0 to 10: ";
		cin >> numberOfPlayers;
		if (numberOfPlayers > 10 || numberOfPlayers < 0) {
			throw exception("Invalid number of players.");
		}

		Blackjack newBlackjackGame(numberOfPlayers);
		newBlackjackGame.play();
	}
	catch (exception &excpt) {
		cout << excpt.what() << endl;
	}

	

	system("pause");
	return 0;
}