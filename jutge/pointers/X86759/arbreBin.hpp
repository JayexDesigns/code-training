#ifndef ARBREBIN_HPP
#define ARBREBIN_HPP
#include <iostream>
using namespace std;

class arbreBin {
 public:
    arbreBin();
	/* Pre: cert */
	/* Post: El resultat es un arbre sense cap element */
	
    arbreBin(const arbreBin &original);
	/* Pre: cert */
	/* Post: El resultat es un arbre copia d'original */
	
    arbreBin(const int &x, const arbreBin &ae, const arbreBin &ad);
	/* Pre: cert */
	/* Post: El resultat es un arbre amb l'element x com a
       arrel, ae com a fill esquerre i a2 com a fill dret */

    //destructor: esborra automàticament els objectes locals
    //en sortir d'un àmbit de visibilitat
    ~arbreBin();	

    int arrel() const;
	/* Pre: El parametre implicit no es buit */
	/* Post: El resultat es l'arrel del parametre implicit */
	
	bool es_buit() const;
	/* Pre: cert */
	/* Post: El resultat indica si el p.i. es buit o no */
	
    arbreBin fe() const;
	/* Pre: El parametre implicit no es buit */
	/* Post: El resultat es el fill esquerre del p.i. original */
	
    arbreBin fd() const;
	/* Pre: El parametre implicit no es buit */
	/* Post: El resultat es el fill dret del p.i. original */
	
	arbreBin& operator=(const arbreBin &original);
	/* Pre: cert */
	/* Post: Operacio d'assignacio d'arbres */
	
	void a_buit();
    /* Pre: cert */
    /* Post: El parametre implicit no te cap element */

	bool compleix_suma_fills() const;
	/* Pre: true */
	/* Post: Retorna si compleix la propietat 'Suma dels fills':
	   Per tot node el seu valor és igual a la suma dels valors
	   dels nodes (arrels) del fill esquerre i del fill dret */

    friend ostream& operator<<(ostream &os, const arbreBin &a);
    /* Pre: cert */
    /* Post: S'han escrit al canal estandard de sortida els elements d'a*/

    friend istream& operator>>(istream &is, arbreBin &a);
    /* Pre: a es buit; el canal estandard d'entrada conte la mida de
       l'arbre i els nodes en postordre d'un arbre binari A; per cada
       node s'indica el seu valor i el nombre de fills */
    /* Post: a = A */
	
	
 private:
    struct node_arbre {
		int info;
		node_arbre* segE;
		node_arbre* segD;
    };
    node_arbre* _arrel;

    static node_arbre* copia_node_arbre(node_arbre* m);
	/* Pre: cert */
	/* Post: Si m es NULL, el resultat es NULL;
	   en cas contrari, el resultat apunta al node arrel
	   d'una jerarquia de nodes que es una copia de la
       jerarquia de nodes que te el node apuntat per m
       com a arrel */
	   
    static void esborra_node_arbre(node_arbre* m);
	/* Pre: cert */
	/* Post: No fa res si m es NULL; en cas contrari,
       allibera espai de tots els nodes de la jerarquia
       que te el node apuntat per m com a arrel */

	static bool compleix_suma_fills(node_arbre* p);
	/* Pre: true */
	/* Post: Retorna si l'arbre apuntat per p compleix la propietat
	   'Suma dels fills': Per tot node el seu valor és igual a la suma
	   dels valors dels nodes (arrels) del fill esquerre i del fill dret */
};
#endif
