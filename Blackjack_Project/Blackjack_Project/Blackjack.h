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
	int numberOfRounds;

public:

	Blackjack(int numberOfPlayers, vector<string> playerNames)
	{
		for (int index = 0; index < numberOfPlayers; index++)
		{
			Player newPlayer(playerNames.at(index));
			players.push_back(newPlayer);
		}
		Deck gameDeck;
		keepPlaying = 'Y';
		numberOfRounds = 0;
	}

	void play()
	{
		do
		{
			numberOfRounds++;
			cout << "Round: " << numberOfRounds << endl;
			round();

			if (players.size() != 0)
			{
				cout << "Press N to quit the game, press anything to go to the next round." << endl;
				cin >> keepPlaying; // CHECK IF CHARACTER
				keepPlaying = toupper(keepPlaying);
			}
			else
			{
				cout << "No human players left, ending the game." << endl;
				keepPlaying = 'N';
			}

		} while (!(keepPlaying == 'N'));
	}

	void playerBets()
	{
		int bet;
		for (int index = 0; index < players.size(); ++index) // write void playerBets()
		{
			cout << "How much would " << players.at(index).getName() << " like to bet?" << endl;
			cin >> bet; // CHECK IF ITS A NUMBER

			// got from https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
			
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input, please enter a number for your bet:" << endl;
					cin >> bet;
				}

				else if (!cin.fail())
				{
					while (bet > players.at(index).getMoney() || bet <= 0) 
					{
						cout << players.at(index).getName() << " has $" << players.at(index).getMoney() << ". Please make a bet that is within their ability: ";
						cin >> bet;
					}
					players.at(index).setBet(bet);
				}
			

			/*while (bet > players.at(index).getMoney() || bet < 0) {
				cout << players.at(index).getName() << " has $" << players.at(index).getMoney() << ". Please make a bet that is within their ability: ";
				cin >> bet; 
			}
			players.at(index).setBet(bet);
			*/
		}
		singleComputerPlayer.setBet();
	}

	void dealCards()
	{
		for (int outerIndex = 0; outerIndex < 2; ++outerIndex) // write void dealPlayers()
		{
			for (int innerIndex = 0; innerIndex < players.size(); ++innerIndex)
			{
				players.at(innerIndex).dealPlayerCard(gameDeck);
			}
			singleComputerPlayer.dealPlayerCard(gameDeck);
			dealer.dealPlayerCard(gameDeck);
		}

	}

	void showHands()
	{
		for (int index = 0; index < players.size(); ++index) // write showPlayerHands()
		{
			cout << players.at(index).getName() << "'s hand: " << players.at(index).getPlayerHandInfo() << endl;
		}
		cout << "Computer Player hand: " << singleComputerPlayer.getPlayerHandInfo() << endl;
		cout << "Dealer's face-up card: " << dealer.getPlayerHandInfo() << endl; 
		// show the dealers first card
	}

	void playerTurns()
	{

		for (int index = 0; index < players.size(); ++index) // void playerTurns()
		{
			cout << players.at(index).getName() << "'s turn." << endl;

			char playerChoice;

			do
			{
					cout << "What would " << players.at(index).getName() << " like to do, hit (Enter: H) or stand (Enter: S)?" << endl; // CHECK IF H OR S
					cin >> playerChoice;

					playerChoice = toupper(playerChoice);

					if (playerChoice != 'H' && playerChoice != 'S')
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have entered wrong input, please enter hit (Enter: H) or stand (Enter: S)" << endl;
						cin >> playerChoice;
						playerChoice = toupper(playerChoice);
					}

						if (playerChoice == 'H' || playerChoice == 'h')
						{
							players.at(index).dealPlayerCard(gameDeck);
							cout << players.at(index).getPlayerHandInfo() << endl;
						}

						if (playerChoice == 'S' || playerChoice == 's')
						{
							cout << "Player" << players.at(index).getName() << "has chosen to stand!";
							
						}

						if (players.at(index).hasPlayerBusted())
						{
							cout << players.at(index).getName() << " has busted!" << endl;
						}
					
			} while (playerChoice == 'H' && !players.at(index).hasPlayerBusted());
			

		}
	}

	void payout()
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (dealer.hasPlayerBusted() && !players.at(index).hasPlayerBusted()) {
				players.at(index).payOut();
				players.at(index).playerWon();
			}
			else if (players.at(index).getPlayerHandValue() <= dealer.getPlayerHandValue() || players.at(index).hasPlayerBusted())
			{
				players.at(index).loseBet();
				players.at(index).playerLost();
			}
			else if (players.at(index).getPlayerHandValue() == dealer.getPlayerHandValue()) {

			}
			else
			{
				players.at(index).payOut();
				players.at(index).playerWon();
			}
		}

		if (dealer.hasPlayerBusted() && !singleComputerPlayer.hasPlayerBusted()) {
			singleComputerPlayer.payOut();
			singleComputerPlayer.playerWon();
		}

		else if (singleComputerPlayer.getPlayerHandValue() < dealer.getPlayerHandValue() || singleComputerPlayer.hasPlayerBusted())
		{
			singleComputerPlayer.loseBet();
			singleComputerPlayer.playerLost();
		}
		else if (singleComputerPlayer.getPlayerHandValue() == dealer.getPlayerHandValue()) {

		}

		else if (singleComputerPlayer.getPlayerHandValue() > dealer.getPlayerHandValue())
		{
			singleComputerPlayer.payOut();
			singleComputerPlayer.playerWon();
		}
		
	}

	void showResults()
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (players.at(index).getDidPlayerLose() && players.at(index).getMoney() <= 0)
			{
				cout << players.at(index).getName() << " bet $" << players.at(index).getBet() << " and lost." << endl;
				cout << "New total: $" << players.at(index).getMoney() << "." << endl;
				cout << players.at(index).getName() << " is out of money!" << endl;
				players.at(index).setPlayerToEliminated();
			}
			else if (players.at(index).getDidPlayerLose())
			{
				cout << players.at(index).getName() << " bet $" << players.at(index).getBet() << " and lost." << endl;
				cout << "New total: $" << players.at(index).getMoney() << "." << endl;
			}
			else if (players.at(index).getPlayerHandValue() == dealer.getPlayerHandValue()) {
				cout << players.at(index).getName() << " bet $" << players.at(index).getBet() << " and broke even." << endl;
				cout << "New total: $" << players.at(index).getMoney() << "." << endl;
			}
			else
			{
				cout << players.at(index).getName() << " bet $" << players.at(index).getBet() << " and won." << endl;
				cout << "New total: $" << players.at(index).getMoney() << "." << endl;
			}
		}

		if (singleComputerPlayer.getDidPlayerLose() && singleComputerPlayer.getMoney() <= 0)
		{
			cout << "Computer player bet $" << singleComputerPlayer.getBet() << " and lost." << endl;
			cout << "New total: $" << singleComputerPlayer.getMoney() << "." << endl;
			cout << "Computer player is out of money!" << endl;
			singleComputerPlayer.setPlayerToEliminated();
		}
		else if (singleComputerPlayer.getDidPlayerLose())
		{
			cout << "Computer player bet $" << singleComputerPlayer.getBet() << " and lost." << endl;
			cout << "New total: $" << singleComputerPlayer.getMoney() << "." << endl;
		}
		else if (singleComputerPlayer.getPlayerHandValue() == dealer.getPlayerHandValue()) {
			cout << "Computer player bet $" << singleComputerPlayer.getBet() << " and broke even." << endl;
			cout << "New total: $" << singleComputerPlayer.getMoney() << "." << endl;
		}
		else
		{
			cout << "Computer player bet $" << singleComputerPlayer.getBet() << " and won." << endl;
			cout << "New total: $" << singleComputerPlayer.getMoney() << "." << endl;
		}
	}

	void clearHands()
	{
		for (int index = 0; index < players.size(); ++index) 
		{
			players.at(index).clearHand();
		}
		singleComputerPlayer.clearHand();
		dealer.clearHand();
	}

	void dealerAndComputerAction()
	{
		int dealerFaceUpCard = dealer.dealerFaceUpCard();

		cout << "Computer player will now decide what to do: " << endl;

		// computer player decides to hit or stand
		do
		{
			if (singleComputerPlayer.determineHitOrStand(dealerFaceUpCard))
			{
				singleComputerPlayer.dealPlayerCard(gameDeck);
				cout << "Computer's hand: " << singleComputerPlayer.getPlayerHandInfo() << endl;
			}
		} while (singleComputerPlayer.determineHitOrStand(dealerFaceUpCard));

		// dealer decides to hit or stand
		do
		{
			if (dealer.getPlayerHandValue() < 17)
			{
				dealer.dealPlayerCard(gameDeck);
			}

			
		} while (dealer.getPlayerHandValue() < 17);

		cout << "Dealer's hand: " << dealer.getPlayerHandInfo() << endl;

		if (dealer.hasPlayerBusted()) {
			cout << "The dealer has busted!" << endl;
		}
		cout << endl; 
	}

	void removeEliminatedPlayers()
	{
		for (int index = 0; index < players.size(); ++index)
		{
			if (players.at(index).isPlayerEliminated())
			{
				players.erase(players.begin() + index);
				index--;
			}
		}
	}

	void round()
	{
		playerBets(); // let players bet, computer bets 1 automatically
		dealCards(); // deal cards to players, computer, and dealer
		showHands(); // show all the cards dealt (DOESN'T SHOW DEALER YET
		playerTurns(); // lets players take action
		dealerAndComputerAction(); // computes dealer and computer action
		payout(); // pays out players/computer
		showResults(); // shows results of the round
		removeEliminatedPlayers(); // removes any players that went below 0 
		clearHands(); // clears hands of players 
	}

	int getNumberOfPlayersLeft()
	{
		return players.size();
	}
};