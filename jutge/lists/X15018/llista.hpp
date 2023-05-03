#ifndef LLISTA_H 
#define LLISTA_H
#include <iostream>
using namespace std;


class Llista { 
  public:
    Llista();
    /* Pre: cert */
    /* Post: El resultat es una llista buida */

    Llista(const Llista& original);
    /* Pre: cert */
    /* Post: El resultat es una copia d'original */

    //destructor: esborra automaticament els objectes locals
    //en sortir d'un ambit de visibilitat
    ~Llista();

    Llista& operator=(const Llista& l);
    /* Pre: cert */
    /* Post: El p.i. passa a ser una copia de l i
       el contingut anterior del p.i. ha estat esborrat
       (excepte si el p.i. i l ja eren el matei objecte) */

    void l_buida();
    /* Pre: cert */
    /* Post: El p.i. passa a ser una llista sense 
       elements i qualsevol contingut anterior del p.i. ha estat esborrat */

    void afegir(const int &x);
    /* Pre: cert */
    /* Post: El p.i. es com el p.i. original pero amb x
       afegit a l'esquerra del punt d'interes */

    void eliminar();
    /* Pre: El p.i. es una llista no buida i el seu punt 
       d'interes no esta a la dreta de tot */
    /* Post: El p.i. es com el p.i. original pero sense 
       l'element on estava el punt d'interes i amb el 
       nou punt d'interes apuntant al successor de 
       l'element esborrat */

    void concat(Llista &l);
    /* Pre: l=L */
    /* Post: El p.i. te els seus elements originals
       seguits pels de L, l queda buida, i el punt d'interes del p.i. passa a ser el primer element */

    bool es_buida() const;
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. es una llista buida o no */

    int mida() const;
    /* Pre: cert */
    /* Post: El resultat es el nombre d'elements de la llista p.i. */

    void inverteix();
    /* Pre: cert */
    /* Post: S'ha invertit l'ordre dels elements del p.i.
       El punt d'interès apunta al mateix element.
       Exemple: [4 5 2 1] = > [1 2 5 4] */

    // Operacions per consultar i modificar el punt d'interes

    int actual() const;
    /* Pre: El p.i. es una llista no buida i el seu punt 
    d'interes no esta sobre l'element fictici del final */
    /* Post: El resultat es l'element apuntat pel punt
       d'interes del p.i. */

    void modifica_actual(const int &x);
    /* Pre: El p.i. es una llista no buida i el seu punt 
       d'interès no esta a la dreta de tot */
    /* Post: El p.i. es com el seu valor original, pero 
       amb x reemplacant l'element actual */

    void inici();
    /* Pre: cert */
    /* Post: El punt d'interes del p.i. esta situat a 
       sobre del primer element de la llista, o a la
       dreta de tot si la llista es buida */

    void fi();
    /* Pre: cert */
    /* Post: El punt d'interes del p.i. esta situat a la 
       dreta de tot (sobre l'elem. fictici del final) */

    void avanca();
    /* Pre: El punt d'interes del p.i. no esta a la 
       dreta de tot */
    /* Post: El punt d'interes del p.i. apunta al
       successor de l'element al qual apuntava 
       originalment, es a dir, es mou cap a la dreta del
       seu valor original */

    void retrocedeix();
    /* Pre: El punt d'interes del p.i. no es el primer 
       element de la llista */
    /* Post: El punt d'interès del p.i. esta situat una 
       posicio més a l'esquerra que al valor original 
       del p.i. */  

    bool dreta_de_tot() const;
    /* Pre: cert */
    /* Post: El resultat indica si el punt d'interes del 
       p.i. esta a la dreta de tot */

    bool sobre_el_primer() const;
    /* Pre: cert */
    /* Post: El resultat indica si el punt d'interes del 
       p.i. esta a sobre del primer element del p.i. o esta a la dreta de tot si la llista es buida */     

    friend ostream& operator<<(ostream &os, pair<Llista *, bool> p);
    /* Pre: cert */
    /* Post: Canvia la direcció en que s'escriuen els enters de la llista p.first:
       Si p.second==true: del primer a l'últim, p.second==false: de l'últim al primer. */

    friend ostream& operator<<(ostream &os, const Llista &l);
    /* Pre: cert */
    /* Post: S'han escrit els enters de la llista l (entre parèntesis el situat en el punt d'interès)
       al canal os seguint la direcció fixada en la pròpia llista l */

    friend istream& operator>>(istream &is, Llista &l);
    /* Pre: l es buida; el canal is conte la mida de la 
    llista i els elements d'una llista L */
    /* Post: l = L */

  private:

    struct node_llista {
        int info;
        node_llista* seg;
        node_llista* ant;
    };

    int longitud;
    node_llista* primer_node;
    node_llista* ultim_node;
    node_llista* act;

    bool dir; // Direcció en que s'escriuen els enters de la llista:
              // true: del primer a l'últim, false: de l'últim al primer.

    static node_llista* copia_node_llista(node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a);
    /* Pre: cert */
    /* Post: Si m es NULL, el resultat, u i a son NULL;
       en cas contrari, el resultat apunta al primer node
       d'una cadena de nodes que son copia de la cadena
       que te el node apuntat per m com a primer, u apunta
       a l'ultim node, a es o be NULL si oact no apunta a
       cap node de la cadena que comença amb m o be apunta
       al node copia del node apuntat per oact */

    static void esborra_node_llista(node_llista* m);
    /* Pre: cert */
    /* Post: No fa res si m es NULL, sino allibera
       espai dels nodes de la cadena que te el node
       apuntat per m com a primer */
};

#endif
