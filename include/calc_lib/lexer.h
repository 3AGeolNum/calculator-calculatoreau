#pragma once

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

DynArray<Bloc*> lexer(const std::string& input);