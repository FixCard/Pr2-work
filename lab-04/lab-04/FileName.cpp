#include <iostream>
#include <string>
#include <ctime>
#include <array>

using namespace std;

#define PI 3.14145
#define osszead(X, Y) (X) + (Y)
#define szoroz(X, Y) (X) * (Y)
#define osztas(X, Y) X/Y

int a = 5;

int FV(int b) {
	cout << b << endl;
	cout << a << endl;
	char x = 'c';

	{
		double b = 3.5;
		cout << b << endl;
		cout << a << endl;
		cout << x << endl;
	}
	cout << x << endl;
	return a + 1;
}

int add(int a, int b) {
	return a + b;
}

int main() {
	//int a = 15;
	cout << FV(a) << endl;

	cout << "Makro: " << endl;
	cout << osszead(3, 4) << endl;
	cout << szoroz(3, 4) << endl;
	cout << osztas(4, 4) << endl;
	cout << szoroz(PI, 5 * 5) << endl;

	cout << endl << endl << "Time: " << endl;
	clock_t kezd, veg;
	kezd = clock();
	int k;
	for (int i = 0; i < 2 * pow(10, 9); i++) {
		// k = osszead(1, 1); 80666
		// k = 1 + 1; 80634
		k = add(1, 1); // 90402bbnbnbnbnbnbnbnbnbnbnnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbbnbnnbnbbnnbnbnbnbnbnbbnbnbbnbnbnbnbnbnnbnbnbnbnbnbbnbnbnbnbnnbnbnbnbnbbnnbbnbnbnbnbnbnbnnbnbnbnbnbnbnbnbbbnbbbnnbbnnbbnbnbnbnnbnbnbnbnbnbnbnbnbnbnbnbnbnnbnbnbnbnbnbnbnbnbnbbnnbbnnbnbnbnbnbnnnbnbnbnbbnbnbnnbbnbnnbnbnbnbnbnbnbnbnbnbnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnnbbnbnnbnbbnnbnbnbnbbnnbnbbnnbnbnnbnbnbbnnbnbnbnbbnbnbnnbnbbnbnbnnbnbnbbnbnbnbnbnbnbnbnbnbnbnnbbnnbnbnbbnnbnbnbnbbnbnbnbnbnbbnnbnbnbnbbnnbnbnbbnnbbnbnnbbnbnnbbnbnnbnbbnnbnbnbnbbnbnbnbnnbbnnbnbnbbnnbnbnbnbnbnbnbnbbnbnnbbnbnnbbnnbnbnbnbnbbnnbnnbnbbnbnnbnbnbbnnnbnbbnbnbnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbbnbnbnbnbnbnbnbnbnbnnbnbnbnbnbnbnbnbnbnbbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnnbnbnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnbnbnnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnbnbnbbnbnbnbnbbnbnbnbnbnbnbbbnbbnbnbnbnbnbnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnnbbnbnbnbnbnbnbnbnbnbnbnbnbbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnbnnbnbnbnbnbbnnbnbbnbnbnnbnbnbnbnbbnbnbnnbbnnbbnbnnbnbbnbnnbnbbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnnbnbnbnnbbnnbnbnbbnnbnbnbbnbnbnbnbnnbnbbnnbnbnbnbnbnbnbnnbbnbnbnbnbnnbbnnbbnbnbnbnbnbnnbnbnbnbnbnbnbnnbbnbnbnnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnnbnbbnnbbnnbnbbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnbnn
	}

	veg = clock();
	cout << (float)(veg - kezd) << endl;
	return 0;
}