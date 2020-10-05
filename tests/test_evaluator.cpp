#include <string>
#include <iostream>
#include <calc_lib/lexer.h>
#include <calc_lib/parser.h>
#include <calc_lib/evaluator.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main() {
    //std::string calcul = "0";
	//do{
	//std::cout << "entrez un calcul valable : " << std::endl;
	//std::cin >> calcul;
	
	std::string calcul = "-45-9+89*-4";
	DynArray<Bloc*> calcul_bloc = lexer(calcul);
	DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);
	//std::cout << "Le resultat est : " << evaluator(parsed_calcul) << std::endl;
	//}while(calcul != "0");
	
	if(atof((evaluator(parsed_calcul)).c_str()) != -410.0){
		return 1;
	}
	return 0;
}