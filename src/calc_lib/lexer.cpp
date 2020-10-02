#include <string>
#include <iostream>
#include <CalculetteProjectConfig.h>
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
	Function taking a string in entry which corresponds to the calculations and delivering 
	a Bloc object.
	**/

	//String giving the operators authorized.
	std::string list_of_operators = "+-*/";
	//Container of the Bloc object.
	DynArray<Bloc*> list_of_bloc(input.size());
	//Position where to put the next bloc in list_of_bloc.
	int position_in_array = 0;
	//number is containing the current number read by the function.
	std::string number = "";
	//value allowing us to konw if we just went through the if bloc. This way we 
	//enter in the "if" bloc again, only if we went through the "else" bloc before.
	int intermediate = -99;
	//To loop in the list_of_bloc
	for (int unsigned position = 0; position < input.size(); ++position) {
		//If we encounter an operator defined in list_of_operators
		if (list_of_operators.find(input[position]) != std::string::npos && intermediate == 0)
		{
			intermediate = 1;
			list_of_bloc[position_in_array] = new Bloc(false, number); //bloc number
			std::cout << "valeur" << list_of_bloc[position_in_array]->get_valeur() << std::endl;
			//atof(number.c_str()) conversion en flottant ou double de la chaine de caractères représentant un number.
			position_in_array++;
			list_of_bloc[position_in_array] = new Bloc(true, std::string(input, position, 1)); //bloc opérateur
			std::cout << "valeur" << list_of_bloc[position_in_array]->get_valeur() << std::endl;
			//on vide le number pour pouvoir stocker le suivant.
			number = "";
			position_in_array++;
		}
		else {
			intermediate = 0;
			number += std::string(input, position, 1); //on ajoute le chiffre dans number pour constituer les nombres avant d'arriver sur un 
		}
	}
	list_of_bloc[position_in_array] = new Bloc(false, number);
	std::cout << "valeur" << list_of_bloc[position_in_array]->get_valeur() << std::endl;
	std::cout << "Fin lexer !" << std::endl;
	std::cout << "Taille new " << cleaner_tab(list_of_bloc, position_in_array).size() << "taille ancien" << list_of_bloc.size() << std::endl;
	return cleaner_tab(list_of_bloc, position_in_array +1);
}

