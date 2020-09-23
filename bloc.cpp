#include <bloc.h>


template<class t> Bloc<T>::Bloc( int nature, T item, Bloc* ptr_haut = nullptr , Bloc* ptr_bas1 = nullptr, Bloc* ptr_bas2 = nullptr):
	nature_(nature), item_(item), ptr_bas1_(ptr_bas1), ptr_bas2_(ptr_bas2), ptr_haut_(ptr_haut) {
		std::cout << "coucou je suis un bloc de nature " << nature << "et qui contient " << item_ << std::endl;
		
		// les nombre n'ont pas de ptr_bas
	}
	
template<class t> Bloc<T>::~Bloc(){
}

template<class t> void Bloc<T>::Set_nature(int nature){
	//0 for nomber and 1 for operator
	
	nature_ = nature;
	std::cout << " hhe tu viens de changer ma nature vers " << nature << std::endl;
}

template<class t> int Bloc<T>::Get_nature(){ return nature_; }

template<class t> void Bloc<T>::Set_item(T item){
	item_ = item;
	std::cout << " hhe tu viens de changer mon contenu vers " << item << std::endl;
}

template<class t> T Bloc<T>::Get_valeur() { return item_; }

template<class t> void Bloc<T>::Set_ptr_haut(Bloc* ptr){
	ptr_haut_ = ptr
}

template<class t> void Bloc<T>::Set_ptr_bas1(Bloc* ptr){
	ptr_bas1_ = ptr
}

template<class t> void Bloc<T>::Set_ptr_bas2(Bloc* ptr){
	ptr_bas2_ = ptr
}

template<class t> Bloc* Bloc<T>::Get_ptr_haut() { return ptr_haut; }

template<class t> Bloc* Bloc<T>::Get_ptr_bas1() { return ptr_bas1; }

template<class t> Bloc* Bloc<T>::Get_ptr_bas2() { return ptr_bas2; }