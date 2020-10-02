#include <iostream>
#include <calc_lib\checker.h>
#include <string>



int main (){
	std::string in;
	std::cout << "Enter your equation, to exit enter quit" << std::endl ;
	while ( in != "quit"){
	std::getline (std::cin , in);
	Checker checke = Checker(in);
	checke.check();
	std::cout << checke.get_checked() << std::endl;
	}
	return 0;

}


