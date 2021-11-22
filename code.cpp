#include <iostream>
#include <cassert>
 
using namespace std;
 

 
void initialiser(int ***g, unsigned int& lignes, unsigned int& colonnes)
{
    // Initialise la grille
    *g = new int*[colonnes];
    for (unsigned int i = 0; i < colonnes; ++i)
    {
        (*g)[i] = new int[lignes];
    }
    for (unsigned int l = 0; l < lignes; l++)
    {
        for (unsigned int c = 0; c < colonnes; c++)
        {
            (*g)[l][c]=0;
        }
    }
}
 
 
void afficher_grille(int **g, unsigned int& lignes, unsigned int& colonnes)
{ 
    // Affiche la grille
    for (unsigned int i = 1; i <= colonnes; ++i) 
    {
        cout << " ---";
    }
    cout << endl;
 
    for (unsigned int l = 0; l < lignes; l++) 
    {
        for (unsigned int c = 0; c < colonnes; c++)
        {
            cout << "| " << g[l][c] << " ";
        }
        cout <<"|" << endl;
        for (unsigned int i = 1; i <= colonnes; ++i) 
        {
            cout << " ---";
        }
        cout << endl;
    }
}

void show_position(int** g, unsigned int& lignes, unsigned int& colonnes) 
{
    // Cette fonction sert juste à vérifier si les cellues de la matrice correspondent bien à leur position réelle 
    // Donc elle sert pas à grande chose en vrai
    int position(-1);

    cout << "cellule -> position : " << endl << endl;

    for (int l = 0; l < lignes; l++) 
    {
        for (int c = 0; c < colonnes; c++)
        {
            position += 1;
            cout << "grille.[" << l << "][" << c << "]" << " -> " << position << endl;
        }
    }
}

void get_position(int **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& p) 
{
    unsigned int position(-1);
    
    for (int l = 0; l < lignes; l++) 
    {
        for (int c = 0; c < colonnes; c++)
        {
            position += 1; 
            if (position == p) 
            {
                // Ce 'if' servira à récupérer les coordonnées de la cellule correspondant à une position en entrée
                // Il faudra donc remplacer le 'cout' par une autre instruction
                cout << "la position " << p << " est dans la cellule " << "grille.[" << l << "][" << c << "]" << endl;
            }   
        }
    }     
}
 
int main()
{
    unsigned int lignes, colonnes, position;
 
    int** grille;
    
    cout << "lignes : ";    //
    cin >> lignes;          // 
                            // Ces quelques lignes serviront pour
    cout << "colonnes : ";  // la programmation mais pour le projet
    cin >> colonnes;        // final il faudra utiliser celle en 
                            // commentaire en dessous (pour le in)
    cout << "position : ";  //  
    cin >> position;        //
    
    
    //cin >> lignes >> colonnes >> position;

    assert (position < (lignes * colonnes));

    cout << endl;
 
    initialiser(&grille, lignes, colonnes);
    afficher_grille(grille, lignes, colonnes);
    cout << endl;
    show_position(grille, lignes, colonnes);
    cout << endl << "get_position() : " << endl << endl;
    get_position(grille, lignes, colonnes, position);
    cout << endl;
 
    return 0;
}
