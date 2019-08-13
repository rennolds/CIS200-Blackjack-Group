//deck class, 52 cards, shuffles, and deals

#pragma once
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include "card.h"

using namespace std;

class Deck
{
private:
	vector<Card> deck;
	int numberOfDecks;
	Card lastCardInDeck;


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
		std::random_shuffle(deck.begin(), deck.end());

	}
	Card dealCard()
	{
		if (deck.empty() == false)
		{
			lastCardInDeck = deck.back();
			deck.pop_back();
		}
		else
		{
			std::cout << "Deck is low. Reshuffling!";
			resetDeck();
			lastCardInDeck = deck.back();
			deck.pop_back();
		}

		return lastCardInDeck;
	}
	void resetDeck()
	{
		// clearing deck
		while (!deck.empty())
			deck.pop_back();

		// creating deck
		deckBuilder(numberOfDecks);
		shuffleDeck();
	}

	std::string lastCardDealtOut() const
	{
		return lastCardInDeck.cardInfo();
	}

};