#include <iostream>
#include <calc_lib/checker.h>
#include <string>



int main (){
	std::string in = "-45 -9+89*-4+2.1-2,1";
	
	//while ( in != "quit"){
		//std::cout << "Enter your equation, to exit enter quit" << std::endl;
		//std::getline (std::cin , in);
		//in = "-45-9+89*-4";
	Checker checke = Checker(in);
	if(!checke.complete_check()){
		return 1;
	}
	std::cout << checke.get_input_modified() << std::endl;
	
	//}

	return 0;
}