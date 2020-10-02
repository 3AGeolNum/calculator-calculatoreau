#include <string>
#include <iostream>
#include <calc_lib\lexer.h>
#include <calc_lib\parser.h>
#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>

int main(){
	
	std::cout << "entrez un calcul valable : " << std::endl;
	std::string calcul;
	std::cin >> calcul ;
	
	DynArray<Bloc*> calcul_bloc = lexer( calcul );
	DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);
	
	std::cout << "look at the bloc chain " << parsed_calcul.size() << std::endl;
	for (int ia = 0 ; ia < parsed_calcul.size(); ++ia){
		//if(parsed_calcul[ia] != nullptr){
			std::cout << "the operator number " << ia << " is at " << parsed_calcul[ia]->get_valeur() << " and it links with " << parsed_calcul[ia]->get_ptr_bas1() << " and " << parsed_calcul[ia]->get_ptr_bas2() << std::endl;
		//}
	}
	return 0;
}