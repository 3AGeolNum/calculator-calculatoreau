#include <CalculetteProjectConfig.h>
#include <string>
#include <iostream>
#include <calc_lib\lexer.h>
#include <calc_lib\parser.h>
#include <calc_lib\evaluator.h>
#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>
#include <calc_lib\checker.h>

/**
 * \fn int main (void)
 * \brief Entry of the program
 *
 * \return EXIT_SUCCESS - Normal stop of the program.
 */

int main(){
	
	// 1/-- Call to the checker
	std::string in; //string input.
	Checker checke = Checker(in);
	while (in != "quit") {
		std::cout << "Enter your equation, to exit enter quit" << std::endl;
		std::getline(std::cin, in);
		Checker checke = Checker(in);
		if (checke.complete_check()) {
			// 2/-- Call to the lexer
			DynArray<Bloc*> calcul_bloc = lexer(in);

			// 3/-- Call to the parser
			DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);

			// 4/-- Call to the evaluator
			std::cout << "Le resultat est : " << evaluator(parsed_calcul) << std::endl;

			std::cout << "nous sommes dans le main " << std::endl;
		}
	}
	return EXIT_SUCCESS;
}