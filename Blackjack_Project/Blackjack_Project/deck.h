#pragma once
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>
#include <stack>
#include "card.h"


class Deck
{
private:
	vector<Card> deck;
	int numberOfDecks;
	Card lastCardInDeck;
	stack<Card> sixDeckStack; 

public:
	Deck()
	{
		numberOfDecks = 6;
		deckBuilder(numberOfDecks);
		shuffleDeck();
	}
	Deck(int deckNumber)
	{
		numberOfDecks = deckNumber;
		deckBuilder(deckNumber);
		shuffleDeck();
	}

	void deckBuilder(int decks)
	{
		Card card;

		const int SUITS_MAX = 4;
		const int RANKS_MAX = 13;

		int suit = 0;
		int rank = 0;

		const char SUITS[SUITS_MAX] = { 'S', 'D', 'C', 'H' };
		const char RANKS[RANKS_MAX] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };


		for (int deckCount = 0; deckCount < decks; deckCount++)
		{
			for (int suit = 0; suit < SUITS_MAX; suit++)
			{
				for (int rank = 0; rank < RANKS_MAX; rank++)
				{
					card = Card(SUITS[suit], RANKS[rank]);
					deck.push_back(card);
				} // rank
			} // suit
		} // deck
	}
	void shuffleDeck()
	{
		random_shuffle(deck.begin(), deck.end());
		for (int index = 0; index < deck.size(); index++) 
		{
			sixDeckStack.push(deck.at(index)); 
		}
	}
	Card dealCard()
	{
		if (sixDeckStack.size() >= 30)
		{
			lastCardInDeck = sixDeckStack.top();
			sixDeckStack.pop(); 
		}
		else
		{
			resetDeck();
			lastCardInDeck = sixDeckStack.top();
			sixDeckStack.pop();
		}
		return lastCardInDeck;
	}
	void resetDeck()
	{
		while (!sixDeckStack.empty())
			sixDeckStack.pop();

		deckBuilder(numberOfDecks);
		shuffleDeck();
	}
	string lastCardDealtOut() const
	{
		return lastCardInDeck.cardInfo();
	}

};