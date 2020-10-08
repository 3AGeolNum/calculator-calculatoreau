/**
 * \file parser.h
 * \brief Parser of the calculator
 * \author CAPILLON Quentin
 * \version 1.0
 * \date 06 octobre 2020
 *
 * header of the functions necessary to define the order of the calculations that the operator will do.
 *
 */

#ifndef PARSER_h
#define PARSER_h

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

//! create a Bloc array whith just operators.
/**
 * \fn DynArray<Bloc*> generate_operator_array( const DynArray<Bloc*>& calcul_initial )
 * \brief Function copying values of one DynArray into another.
 *
 * \param calcul_initial : Bloc array returned by the lexer.
 * \return A new DynArray with all the operator in the same order of calcul_initial.
 * \version {1.0}
 * \author {CAPILLON Quentin}
 * \date October 6th 2020
**/
DynArray<Bloc*> generate_operator_array( const DynArray<Bloc*>& calcul_initial );

//! make links an operator with the blocs that will undergo the operation.
/**
 * \fn void link_bloc( const DynArray<Bloc*>& operator_array, const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2 )
 * \brief edit ptr_bas1_ and ptr_bas2_ for an operator Bloc.
 *
 * \param calcul_initial : Bloc array returned by the lexer.
 *		  operator_array : Bloc array whith just operators.
 *		  num_ope : indice of the Bloc to linke in the operator_array.
 *		  num_bloc1 : indice of the first Bloc to be linked in the calcul_initial.
 *		  num_bloc2 : indice of the second Bloc to be linked in the calcul_initial.
 * \version {1.0}
 * \author {CAPILLON Quentin}
 * \date October 6th 2020
**/
void link_bloc( const DynArray<Bloc*>& operator_array, const DynArray<Bloc*>& calcul_initial,int num_ope, int num_bloc1, int num_bloc2 );

//! fill operator_array_ordonated by the end with the operators corresponding to symb1 or symb2.
/**
 * \fn void fill_ordonated_operator_array( std::string symb1, std::string symb2, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count )
 * \brief puch back operator_array_ordonated whith alla opérators + and - or * and /.
 *
 * \param operator_array : Bloc array whith just operators.
 *		  operator_array_ordonated : Bloc array whith just operators ordonated for calculation.
 *		  symb1 : symbole of an operator has to be filled.
 *		  symb2 : symbole of an other operator has to be filled in the same time.
 *		  count : number of Blocs added to operator_array_ordonated.
 * \version {1.0}
 * \author {CAPILLON Quentin}
 * \date October 6th 2020
**/
void fill_ordonated_operator_array( std::string symb1, std::string symb2, const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated, int& count );

//! ordonate operator_array in operator_array_ordonated.
/**
 * \fn void ordonate_array( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated )
 * \brief fonction calling fill_ordonated_operator_array(...) for * and / then for + and - .
 *
 * \param operator_array : Bloc array whith just operators.
 *		  operator_array_ordonated : Bloc array whith just operators ordonated for calculation.
 * \return A DynArray with all the operator in the order needed for calculation.
 * \version {1.0}
 * \author {CAPILLON Quentin}
 * \date October 6th 2020
**/
void ordonate_array( const DynArray<Bloc*>& operator_array, DynArray<Bloc*>& operator_array_ordonated );

//! Analyze the array of Blocs given by the lexer and give another array of Blocc with only operators organized for the calculator.
/**
 * \fn DynArray<Bloc*> parser( const DynArray<Bloc*>& calcul_initial )
 * \brief edit the links of the operator Blocs and organize them in a new array.
 *
 * \param calcul_initial : Bloc array returned by the lexer.
 * \return A DynArray with all the operator in the order needed for calculation.
 * \version {1.0}
 * \author {CAPILLON Quentin}
 * \date October 6th 2020
**/
DynArray<Bloc*> parser( const DynArray<Bloc*>& calcul_initial );

#endif