#pragma once
#include"hand.h"
//#include"deck.h"

class Player
{
private:
	bool busted;
	int money;
	bool eliminated;
	bool didPlayerLose;
	string playerName;

protected:
	int bet;
	Hand playerHand;

public:
	Player(string name)
	{
		busted = false;
		money = 100;
		bet = 0;
		eliminated = false;
		playerName = name;
	}

	virtual void setBet(int num)
	{
		bet = num;
	}

	void payOut()
	{
		money += bet;
	}

	void loseBet()
	{
		money -= bet;
	}

	void dealPlayerCard(Deck &deck)
	{
		playerHand.addCard(deck);
	}

	bool hasPlayerBusted()
	{
		return playerHand.hasBusted();
	}

	int getPlayerHandValue()
	{
		return playerHand.getValue();
	}

	void clearHand()
	{
		int numberOfCards = playerHand.getHandSize();
		for (int index = 0; index < numberOfCards; index++)
		{
			playerHand.removeCard();
		}
	}

    string getPlayerHandInfo()
	{
		string playerHandInfo;
		playerHandInfo = playerHand.handInfo();
		return playerHandInfo;
	}

	int getBet()
	{
		return bet;
	}

	int getMoney()
	{
		return money;
	}

	bool isPlayerEliminated()
	{
		return eliminated;
	}

	void setPlayerToEliminated()
	{
		eliminated = true;
	}

	void playerLost()
	{
		didPlayerLose = true;
	}

	void playerWon()
	{
		didPlayerLose = false;
	}

	bool getDidPlayerLose()
	{
		return didPlayerLose;
	}

	string getName()
	{
		return playerName;
	}

};