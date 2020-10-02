#include <calc_lib\evaluator.h>
#include <calc_lib\bloc.h>
#include <iostream>
#include <string>

double evaluator(DynArray<Bloc*>& parsed_calcul )
{

	for (int ia = 0; ia < parsed_calcul.size() -1; ++ia) {
		
		double lhs = atof(((parsed_calcul[ia]->get_ptr_bas1())->get_valeur()).c_str());
		double rhs = atof(((parsed_calcul[ia]->get_ptr_bas2())->get_valeur()).c_str()); // Attention : probleme parser, si ca marche pas mettre une valeur fixe a rhs

		if (std::string(parsed_calcul[ia]->get_valeur(), 0, 1) == "+")
		{
			parsed_calcul[ia + 1]->set_valeur(std::to_string(add(lhs, rhs)));
		}
		else if (std::string(parsed_calcul[ia]->get_valeur(), 0, 1) == "-")
		{
			parsed_calcul[ia + 1]->set_valeur(std::to_string(sub(lhs, rhs)));
		}
		else if (std::string(parsed_calcul[ia]->get_valeur(), 0, 1) == "*")
		{
			parsed_calcul[ia + 1]->set_valeur(std::to_string(mul(lhs, rhs)));
		}
		else if (std::string(parsed_calcul[ia]->get_valeur(), 0, 1) == "/")
		{
			parsed_calcul[ia + 1]->set_valeur(std::to_string(div(lhs, rhs)));
		}

			/*

		enum Opr {+, -, =, /};
		Opr op = +;
		switch (op)
		// switch (std::string(parsed_calcul[ia]->get_valeur()),0,1) 
		{
		case +:
		    parsed_calcul[ia+1] = add(lhs, rhs);
			break;
		case -:
			parsed_calcul[ia + 1] = sub(lhs, rhs);
			break;
		case *:
			parsed_calcul[ia + 1] = mul(lhs, rhs);
			break;
		case /:
			parsed_calcul[ia + 1] = div(lhs, rhs);
			break;
		default:
			break;
		} */
	}
	
	double lhs = atof(((parsed_calcul[parsed_calcul.size() - 1]->get_ptr_bas1())->get_valeur()).c_str());
	double rhs = atof(((parsed_calcul[parsed_calcul.size() - 1]->get_ptr_bas2())->get_valeur()).c_str()); // Attention : probleme parser, si ca marche pas mettre une valeur fixe a rhs

	if (std::string(parsed_calcul[parsed_calcul.size() - 1]->get_valeur(), 0, 1) == "+")
	{
		return(add(lhs, rhs));
	}
	else if (std::string(parsed_calcul[parsed_calcul.size() - 1]->get_valeur(), 0, 1) == "-")
	{
		return(sub(lhs, rhs));
	}
	else if (std::string(parsed_calcul[parsed_calcul.size() - 1]->get_valeur(), 0, 1) == "*")
	{
		return(mul(lhs, rhs));
	}
	else
	{
		return(div(lhs, rhs));
	}



	/* 
	switch (std::string(parsed_calcul[parsed_calcul.size()-1]->get_valeur()),0,1) {
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
	default:
		break;
	} */
	
}


double add(double lhs, double rhs)
{
	return lhs + rhs;
}

double sub(double lhs, double rhs)
{
	return lhs - rhs;
}

double mul(double lhs, double rhs)
{
	return lhs * rhs;
}

double div(double lhs, double  rhs)
{
	return lhs / rhs;
}