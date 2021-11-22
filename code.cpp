#include <iostream>
#include <cassert>
using namespace std;




void initialiser(int **g, unsigned int lignes, unsigned int colonnes) {

    //int** g;
    g = new int*[colonnes];           
    for (int i = 0; i < colonnes; ++i) {     
        g[i] = new int[lignes];     
    }
}

void afficher_grille(int **g, unsigned int& lignes, unsigned int& colonnes) 
{
    
    for (unsigned int i = 1; i <= colonnes; ++i) {
        cout << " ---";
    }
    cout << endl;

    for (unsigned int l = 0; l < lignes; l++) {
        for (unsigned int c = 0; c < colonnes; c++){
            cout << "| " << g[l][c] << " ";
        }
            for (unsigned int i = 1; i <= colonnes; ++i) {
    }
        cout <<"|" << endl;
    for (unsigned int i = 1; i <= colonnes; ++i) {
        cout << " ---";
    }
    cout << endl;
    
    }
}



int main() 
{
    unsigned int lignes, colonnes;

    int** grille;

    cin >> lignes;
    cin >> colonnes;

    initialiser(grille, lignes, colonnes);
    afficher_grille(grille, lignes, colonnes);

    return 0;
}
