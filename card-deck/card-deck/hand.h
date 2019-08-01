// hand for player that adds card, gets value and rank
//has an ace or not, or has busted

#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

class Hand
{
private:
	static void setCardValues()
	{
		cardValues['A'] = 1;
		cardValues['2'] = 2;
		cardValues['3'] = 3;
		cardValues['4'] = 4;
		cardValues['5'] = 5;
		cardValues['6'] = 6;
		cardValues['7'] = 7;
		cardValues['8'] = 8;
		cardValues['9'] = 9;
		cardValues['0'] = 10;
		cardValues['J'] = 10;
		cardValues['Q'] = 10;
		cardValues['K'] = 10;
	}

protected:
	std::vector<Card> hand;					// hand of Cards
	static std::map <char, int> cardValues;	// holds card values

public:
	Hand()
	{
		setCardValues();
	}
	Hand(int num)
	{
		Card card = Card();

		hand[0] = card;
		hand[1] = card;

		setCardValues();
	}

	void addCard(Deck &deck)
	{
		hand.push_back(deck.dealCard());
	}
	void addCard(Card &card)
	{
		hand.push_back(card);
	}

	int getValue() const //handles ace card too
	{
		int handValue = 0;
		char rank = ' ';
		int handSize = hand.size();
		bool hasAce = false;

		// determine value of hand
		for (int count = 0; count < handSize; count++)
		{
			// get rank from Card class
			rank = hand[count].getRank();

			if (rank == 'A')
				hasAce = true;

			// use rank to determine card's value
			handValue += cardValues.find(rank)->second;
		} 

		// Ace will be 1 or 11
		if (hasAce) 
		{
			if (handValue + 10 <= 21) 
			{
				handValue += 10;
			} 
		} 

		return handValue;
	}
	int getSize() const //of hand
	{
		return hand.size();
	}

	bool sameRank() const
	{
		bool sameRank;
		int size = hand.size();
		char card1Rank = ' ';

		if (size > 2 || hand[0].getRank() != hand[1].getRank())
		{
			sameRank = false;
		}
		else
		{
			sameRank = true;
		}

		return sameRank;
	}
	bool card2IsAce() const
	{
		bool isItAce = false;
		int size = hand.size();

		if (size == 2 && hand[1].getRank() == 'A')
			isItAce = true;

		return isItAce;
	}

	Card removeCard()
	{
		Card card;

		card = hand.back();
		hand.pop_back();

		return card;
	}

	bool hasBusted() const
	{
		bool busted;

		if (getValue() > 21)
		{
			busted = true;
		}
		else
		{
			busted = false;
		}

		return busted;
	}

	std::string handInfo() const
	{
		std::string outString = "[";
		int handSize_less1 = hand.size() - 1;
		int handSize = hand.size();

		// loop to add card
		for (int count = 0; count < handSize; count++)
		{
			outString += hand[count].cardInfo();
			if (count != handSize_less1)
			{
				outString += ", ";
			}
		}
		outString += "]\n";

		return outString;
	}
	std::string dealerHandInfo() const
	{
		std::string outString = "[XX, ";

		outString += hand[1].cardInfo();

		outString += "]\n\n";

		return outString;
	}


	/*
	//gives 2 cards to dealer and player
	void initializeHands(Deck &deck, Player &player, Dealer &dealer)
	{
		// create a hand for the dealer & user
		for (int count = 0; count < 2; count++)
		{
			dealer.hand + deck;		
			user.hand + deck;		
	}
	*/
};