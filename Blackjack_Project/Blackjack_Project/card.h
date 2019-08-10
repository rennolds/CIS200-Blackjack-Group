//card class
//makes a single card that can be used by deck class
//collection of cards that can be shuffled

//https://codereview.stackexchange.com/questions/41810/card-and-deck-classes
//http://www.cplusplus.com/forum/general/163824/

#pragma once
#include <string>

using namespace std;

class Card
{
private:
	char suit;	//card suit
	char rank;	//card number

public:
	Card()
	{
		suit = 'S';
		rank = 'R';
	}
	Card(char s, char r)
	{
		suit = s;
		rank = r;

	}

	void setSuit(char s)
	{
		suit = s;
	}
	void setRank(char r)
	{
		rank = r;
	}
	char getSuit() const
	{
		return suit;
	}
	char getRank() const
	{
		return rank;
	}

	//prints cards suit and rank as SR, (SuitRank)
	string cardInfo() const
	{
		char card[2];

		card[0] = getRank();
		card[1] = getSuit();

		string info(card, 2);

		return info;
	}
};