#include "llista.hpp"

// -------------------------
// MÈTODES PRIVATS DE CLASSE
// -------------------------

void Llista::esborra_node_llista(node_llista* m) {
  if (m != NULL) {
    esborra_node_llista(m->seg);
    delete m;
  }
}

Llista::node_llista* Llista::copia_node_llista(node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
  node_llista* n;
  if (m==NULL) {n=NULL; u=NULL; a=NULL;}
  else {
    n = new node_llista;
    n->info = m->info;
    n->ant = NULL;
    n->seg = copia_node_llista(m->seg, oact, u, a);
    if (n->seg == NULL) u = n;
    else (n->seg)->ant = n;
    if (m == oact) a = n;
  }
  return n;
}


// -------------------------
// MÈTODES PÚBLICS
// -------------------------

Llista::Llista() : dir(true) {
  longitud = 0;
  primer_node = NULL;
  ultim_node = NULL;
  act = NULL;
}

Llista::Llista(const Llista &original) {
  longitud = original.longitud;
  primer_node = copia_node_llista(original.primer_node, original.act, ultim_node, act);
}

Llista::~Llista() {
  esborra_node_llista(primer_node);
}

Llista& Llista::operator=(const Llista& l) {
  if (this != &l) {
    longitud = l.longitud;
    esborra_node_llista(primer_node);
    primer_node = copia_node_llista(l.primer_node, l.act, ultim_node, act);
  }
  return *this;
}

void Llista::l_buida() {
  esborra_node_llista(primer_node);
  longitud = 0;
  primer_node = NULL;
  ultim_node = NULL;
  act = NULL;
}

void Llista::afegir(const int &x) {
  node_llista* aux;
  aux = new node_llista;
  aux->info = x;
  aux->seg = act;
  if (longitud == 0) {
     aux->ant = NULL;
     primer_node = aux;
     ultim_node = aux;
  }
  else if (act == NULL) {
     aux->ant = ultim_node;
     ultim_node->seg = aux;
     ultim_node = aux;
  }
  else if (act == primer_node) {
     aux->ant = NULL;
     act->ant = aux;
     primer_node = aux;
  }
  else {
     aux->ant = act->ant;
     (act->ant)->seg = aux;
     act->ant = aux;
  }
  ++longitud;
}

void Llista::eliminar() {
  node_llista* aux;
  aux = act;
  if (longitud == 1) {
    primer_node = NULL;
    ultim_node = NULL;
  }
  else if (act == primer_node) {
  primer_node = act->seg;
  primer_node->ant = NULL;
  }
  else if (act == ultim_node) {
  ultim_node = act->ant;
  ultim_node->seg = NULL;
  }
  else {
  (act->ant)->seg = act->seg;
  (act->seg)->ant = act->ant;
  }
  act = act->seg;
  delete aux;
  --longitud;
}

void Llista::concat(Llista &l) {
  if (l.longitud > 0) {
  if (longitud == 0) {
    primer_node = l.primer_node;
  }
  else {
    ultim_node->seg = l.primer_node;
    (l.primer_node)->ant = ultim_node;
  }
  ultim_node = l.ultim_node;
  longitud += l.longitud;
  l.primer_node = NULL;
  l.ultim_node = NULL;
  l.act = NULL;
  l.longitud = 0;
  }
  act= primer_node;
}

bool Llista::es_buida() const {
  return primer_node == NULL;
}

int Llista::mida() const {
  return longitud;
}
  
int Llista::actual() const {
  return act->info; // equival a *it
}
  
void Llista::modifica_actual(const int &x) {
  act->info = x; // equival a *it=x;
}   

void Llista::inici() {
  act = primer_node; // equival a it=l.begin();
}   
   
void Llista::fi() {
  act = NULL; // equival a it=l.end();
}

void Llista::avanca() {
  act= act->seg; // equival a ++it;
}

void Llista::retrocedeix() {
  if (act == NULL) act = ultim_node; // equival a --it;
  else act = act->ant;
}

bool Llista::dreta_de_tot() const {
  return act == NULL; // equival a comparar it==l.end()
}

bool Llista::sobre_el_primer() const {
  return act == primer_node; // equival a comparar it==l.begin()
}    

ostream& operator<<(ostream &os, pair<Llista *, bool> p) {
  p.first->dir = p.second;
  return os;
}

ostream& operator<<(ostream &os, const Llista &l) {
  Llista::node_llista *p;
  int lon = 0;
  if (l.dir) {
    p = l.primer_node;
    os << "[";
    while(p != NULL) {
      if (p == l.act)
        os << "(" << p->info << ")";
      else
        os << p->info;
      if (p->seg != NULL) os << ",";
      p = p->seg;
      lon++;
    }
    os << "]>" << endl;
  } else {
    p = l.ultim_node;
    os << "[";
    while(p != NULL) {
      if (p == l.act)
        os << "(" << p->info << ")";
      else
        os << p->info;
      if (p->ant != NULL) os << ",";
      p = p->ant;
      lon++;
    }
    os << "]<" << endl;
    if (lon != l.longitud) os << "Longitud de la llista no concorda amb el nombre d'elements que conté.\n";
  }
  return os;
}

istream& operator>>(istream &is, Llista &l) {
  int n;
  is >> n;
  l.inici();
  while (n>0) {    
      int e;
      is >> e;
      l.afegir(e);
      --n;
  }
  return is;
}
