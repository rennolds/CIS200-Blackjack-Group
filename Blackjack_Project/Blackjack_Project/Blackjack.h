#pragma once
#include<vector>
//#include"Player.h"
#include"deck.h"
#include "ComputerPlayer.h"


using namespace std;

class Blackjack
{

private:
	vector<Player> players;
	Deck gameDeck;
	ComputerPlayer singleComputerPlayer;
	ComputerPlayer dealer;
	char keepPlaying;

public:

	Blackjack(int numberOfPlayers)
	{
		for (int index = 0; index < numberOfPlayers; index++)
		{
			Player newPlayer;
			players.push_back(newPlayer);
		}
		Deck gameDeck;
		keepPlaying = 'Y';
	}

	void play()
	{
		do
		{
			round();

			cout << "Press N to quit the game, press anything to go to the next round." << endl;
			cin >> keepPlaying; // CHECK IF CHARACTER
			keepPlaying = toupper(keepPlaying);

		} while (!(keepPlaying == 'N'));
	}

	void round()
	{
		int bet;
		for (int index = 0; index < players.size(); ++index) // write void playerBets()
		{
			cout << "How much would you player " << index + 1 << " like to bet?" << endl;
			cin >> bet; // CHECK IF ITS A NUMBER

			players.at(index).setBet(bet);
		}

		singleComputerPlayer.setBet();

		for (int outerIndex = 0; outerIndex < 2; ++outerIndex) // write void dealPlayers()
		{
			for (int innerIndex = 0; innerIndex < players.size(); ++innerIndex)
			{
				players.at(innerIndex).dealPlayerCard(gameDeck);
			}
			singleComputerPlayer.dealPlayerCard(gameDeck);
			dealer.dealPlayerCard(gameDeck);
		}

		int dealerFaceUpCard = dealer.dealerFaceUpCard();

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
				cout << "What would player " << index + 1 << " like to do, hit (Enter: H) or stand (Enter: S)?" << endl; // CHECK IF H OR S
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

		cout << "Computer player will now decide what to do: " << endl;

		// computer player decides to hit or stand
		do {
			if (singleComputerPlayer.determineHitOrStand(dealerFaceUpCard)) {
				singleComputerPlayer.dealPlayerCard(gameDeck);
			}
		} while (singleComputerPlayer.determineHitOrStand(dealerFaceUpCard));

		// dealer decides to hit or stand
		do {
			if (dealer.getPlayerHandValue() < 17) {
				dealer.dealPlayerCard(gameDeck);
			}

		} while (dealer.getPlayerHandValue() < 17);

		// determines whether to pay out or subtract winnings for players
		for (int index = 0; index < players.size(); ++index)
		{

			if (players.at(index).getPlayerHandValue() > dealer.getPlayerHandValue()) {
				players.at(index).payOut();
			}
			else if (players.at(index).getPlayerHandValue() < dealer.getPlayerHandValue()) {
				players.at(index).loseBet();
			}

		}

		// determines whether to pay out or subtract winnings for computer player
		if (singleComputerPlayer.getPlayerHandValue() > dealer.getPlayerHandValue()) {
			singleComputerPlayer.payOut();
		}
		else if (singleComputerPlayer.getPlayerHandValue() > dealer.getPlayerHandValue()) {
			singleComputerPlayer.loseBet();
		}


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
		singleComputerPlayer.clearHand();
		dealer.clearHand();
	}

	int getNumberOfPlayersLeft()
	{
		return players.size();
	}
};