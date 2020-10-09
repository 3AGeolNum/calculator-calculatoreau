
#include <calc_lib/bloc.h>


Bloc::Bloc( bool nature, std::string item, Bloc* ptr_below1, Bloc* ptr_below2):
	nature_(nature), item_(item), ptr_below1_(ptr_below1), ptr_below2_(ptr_below2) {
		// les nombre n'ont pas de ptr_bas
	}
	
Bloc::~Bloc(){
}

void Bloc::set_nature(bool nature){
	//0 for nomber and 1 for operator
	nature_ = nature;
}

//bool Bloc::get_nature() const { return nature_; }

void Bloc::set_value(std::string item){
	item_ = item;
}

//std::string Bloc::get_valeur() { return item_; }

void Bloc::set_ptr_below1(Bloc* ptr){
	ptr_below1_ = ptr;
}

void Bloc::set_ptr_below2(Bloc* ptr){
	ptr_below2_ = ptr;
}

Bloc* Bloc::get_ptr_below1() { return ptr_below1_; }

Bloc* Bloc::get_ptr_below2() { return ptr_below2_; }