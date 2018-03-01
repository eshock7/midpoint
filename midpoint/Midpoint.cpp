#include <iostream>
#include <string>

using namespace std;

double* midPoint(double x1, double y1, double x2, double y2);

/*
int main(){
	double *result = midPoint(1.0, 2.0, 4.0, 5.0);
	double correctanswer[2] = { 2.5, 3.5 };
	if (correctanswer[0] == result[0] && correctanswer[1] == result[1])
		cout << "Pass\n";
	else
		cout << "Fail\n";
	string dummy;
	cin >> dummy;
	return 0;
}
*/

double* midPoint(double x1, double y1, double x2, double y2) {
	double midpointholder[2];
	double midpointx = (x1 + x2) / 2;
	double midpointy = (y1 + y2) / 2;
	midpointholder[0] = midpointx;
	midpointholder[1] = midpointy;
	return midpointholder;
}
