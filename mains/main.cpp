#include <iostream>
#include <string>
#include <CalculetteProject.h>
#include <calc_lib/lexer.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main(){
	//main yas pour tester mes modifs
	std::string chaine_test = "-45-9+89*-4";
	DynArray<Bloc*> retour (lexer(chaine_test));
	for (int ia = 0 ; ia < retour.size(); ++ia){
		std::cout << "Element de rang " << ia << " est " << retour[ia]->get_valeur() << std::endl;
	}
}