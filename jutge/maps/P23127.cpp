#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Proposta {
    string nom;
    int votsAFavor;
    int votsEnContra;
    vector< pair<string, bool> > vots;
};

int main() {
    int n;
    while(cin >> n) {
        map<string, Proposta> propostes;
        for (int i = 0; i < n; ++i) {
            string nom, proposta;
            cin >> nom >> proposta;
            Proposta p;
            p.nom = nom;
            p.votsAFavor = 0;
            p.votsEnContra = 0;
            propostes[proposta] = p;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string nom, vot, proposta;
            cin >> nom >> vot >> proposta;
            bool found = false;
            for (int j = 0; j < (int)propostes[proposta].vots.size(); ++j) {
                if (propostes[proposta].vots[j].first == nom) {
                    found = true;
                    if (vot == "SI") propostes[proposta].vots[j].second = true;
                    else propostes[proposta].vots[j].second = false;
                }
            }
            if (!found) {
                propostes[proposta].vots.push_back({nom, (vot == "SI")});
            }
        }

        for (map<string, Proposta>::iterator it = propostes.begin(); it != propostes.end(); ++it) {
            for (int i = 0; i < (int)(*it).second.vots.size(); ++i) {
                if ((*it).second.vots[i].second) ++(*it).second.votsAFavor;
                else ++(*it).second.votsEnContra;
            }
        }

        for (map<string, Proposta>::iterator it = propostes.begin(); it != propostes.end(); ++it)
            if ((*it).second.votsAFavor > 0 && (*it).second.votsAFavor > (*it).second.votsEnContra)
                cout << (*it).first << ", de " <<(*it).second.nom << ", que ha guanyat " << (*it).second.votsAFavor << "-" << (*it).second.votsEnContra << endl;
        cout << "----------" << endl;
        cin.ignore();
    }
}