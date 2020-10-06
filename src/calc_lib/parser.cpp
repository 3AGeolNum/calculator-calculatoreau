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
		
		}
	}
	return operator_array;
} 

void link_bloc( const DynArray<Bloc*>& operator_array, const DynArray<Bloc*>& calcul_initial,int num_ope, bool second_iteration){
	
	/*numbers of the blocks to be linked in the calcul_initial
	initialized for the numbers on either side of the current operator
	*/
	int num_bloc1 = num_ope * 2;
	int num_bloc2 = 2 * (num_ope + 1);
	
	//test if we have to change blocs to linked
	
	//in first position we don't have to change
	if (num_ope > 0) {
		//test if the previous operator has been edited if yes we position num_bloc1 on it
		if( operator_array[num_ope - 1]->get_ptr_bas1() != nullptr ){
			num_bloc1 -= 1;
			
			//during the second iteration + and - are edited they must therefore be linked to the result of a series of * or / rather than to the nearest operator
			//check that we are not going to exit the array to test it
			if ( second_iteration && num_bloc1 - 1 > 0 ){
				
				while ( calcul_initial[num_bloc1]->get_valeur() == "*" || calcul_initial[num_bloc1]->get_valeur() == "/" ){
					num_bloc1 -= 2;
				}
			}
		}
	}
	
	//in last position we don't have to change
	if ( num_ope < operator_array.size() - 1 ){
		//test if the next operator has been edited if yes we position num_bloc2 on it
		if ( operator_array[num_ope + 1]->get_ptr_bas1() != nullptr ){
			num_bloc2 += 1;
			
			//same explication like line 47 in the other direction
			if ( second_iteration && num_bloc2 + 2 < calcul_initial.size() ){
				
				while ( calcul_initial[num_bloc2 + 2]->get_valeur() == "*" || calcul_initial[num_bloc2 + 2]->get_valeur() == "/" ){
					num_bloc2 += 2;
				}
			}
		}	
	}
	//in finally we edit links
	operator_array[num_ope]->set_ptr_bas1( calcul_initial[num_bloc1] );
	operator_array[num_ope]->set_ptr_bas2( calcul_initial[num_bloc2] );
}

void fill_ordonated_operator_array(std::string symb1, std::string symb2, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count){
	
	for(int pos = 0; pos < operator_array.size(); ++pos){
		
		if(operator_array[pos]->get_valeur() == symb1 || operator_array[pos]->get_valeur() == symb2){
			operator_array_ordonated[count] = operator_array[pos];
			++count;
		}
	}
}

void ordonate_array(const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated){
	
	// count stok the size of ordonated_operator_array, it count iterations
	int count = 0;
	std::string operators = "*/+-";
	for (int pp=0; pp<4; ++++pp){
		fill_ordonated_operator_array(std::string(operators, pp, 1), std::string(operators, pp + 1, 1), operator_array,operator_array_ordonated, count);
	}
}

DynArray<Bloc*> parser(const DynArray<Bloc*>& calcul_initial){
	
	//first generate arrays with just operator 
	DynArray<Bloc*> operator_array = generate_operator_array( calcul_initial );
	DynArray<Bloc*> operator_array_ordonated( operator_array.size() );
	
	// for the first iteration we are just interest of * and / 	
	bool second_iteration = false;
	//we edit all the links of the * and / operators in order
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		
		if ( operator_array[num_ope]->get_valeur() == "*" || operator_array[num_ope]->get_valeur() == "/" ){
			link_bloc( operator_array, calcul_initial, num_ope, second_iteration);
		}
	}
	
	/*in the second iteration we link operatos + and -.
	boll second_iteration is difine to use the same fonction link_bloc for the 2 iteration
	*/
	second_iteration = true;
	//we make all the links of the + and - operators in order
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){

		if( operator_array[num_ope]->get_valeur() == "+" || operator_array[num_ope]->get_valeur() == "-") {
			link_bloc( operator_array, calcul_initial, num_ope, second_iteration );
		}
	}
	// we ordonate the operator_array in operator_array_ordonated for the calculation.
	ordonate_array(operator_array, operator_array_ordonated);
	
	return operator_array_ordonated;
}	

#endif