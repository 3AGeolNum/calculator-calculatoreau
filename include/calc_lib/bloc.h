/*!
 * \file bloc.h
 * \brief Bloc class defining the smallest element of the input string corresponding to the calculations to do.
 * \author CAPILLON Quentin & PERRIER Yassine
 * \version 1.0
 */

#ifndef BLOC_h
#define BLOC_h

#include<string>
#include<iostream>

class Bloc{
	public:
		//! Bloc's constructor
		/*!
		\sa Bloc(bool nature=false, std::string item="", Bloc* ptr_haut = nullptr , Bloc* ptr_bas1 = nullptr, Bloc* ptr_bas2 = nullptr)
		\param nature false if it is a number and true if it is an operator.
				item string corresponding to the value of the bloc (number or operator)
				ptr_haut pointer to the bloc needing the result of this operation in case the current bloc is an operator.
				ptr_bas1 pointer to the first bloc needed to apply the operation in case the current bloc is an operator.
				ptr_bas2 pointer to the second bloc needed to apply the operation in case the current bloc is an operator.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		Bloc( bool nature=false, std::string item="", Bloc* ptr_haut = nullptr , Bloc* ptr_bas1 = nullptr, Bloc* ptr_bas2 = nullptr);
		//! Bloc's destructor
		/*!
		\sa ~Bloc()
		\author {CAPILLON Quentin}
	    \version {1.0}
		\date October 2nd 2020
		*/
		~Bloc();
		
		//! Set the nature of the bloc.
		/*!
		\sa set_nature(bool nature)
		\param nature true if it is an operator and false if not.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		void set_nature(bool nature);
		
		//! Get the nature of the bloc.
		/*!
		\sa get_nature()
		\return nature_ of the bloc ; true if it is an operator and false if not.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		bool get_nature() const { return nature_; };
		
		//! Set the value of the bloc.
		/*!
		\sa set_valeur(std::string item)
		\param item string giving the value.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		void set_valeur(std::string item);
		
		//! Get the value of the bloc.
		/*!
		\sa set_valeur(std::string item)
		\return item_ which is the value.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		std::string get_valeur() { return item_; };
		
		//! Set the pointers of the bloc.
		/*!
		\sa set_ptr_haut(Bloc* ptr) set_ptr_bas1(Bloc* ptr) set_ptr_bas2(Bloc* ptr)
		\param ptr pointeur to the bloc to be linked.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
		void set_ptr_haut(Bloc* ptr);
		void set_ptr_bas1(Bloc* ptr);
		void set_ptr_bas2(Bloc* ptr);
		
		//! Get the pointers of the bloc.
		/*!
		\sa get_ptr_haut(Bloc* ptr) get_ptr_bas1(Bloc* ptr) get_ptr_bas2(Bloc* ptr)
		\return ptr pointeur linked to the bloc.
		\author {CAPILLON Quentin & PERRIER Yassine}
		\version {1.0}
		\date October 2nd 2020
		*/
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