#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>

using namespace std;

vector<string> makedeck();
vector<int> shuffle();
void playgame(vector<string>deck, vector<int> dealer);
void clean_player(vector<string> deck, vector<int>& player);
bool clean_every_other(vector<string> deck, vector<int>& player);
bool clean_neighbors(vector<string> deck, vector<int>& player);
void printdeck(vector<string>deck, vector<int> cards);
void printcard(vector<string>deck, int card);
int takecard(vector<int>& dealer);
int getsuit(int card);
//tells player instructions, and sets up game
int main()
{
	cout << "Welcome to Mouradov Grandmothers Card Game!!!" << endl;
	cout << "The rules to this game are simple."<< endl;
	cout << "You will be dealt on card at a time." << endl;
	cout << "If the card drawn matches the card previously drawn, then the most recent card drawn will be removed." << endl;
	cout << "If the card drawn matches the card drawn before the previosly drawn card, then that card will be removed." << endl;
	cout << "When all the cards have been drawn, and there are 4 or less cards in your hand, you will be declared the winner." << endl;
	cout << "If there are more than four cards in your hand, you will be declared the loser and will be given a choice to restart or quit." << endl;
	cout << "Now get ready to play!!!!." << endl;
	vector<string> deck = makedeck();
	vector<int> dealer = shuffle();

	bool play_again = true;
	while (play_again) {
		playgame(deck, dealer);
		cout << endl << "Do you want to play again? <y/n> ";
		string ans;
		cin >> ans;
		if (ans == "n") play_again = false;
	}
	system("Pause");
	return 0;
}
//sets up card deck
void printdeck(vector<string>deck, vector<int> cards){
	for (unsigned int i = 0; i <cards.size(); i++){
		printcard(deck, cards.at(i));
	}
}
void printcard(vector<string>deck, int card){
	cout << deck[card] << endl;
}
//allows the player to play the game
void playgame(vector<string> deck, vector<int>dealer){
	vector<int> player;
	//go until we run out of cards
	while (dealer.size() > 0){
		// Wait for player.
		cout << endl;
		system("Pause");
		system("cls");

		//take top card off the deck and give it to player
		int newcard = takecard(dealer);
		cout << "Player draws a card: ";
		printcard(deck, newcard);
		cout << dealer.size() << " cards remaining." << endl;

		// show user what they've got
		cout << endl << "Player's hand:" << endl;
		printdeck(deck, player);
		cout << endl;

		// and add the new card to the player
		player.push_back(newcard);

		// remove cards according to the rules
		clean_player(deck, player);
	}
	//declares win or loss
	if (player.size() < 5){
		cout << "You win!" << endl;
	}
	else {
		cout << "You lose, too many cards..." << endl;
	}
}
//goes through and clears cards, telling player which cards were cleared
void clean_player(vector<string> deck, vector<int>& player){
	bool changed = true;
	while (changed) {
		bool changed1 = clean_every_other(deck, player);
		bool changed2 = clean_neighbors(deck, player);
		changed = changed1 | changed2;
	}
}
bool clean_every_other(vector<string> deck, vector<int>& player){
	for (int i = 0; i < ((int)player.size()) - 2; i++){
		if (getsuit(player.at(i)) == getsuit(player.at(i + 2))) {
			cout << "Discarding ";
			printcard(deck, player.at(i));
			player.erase(player.begin()+i);
			return true;
		}
	}
	return false;
}

bool clean_neighbors(vector<string> deck, vector<int>& player){
	for (int i = 0; i < ((int)player.size()) - 1; i++){
		if (getsuit(player.at(i)) == getsuit(player.at(i + 1))) {
			cout << "Discarding ";
			printcard(deck, player.at(i+1));
			player.erase(player.begin() + i+1);
			return true;
		}
	}
	return false;
}
//checks for a win
int getsuit(int card){
	return card % 4;
}
int takecard(vector<int>& dealer){
	int card = dealer.back();
	dealer.pop_back();
	return card;
}
//lists all cards and gets ready to shuffle them
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
//shuffles card deck
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