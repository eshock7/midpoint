#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vectorA;
	for (int i = 0; i < 4; i++);
	vectorA.push_back(rand() % 100);

	for (int i = 0; i < 4; i++)
		cout << vectorA.at(i) << endl;

	vectorA.insert(vectorA.begin(), 1, 0);
	for (int i = 0; i < vectorA.size(); i++)
		cout << vectorA.at(i) << endl;
	vectorA.assign(2, 100);

	system("pause");
	return 0;
}