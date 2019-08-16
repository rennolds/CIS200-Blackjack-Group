#pragma once

class Hand
{
private:
	void setCardValues()
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
		cardValues['T'] = 10; 
		cardValues['J'] = 10;
		cardValues['Q'] = 10;
		cardValues['K'] = 10;
	}

protected:
	vector<Card> hand;		
	map <char, int> cardValues;	

public:
	Hand()
	{
		setCardValues();
	}
	Hand(int num)
	{
		Card card = Card();
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
	int getValue() const 
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
	int getSize() const
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

	void removeCard()
	{
		hand.pop_back();
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

	string handInfo() const
	{
		string outString = "[";
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
	string dealerHandInfo() const
	{
		string outString = hand[0].cardInfo(); 
		return outString;
	}

	int getHandSize()
	{
		return hand.size();
	}

	int getDealerFaceCard() {

		char rank = ' ';
		rank = hand.at(0).getRank();

		return cardValues.find(rank)->second;
	}
};