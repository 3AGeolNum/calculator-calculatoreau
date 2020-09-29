
#include <iostream>
#ifndef calcul_parsing
#define calcul_parsing
#include <calc_lib\lexer.h>

// in this fonction we create new blocs we may dont forget to delete it in the calculator
DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial){

	DynArray<Bloc*> operator_array((calcul_initial.size()-1)/2);
	for( int num_bloc = 1; num_bloc < calcul_initial.size(); num_bloc++ ){
		
		if( calcul_initial[num_bloc]->get_nature() ){
			Bloc* current_bloc_ptr = new Bloc(*calcul_initial[num_bloc]);
			operator_array[num_bloc] = current_bloc_ptr;
		}
	}
	return operator_array;
	
} 

bool link_bloc( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2, bool if_precedent_edited ){
	if ( !if_precedent_edited ){
			
		operator_array[num_ope]->set_ptr_bas1( calcul_initial[num_bloc1] );
		operator_array[num_ope]->set_ptr_bas2( calcul_initial[num_bloc2] );
		
		operator_array_ordonated.push_back(operator_array[num_ope]);
		if_precedent_edited = true;
	}
	else{
		if_precedent_edited = false;
	}
	return if_precedent_edited;
}

void edit_links1( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial ){
	std::string multiply = "*";
	std::string divise = "/";
	bool if_precedent_edited = false; // true si le bloc de l'opérateur précedent à été édité dans cette boucle
	
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		
		if (operator_array[num_ope]->get_valeur() == multiply || operator_array[num_ope]->get_valeur() == divise ){
			
			//determination of side-bloc links
			int num_bloc1 = num_ope * 2;
			int num_bloc2 = 2 * (num_ope + 1);
			if_precedent_edited = link_bloc( operator_array, operator_array_ordonated, calcul_initial, num_ope, num_bloc1, num_bloc2, if_precedent_edited );
		}
		else{
			if_precedent_edited = false;
		}
	}
}

		
void edit_links( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial ){
	bool if_precedent_edited = false; // true si le bloc de l'opérateur précedent à été édité
	
	for( int num_ope = 0; num_ope < operator_array.size(); num_ope++ ){
		
		if( operator_array[num_ope]->get_ptr_bas1() == nullptr && if_precedent_edited ) {
		
			int num_bloc1 = num_ope * 2;
			int num_bloc2 = 2 * (num_ope + 1);
			
			if( operator_array[num_ope + 1]->get_ptr_bas1() != nullptr ){
				num_bloc1 -= 1;
			}
			
			if( operator_array[num_ope + 1]->get_ptr_bas1() != nullptr ){
				num_bloc2 += 1;
			}
			
			if_precedent_edited = link_bloc( operator_array, operator_array_ordonated, calcul_initial, num_ope, num_bloc1, num_bloc2, if_precedent_edited );
		}
		else{
			if_precedent_edited = false;
		}
	}
}

DynArray<Bloc*> parser(const DynArray<Bloc*>& calcul_initial){
	
	
	DynArray<Bloc*> operator_array = generate_operator_array( calcul_initial );
	DynArray<Bloc*> operator_array_ordonated( operator_array.size() );
	operator_array_ordonated.resize(0);
	
	// for the first iteration we are just interest of * and / 
	edit_links1( operator_array, operator_array_ordonated, calcul_initial );
	
	while( operator_array_ordonated.size() != operator_array.size()){
		
		edit_links( operator_array, operator_array_ordonated, calcul_initial );
	}
	
	return operator_array_ordonated;
}	

#endif