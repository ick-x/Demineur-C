#include <iostream>
#include <cassert>
 
 
using namespace std;
 
 
void initialiser(int ***g, unsigned int& lignes, unsigned int& colonnes)
{
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

void get_position(int **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& position) 
{
    
}
 
int main()
{
    unsigned int lignes, colonnes;
 
    int** grille;
 
    cin >> lignes;
    cin >> colonnes;
 
    initialiser(&grille, lignes, colonnes);
    afficher_grille(grille, lignes, colonnes);
    cout << endl;
    show_position(grille, lignes, colonnes);
 
    return 0;
}
