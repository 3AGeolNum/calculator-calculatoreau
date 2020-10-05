/**
 * \file lexer.cpp
 * \brief Lexer of the calculator
 * \author PERRIER Yassine
 * \version 1.0
 * \date 28 september 2020
 *
 * definitions of the functions needed to cut the input string into unitary blocs.
 *
 */

#include <string>
#include <iostream>
#include <CalculetteProjectConfig.h>
#include <calc_lib/lexer.h>

void copy_local(DynArray<Bloc*>& new_tab, const DynArray<Bloc*>& local_tab_copied) {
	for (int ia = 0; ia < new_tab.size(); ia++) {
		new_tab[ia] = local_tab_copied[ia];
	}
}


DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size){
	DynArray<Bloc*> modified(size);
	copy_local(modified, other);
	return modified;
}

DynArray<Bloc*> lexer(const std::string& input) {
	//String giving the operators authorized.
	std::string list_of_operators = "+-*/";
	//Container of the Bloc object.
	DynArray<Bloc*> list_of_bloc(input.size());
	//Position where to put the next bloc in list_of_bloc.
	int position_in_array = 0;
	//number is containing the current number read by the function.
	std::string number = "";
	//value allowing us to konw if we just went through the if bloc. This way we 
	//enter in the "if" bloc again, only if we went through the "else" bloc before.
	int intermediate = -99;
	//To loop in the list_of_bloc
	for (int unsigned position = 0; position < input.size(); ++position) {
		//If we encounter an operator defined in list_of_operators
		if (list_of_operators.find(input[position]) != std::string::npos && intermediate == 0)
		{
			intermediate = 1;
			list_of_bloc[position_in_array] = new Bloc(false, number); //bloc number
			position_in_array++;
			list_of_bloc[position_in_array] = new Bloc(true, std::string(input, position, 1)); //bloc opérator
			//We empty the variable number.
			number = "";
			position_in_array++;
		}
		else {
			intermediate = 0;
			//We add the figure in number to build the number we'll put in the next bloc.
			number += std::string(input, position, 1); 
		}
	}
	list_of_bloc[position_in_array] = new Bloc(false, number);
	return cleaner_tab(list_of_bloc, position_in_array +1);
}

