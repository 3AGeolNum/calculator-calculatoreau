#include <iostream>
#include <string>


int main()
{


	bool condition = true; // Tant que la condition est vraie, répéter la boucle de calculs

	do
	{
		std::cout << "Please enter your calculation : " << std::endl;
		std::string calc();
		getline(cin, calc); // gestion des espaces 

		std::string calc_input();
		calc_input = calc.check_input();

		DynArray <Bloc*> lexer(calc_input.size()) // Tableau dynamique de pointeurs de blocs


		for (int ia(0); ia << calc_input.size(); ++ia)
		{
			Bloc* bloc = new Bloc;
			
			lexer = calc_input(dolexer);
			lexer.pushback(bloc);
		}


		parser(lexer);
		evaluator(lexer);



		std::cout << "Press Q to exit  : " << std::endl;
		std::string exit();
		getline(cin, exit); 



		if (exit == "Q")             // Si Q, on change la condition pour quitter, sinon, on recommence
		{
			condition = false;
		}

	} while (condition == true);
	
	std::cout << "Thank you and see you soon !" << std::endl;

	return 0;
}