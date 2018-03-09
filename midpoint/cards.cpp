#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>

using namespace std;

vector<string> makedeck();
vector<int> shuffle();
void playgame(vector<string>deck, vector<int> order);
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
	for (int i = 0; i <order.size(); i++){
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
		system("Pause");
		//take top card off the deck and find suit
		int newcard = takecard(order);
		cout << "player draws a card: ";
		printcard(deck, newcard);
		int newcardsuit = getsuit(newcard);
		if (hand.size() > 0){
			cout << "players hand is \n";
			printdeck(deck, hand);
				//look at the last card in player hand and find suit
			int lastcard = hand.back();
			int lastcardsuit = getsuit(lastcard);
			//if suits are the same then throw last card from the players hand away
			if (newcardsuit == lastcardsuit){
				hand.pop_back();
			}
		}
		//add new card to players hand
		hand.push_back(newcard); 
	}
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
				suitstring = "spades";
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
	srand(time(NULL));
	for (int i = 0; i < 52; i++){
		int swapwith = rand() % 52;
		int temp = newdeck[i];
		newdeck[i] = newdeck[swapwith];
		newdeck[swapwith] = temp;
	}
	return newdeck;
}