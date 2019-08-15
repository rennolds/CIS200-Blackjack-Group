#pragma once
#include"deck.h"
#include "ComputerPlayer.h"

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

			cout << "Press N to quit the game, press anyother single key to go to the next round." << endl;
			cin >> keepPlaying;
			keepPlaying = toupper(keepPlaying);
		
		} while (!(keepPlaying == 'N'));
	}

	void playerBets()
	{
		int bet;
		for (int index = 0; index < players.size(); ++index) 
		{
			cout << "How much would " << players.at(index).getName() << " like to bet?" << endl;
			cin >> bet;

			// based off of https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
			
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input, please enter a number for your bet:" << endl;
					cin >> bet;
					players.at(index).setBet(bet);
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
		}
		singleComputerPlayer.setBet();
	}

	void dealCards()
	{
		for (int outerIndex = 0; outerIndex < 2; ++outerIndex) 
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
		for (int index = 0; index < players.size(); ++index)
		{
			cout << players.at(index).getName() << "'s hand: " << players.at(index).getPlayerHandInfo() << endl;
		}
		cout << "Computer player's hand: " << singleComputerPlayer.getPlayerHandInfo() << endl;
		cout << "Dealer's face-up card: " << dealer.getDealerHandInfo() << endl; 
	}

	void playerTurns()
	{

		for (int index = 0; index < players.size(); ++index) 
		{
			cout << players.at(index).getName() << "'s turn." << endl;
			char playerChoice;

			do
			{
					cout << "What would " << players.at(index).getName() << " like to do, hit (Enter: H) or stand (Enter: S)?" << endl;
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
							cout << "Player " << players.at(index).getName() << " has chosen to stand!" << endl;
							
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
			if (dealer.hasPlayerBusted() && !players.at(index).hasPlayerBusted()) // dealer busts
			{
				players.at(index).payOut();
				players.at(index).playerWon();
			}
			else if (players.at(index).getPlayerHandValue() <= dealer.getPlayerHandValue() || players.at(index).hasPlayerBusted()) // player lost
			{
				players.at(index).loseBet();
				players.at(index).playerLost();
			}
			else if (players.at(index).getPlayerHandValue() == dealer.getPlayerHandValue()) 
			{
				// hands are equal, do nothing
			}
			else // player won 
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
		else if (singleComputerPlayer.getPlayerHandValue() == dealer.getPlayerHandValue()) 
		{
			// equal hands, do nothing
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

		while (singleComputerPlayer.determineHitOrStand(dealerFaceUpCard)) 
		{
			singleComputerPlayer.dealPlayerCard(gameDeck);
		}
		cout << "\nComputer player's hand: " << singleComputerPlayer.getPlayerHandInfo() << endl;

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
		playerBets();
		dealCards(); 
		showHands(); 
		playerTurns(); 
		cout << endl;
		dealerAndComputerAction(); 
		cout << endl;
		payout(); 
		cout << endl;
		showResults(); 
		cout << endl;
		removeEliminatedPlayers();
		clearHands(); 
	}
};