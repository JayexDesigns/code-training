#include "llista.hpp"
using namespace std;

int main() {
  int n;
  cin >> n; // Posicions que hem d'avançar el punt d'interès

  Llista l;
  cin >> l;
  l.inici();
  for (int i=0; i<n; i++) l.avanca();
  cout << l << endl;

  pair<Llista *, bool> endevant(&l, true), endarrera(&l, false);

  while (cin >> n) {
    l.inserir_en_ordre(n);
    if (n >= 0) {
      cout << endevant << l;
      cout << endarrera << l << endl;
    }
  }
}
