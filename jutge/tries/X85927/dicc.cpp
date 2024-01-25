#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    dicc();  // Constructora per defecte. Crea un diccionari buit.

    ~dicc(); // Destructora

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    nat quantes_comencen(string prefix) const;
    // Pre: cert
    // Post: Retorna el nº de claus que comencen amb el prefix donat

  private:
    struct node {
      char _c;    // Símbol posició i-èssima de la clau
      node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
      node* _cen; // Fill central, apunta a símbols següent posició
      node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
      node(const char &c, node* esq = nullptr, node* cen = nullptr, node* dre = nullptr);
    };
    node* _arrel;
    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    void findr(node* n, int depth, int &sum, string &prefix) const;
    // Pre: sum > 0
    // Post: guarda a sum la quantitat de coincidencies amb el prefix
};

// Aquí va la implementació del mètode públic i dels mètodes privats addicionals
nat dicc::quantes_comencen(string prefix) const {
  if (_arrel == nullptr) return 0;
  int sum = 0;
  findr(_arrel, 0, sum, prefix);
  return sum;
}

void dicc::findr(node* n, int depth, int &sum, string &prefix) const {
  if (n == nullptr) return;

  if (n->_c == '#') {
    if (depth >= prefix.length()) ++sum;
  }
  if (depth >= prefix.length()) {
    findr(n->_esq, depth, sum, prefix);
    findr(n->_dre, depth, sum, prefix);
    findr(n->_cen, depth, sum, prefix);
  }
  else if (n->_c > prefix[depth]) findr(n->_esq, depth, sum, prefix);
  else if (n->_c < prefix[depth]) findr(n->_dre, depth, sum, prefix);
  else if (n->_c == prefix[depth]) findr(n->_cen, depth + 1, sum, prefix);

  return;
}
