#include <iostream>
#include <string>
#include <CalculetteProject.h>
#include <calc_lib/lexer.h>

int main(){
	string chaine_test = "45-9+89*4";
	lexer(chaine_test);
}