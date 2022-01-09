#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef enum { VIDE = 32, MINE = 109 } Etat;

typedef enum { DEVOILEE, CACHEE = 46, MARQUEE = 120 } Statut;

typedef enum { NEUTRE = 32, UN = 49, DEUX = 50, TROIS = 51, QUATRE = 52, CINQ = 53, SIX = 54, SEPT = 55, HUIT = 56 } Valeur;

struct Case {
	Etat etat_case = Etat::VIDE;
	Statut statut_case = Statut::CACHEE;
	Valeur valeur_case = Valeur::NEUTRE;
};

typedef Case Item;

void initialiser(Item ***g, unsigned int& lignes, unsigned int& colonnes)
{
	// Initialise la grille
	*g = new Item*[lignes];
	for (unsigned int i = 0; i < lignes; ++i)
	{
		(*g)[i] = new Item[colonnes];
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
			if (g[l][c].statut_case == DEVOILEE && g[l][c].valeur_case != NEUTRE) {
				cout << "| " << (char)g[l][c].valeur_case << " ";
			}
			else if(g[l][c].statut_case == DEVOILEE && g[l][c].etat_case == VIDE && g[l][c].valeur_case == NEUTRE) {
				cout << "| " << (char)g[l][c].etat_case << " ";
			}
			else if(g[l][c].statut_case == DEVOILEE && g[l][c].etat_case == MINE) {
				cout << "| " << (char)g[l][c].etat_case << " ";
			}
			else {
			cout << "| " << (char)g[l][c].statut_case << " ";
			}
		}
		cout << "|" << endl;
		for (unsigned int i = 1; i <= colonnes; ++i)
		{
			cout << " ___";
		}
		cout << endl;
	}
}

void placer_mine(Item **g, unsigned int& lignes, unsigned int& colonnes, unsigned int nb_mines, unsigned int prob)
{
	if (prob == 1) {
		
		int pos_max;
		pos_max = (lignes * colonnes) - 1;

		srand (time(NULL));

		for (int i = 0; i < nb_mines; i++)
		{
			int pos_mine;
			pos_mine = rand() % pos_max;
			cout << pos_mine << " "; 
		}
	}

	else {

		for (int i = 0; i < nb_mines; i++)
		{
			int mine;

			cin >> mine;

			int position(-1);

			for (int l = 0; l < lignes; l++)
			{
				for (int c = 0; c < colonnes; c++)
				{
					position += 1;
					if (position == mine)
					{
						g[l][c].etat_case = MINE;
						g[l][c].statut_case = CACHEE;
					}
				}
			}
		}
	}
}

void game_lost(Item** g, unsigned int& lignes, unsigned int& colonnes,unsigned int prob)
{
	if (prob == 2) {
		for (int l = 0; l < lignes; l++)
		{
			for (int c = 0; c < colonnes; c++)
			{
				if (g[l][c].etat_case == MINE)
					g[l][c].statut_case = DEVOILEE;
			}
		}
	}
	if (prob == 3) {
		cout << "game not won";
	}
	if (prob == 4) {
		cout << "game lost";
	}

}
void game_won (Item** g, unsigned int& lignes, unsigned int& colonnes,unsigned int prob) 
{
	assert (prob < lignes * colonnes);
	int position(-1);

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			if (g[l][c].etat_case == MINE && g[l][c].statut_case == MARQUEE) {
				if (prob == 3) {
					cout << "game won";
				}
				else if (prob == 4) {
					cout << "game not lost";
				}
			}
		}
	}
}
void marquer_mine(Item **g, unsigned int& lignes, unsigned int& colonnes, int& mine, unsigned int& prob)
{
	assert (mine < lignes * colonnes);
	int position(-1);

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == mine)
			{
				if (g[l][c].etat_case != MINE)
				{
					game_lost(g, lignes, colonnes, prob);
				}

				else 
				{ 
					if (prob == 2)
						g[l][c].statut_case = MARQUEE;
					else if (prob ==3 || prob == 4)
						game_won(g, lignes, colonnes, prob);
				}
			}
		}
	}
}



void compteMine(Item **g, unsigned int& lignes, unsigned int& colonnes, int& caseRemplir) {

	assert (caseRemplir < lignes * colonnes);

	int position(-1);
	int compte = 0;

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == caseRemplir)
			{
				unsigned int col, li;

				col = c;
				li = l;

				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				l--;
				position -= lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				c--;
				position--;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				c--;
				position--;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				l++;
				position += lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				l++;
				position += lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					if (g[l][c].etat_case == MINE)
						compte++;
				}

				if (compte == 0) {
					g[li][col].valeur_case = NEUTRE;
				}
				else if(compte == 1) {
					g[li][col].valeur_case = UN;
				}
				else if (compte == 2) {
					g[li][col].valeur_case = DEUX;
				}
				else if (compte == 3) {
					g[li][col].valeur_case = TROIS;
				}
				else if (compte == 4) {
					g[li][col].valeur_case = QUATRE;
				}
				else if (compte == 5) {
					g[li][col].valeur_case = CINQ;
				}
				else if (compte == 6) {
					g[li][col].valeur_case = SIX;
				}
				else if (compte == 7) {
					g[li][col].valeur_case = SEPT;
				}
				else if (compte == 8) {
					g[li][col].valeur_case = HUIT;
				}
			}				
		}
	}
}

void voisine(Item **g, unsigned int& lignes, unsigned int& colonnes, int& pos) {

	assert (pos < colonnes * lignes);
	assert (pos >= 0);

	int position(-1);
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == pos)
			{
				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0)
				{
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case != CACHEE);
					
					else { 

						if (g[l][c].valeur_case != NEUTRE){
							g[l][c].statut_case = DEVOILEE; 
						}
						else {
							g[l][c].statut_case = DEVOILEE; 
							voisine(g, lignes, colonnes, position); 
						}
					}
				}
			
				c--;
				position --;
				l--;
				position -= colonnes;

				if (c < colonnes && c >= 0 && l < lignes && l >= 0)
				{ 
					
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case != CACHEE);


					else {
						if (g[l][c].valeur_case != NEUTRE){
							g[l][c].statut_case = DEVOILEE; 
						}
						else {
							g[l][c].statut_case = DEVOILEE; 
							voisine(g, lignes, colonnes, position); 
						} 
					}
				}

				c--;
				position --;
				l++;
				position += colonnes;

				if (c < colonnes && c >= 0 && l < lignes && l >= 0)
				{
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case != CACHEE);
					
					else { 
						if (g[l][c].valeur_case != NEUTRE){
							g[l][c].statut_case = DEVOILEE; 
						}
						else {
							g[l][c].statut_case = DEVOILEE; 
							voisine(g, lignes, colonnes, position); 
						} 
					}
				}
				c++;
				position ++;
				l++;
				position += colonnes;

				if (c < colonnes && c >= 0 && l < lignes && l >= 0)
				{
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case != CACHEE);
					
					else { 
						if (g[l][c].valeur_case != NEUTRE){
							g[l][c].statut_case = DEVOILEE; 
						}
						else {
							g[l][c].statut_case = DEVOILEE; 
							voisine(g, lignes, colonnes, position); 
						} 
					}
				}
			}
		}
	}
}

void demasquer_case(Item **g, unsigned int& lignes, unsigned int& colonnes, int& demasque, unsigned int& prob)
{	
	assert(demasque < lignes * colonnes);
	int position(-1);
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == demasque)
			{
				if (g[l][c].etat_case == MINE)
				{
					game_lost(g, lignes, colonnes, prob);
				}
				else 
				{
					if (prob == 2) 
					{ 
						if (g[l][c].statut_case != MARQUEE || g[l][c].statut_case != DEVOILEE || g[l][c].valeur_case == NEUTRE) { 
							g[l][c].statut_case = DEVOILEE;
							compteMine(g, lignes, colonnes, demasque);

							if (g[l][c].valeur_case != NEUTRE);
							else 
								voisine(g, lignes, colonnes, position);
						}
					}
					if (prob == 3 || prob == 4) {
						game_won(g, lignes, colonnes, prob);
					}
				}
			}
		}
	}
}

void problem() {

	unsigned int prob;
	cin >> prob;

	assert(prob >= 1);
	assert (prob <= 5);

	Item** grille;

	if (prob == 1) {

		unsigned int lignes, colonnes, nb_mines;
		cin >> lignes >> colonnes >> nb_mines;

		initialiser(&grille, lignes, colonnes);

		cout << lignes << " " << colonnes << " " << nb_mines << " ";

		placer_mine(grille, lignes, colonnes, nb_mines, prob);

		cout << endl;
	}

	if (prob == 2) {
		
		unsigned int lignes, colonnes, nb_mines, nb_coups;
		cin >> lignes >> colonnes >> nb_mines;


		initialiser(&grille, lignes, colonnes);
		placer_mine(grille, lignes, colonnes, nb_mines, prob);

		cin >> nb_coups;

		for (unsigned int i = 0; i < nb_coups; ++i) 
		{

			char type_coup;
			int pos_coup;
			cin >> type_coup >> pos_coup;
			
			if (type_coup == 68) 
			{
				demasquer_case(grille, lignes, colonnes, pos_coup, prob);
			}
			else if (type_coup == 77)
			{
				marquer_mine(grille, lignes, colonnes, pos_coup, prob);
			}

		}


		cout << lignes << " " << colonnes << endl;
		afficher_grille(grille, lignes, colonnes);

	}

	if (prob == 3 || prob == 4) {

		unsigned int lignes, colonnes, nb_mines, nb_coups;
		cin >> lignes >> colonnes >> nb_mines;


		initialiser(&grille, lignes, colonnes);
		placer_mine(grille, lignes, colonnes, nb_mines, prob);

		cin >> nb_coups;

		for (unsigned int i = 0; i < nb_coups; ++i) 
		{

			char type_coup;
			int pos_coup;
			cin >> type_coup >> pos_coup;
			
			if (type_coup == 68) 
			{
				demasquer_case(grille, lignes, colonnes, pos_coup, prob);
			}
			else if (type_coup == 77)
			{
				marquer_mine(grille, lignes, colonnes, pos_coup, prob);
			}
		}
	}

	if (prob == 5) {
		
	}
}

int main()
{
	problem();

	//system("pause");
	return 0;
}
