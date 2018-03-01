#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> makedeck();
int main()
{
	vector<string> deck = makedeck();
	system("Pause");
	return 0;
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

