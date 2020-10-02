#include <calc_lib\evaluator.h>
#include <calc_lib\parser.h>
#include <calc_lib\bloc.h>
#include <iostream>

double DynArray<Bloc*>::evaluator(DynArray<Bloc*> const& calc )
{
	DynArray<Bloc*> parsed_calcul;
	parsed_calcul = parser(calc);

	for (int ia = 0; ia < parsed_calcul.size() - 1; ++ia) {
		double lhs = atof(((parsed_calcul[ia]->get_ptr_bas1())->get_valeur()).c_str());
		double rhs = atof(((parsed_calcul[ia]->get_ptr_bas2())->get_valeur()).c_str());

		char op = parsed_calcul.cstr()[ia];

		switch (parsed_calcul[ia]->get_valeur()) {
		case "+":
		    parsed_calcul[ia+1] = add(lhs, rhs);
			break;
		case "-":
			parsed_calcul[ia + 1] = sub(lhs, rhs);
			break;
		case "*":
			parsed_calcul[ia + 1] = mul(lhs, rhs);
			break;
		case "/":
			parsed_calcul[ia + 1] = div(lhs, rhs);
			break;
		}
	}

	switch (parsed_calcul[parsed_calcul.size()-1]->get_valeur()) {
		double lhs = atof(((parsed_calcul[parsed_calcul.size() - 1]->get_ptr_bas1())->get_valeur()).c_str());
		double rhs = atof(((parsed_calcul[parsed_calcul.size() - 1]->get_ptr_bas2())->get_valeur()).c_str());
	case "+":
		return add(lhs, rhs);
		break;
	case "-":
		return sub(lhs, rhs);
		break;
	case "*":
		return mul(lhs, rhs);
		break;
	case "/":
		return div(lhs, rhs);
		break;
	}
}


double add(lhs, rhs)
{
	return lhs + rhs;
}

double sub(lhs, rhs)
{
	return lhs - rhs;
}

double mul(lhs, rhs)
{
	return lhs * rhs;
}

double div(lhs, rhs)
{
	return lhs / rhs;
}