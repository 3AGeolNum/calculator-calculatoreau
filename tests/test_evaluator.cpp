#include <string>
#include <iostream>
#include <calc_lib/lexer.h>
#include <calc_lib/parser.h>
#include <calc_lib/evaluator.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

int main() {
	std::string calcul = "-45-9+89*-4.-.0";
	DynArray<Bloc*> calcul_bloc = lexer(calcul);
	std::cout << "lexer okay! " << std::endl;
	DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);
	
	
	if(atof((evaluator(parsed_calcul)).c_str()) != -410.0){
		return 1;
	}
	return 0;
}
