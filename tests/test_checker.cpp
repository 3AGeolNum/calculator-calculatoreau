#include <iostream>
#include <calc_lib\checker.h>
#include <string>



int main (){
	std::string in;
	
	while ( in != "quit"){
		std::cout << "Enter your equation, to exit enter quit" << std::endl;
		//std::getline (std::cin , in);
		in = "-45-9+89*-4";
		Checker checke = Checker(in);
		checke.complete_check();
		std::cout << checke.get_checked() << std::endl;
	}
	return 0;

}