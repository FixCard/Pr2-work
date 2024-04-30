#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Series {
	string name;
	int season;
	int episodes;
	int lenght;
	int price;
};

class Filmek {
	int db;
	Series* tmb;

	public:
		Filmek(string file_name);
		int Getadatdb();
		int Osszesreszszama();
		Series Legdragabb();
		void Kiir();

		~Filmek();
};

int main()
{
	string file_name = "Filmsorozatok.txt";
	Filmek F(file_name);
	F.Kiir();
	cout << "Sorozatok szama: " << F.Getadatdb() << endl;
	cout << "Reszek szama: " << F.Osszesreszszama() << endl;

	Series most_expensive = F.Legdragabb();
	cout << "Legdragabb film: " << most_expensive.name << ", " << most_expensive.price << endl;
}

Filmek::Filmek(string file_name) {
	db = 0;
	string row;
	ifstream be(file_name);

	if (be.fail()) {
		cout << "Hiba a fajl megnyitasa soran." << endl;
		return;
	}

	while (!be.eof()) {
		getline(be, row);
		db++;
	}
	be.seekg(0, ios::beg);
	//be.close();

	//cout << "A fajlban " << db << " sorozat talalhato" << endl;

	int i = 0;
	tmb = new Series[db];
	while (!be.eof()) {
		getline(be, tmb[i].name, ';');

		getline(be, row, ';');
		tmb[i].season = stoi(row);

		getline(be, row, ';');
		tmb[i].episodes = stoi(row);

		getline(be, row, ';');
		tmb[i].lenght = stoi(row);

		getline(be, row);
		tmb[i].price = stoi(row);

		i++;
	}
	be.close();
}

Filmek::~Filmek() {
	delete[] tmb;
}

int Filmek::Getadatdb() {
	return db;
}

int Filmek::Osszesreszszama() {
	int all_films = 0;
	for (int i = 0; i < db; i++) {
		all_films += tmb[i].season * tmb[i].episodes;
	}
	return all_films;
}

Series Filmek::Legdragabb() {
	int most_expensive_index = 0;
	for (int i = 1; i < db; i++) {
		if (tmb[most_expensive_index].price < tmb[i].price) {
			most_expensive_index = i;
		}
	}
	return tmb[most_expensive_index];
}

void Filmek::Kiir() {
	cout << setw(15) << "Sorozat" << setw(8) << "Evad" << setw(10) << "Epizodok" << setw(8) << "Hossz" << setw(8) << "Ar" << endl;

	for (int i = 0; i < db; i++) {
		cout << setw(15) << tmb[i].name << setw(8) << tmb[i].season << setw(10) << tmb[i].episodes << setw(8) << tmb[i].lenght << setw(8) << tmb[i].lenght << endl;
	}
}