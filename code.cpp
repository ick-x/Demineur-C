#include <iostream>
#include <cassert>

using namespace std;

typedef char Item;

enum Etat
{														
	VIDE, MINE
};

enum Statut 
{
	DEVOILEE, CACHEE, MARQUEE
};

enum Valeur
{
	NEUTRE, 
};

typedef struct {Etat etat_case; Valeur valeur_case; Statut statut_case} Case;



void initialiser(Item ***g, unsigned int& lignes, unsigned int& colonnes)
{
	// Initialise la grille
	*g = new Item*[colonnes];
	for (unsigned int i = 0; i < colonnes; ++i)
	{
		(*g)[i] = new Item[lignes];
	}
	for (unsigned int l = 0; l < lignes; l++)
	{
		for (unsigned int c = 0; c < colonnes; c++)
		{
			(*g)[l][c] = Case::etat_case = VIDE;
			(*g)[l][c] = Case::statut_case = CACHEE;
		}
	}
}


void afficher_grille(Item **g, unsigned int& lignes, unsigned int& colonnes)
{
	// Affiche la grille
	for (unsigned int i = 1; i <= colonnes; ++i)
	{
		cout << " ___";
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
			cout << " ___";
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

void placer_mine(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int nb_mines)
{
	for (int i = 0; i < nb_mines; i++) 
	{
		int mine;

		cout << "Placer une mine : ";
		cin >> mine;
		
		int position(-1);

		for (int l = 0; l < lignes; l++)
		{
			for (int c = 0; c < colonnes; c++)
			{
				position += 1;
				if (position == mine)
				{
					g[l][c] = Etat::MINE;
				}
			}
		}
	}
}

void marquer_mine(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& mine)
{
	int position(-1);

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == mine)
			{
				g[l][c] = Case::statut_case = MARQUEE;
			}
		}
	}
}

void demasquer_case(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int& demasque)
{
	unsigned int position(-1);
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == demasque)
			{	
				if (g[l][c] == Etat::MINE)
				{
					cout << "Perdu : Mine decouverte" << endl;
					exit(1);
				}
				else 
				{
					g[l][c] = Etat::VIDE;

				}
			}
		}
	}
}

int main()
{
	unsigned int lignes, colonnes, mine_marquee, case_demasquee, nb_mines;

	Item** grille;

	cout << "Lignes : ";            //
	cin >> lignes;                  // 
									// Ces quelques lignes serviront pour
	cout << "Colonnes : ";          // la programmation mais pour le projet
	cin >> colonnes;                // final il faudra utiliser celle en 
									// commentaire en dessous (pour le 'in')  
	          
	cout << "Nombre de mines a placer : " ;
	cin >> nb_mines;

	initialiser(&grille, lignes, colonnes);
	placer_mine(grille, lignes, colonnes, nb_mines);

	//cout << "Marquer une mine : ";    
	//cin >> mine_marquee;

	cout << "Case a demasquer : ";
	cin >> case_demasquee;

	//cin >> lignes >> colonnes >> position;

	assert(mine_marquee < lignes * colonnes);
	assert(case_demasquee < lignes * colonnes);

	cout << endl;

	afficher_grille(grille, lignes, colonnes);

	cout << endl;
	//show_position(grille, lignes, colonnes);
    
	//marquer_mine(grille, lignes, colonnes, mine_marquee);
	//cout << endl;
	//afficher_grille(grille, lignes, colonnes);
	cout << endl;
	demasquer_case(grille, lignes, colonnes, case_demasquee);
	cout << endl;
	afficher_grille(grille, lignes, colonnes);


	return 0;
}


/*
    char lettre;
    int nombre;
    cin >> lettre >> nombre;

    cout << lettre << " " << nombre;
    return 0;
*/