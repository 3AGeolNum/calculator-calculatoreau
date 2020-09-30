//input chaine de caractère
#include <string>
#include <iostream>
#include <CalculetteProject.h>
#include <calc_lib/lexer.h>


void copy_local(DynArray<Bloc*>& new_tab, const DynArray<Bloc*>& local_tab_copied) {
	for (int ia = 0; ia < new_tab.size(); ia++) {
		new_tab[ia] = local_tab_copied[ia];
	}
}

DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size){
	
	DynArray<Bloc*> modified(size);
	copy_local(modified, other);
	return modified;
}

DynArray<Bloc*> lexer(const std::string& input) {
	/**
	Fonction qui prend une chaine de caractères en entrée correspondant aux opérations.
		Elle renvoie un objet bloc.
	**/

	//Listes des symboles autorisés.
	//String chiffres = "0123456789";

	std::string operateurs = "+-*/";
	DynArray<Bloc*> liste_des_blocs(input.size());
	int position_dans_array = 0; //position ou ranger le prochain bloc dans la liste des blocs.
	std::string nombre = "";
	int intermediaire = -99; //on rentre pas dans le if tout de suite car si le premier symbole c'est - il faut 
	//l'ajouter dans le bloc nombre.
	//Boucle pour parcourir la liste des éléments de la chaine.
	for (int unsigned position = 0; position < input.size(); ++position) {
		//si on rencontre un opérateur
		if (operateurs.find(input[position]) != std::string::npos && intermediaire == 0)
		{
			intermediaire = 1;
			liste_des_blocs[position_dans_array] = new Bloc(false, nombre); //bloc nombre
			std::cout << "valeur" << liste_des_blocs[position_dans_array]->get_valeur() << std::endl;
			//atof(nombre.c_str()) conversion en flottant ou double de la chaine de caractères représentant un nombre.
			position_dans_array++;
			liste_des_blocs[position_dans_array] = new Bloc(true, std::string(input, position, 1)); //bloc opérateur
			std::cout << "valeur" << liste_des_blocs[position_dans_array]->get_valeur() << std::endl;
			//on vide le nombre pour pouvoir stocker le suivant.
			nombre = "";
			position_dans_array++;
		}
		else {
			intermediaire = 0;
			nombre += std::string(input, position, 1); //on ajoute le chiffre dans nombre pour constituer les nombres avant d'arriver sur un 
		}
	}
	liste_des_blocs[position_dans_array] = new Bloc(false, nombre);
	std::cout << "valeur" << liste_des_blocs[position_dans_array]->get_valeur() << std::endl;
	std::cout << "Fin lexer !" << std::endl;
	std::cout << "Taille new " << cleaner_tab(liste_des_blocs, position_dans_array).size() << "taille ancien" << liste_des_blocs.size() << std::endl;
	return cleaner_tab(liste_des_blocs, position_dans_array);
}

