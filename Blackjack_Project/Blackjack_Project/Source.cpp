#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Blackjack.h"

using namespace std;

int main()
{
	srand(time(0)); 
	Deck exampleDeck;
	Hand exampleHand;
	exampleHand.addCard(exampleDeck);
	exampleHand.addCard(exampleDeck);
	exampleHand.addCard(exampleDeck);

	string handInfo;
	handInfo = exampleHand.handInfo();
	cout << handInfo << endl;

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

		string playerName;
		vector <string> playerNames;
		for (int index = 0; index < numberOfPlayers; ++index)
		{
			cout << "Provide a name for player " << index + 1 << ": " << endl;
			cin >> playerName;
			playerNames.push_back(playerName);
		}
		Blackjack newBlackjackGame(numberOfPlayers, playerNames);
		newBlackjackGame.play();
	}
	catch (exception &excpt) {
		cout << excpt.what() << endl;
	}

	

	system("pause");
	return 0;
}