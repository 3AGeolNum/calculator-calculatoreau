
DynArray<Bloc*> generate_operator_array(const DynArray<Bloc*>& calcul_initial){

	DynArray<Bloc*> operator_array((calcul_initial.size()-1)/2);
	for( int num_bloc = 1; num_bloc < calcul_initial.size(); num_bloc++ ){
		
		if( calcul_initial[num_bloc]->nature ){
			Bloc* current_bloc_ptr = new Bloc(*calcul_initial[num_bloc]);
			operator_array[num_bloc] = current_bloc_ptr;
		}
	}
	return operator_array;
	
} 

void organize_priority_operators(const DynArray<Bloc*>& calcul_initial){
	
	
	DynArray<Bloc*> operator_array = generate_operator_array(calcul_initial);
	DynArray<Bloc*> operator_array_ordonated(operator_array.size());
	operator_array_ordonated.resize(0);
	
	
	
	while( operator_array_ordonated.size() != operator_array.size()){
		
		
		
	}
}

bool link_bloc(DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial, int num_bloc1, int num_bloc2, bool if_precedent_edited){
	if ( !if_precedent_edited ){
			
				operator_array[num_ope]->set_ptr_bas1( calcul_initial[num_bloc1] );
				operator_array[num_ope]->set_ptr_bas2( calcul_initial[num_bloc2] );
				
				operator_array_ordonated.puch_back(operator_array[num_ope]);
				if_precedent_edited = True;
			}
			else{
				if_precedent_edited = False;
			}
}

void edit_links1(DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial){
	std::string multiply, divise = "*", "/";
	bool if_precedent_edited = False; // true si le bloc de l'opérateur précedent à été édité
	
	for( int num_ope = 0; num_ope < operator_array.size(); num_bloc++ ){
		
		if (operator_array->get_item() == multiply || operator_array->get_item() == divise ){
			
			if_precedent_edited = link_bloc( operator_array, operator_array_ordonated, calcul_initial, 2 * num_bloc, 2 * (num_bloc + 1), if_precedent_edited );
		}
		else{
			if_precedent_edited = False;
		}
	}
}

		
void edit_links(DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, const DynArray<Bloc*>& calcul_initial){
	std::string multiply, divise = "*", "/";
	bool if_precedent_edited = False; // true si le bloc de l'opérateur précedent à été édité
	
	for( int num_ope = 0; num_ope < operator_array.size(); num_bloc++ ){
		
		if( operator_array[num_ope]->get_ptr_bas1 == nullptr ) {
		
			
		}
	}
}	
	