#include <iostream>
#include <string>
#include <CalculetteProjectConfig.h>
#include <calc_lib/lexer.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main(){
	//Creation of a string defining a calculation.
	std::string chaine_test = "-45-9+89*-4";
	//Creation of a dynarray containing bloc of elementary parts of the previous string.
	DynArray<Bloc*> retour (lexer(chaine_test));
	//Affichage du DynArray.
	for (int ia = 0 ; ia < retour.size(); ++ia){
		

			std::cout << "Element de rang " << ia << " est " << retour[ia]->get_value() << std::endl;
	}

	return 0;
}