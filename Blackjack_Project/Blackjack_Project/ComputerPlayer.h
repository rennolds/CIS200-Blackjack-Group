#pragma once
#include "Player.h"

class ComputerPlayer : public Player 
{

public:

	ComputerPlayer() : Player("Computer Player") 
	{

	}

	bool determineHitOrStand(int dealerFaceUpCard) 
	{

		if (this->getPlayerHandValue() <= 11)
		{
			return true;
		}

		else if (this->getPlayerHandValue() == 12) 
		{
			if (dealerFaceUpCard >= 4 && dealerFaceUpCard <= 6) 
			{
				return false;
			}
			else 
			{
				return true;
			}
		}

		else if (this->getPlayerHandValue() >= 13 && this->getPlayerHandValue() <= 15) 
		{
			if (dealerFaceUpCard <= 6 || (dealerFaceUpCard == 10 && this->getPlayerHandValue() == 15)) 
			{
				return false;
			}
			else 
			{
				return true;
			}
		}

		else if (this->getPlayerHandValue() == 16) 
		{
			if (dealerFaceUpCard == 7 || dealerFaceUpCard == 8)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	void setBet() 
	{
		bet = 1;
	}

	int dealerFaceUpCard() 
	{
		return playerHand.getDealerFaceCard();
	}

	string getDealerHandInfo() 
	{
		string playerHandInfo = playerHand.dealerHandInfo(); 
		return playerHandInfo; 
	}
};