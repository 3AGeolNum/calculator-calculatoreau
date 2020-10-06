#ifndef EVALUATOR_INCLUDED
#define EVALUATOR_INCLUDED

/*!
 * \file evaluator.h
 * \brief Evaluator function definition
 * \author Julien-Herrero
 * \version 1
 */

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

	/*!
	 *  \brief Evaluator function
	 *
	 *  Function that allows to apply the final calculation
	 *
	 *  \param calc : parsed calculation
	 *  \return character string containing the result of the calculation
	 */
std::string evaluator(const DynArray<Bloc*>& parsed_calcul);

	/*!
	 *  \brief Addition function
	 *
	 *  Addition function to apply an operator + between two terms
	 *
	 *  \param lhs : left term,
	 * rhs : right term 
	 *
	 *  \return double containing the result of the addition
	 */
double add(double lhs, double rhs);

	/*!
	 *\brief Substraction function
	 *
	 *  Substraction function to apply an operator + between two terms
	 *
	 *  \param lhs : left term,
	 * rhs : right term
	 *
	 *  \return double containing the result of the substraction
	 */
double sub(double lhs, double rhs);

	/*!
	 *\brief Multiplication function
	 *
	 *  Multiplication function to apply an operator * between two terms
	 *
	 *  \param lhs : left term,
	 * rhs : right term
	 *
	 *  \return double containing the result of the multiplication
	 */
double mul(double lhs, double rhs);

	/*!
	*\brief Division function
	*
	*  Division function to apply an operator + between two terms
	*
	*  \param lhs : left term,
	* rhs : right term
	*
	*  \return double containing the result of the division
	*/
double div(double lhs, double rhs);


#endif //EVALUATOR_INCLUDED
