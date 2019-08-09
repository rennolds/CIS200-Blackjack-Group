#pragma once

#include<vector>
#include"hand.h"
#include"deck.h"

using namespace std;

class Player
{
private:
	bool busted;
	int money;


protected:
	int bet;
	Hand playerHand;

public:
	Player()
	{
		busted = false;
		money = 100;
		bet = 0;
	}

	bool checkBusted()
	{
		return busted;
	}

	void bustPlayer()
	{
		busted = true;
		money -= bet;
		bet = 0;
	}

	virtual void setBet(int num)
	{
		bet = num;
	}

	void payOut()
	{
		money += bet * 2;
		bet = 0;
	}

	void loseBet()
	{
		money -= bet * 2;
		bet = 0;
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

};