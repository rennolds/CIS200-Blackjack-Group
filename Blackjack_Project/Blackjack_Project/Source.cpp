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
	int numberOfPlayers;

	try {
		cout << "Welcome to the Blackjack Simulation. Please indicate how many players will be playing in this game, from 0 to 10: ";
		cin >> numberOfPlayers;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input, please enter a number for number of players:" << endl;
			cin >> numberOfPlayers;

		}

		if (!cin.fail())
		{
			if (numberOfPlayers > 10 || numberOfPlayers < 0)
			{
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
	}
	catch (exception &excpt)
	{
		cout << excpt.what() << endl;
	}

	system("pause");
	return 0;
}

/*got input valid or not from  https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
though if input is both int an string, c++ makes it to diff to cover all possible inputs,
though if just int or string is entered in wrong input it can be cought and fixed in cin.fail()*/