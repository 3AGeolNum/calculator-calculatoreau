/**
 * \file parser.h
 * \brief Parser of the calculator
 * \author CAPILLON Quentin
 * \version 1.0
 * \date 06 octobre 2020
 *
 * definitions of the functions needed to define the order of the calculations that the operator will do.
 *
 */
 
#include <iostream>
#ifndef calcul_parsing
#define calcul_parsing
#include <calc_lib/lexer.h>

DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial){

	DynArray<Bloc*> operator_array((calcul_initial.size()-1)/2);
	int position_operator_array = 0;
	for( int num_bloc = 1; num_bloc < calcul_initial.size(); num_bloc++ ){
		
		if( calcul_initial[num_bloc]->get_nature() ){
			operator_array[position_operator_array] = calcul_initial[num_bloc];
			position_operator_array += 1;
		}
	}
	return operator_array;
} 

void link_bloc( const DynArray<Bloc*>& operator_array, const DynArray<Bloc*>& calcul_initial,int num_ope, bool second_iteration, bool first_second_iteration = false){
	
	/*numbers of the blocks to be linked in the calcul_initial
	initialized for the numbers on either side of the current operator
	*/
	int num_bloc1 = num_ope * 2;
	int num_bloc2 = 2 * (num_ope + 1);

	//test if we have to change blocs to linked
	
	//in first position we don't have to change
	if (num_ope > 0) {
		if( operator_array[num_ope - 1]->get_ptr_below1() != nullptr ){
			num_bloc1 -= 1;
            while( second_iteration && !first_second_iteration && num_bloc1 - 1 > 0 && (calcul_initial[num_bloc1]->get_value() == "*" || calcul_initial[num_bloc1]->get_value() == "/") )
            {
				num_bloc1 -= 2;
			}
		}
	}

	if ( num_ope < operator_array.size() - 1 ){
		if ( operator_array[num_ope + 1]->get_ptr_below1() != nullptr ){
			num_bloc2 += 1;

			while ( second_iteration && num_bloc2 + 2 < calcul_initial.size() && (calcul_initial[num_bloc2 + 2]->get_value() == "*" || calcul_initial[num_bloc2 + 2]->get_value() == "/" )){
				num_bloc2 += 2;
			}
		}	
	}
	operator_array[num_ope]->set_ptr_below1( calcul_initial[num_bloc1] );
	operator_array[num_ope]->set_ptr_below2( calcul_initial[num_bloc2] );
}

void seeker_and_fill(std::string symb1, std::string symb2, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count){
	for(int pos = 0; pos < operator_array.size(); ++pos){
		if(operator_array[pos]->get_value() == symb1 || operator_array[pos]->get_value() == symb2){
			operator_array_ordonated[count] = operator_array[pos];
			++count;
		}
	}
}

void ordonate_array(const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated){
	int count = 0;
	std::string operators = "*/+-";
	for (int pp=0; pp<4; ++++pp){
		seeker_and_fill(std::string(operators, pp, 1), std::string(operators, pp + 1, 1), operator_array,operator_array_ordonated, count);
	}
}

DynArray<Bloc*> parser(const DynArray<Bloc*>& calcul_initial){
	
	
	DynArray<Bloc*> operator_array = generate_operator_array( calcul_initial );
	DynArray<Bloc*> operator_array_ordonated( operator_array.size() );
	//operator_array_ordonated.resize(0);
	
	// for the first iteration we are just interest of * and / 
	
	bool second_iteration = false;

	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		
		if ( operator_array[num_ope]->get_value() == "*" || operator_array[num_ope]->get_value() == "/" ){
			
		//	std::cout << "operator value is : " << std::endl;
		//	std::cout << operator_array[num_ope]->get_value() << std::endl;
			link_bloc( operator_array, calcul_initial, num_ope, second_iteration);
		}
	}
	
	second_iteration = true;
    bool first_second_iteration = true;
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
        int count = 0;
		if( operator_array[num_ope]->get_value() == "+" || operator_array[num_ope]->get_value() == "-") {
				
			link_bloc( operator_array, calcul_initial, num_ope, second_iteration, first_second_iteration );
		//	std::cout << operator_array[num_ope]->get_value() << std::endl;
			count += 1;
            first_second_iteration = false;
		}
	}
	// ordonate the operator_array in operator_array_ordonated.
	ordonate_array(operator_array, operator_array_ordonated);
	
	return operator_array_ordonated;
}	

#endif