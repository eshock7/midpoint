#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>

using namespace std;

vector<string> makedeck();
vector<int> shuffle();
void playgame(vector<string>deck, vector<int> order);
void clean_hand(vector<string> deck, vector<int>& hand);
bool clean_every_other(vector<string> deck, vector<int>& hand);
bool clean_neighbors(vector<string> deck, vector<int>& hand);
void printdeck(vector<string>deck, vector<int> order);
void printcard(vector<string>deck, vector<int> order, int card);
int takecard(vector<int>& order);
int getsuit(int card);
int main()
{
	vector<string> deck = makedeck();
	vector<int> order = shuffle();

	playgame(deck, order);
	system("Pause");
	return 0;
}
void printdeck(vector<string>deck, vector<int> order){
	for (unsigned int i = 0; i <order.size(); i++){
		printcard(deck, order, i);
	}
}
void printcard(vector<string>deck, int card){
	cout << deck[card] << endl;
}
void printcard(vector<string>deck, vector<int> order, int card){
	cout << deck[order[card]] << endl;
}
void playgame(vector<string> deck, vector<int>order){
	vector<int> hand;
	//go until we run out of cards
	while (order.size() > 0){
		// Wait for player.
		cout << endl;
		system("Pause");
		system("cls");

		//take top card off the deck and give it to player
		int newcard = takecard(order);
		cout << "Player draws a card: ";
		printcard(deck, newcard);
		cout << order.size() << " cards remaining." << endl;

		// show user what they've got
		cout << endl << "Player's hand:" << endl;
		printdeck(deck, hand);
		cout << endl;

		// and add the new card to the hand
		hand.push_back(newcard);

		// remove cards according to the rules
		clean_hand(deck, hand);
	}
}

void clean_hand(vector<string> deck, vector<int>& hand){
	bool changed = true;
	while (changed) {
		bool changed1 = clean_every_other(deck, hand);
		bool changed2 = clean_neighbors(deck, hand);
		changed = changed1 | changed2;
	}
}
bool clean_every_other(vector<string> deck, vector<int>& hand){
	for (int i = 0; i < ((int)hand.size()) - 2; i++){
		if (getsuit(hand.at(i)) == getsuit(hand.at(i + 2))) {
			cout << "Discarding ";
			printcard(deck, hand.at(i));
			hand.erase(hand.begin()+i);
			return true;
		}
	}
	return false;
}

bool clean_neighbors(vector<string> deck, vector<int>& hand){
	for (int i = 0; i < ((int)hand.size()) - 1; i++){
		if (getsuit(hand.at(i)) == getsuit(hand.at(i + 1))) {
			cout << "Discarding ";
			printcard(deck, hand.at(i+1));
			hand.erase(hand.begin() + i+1);
			return true;
		}
	}
	return false;
}

int getsuit(int card){
	return card % 4;
}
int takecard(vector<int>& order){
	int card = order.back();
	order.pop_back();
	return card;
}
vector<string> makedeck(){
	vector<string> deck;
	for (int rank = 1; rank < 14; rank++){
		string rankstring;
		if (rank == 1)
			rankstring = "Ace";
		else if (rank == 11)
			rankstring = "Jack";
		else if (rank == 12)
			rankstring = "Queen";
		else if (rank == 13)
			rankstring = "King";
		else
			rankstring = to_string(rank);

		for (int suit = 1; suit < 5; suit++){
			string suitstring;
			if (suit == 1)
				suitstring = "Clubs";
			else if (suit == 2)
				suitstring = "Diamonds";
			else if (suit == 3)
				suitstring = "Hearts";
			else
				suitstring = "Spades";
			string card = rankstring + " of " + suitstring;
			deck.push_back(card);
		}
	}
	return deck;
}
vector<int> shuffle(){
	vector<int> newdeck;
	for (int i = 0; i < 52; i++){
		newdeck.push_back(i);
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 52; i++){
		int swapwith = rand() % 52;
		int temp = newdeck[i];
		newdeck[i] = newdeck[swapwith];
		newdeck[swapwith] = temp;
	}
	return newdeck;
}