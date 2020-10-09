#include <CalculetteProjectConfig.h>
#include <string>
#include <iostream>
#include <calc_lib/lexer.h>
#include <calc_lib/parser.h>
#include <calc_lib/evaluator.h>
#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>
#include <calc_lib/checker.h>
/**
 * \file main.cpp
 * \brief Entry of the calculator project
 * \author PERRIER Yassine
 * \version 1.0
 * \date 28 september 2020
 *
 */


/**
 * \fn int main()
 * \brief Entry of the program
 *
 * \return EXIT_SUCCESS - Normal stop of the program.
 */

//void affichage( DynArray< Bloc* > parsed_calcul ) {
//	for (int i = 0; i < parsed_calcul.size(); i++) {
//        std::cout << "Mon pointeur est : " << parsed_calcul[i] << std::endl;
//        std::cout << "Mon pointeur bas 1 " << parsed_calcul[i]->get_ptr_bas1()
//                  << std::endl;
//        std::cout << "Mon pointeur bas 2 " << parsed_calcul[i]->get_ptr_bas2()
//                  << std::endl;
//	}
//}

int main(){
	
	// 1/-- Call to the checker
	std::string in; //string input.
	while (in != "quit") {
		std::cout << "Enter your equation, to exit enter quit" << std::endl;
		std::getline(std::cin, in);
		Checker checke = Checker(in);
		if (checke.complete_check()) {
			// 2/-- Call to the lexer
            DynArray< Bloc* > calcul_bloc = lexer( checke.get_input_modified());
            //std::cout << "TEST " << checke.get_input_modified() << std::endl;
			//if there is at least one operation
			if (calcul_bloc.size()>1){
				// 3/-- Call to the parser
				DynArray<Bloc*> parsed_calcul = parser(calcul_bloc);
                //affichage( parsed_calcul );

				// 4/-- Call to the evaluator
				std::cout << "The result is : " << evaluator(parsed_calcul) << std::endl;
			}
			//if only one number
			else{
                std::cout << "The result is : " << checke.get_input_modified() << std::endl;
			}
		}
	}
	return EXIT_SUCCESS;
}