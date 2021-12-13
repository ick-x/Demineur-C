#include <iostream>
#include <cassert>

using namespace std;

typedef char Item;

typedef enum {VIDE = 32, MINE = 120} Etat;

typedef enum {DEVOILEE, CACHEE = 46, MARQUEE = 109} Statut;

typedef enum {NEUTRE, VOISINE} Valeur;

struct Case {
    Etat etat_case = Etat::VIDE;
    Statut statut_case = Statut::CACHEE;
};

