#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Teglalap {
	private: int mag, alap;
	public: bool init(int a, int b) {
		if (a > 0 && b > 0) {
			mag = a;
			alap = b;
			return true;
		}
		cout << "Hiba az alap es a magassag nem lehet negativ!" << endl;
		return false;
	}
	public: int ter() {
		return alap * mag;
	}
	public: int ker() {
		return 2 * (alap + mag);
	}
	public: int getAlap() {
		return alap;
	}
	public: int getMag() {
		return mag;
	}
};

int main() {
	int old1, old2;
	cout << "Adja meg a teglalap oldalait: " << endl;


	Teglalap t1, t2;
	bool inited = false;
	while (!inited) {
		cin >> old1;
		cin >> old2;
		inited = t2.init(old1, old2);
	}
	t1.init(5, 10);
	t2.init(old1, old2);

	cout << "Az elso teglalap terulete: " << t1.ter() << " kerulete: " << t1.ker() << endl << "Masodik teglalap terulete: " << t2.ter() << " kerulete: " << t2.ker() << endl;
	cout << "Az elso teglalap magassaga: " << t1.getMag() << endl;
}


