#include "Card.h"
#include "Deck.h"
#include "hand.h"

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	srand(unsigned(time(NULL)));

	int numberOfDecks = 6;

	Deck multipleDecks(numberOfDecks);


	system("pause");
	return 0;
}