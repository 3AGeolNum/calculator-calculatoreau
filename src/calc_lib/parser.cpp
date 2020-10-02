#include <iostream>
#ifndef calcul_parsing
#define calcul_parsing
#include <calc_lib\lexer.h>

DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial){

	DynArray<Bloc*> operator_array((calcul_initial.size()-1)/2);
	int position_operator_array = 0;
	for( int num_bloc = 1; num_bloc < calcul_initial.size(); num_bloc++ ){
		
		if( calcul_initial[num_bloc]->get_nature() ){
			operator_array[position_operator_array] = calcul_initial[num_bloc];
			
			std::cout << operator_array[position_operator_array]->get_valeur() << std::endl;
			position_operator_array += 1;
		}
	}

	return operator_array;
	
} 

void link_bloc( const DynArray<Bloc*>& operator_array, const DynArray<Bloc*>& calcul_initial,int num_ope ){
	
	int num_bloc1 = num_ope * 2;
	int num_bloc2 = 2 * (num_ope + 1);
	
	if (num_ope > 0) {
		if( operator_array[num_ope - 1]->get_ptr_bas1() != nullptr ){
			num_bloc1 -= 1;
		}
	}

	if ( num_ope < operator_array.size() - 1 ){
		if ( operator_array[num_ope + 1]->get_ptr_bas1() != nullptr ){
			num_bloc2 += 1;
		}	
	}
	operator_array[num_ope]->set_ptr_bas1( calcul_initial[num_bloc1] );
	operator_array[num_ope]->set_ptr_bas2( calcul_initial[num_bloc2] );

}

void seeker_and_fill(std::string symb1, std::string symb2, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count){
	for(int pos = 0; pos < operator_array.size(); ++pos){
		if(operator_array[pos]->get_valeur() == symb1 || operator_array[pos]->get_valeur() == symb2){
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
	std::cout << "on passe aux * / " << "\n" << operator_array.size() << std::endl;

	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		
		if ( operator_array[num_ope]->get_valeur() == "*" || operator_array[num_ope]->get_valeur() == "/" ){
			std::cout << "la valeur de l'opérateur est : " << std::endl;
			std::cout << operator_array[num_ope]->get_valeur() << std::endl;
			link_bloc( operator_array, calcul_initial, num_ope );
		}
	}
	std::cout << "on passe aux + - " << std::endl;
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){

		if( operator_array[num_ope]->get_valeur() == "+" || operator_array[num_ope]->get_valeur() == "-") {
			
			link_bloc( operator_array, calcul_initial, num_ope );
			std::cout << "la valeur de l'opérateur est : " << std::endl;
			std::cout << operator_array[num_ope]->get_valeur() << std::endl;
		}
	}
	// we ordonate the operator_array in operator_array_ordonated.
	std::cout << "allé on ordonne tout ca " << std::endl;
	ordonate_array(operator_array, operator_array_ordonated);
	
	return operator_array_ordonated;
}	

#endif