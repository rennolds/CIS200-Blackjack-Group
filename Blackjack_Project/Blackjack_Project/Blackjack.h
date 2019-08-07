#pragma once

#include<vector>
#include"Player.h"
#include"deck.h"


using namespace std;

class Blackjack 
{

private:
	vector<Player> players;
	Player computerPlayer;
	Deck gameDeck;

public:

	Blackjack(int numberOfPlayers)
	{
		for (int index = 0; index < numberOfPlayers; index++)
		{
			Player newPlayer;
			players.push_back(newPlayer);
		}

		Player computerPlayer;
		Deck gameDeck;
	}

	void play()
	{
		while (players.size() > 0)
		{
			round();
		}
	}


	void round()
	{
		for (int index = 0; index < players.size(); index++)
		{
		 
			// deal each player 
			
		}
		// deal the dealer 

		for (int index = 0; index < players.size(); index++)
		{

			// get each players action

		}
		// get dealer action

		for (int index = 0; index < players.size(); index++)
		{
			// pay out each player
		}
		// pay out dealer 

		for (int index = 0; index < players.size(); index++)
		{
			// remove any player that has busted from the vector
		}
	}

	void turn(Player player)
	{

	}

	void payOut()
	{


	}


};