# include <iostream>

using namespace std;

void afficheTableau(int taille, int tab[])
{
	// AFfiche les elements du tableau separes par des espaces
	for (size_t i = 0; i < taille; ++i)
	{
		cout << tab[i] << " ";
	}
	cout << "\n";
}

void inversion(int &valeur1, int &valeur2)
{
	// Fonction d'echange de nombres
	int interm = 0;
	interm = valeur1;
	valeur1 = valeur2;
	valeur2 = interm;
}

int insertionSort(int taille, int tab[])
{
	// Algorithme de tri du tableau avec la methode Insertion Sort
	int nbrInversions = 0;
	for (size_t i = 1; i < taille; ++i)
	{
		for (size_t j = i; j > 0 && j < taille; j--)
        {
            if (tab[j-1] > tab[j])
            {
                inversion(tab[j-1], tab[j]);
                ++nbrInversions;
            }
            else
            {
                break;
            }
        }
	}
	return nbrInversions;
}

int main()
{
    int tab[40] = { 9,98,5,6,-3,4,2,1,8,65,12,74,2,21,5,15,-17,18,54,20,100,20,125,134,185,165,14,-8,-23,45,-36,-2,97,63,82,10,-10, -99, 77,-89 }; // Tableau a trier
	int taille = 40;
	int nbInvert = 0; // Nombre d'echanges realises

    cout << "--- Insertion Sort ---" << "\n" << "\n" << "Tableau d'origine " << taille << " :" << "\n";
	afficheTableau(taille, tab);

	nbInvert = insertionSort(taille, tab);

	cout << "Tableau trie en " << nbInvert << " inversions :" << "\n";
	afficheTableau(taille, tab);

	// La pause est necessaire pour voir le resultat sous Windows avant la fermeture de la console
	system("pause");
    return 0;
}
