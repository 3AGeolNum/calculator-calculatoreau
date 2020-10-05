#ifndef CHECKER_h
#define CHECKER_h

#include <iostream>
/**
 * \file checker.h
 * \brief Header of the checker class
 * \author Priscillia.L
 * \version 0.0.1
 * \date October 2nd 2020
 *
 * Programme de test pour l'objet de gestion des chaînes de caractères Str_t.
 *
 */


class Checker {
public:
	//! Cheker's constructor
	/*!
      \sa Checker(std::string str)
      \param str string to analyze
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */

	Checker(std::string str);
	//! Checker's destructor
/*!
      \sa ~Checker()
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	~Checker();
	
	//!  Verify whether the input string is empty
    /*!
      \sa is_input_empty(std::string str)
      \param str string to analyze
	  \return a boolean that says whether the input is empty (true) or not (false)
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	bool is_input_empty(std::string str);
	
	//! Use the position in the auth_ string to analyze the input string

    /*!
      \sa check_pos(int pos)
      \param pos result of a find into the auth_ string.
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	void check_pos(int pos);
	
	//!  Run test through the string

    /*!
      \sa check()
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	void check();
	
		//!  Verify if the first or last member of the input string is an operator. This situation is illegal

    /*!
      \sa is_end_operator()
      \param pos result of a find into the auth_ string.
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	void is_end_operator();
	
	//!  A class to be gone add is_end_operator to what check does and retun a boolean

    /*!
      \sa complete_check()
	  \return returns the boolean checked_ that says whether the string is up to our standard.
	  \author {Labourg Priscillia}
	  \version {0.0.1}
	  \date October 2nd 2020
    */
	bool complete_check();
	
	//!  Returns checked_, mostly used to debug

    /*!
      \sa get_checked()
	  \return the boolean checke in its current state.
	  \author {Labourg Priscillia}
	  \version {0.0.1}
    */
	bool get_checked();
	
	

private:
	int op_ = 0; // class variable used by check()
	int min_ = 0; // class variable used by check ()
	bool checked_ = true; //Boolean showing
	std::string auth_ = "1234567890		+-*/?,"; // String of allowed characters
	std::string input_; //String that needs to be checked


};

#endif