#include <iostream>

class Checker{
public :
	Checker(std::string str);
	~Checker();
	bool is_input_empty(std::string str);
	void check_pos(int pos);
	void check();

private:
	int op_ = 0;
	bool checked_ = true;
	std::string auth_ = "1234567890 +-*/?,";
	std::string input_;

};
