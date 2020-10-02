#include <iostream>
#include <string>
#include <CalculetteProjectConfig.h>
#include <calc_lib/lexer.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main(){
	//création d'une chaine de calcul.
	std::string chaine_test = "-45-9+89*-4";
	//Création d'un DynArray de bloc contenant les parties élémentaires de la chaine.
	DynArray<Bloc*> retour (lexer(chaine_test));
	//Affichage du DynArray.
	for (int ia = 0 ; ia < retour.size(); ++ia){
		

			std::cout << "Element de rang " << ia << " est " << retour[ia]->get_valeur() << std::endl;
	}
	std::cout << "ICICICI " << retour.size() <<  std::endl;
}