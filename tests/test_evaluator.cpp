#include <string>
#include <iostream>
#include <calc_lib\lexer.h>
#include <calc_lib\parser.h>
#include <calc_lib\evaluator.h>
#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>

int main() {

	std::cout << "entrez un calcul valable : " << std::endl;
	std::string calcul;
	std::cin >> calcul;

	DynArray<Bloc*> calcul_bloc = lexer(calcul);
	DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);
	std::cout << "Le resultat est : " << evaluator(parsed_calcul) << std::endl;

	return 0;
}