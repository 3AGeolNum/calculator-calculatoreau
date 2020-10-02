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

#pragma once

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

void copy_local(DynArray<Bloc*>& new_tab, DynArray<Bloc*>& local_tab_copied);
DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size);

DynArray<Bloc*> lexer(const std::string& input);

#endif