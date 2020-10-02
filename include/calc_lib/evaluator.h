#ifndef EVALUATOR_INCLUDED
#define EVALUATOR_INCLUDED

#include <calc_lib\bloc.h>
#include <calc_lib\DynArray.h>


double evaluator(DynArray<Bloc*>& calc);

double add(double lhs, double rhs);
double sub(double lhs, double rhs);
double mul(double lhs, double rhs);
double div(double lhs, double rhs);


#endif //EVALUATOR_INCLUDED
