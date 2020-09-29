#include <iostream>
#include <checker.h>




bool is_input_empty(std::string str){
	return str.empty() or str.find_first_not_of(" ") == std::string::npos or str.find_first_not_of("	") == std::string::npos;
}


int process_pos(int pos,int op){
if (pos == -1) {
                        std::cout << " is a non valid element. Only numbers integer or float and  basic operators (*,+,-,/) are authorized."<< std::endl;
                return op;
                }
                else if (pos > 10){
                        op += 1;
                        std::cout << "operator = " << op <<  std::endl;

                        if (op == 2){
                        std::cout << "Invalid argument. Two successive operator are not valid" << std::endl;
                        return op;
                        }
                }

                else if (pos == 10){
			return op;
                }
                else if(pos < 10 and pos >0){

                //Reinitialisation of operator
                return 0;
		}
		return 0;
	

}


void check(std::string in ) {

	std::string auth = "1234567890 +-*/?,";
	int op = 0;
	if (is_input_empty(in)){
		std::cout << "Please, write something." << std::endl;
		return;

	}

	for(int a=0; a <= in.size()-1 ; ++a){
		std::cout << "Current element is  n°" << a  << " : "<< in[a] << std::endl;
		int pos = auth.find(in[a]);
		op = process_pos(pos,op);
	}	
	return;
}

int main (){
	std::string in;
	std::cout << "Enter your equation, to exit enter quit" << std::endl ;
	while ( in != "quit"){
	getline (std::cin, in);
	Checker checke = Checker(in);
	checke.check();
	std::cout << in << std::endl;
	}
	return 0;

}


