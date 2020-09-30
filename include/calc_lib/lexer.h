#pragma once

#include <calc_lib/bloc.h>
#include <calc_lib/DynArray.h>

void copy_local(DynArray<Bloc*>& new_tab, DynArray<Bloc*>& local_tab_copied);
DynArray<Bloc*> cleaner_tab(const DynArray<Bloc*>& other, int size);
DynArray<Bloc*> lexer(const std::string& input);
