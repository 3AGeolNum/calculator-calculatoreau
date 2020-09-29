#include <string>
#include <iostream>
#include <calc_lib/parcer.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main(){
	
	std::cout << "entrez un calcul valable : " << std::endl;
	std::string calcul;
	std::cin >> calcul >> std::endl;
	
	DynArray<Bloc*> calcul_bloc = lexer( calcul );
	DynArray<Bloc*> parsed_calcul = parser( calcul_bloc );
	
	std::cout << 
	for (int ia = 0 ; ia < parsed_calcul.size(); ++ia){
		std::cout << "the operator number " << ia << " is at " << parsed_calcul[ia] << " and it links with " << parsed_calcul[ia]->ptr_bas1() << " and " << parsed_calcul[ia]->ptr_bas2() << std::endl;
	}
	return 0
}