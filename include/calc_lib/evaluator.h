#ifndef EVALUATOR_INCLUDED
#define EVALUATOR_INCLUDED

#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>


double DynArray<Bloc*> evaluator(DynArray<Bloc*> const& calc)

double add(lhs, rhs);
double sub(lhs, rhs);
double mul(lhs, rhs);
double div(lhs, rhs);

#endif //EVALUATOR_INCLUDED
