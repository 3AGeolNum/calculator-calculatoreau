#ifndef BLOC_h
#define BLOC_h

#include<string>
#include<iostream>

class Bloc{
	public:
		Bloc( bool nature, std::string item, Bloc* ptr_haut = nullptr , Bloc* ptr_bas1 = nullptr, Bloc* ptr_bas2 = nullptr);
		~Bloc();
		
		void set_nature(bool nature); //0 for nomber and 1 for operator
		bool get_nature() const { return nature_; };
		void set_valeur(std::string item);
		std::string get_valeur() { return item_; };
		void set_ptr_haut(Bloc* ptr);
		void set_ptr_bas1(Bloc* ptr);
		void set_ptr_bas2(Bloc* ptr);
		Bloc* get_ptr_haut();
		Bloc* get_ptr_bas1();
		Bloc* get_ptr_bas2();
	private :
		bool nature_;//false for nomber and true for operator
		std::string item_;
		Bloc* ptr_haut_;
		Bloc* ptr_bas1_;
		Bloc* ptr_bas2_;
		
};

#endif