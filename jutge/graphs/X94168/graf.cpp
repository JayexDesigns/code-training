#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
    // Graf dirigit i no etiquetat.
    // Les arestes es guarden en una matriu d’adjacència.
public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();

    vector<nat> quantes_arestes_es_visiten() const;
    // Pre: Cert
    // Post: Retorna quantes arestes diferents es poden visitar (hi ha un camí)
    // des de cada vèrtex del graf.

private:
    nat n;                  // Nombre de vèrtexs
    nat m;                  // Nombre d’arestes
    vector<vector<bool>> a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
    nat visita(nat index, vector<vector<bool>> &matrix) const;
    // Pre: index < n
    // Post: Retorna quantes arestes diferents es poden visitar per el node 'index'
    // Cost: O(n^2)
};

// Aquí va la implementació del mètode públic quantes_arestes_es_visiten i privats addicionals
vector<nat> graf::quantes_arestes_es_visiten() const {
    vector<nat> v(n, 0);
    for (int i = 0; i < n; ++i) {
        vector<vector<bool>> matrix = a;
        v[i] = visita(i, matrix);
    }
    return v;
}

nat graf::visita(nat index, vector<vector<bool>> &matrix) const {
    nat sum = 0;
    for (int i = 0; i < n; ++i) {
        if (index != i && matrix[index][i]) {
            ++sum;
            matrix[index][i] = false;
            sum += visita(i, matrix);
        }
    }
    return sum;
}
