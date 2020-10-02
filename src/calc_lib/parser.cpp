#ifndef calcul_parsing_h
#define calcul_parsing_h

#include <iostream>
#include <calc_lib/lexer.h>
#include <calc_lib/parser.h>


// in this fonction we create new blocs we may dont forget to delete it in the calculator
DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial){
	int count = 0;
	DynArray<Bloc*> operator_array(calcul_initial.size());
	for( int num_bloc = 0; num_bloc < calcul_initial.size(); num_bloc++ ){
		std::cout << "Passage par cette boucle" << std::endl;
		if( calcul_initial[num_bloc]->get_nature() ){
			operator_array[count] = new Bloc(*calcul_initial[num_bloc]);
			//operator_array[count] = calcul_initial[num_bloc];
			std::cout << "Mon bloc est " << operator_array[count]->get_valeur() << std::endl;		
			++count;
		}
	}
	std::cout << "Pourquoi" << std::endl;
	//DynArray<Bloc*> test(cleaner_tab(operator_array, count));
	std::cout << "Mon bloc est " << operator_array[0]->get_valeur() << std::endl;
	return cleaner_tab(operator_array, count);
	
} 

bool link_bloc( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2, bool if_precedent_edited ){
	if ( !if_precedent_edited ){
			
		operator_array[num_ope]->set_ptr_bas1( calcul_initial[num_bloc1] );
		operator_array[num_ope]->set_ptr_bas2( calcul_initial[num_bloc2] );
		
		if_precedent_edited = true;
	}
	else{
		//if we have more than one * or / in the row.
		operator_array[num_ope]->set_ptr_bas1(calcul_initial[num_bloc1-1]);
		operator_array[num_ope]->set_ptr_bas2(calcul_initial[num_bloc2]);
		
		if_precedent_edited = false;
	}
	return if_precedent_edited;
}

void initializing_links_for_plusminus( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, 
const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2, bool if_precedent_edited ){
	//Todo: cut the long following function named edit_links.
}

void edit_links1( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial ){
	bool if_precedent_edited = false; // true si le bloc de l'opérateur précedent à été édité dans cette boucle
	
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		int num_bloc1 = num_ope * 2;
		int num_bloc2 = 2 * (num_ope + 1);
		std::cout << "AVANT PREMIER IF" << std::endl;
		if (operator_array[num_ope]->get_valeur() == "*" || operator_array[num_ope]->get_valeur() == "/" ){
			std::cout << "APRES" << std::endl;
			//determination of side-bloc links
			if_precedent_edited = link_bloc( operator_array, operator_array_ordonated, calcul_initial, num_ope, num_bloc1, num_bloc2, if_precedent_edited );
		}
		//if we have a plus or a minus on the first or last position !
		//if we have only one plus or minus. Ex: 2+5.
		else if (num_ope == 0 && num_ope == operator_array.size()-1){
			operator_array[num_ope]->set_ptr_bas1(calcul_initial[num_bloc1]);
			operator_array[num_ope]->set_ptr_bas2(calcul_initial[num_bloc2]);
			if_precedent_edited = false;
		}
		//In first position
		else if (num_ope == 0){
			operator_array[num_ope]->set_ptr_bas1(calcul_initial[num_bloc1]);
			operator_array[num_ope]->set_ptr_bas2(calcul_initial[num_bloc2+1]);
			if_precedent_edited = false;
		}
		//In last position
		else if (num_ope == operator_array.size()-1){
			operator_array[num_ope]->set_ptr_bas1(calcul_initial[num_bloc1-1]);
			operator_array[num_ope]->set_ptr_bas2(calcul_initial[num_bloc2]);
			if_precedent_edited = false;
		}
		else{
			operator_array[num_ope]->set_ptr_bas1(calcul_initial[num_bloc1 - 1]);
			operator_array[num_ope]->set_ptr_bas2(calcul_initial[num_bloc2 + 1]);
			if_precedent_edited = false;
		}
	}
}

void seeker_and_fill(std::string symb, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count){
	for(int pos = 0; pos < operator_array.size(); ++pos){
		if(operator_array[pos]->get_valeur() == symb){
			operator_array_ordonated[count] = operator_array[pos];
			++count;
		}
	}
}

void ordonate_array(const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated){
	int count = 0;
	std::string operators = "*/+-";
	for (int pp=0; pp<4; ++pp){
		seeker_and_fill(std::string(operators, pp, 1),operator_array,operator_array_ordonated,count);
	}
}

DynArray<Bloc*> parser(const DynArray<Bloc*>& calcul_initial){
	
	
	DynArray<Bloc*> operator_array(generate_operator_array( calcul_initial ));
	DynArray<Bloc*> operator_array_ordonated( operator_array.size() );

	// we edit links between blocs
	edit_links1( operator_array, operator_array_ordonated, calcul_initial );

	// we ordonate the operator_array in operator_array_ordonated.
	ordonate_array(operator_array, operator_array_ordonated);
	
	return operator_array_ordonated;
}	

#endif