#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Province {
    string name;
    string capital;
    int population;
    int area;
    double gdp;
};

struct Country {
    string name;
    string capital;
    vector<Province> provs;
};

typedef vector<Country> Countries;

double gdp(const Countries& p, char c, double d) {
    double sum = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i].name[0] == c) {
            for (int j = 0; j < (int)p[i].provs.size(); ++j) {
                Province prov = p[i].provs[j];
                if ((prov.population/double(prov.area)) > d) sum += prov.gdp;
            }
        }
    }
    return sum;
}

int main() {
    return 0;
}