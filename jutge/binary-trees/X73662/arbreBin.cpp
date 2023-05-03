#include "arbreBin.hpp"
#include <string>
#include <stack>

// -------------------------
// MÈTODES PRIVATS DE CLASSE
// -------------------------

arbreBin::node_arbre* arbreBin::copia_node_arbre(node_arbre* m)
{
  node_arbre* n;
  if (m == NULL) n = NULL;
  else {
    n = new node_arbre;
    n->info = m->info;
    n->segE = copia_node_arbre(m->segE);
    n->segD = copia_node_arbre(m->segD);
  }
  return n;
}

void arbreBin::esborra_node_arbre(node_arbre* m)
{
  if (m != NULL) {
    esborra_node_arbre(m->segE);
    esborra_node_arbre(m->segD);
    delete m;
  }
}

// -------------------------
// MÈTODES PÚBLICS
// -------------------------

arbreBin::arbreBin() {
	_arrel = NULL;
}
	
arbreBin::arbreBin(const arbreBin &original) {
	_arrel = copia_node_arbre(original._arrel);
}
	
arbreBin::arbreBin(const int &x, const arbreBin &ae, const arbreBin &ad) {
	_arrel = new node_arbre;
	_arrel->info = x;
	_arrel->segE = copia_node_arbre(ae._arrel);
	_arrel->segD = copia_node_arbre(ad._arrel);
}
	
arbreBin::~arbreBin() {
	esborra_node_arbre(_arrel);
}

int arbreBin::arrel() const {
	return _arrel->info;
}
	
bool arbreBin::es_buit() const {
	return (_arrel == NULL);
}
	
arbreBin arbreBin::fe() const {
	arbreBin a;
	a._arrel = copia_node_arbre(_arrel->segE);
	return a;
}
	
	
arbreBin arbreBin::fd() const {
	arbreBin a;
	a._arrel = copia_node_arbre(_arrel->segD);
	return a;
}
	
arbreBin& arbreBin::operator=(const arbreBin &original) {
	if (this != &original) {
		node_arbre* aux;
		aux = copia_node_arbre(original._arrel);
		esborra_node_arbre(_arrel);
		_arrel = aux;
	}
	return *this;
}
	
void arbreBin::a_buit() {
	esborra_node_arbre(_arrel);
	_arrel = NULL;
}
    
std::string dep = "";
ostream& operator<<(ostream &os, const arbreBin &x)
{
  std::string d1 = dep;
  if (x.es_buit()) 
    os << ".";
  else {
    os << "["<<x.arrel() << "]\n" << d1 << " \\__";
    dep = d1 + " |  ";
    os << x.fd();
    os << "\n" << d1 << " \\__";
    dep = d1 + "    ";
    os << x.fe();
  }
  dep = d1;
  return os;
}

istream& operator>>(istream &is, arbreBin &x) {
  int node;
  int size, nf;
  std::stack<arbreBin> p;

  is >> size;  
  while (size > 0) {
    is >> node >> nf;
    if (nf == 0) {  //fills buits
      p.push(arbreBin(node, arbreBin(), arbreBin()));
    } else if (nf == -1) {  //nf=-1 --> nomes un fill, l'esquerre
      arbreBin fe = p.top();
      p.pop();
      p.push(arbreBin(node, fe, arbreBin()));
    }
    else if (nf == 1) {  //nf=1 --> nomes un fill, el dret
      arbreBin fd = p.top();
      p.pop();
      p.push(arbreBin(node, arbreBin(), fd));
    } else {  //nf=2 --> dos fills no buits
      arbreBin fd = p.top();
      p.pop();
      arbreBin fe = p.top();
      p.pop();
      p.push(arbreBin(node, fe, fd));
    }
    --size;
  }
  if (not p.empty()) x = p.top();
  return is;
	
} 