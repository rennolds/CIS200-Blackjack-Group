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
	char keepPlaying;

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
		keepPlaying = 'Y';
	}

	void play()
	{
		do 
		{
			round();
			cout << "Press N to quit the game, press anything to go to the next round." << endl;
			cin >> keepPlaying;

		} while (!(keepPlaying == 'N'));
	}

	void round()
	{
		int bet;
		for (int index = 0; index < players.size(); ++index) // write void playerBets()
		{
			cout << "How much would you player " << index + 1 << " like to bet?" << endl;
			cin >> bet;
			
			players.at(index).setBet(bet);
		}

		for (int outerIndex = 0; outerIndex < 2; ++outerIndex) // write void dealPlayers()
		{
			for (int innerIndex = 0; innerIndex < players.size(); ++innerIndex)
			{
				players.at(innerIndex).dealPlayerCard(gameDeck);
			}
		}

		for (int index = 0; index < players.size(); ++index) // write showPlayerHands()
		{
			// show the players hand
		}
		// show the computers hand
		// show the dealers first card

		
		for (int index = 0; index < players.size(); ++index) // void playerTurns()
		{
			cout << "Player " << index + 1 << "'s turn." << endl;
			char playerChoice; 

			do 
			{
				cout << "What would player " << index + 1 << " like to do, hit (Enter: H) or stand (Enter: S)?" << endl;
				cin >> playerChoice;

				if (playerChoice == 'H')
				{
					players.at(index).dealPlayerCard(gameDeck);
					// show player what they got 
				}

				if (players.at(index).hasPlayerBusted())
				{
					cout << "Player " << index + 1 << " has busted!" << endl;
				}

			} while (playerChoice == 'H' && !players.at(index).hasPlayerBusted());
		}

		// computer takes action
		// dealer takes action

		for (int index = 0; index < players.size(); ++index)
		{
			// get dealer hand value
			// get player hand value
			// if player value > dealer, increase their money by bet
			// else if player value < dealer, decrease their money by bet
			// else, do nothing
		}
		
		// payout accordingly. increase by 1 or decrease by 1, or do nothing

		for (int index = 0; index < players.size(); ++index)
		{
			// show everyone's totals 
			// check if their total is less than 0, if so, remove them from vector
			// give players option to quit, if they do, remove them from vector
		}

		// show computer total 
	
		for (int index = 0; index < players.size(); ++index) // write void clearPlayerHands()
		{
			players.at(index).clearHand();
		}
	}

	

	int getNumberOfPlayersLeft()
	{
		return players.size();
	}
};