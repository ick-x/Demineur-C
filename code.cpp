#include <iostream>
#include <cassert>

using namespace std;

typedef enum { VIDE = 32, MINE = 120 } Etat;

typedef enum { DEVOILEE, CACHEE = 46, MARQUEE = 109 } Statut;

typedef enum { NEUTRE = 46, UN = 49, DEUX = 50, TROIS = 51, QUATRE = 52, CINQ = 53, SIX = 54, SEPT = 55, HUIT = 56 } Valeur;

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
	for (unsigned int l = 0; l < lignes; l++)
	{
		for (unsigned int c = 0; c < colonnes; c++)
		{
			(*g)[l][c].statut_case = CACHEE;
			(*g)[l][c].etat_case = VIDE;
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
			if (g[l][c].valeur_case != NEUTRE && g[l][c].etat_case != MINE) {
				cout << "| " << (char)g[l][c].valeur_case << " ";
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

void show_position(Item** g, unsigned int& lignes, unsigned int& colonnes)
{
	// Cette fonction sert juste à vérifier si les cellules de la matrice 
	// correspondent bien à leur position réelle. 

	int position(-1);

	cout << "cellule -> position -> contenu : " << endl << endl;

	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;

			cout << "grille[" << l << "][" << c << "]" << " -> " << position << " -> " << g[l][c].statut_case << endl;
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
					g[l][c].etat_case = MINE;
					g[l][c].statut_case = CACHEE;
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
				g[l][c].statut_case = MARQUEE;
			}
		}
	}
}

void compteMine(Item **g, unsigned int& lignes, unsigned int& colonnes, int& caseRemplir) {
	int position(-1);
	int compte = 0;
	unsigned int col, li;
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == caseRemplir)
			{
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

void voisine(Item **g, unsigned int& lignes, unsigned int& colonnes, int& demasque) {
	int position(-1);
	for (int l = 0; l < lignes; l++)
	{
		for (int c = 0; c < colonnes; c++)
		{
			position += 1;
			if (position == demasque)
			{
				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				l--;
				position -= lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				c--;
				position--;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}
				
				c--;
				position--;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				l++;
				position += lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				l++;
				position += lignes;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}

				c++;
				position++;
				if (c < colonnes && c >= 0 && l < lignes && l >= 0) {
					compteMine(g, lignes, colonnes, position);
					if (g[l][c].etat_case == MINE || g[l][c].statut_case == MARQUEE || g[l][c].statut_case == DEVOILEE || g[l][c].valeur_case != NEUTRE);
					else { g[l][c].statut_case = DEVOILEE; voisine(g, lignes, colonnes, position); }
				}
			}
		}
	}
}

void demasquer_case(Item **g, unsigned int& lignes, unsigned int& colonnes, int& demasque)
{
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
					cout << "Perdu : Mine decouverte" << endl;
					system("pause");
					exit(1);
				}
				else
				{
					g[l][c].statut_case = DEVOILEE;
					compteMine(g, lignes, colonnes, demasque);
					voisine(g, lignes, colonnes, demasque);
				}
			}
		}
	}
}

int main()
{
	unsigned int lignes, colonnes, mine_marquee, nb_mines;
	int case_demasquee;

	Item** grille;

	cout << "Lignes : ";
	cin >> lignes;
	cout << "Colonnes : ";
	cin >> colonnes;

	cout << "Nombre de mines a placer : ";
	cin >> nb_mines;

	initialiser(&grille, lignes, colonnes);
	placer_mine(grille, lignes, colonnes, nb_mines);

	cout << "Marquer une mine : ";
	cin >> mine_marquee;

	cout << "Case a demasquer : ";
	cin >> case_demasquee;

	//cin >> lignes >> colonnes >> position;

	assert(mine_marquee < lignes * colonnes);
	assert(case_demasquee < lignes * colonnes);

	cout << endl;
	show_position(grille, lignes, colonnes);

	marquer_mine(grille, lignes, colonnes, mine_marquee);

	afficher_grille(grille, lignes, colonnes);

	cout << endl;
	demasquer_case(grille, lignes, colonnes, case_demasquee);
	afficher_grille(grille, lignes, colonnes);

	system("pause");
	return 0;
}

/*
char lettre;
int nombre;
cin >> lettre >> nombre;

cout << lettre << " " << nombre;
return 0;
*/
