
#include <calc_lib\bloc.h>


Bloc::Bloc( bool nature, std::string item, Bloc* ptr_haut, Bloc* ptr_bas1, Bloc* ptr_bas2):
	nature_(nature), item_(item), ptr_bas1_(ptr_bas1), ptr_bas2_(ptr_bas2), ptr_haut_(ptr_haut) {
		std::cout << "coucou je suis un bloc de nature " << nature << "et qui contient " << item_ << std::endl;	
		// les nombre n'ont pas de ptr_bas
	}
	
Bloc::~Bloc(){
}

void Bloc::set_nature(bool nature){
	//0 for nomber and 1 for operator
	
	nature_ = nature;
	std::cout << " hhe tu viens de changer ma nature vers " << nature << std::endl;
}

//bool Bloc::get_nature() const { return nature_; }

void Bloc::set_valeur(std::string item){
	item_ = item;
	std::cout << " hhe tu viens de changer mon contenu vers " << item << std::endl;
}

//std::string Bloc::get_valeur() { return item_; }

void Bloc::set_ptr_haut(Bloc* ptr){
	ptr_haut_ = ptr;
}

void Bloc::set_ptr_bas1(Bloc* ptr){
	ptr_bas1_ = ptr;
}

void Bloc::set_ptr_bas2(Bloc* ptr){
	ptr_bas2_ = ptr;
}

Bloc* Bloc::get_ptr_haut() { return ptr_haut_; }

Bloc* Bloc::get_ptr_bas1() { return ptr_bas1_; }

Bloc* Bloc::get_ptr_bas2() { return ptr_bas2_; }