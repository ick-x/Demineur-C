#include <iostream>
#include <cassert>

using namespace std;

typedef char Item;

void initialiser(Item ***g, unsigned int& lignes, unsigned int& colonnes)
{
	// Initialise la grille
	*g = new Item*[colonnes];
	char case_cache = 46;
	for (unsigned int i = 0; i < colonnes; ++i)
	{
		(*g)[i] = new Item[lignes];
	}
	for (unsigned int l = 0; l < lignes; l++)
	{
		for (unsigned int c = 0; c < colonnes; c++)
		{
			(*g)[l][c] = case_cache;
		}
	}
}


void afficher_grille(Item **g, unsigned int& lignes, unsigned int& colonnes)
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
		cout << "|" << endl;
		for (unsigned int i = 1; i <= colonnes; ++i)
		{
			cout << " ---";
		}
		cout << endl;
	}
}

void show_position(Item** g, unsigned int& lignes, unsigned int& colonnes)
{
	// Cette fonction sert juste à vérifier si les cellules de la matrice 
	// correspondent bien à leur position réelle. 

	int position(-1);
	int p(0);

	cout << "cellule -> position : " << endl << endl;

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;

			cout << "grille[" << l << "][" << c << "]" << " -> " << position << endl;
		}
	}
}

void marquer_mine(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& mine)
{
	unsigned int position(-1);
	char marquage_mine = 120;		//Code ascii de "x"

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == mine)
			{
				g[l][c] = marquage_mine;
			}
		}
	}
}

void demasquer_case(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& demasque)
{
	unsigned int position(-1);
	char case_vide = 32;			//Code ascii de l'espace
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == demasque)
			{
				g[l][c] = case_vide;
			}
		}
	}
}

int main()
{
	unsigned int lignes, colonnes, mine_marquee, case_demasquee;

	Item** grille;

	cout << "Lignes : ";            //
	cin >> lignes;                  // 
									// Ces quelques lignes serviront pour
	cout << "Colonnes : ";          // la programmation mais pour le projet
	cin >> colonnes;                // final il faudra utiliser celle en 
									// commentaire en dessous (pour le 'in')
	cout << "Marquer une mine : ";  //  
	cin >> mine_marquee;            //

	cout << "Case a demasquer :";
	cin >> case_demasquee;

	//cin >> lignes >> colonnes >> position;

	assert(mine_marquee < lignes * colonnes);
	assert(case_demasquee < lignes * colonnes);

	cout << endl;

	initialiser(&grille, lignes, colonnes);
	afficher_grille(grille, lignes, colonnes);

	cout << endl;
	show_position(grille, lignes, colonnes);
	cout << endl;
	marquer_mine(grille, lignes, colonnes, mine_marquee);
	cout << endl;
	afficher_grille(grille, lignes, colonnes);
	cout << endl;
	demasquer_case(grille, lignes, colonnes, case_demasquee);
	cout << endl;
	afficher_grille(grille, lignes, colonnes);


	system("pause");
	return 0;
}
