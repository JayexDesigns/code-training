#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cotxe {
    string nom;
    int distancia;
    int preu;
};

typedef vector<Cotxe> Cotxes;

int getLastCar(vector<Cotxe>& cars, int p1, int p2, int left, int right) {
    if (right > left) {
        int pos = (left + right) / 2;
        bool nextPos;
        if (pos >= (int)cars.size()-1) nextPos = true;
        else nextPos = cars[pos+1].distancia > p2;

        if (cars[pos].distancia <= p2 && nextPos) return pos;
        else if (cars[pos].distancia > p2) {
            int lastCar = getLastCar(cars, p1, p2, left, pos);
            if (lastCar != -1) return lastCar;
            else return -1;
        }
        else {
            int lastCar = getLastCar(cars, p1, p2, pos, right);
            if (lastCar != -1) return lastCar;
            else return -1;
        }
    }
    return -1;
}


int getFirstCar(vector<Cotxe>& cars, int p1, int p2, int left, int right) {
    if (right > left) {
        int pos = (left + right) / 2;
        bool prevPos;
        if (pos <= 0) prevPos = true;
        else prevPos = cars[pos-1].distancia < p1;

        if (cars[pos].distancia >= p1 && prevPos) return pos;
        else if (cars[pos].distancia < p1) {
            int lastCar = getFirstCar(cars, p1, p2, pos, right);
            if (lastCar != -1) return lastCar;
            else return -1;
        }
        else {
            int lastCar = getFirstCar(cars, p1, p2, left, pos);
            if (lastCar != -1) return lastCar;
            else return -1;
        }
    }
    return -1;
}

// Llegeix el nom, la distància i el preu d'un cotxe de l'entrada estandar,
// crea el cotxe amb aquestes dades i el retorna.
Cotxe llegirCotxe() {
    Cotxe car;
    cin >> car.nom >> car.distancia >> car.preu;
    return car;
}

// Retorna cert si el cotxe que és rep com a paràmetre té una distància
// dins de l'interval [p1,p2].
bool pertanyAInterval(const Cotxe &cotxe, int p1, int p2) {
    return (cotxe.preu >= p1 and cotxe.preu <= p2);
}

int main() {
    int n;
    cin >> n;
    vector<Cotxe> cars;
    for (int i = 0; i < n; ++i) {
        Cotxe car = llegirCotxe();
        cars.push_back(car);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        cin >> p1 >> p2;
        if (!(cars[0].distancia > p2 || cars[cars.size()-1].distancia < p1)) {
            int firstCar = getFirstCar(cars, p1, p2, 0, (int)cars.size());
            int lastCar = getLastCar(cars, p1, p2, 0, (int)cars.size());
            if (firstCar != -1 && lastCar != -1) {
                int sum = 0;
                for (int j = lastCar; j >= firstCar; --j) {
                    sum += cars[j].preu;
                }
                cout << sum;
                for (int j = lastCar; j >= firstCar; --j) {
                    cout << " " << cars[j].nom;
                }
                cout << endl;
            }
            else cout << 0 << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}