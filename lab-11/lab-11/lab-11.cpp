#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct jatekos {
    string nev;
    int szul;
    string poszt;
    int meccs, loves, gol;
};

class Labdarugo {
    int db;
    jatekos* tmb;
public:
    Labdarugo(string filenev);
    ~Labdarugo();
    void kiir();
    int OsszLoves();
    jatekos legtobbgol();
    void Fiatalok();
    jatekos* Egyenlo();
};



int main() {
    string filenev = "jatekosok.txt";
    Labdarugo L(filenev);
    L.kiir();
    cout << endl << "Osszes loves: " << L.OsszLoves() << endl;

    jatekos legtobbetRugottSanyi = L.legtobbgol();
    cout << endl << "legtobb golt rugta: " << legtobbetRugottSanyi.nev << endl << endl;

    L.Fiatalok();
    
    jatekos* e = L.Egyenlo();
    cout << endl << e[3].nev << endl;

    return 0;
}

Labdarugo::Labdarugo(string filenev) {
    ifstream be(filenev);

    if (be.fail()) {
        cout << "Hibas fajl olvasas." << endl;
        exit(1);
    }

    string sor;
    be >> db;
    tmb = new jatekos[db];

    for (int i = 0; i < db; i++) {
        getline(be, tmb[i].nev, ':');
        getline(be, sor, ':');
        tmb[i].szul = stoi(sor);
        getline(be, tmb[i].poszt, ':');
        getline(be, sor, ':');
        tmb[i].meccs = stoi(sor);
        getline(be, sor, ':');
        tmb[i].loves = stoi(sor);
        getline(be, sor);
        tmb[i].gol = stoi(sor);

    }

    be.close();
}

Labdarugo::~Labdarugo() {
    delete[] tmb;
}

void Labdarugo::kiir() {
    cout.setf(ios::left);
    cout << setw(12) << "Nev" << setw(10) << "Szul." << setw(10) << "poszt" << setw(10) << "meccs" << setw(10) << "loves" << setw(10) << "gol" << endl;

    for (int i = 0; i < db; i++) {
        cout << setw(10) << tmb[i].nev << setw(10) << tmb[i].szul << setw(10) << tmb[i].poszt << setw(10) << tmb[i].poszt << setw(10) << tmb[i].loves << setw(10) << tmb[i].gol << endl;
    }
}

int Labdarugo::OsszLoves() {
    int osszloves = 0;
    for (int i = 0; i < db; i++) {
        osszloves += tmb[i].loves;
    }
    return osszloves;
}

jatekos Labdarugo::legtobbgol() {
    
    int gol = 0;
    for (int i = 1; i < db; i++) {
       
        
        if (tmb[gol].gol < tmb[i].gol) {
            gol = i;
        }
        
        
    }
    return tmb[gol];
}

void Labdarugo::Fiatalok() {
    int start = 1995;
    for (int i = 0; i < db; i++) {
        if (tmb[i].szul >= start) {
            cout << "Fiatal: " << tmb[i].nev << ", " << tmb[i].szul << endl;
        }
    }
}

jatekos* Labdarugo::Egyenlo() {
    int egyenloek = 0;
    jatekos* e = new jatekos[db];
    for (int i = 0; i < db; i++) {
        for (int j = 0; j < db; j++) {
            if (j != i && tmb[i].gol == tmb[j].gol) {
                e[egyenloek] = tmb[i];
                egyenloek++;
            }
        }
    }
    jatekos* e2 = new jatekos[egyenloek];
    for (int i = 0; i < egyenloek; i++) {
        e2[i] = e[i];
    }

    return e2;
}

