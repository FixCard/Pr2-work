#include<iostream>
#include<ctime>
#include<string>
#include<vector>

using namespace std;



int main() {
	int f = 10;
	int *mut;
	int &fi = f;
	mut = &f;

	cout << "f=" << f << ", fi=" << fi << ", *mut=" << *mut << endl;
	fi = 20;
	cout << "f=" << f << ", fi=" << fi << ", *mut=" << *mut << endl;

	cout << &f << " " << &fi << " " << mut << " " << &mut << endl;

	// vektorok
	
	vector <int> jegyek(3);
	char bet;
	int szam;
	int i;
	for (i = 0; i < 3; i++) {
		cout << "Adja meg az " << i + 1 << ". tanulo jegyet (1-5): " << endl;
		cin >> jegyek[i];
	}

	cout << "Akar meg jegyet felvenni? (y/n)" << endl;
	cin >> bet;
	if (bet == 'y') {
		do {
			cout << "Jegy (1-5): " << endl;
			cin >> szam;
			jegyek.push_back(szam);
			cout << "akar meg egyet? (y/n)";
			cin >> bet;
			i++;
		} while (bet == 'y');
	}
	
	cout << "Jegyek szama " << jegyek.size() << endl;
	cout << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++) {
		cout << jegyek.at(i) << ", ";
	}

	/*
	jegyek.pop_back();

	cout << endl << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++) {
		cout << jegyek.at(i) << ", ";
	}
	*/

	jegyek.insert(jegyek.begin() + 1, 1);

	cout << endl << endl << "Osztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++) {
		cout << jegyek.at(i) << ", ";
	}
};