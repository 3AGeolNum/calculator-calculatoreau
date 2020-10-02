#include <calc_lib/checker.h>


Checker::Checker(std::string str): input_(str){

}


Checker::~Checker(){

}


bool  Checker::is_input_empty(std::string str){
        return str.empty() || str.find_first_not_of(" ") == std::string::npos || str.find_first_not_of("	") == std::string::npos;
}

void Checker::check_pos(int pos){
	if (pos == -1) {
                	std::cout << " is a non valid element. Only numbers integer or float and  basic operators (*,+,-,/) are authorized."<< std::endl;
					checked_ = false;
                }
        else if (pos > 11 && pos != 13){
                op_ += 1;
                std::cout << "operator = " << op_ <<  std::endl;

                if (op_ == 2 || min_ != 0){
                        std::cout << "Invalid argument. Two successive operator that are not minus is not valid" << std::endl;
			checked_ = false;
                        }
                }
	else if (pos == 13){
		
		min_ += 1;

		if (min_ >= 3){
		std::cout << "Invalid argument. More too many minux operator" << std::endl;
		checked_ = false ;
		}
			
		}
        else if(pos < 11 && pos >0){
		
		op_ = 0;
		min_ = 0;

                //Reinitialisation of operator and minus
              
                }


}

void Checker::is_end_operator() {
	if (!is_input_empty(input_)) {
		int start = auth_.find(input_[0]);
		int end = auth_.find(input_[input_.size() - 1]);

		if (start > 11 && start != 13) {
			checked_ = false;
			return;
		}

		if (end > 10) {
			checked_ = false;
		}
	}
	
}

void Checker::check(){
	if (is_input_empty(input_)){
                std::cout << "Please, write something." << std::endl;
                checked_ = false;
                return;
	}

        for(int a=0; a <= input_.size()-1 ; ++a){
                //std::cout << "Current element is  n°" << a  << " : "<< input_[a] << std::endl;
			if (checked_ == false) {
				return;
				}
                int pos = auth_.find(input_[a]);
                check_pos(pos);
        }


	}

bool Checker::complete_check() {
	is_end_operator();
	check();
	return checked_;

}

bool Checker::get_checked(){

	return checked_;

}