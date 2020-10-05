/**
 * \file lexer.h
 * \brief Lexer of the calculator
 * \author PERRIER Yassine
 * \version 1.0
 * \date 28 septembre 2020
 *
 * header of the functions needed to cut the input string into unitary blocs.
 *
 */

#ifndef LEXER_h
#define LEXER_h

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

//! Make a copy of a DynArray into another.
/**
 * \fn void copy_local (DynArray<Bloc*>& new_tab, const DynArray<Bloc*>& local_tab_copied)
 * \brief Function copying values of one DynArray into another.
 *
 * \param new_tab New DynArray which will get the copy.
 *       local_tab_copied the DynArray copied.
 * \version {1.0}
 * \author {PERRIER Yassine}
 * \date October 2nd 2020
 */
void copy_local(DynArray<Bloc*>& new_tab, DynArray<Bloc*>& local_tab_copied);

//! Remove all nullpointers in case there are nullptr.
/**
 * \fn DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size)
 * \brief Function eliminating all null pointers from a dynarray, by creating a new dynarray with a given size.
 *
 * \param other The DynArray to be cleaned.
 *	      size Size of the new dynarray to be returned.
 * \return A new DynArray with the new size.
 * \version {1.0}
 * \author {PERRIER Yassine}
 * \date October 2nd 2020
 */
DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size);

//! Build a DynArray containing bloc objects of each element of the input string.
/**
 * \fn DynArray<Bloc*> lexer (const std::string& input)
 * \brief Function dividing the input string given by the user into small blocs.
 *
 * \param input Input string of the user.
 * \return A dynarray containing blocs of each element of the input string. 
 * \version {1.0}
 * \author {PERRIER Yassine}
 * \date October 2nd 2020
 */
DynArray<Bloc*> lexer(const std::string& input);

#endif