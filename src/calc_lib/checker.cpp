#include <calc_lib/checker.h>


Checker::Checker(std::string str): input_(str){

}


Checker::~Checker(){

}


bool  Checker::is_input_empty(std::string str){
        return str.empty() or str.find_first_not_of(" ") == std::string::npos or str.find_first_not_of("	") == std::string::npos;
}

void Checker::check_pos(int pos){
	if (pos == -1) {
                	std::cout << " is a non valid element. Only numbers integer or float and  basic operators (*,+,-,/) are authorized."<< std::endl;
                }
                else if (pos > 10){
                        op_ += 1;
                        std::cout << "operator = " << op_ <<  std::endl;

                        if (op_ == 2){
                        std::cout << "Invalid argument. Two successive operator are not valid" << std::endl;
                        }
                }

                else if (pos == 10){
			op_ = op_;
                }
                else if(pos < 10 and pos >0){
			op_ = 0;

                //Reinitialisation of operator
              
                }


}

void Checker::check(){
	if (is_input_empty(input_)){
                std::cout << "Please, write something." << std::endl;
                checked_ = false;
                return;
	}

        for(int a=0; a <= input_.size()-1 ; ++a){
                std::cout << "Current element is  n°" << a  << " : "<< input_[a] << std::endl;
                int pos = auth_.find(input_[a]);
                check_pos(pos);
        }
        checked_ = true;


	}







