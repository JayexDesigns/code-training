#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Jugador {
    string nom;
    int salari;
    int punts;
};

typedef vector<Jugador> Jugadors;



int getUltimJugador(Jugadors& jugadors, int p1, int p2, int left, int right) {
    if (right > left) {
        int pos = (left + right) / 2;
        bool nextPos;
        if (pos >= (int)jugadors.size()-1) nextPos = true;
        else nextPos = jugadors[pos+1].punts > p2;

        if (jugadors[pos].punts <= p2 && nextPos) return pos;
        else if (jugadors[pos].punts > p2) {
            int ultimJugador = getUltimJugador(jugadors, p1, p2, left, pos);
            if (ultimJugador != -1) return ultimJugador;
            else return -1;
        }
        else {
            int ultimJugador = getUltimJugador(jugadors, p1, p2, pos, right);
            if (ultimJugador != -1) return ultimJugador;
            else return -1;
        }
    }
    return -1;
}

int getPrimerJugador(Jugadors& jugadors, int p1, int p2, int left, int right) {
    if (right > left) {
        int pos = (left + right) / 2;
        bool prevPos;
        if (pos <= 0) prevPos = true;
        else prevPos = jugadors[pos-1].punts < p1;

        if (jugadors[pos].punts >= p1 && prevPos) return pos;
        else if (jugadors[pos].punts < p1) {
            int primerJugador = getPrimerJugador(jugadors, p1, p2, pos, right);
            if (primerJugador != -1) return primerJugador;
            else return -1;
        }
        else {
            int primerJugador = getPrimerJugador(jugadors, p1, p2, left, pos);
            if (primerJugador != -1) return primerJugador;
            else return -1;
        }
    }
    return -1;
}



// Llegeix el nom, el salari i els punts d'un jugador de l'entrada estandar,
// crea el jugador amb aquestes dades i el retorna.
Jugador llegirJugador() {
    Jugador jugador;
    cin >> jugador.nom >> jugador.salari >> jugador.punts;
    return jugador;
}

// Retorna cert sii el jugador que és rep com a paràmetre té un nombre de punts
// dins de l'interval [p1,p2].
bool pertanyAInterval(const Jugador &jugador, int p1, int p2) {
    return (jugador.punts >= p1 && jugador.punts <= p2);
}

int main() {
    int n;
    cin >> n;
    Jugadors jugadors;
    for (int i = 0; i < n; ++i) {
        Jugador jugador = llegirJugador();
        jugadors.push_back(jugador);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        cin >> p1 >> p2;
        if (!(jugadors[0].punts > p2 || jugadors[jugadors.size()-1].punts < p1)) {
            int primerJugador = getPrimerJugador(jugadors, p1, p2, 0, (int)jugadors.size());
            int ultimJugador = getUltimJugador(jugadors, p1, p2, 0, (int)jugadors.size());
            if (primerJugador != -1 && ultimJugador != -1) {
                int sum = 0;
                for (int j = ultimJugador; j >= primerJugador; --j) {
                    sum += jugadors[j].salari;
                }
                cout << sum;
                for (int j = primerJugador; j <= ultimJugador; ++j) {
                    cout << " " << jugadors[j].nom;
                }
                cout << endl;
            }
            else cout << 0 << endl;
        }
        else cout << 0 << endl;
    }

    return 0;
}