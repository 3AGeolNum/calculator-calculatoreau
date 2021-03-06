#include <calc_lib/evaluator.h>
#include <calc_lib/bloc.h>
#include <calc_lib/lexer.h>
#include <iostream>
#include <string>

std::string evaluator(const DynArray< Bloc* >& parsed_calcul )
{
    //DynArray< Bloc* > parsed_calcul( calcul_init.size() );
    //copy_local( parsed_calcul, calcul_init );
	std::string res;
	for (int ia = 0; ia < parsed_calcul.size(); ++ia) {
		
		/* left and right terms are obtained with the values of bottom bloc pointers. 
		 The expression atof interprete the content as a floating point number and returns its value as a double 
		 */

		double lhs = atof(((parsed_calcul[ia]->get_ptr_below1())->get_value()).c_str()); // left term of the operation
		double rhs = atof(((parsed_calcul[ia]->get_ptr_below2())->get_value()).c_str()); // right term of the operation

		/* loop to do all the operations in the order in which the blocks are received by the parser
		*/
		if (std::string(parsed_calcul[ia]->get_value(), 0, 1) == "+")
		{
			res = std::to_string(add(lhs, rhs));
		}
		else if (std::string(parsed_calcul[ia]->get_value(), 0, 1) == "-")
		{
			res = std::to_string(sub(lhs, rhs));
		}
		else if (std::string(parsed_calcul[ia]->get_value(), 0, 1) == "*")
		{
			res = std::to_string(mul(lhs, rhs));
		}
		else if (std::string(parsed_calcul[ia]->get_value(), 0, 1) == "/")
		{
			res = std::to_string(div(lhs, rhs));
		}

		parsed_calcul[ia]->set_value(res);
	}
	return res;
}


double add(double lhs, double rhs) {
	return lhs + rhs;
}

double sub(double lhs, double rhs) {
	return lhs - rhs;
}

double mul(double lhs, double rhs) {
	return lhs * rhs;
}

double div(double lhs, double rhs) {
	assert( rhs != 0.0 ); // In debug mode.
	if( rhs != 0.0 ){ //in release mode.
		return lhs / rhs;
	}
	std::cout << "Division by 0 noticed" << std::endl;
	exit( 3 );
}