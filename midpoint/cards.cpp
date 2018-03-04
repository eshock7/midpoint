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
int main()
{
	vector<string> deck = makedeck();
	vector<int> order = shuffle();
	printdeck(deck, order);
	system("Pause");
	return 0;
}
void printdeck(vector<string>deck, vector<int> order){
	for (int i = 0; i < 52; i++){
		cout << deck[order[i]] << endl;
	}
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