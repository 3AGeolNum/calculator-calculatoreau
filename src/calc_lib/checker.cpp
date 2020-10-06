#include <calc_lib/checker.h>

Checker::Checker( std::string str ) : input_( str ) {}

Checker::~Checker() {}

bool Checker::is_input_empty( std::string str )
{
    return str.empty() || str.find_first_not_of( " " ) == std::string::npos
           || str.find_first_not_of( "	" ) == std::string::npos;
}

void Checker::check_pos( int pos )
{
    if( pos == -1 )
    {
        // This is the case where the element is not part of the authorised
        // elements
        std::cout << " Non valid element. Only numbers integer or float and  "
                     "basic operators (*,+,-,/) are authorized."
                  << std::endl;
        checked_ = false;
    }
    else if( pos > 11 && pos != 13 && pos != auth_.size()-1 )
    {
        // This behaviour is for every operator minus minus that have a specific
        // behaviour due to negative number
        op_ += 1;
        std::cout << "operator = " << op_ << std::endl;

		
        if( op_ == 2 || min_ != 0 )
        {
            // Here it is testing there is only one operator between two numbers
            std::cout << "Invalid argument. Two successive operator that are "
                         "not minus is not valid"
                      << std::endl;
            checked_ = false;
        }
        point_ = false;
    }

	else if( pos == auth_.size()-1 )
    {
        // This behaviour is for every operator point that have a specific
        // behaviour due to negative number
        op_ += 1;
        std::cout << "operator is point " << op_ << std::endl;
		
		if (point_) {
            checked_ = false;
            std::cout << "Two points detected before new operator, invalid "
                         "operation.";
		}
        point_ = true;
        if( op_ == 2 || min_ != 0 )
        {
            // Here it is testing there is only one operator between two numbers
            std::cout << "Invalid argument. Two successive operator that are "
                         "not minus is not valid"
                      << std::endl;
            checked_ = false;
        }
    }
    else if( pos == 13 )
    {
        // Here is the behaviour abour minus
        point_ = false;
        min_ += 1;
        if( min_ >= 3 )
        { // Two minus can be used for exemple 8--2 which would be 8+2 so only
          // three minus is a bad situation
            std::cout << "Invalid argument. More too many minux operator"
                      << std::endl;
            checked_ = false;
        }
    }
   
        else if( pos < 11 && pos > 0 )
        {
            // Here is the behaviour for numbers that reset the counter for the
            // operators
            op_ = 0;
            min_ = 0;
            // Reinitialisation of operator and minus
        }
}

void Checker::is_end_operator()
{
    // We start by checking if the string is empty this is due to the way the
    // structure is done. It is up for improvement
    if( !is_input_empty( input_ ) )
    {
        int start =
            auth_.find( input_[0] ); // First character of the input string
        int end = auth_.find(
            input_[input_.size() - 1] ); // Last character of the input string

        if( start > 11 && start != 13 )
        {
            // Check if the first operator is invalid. The Minus can be used for
            // a negative number
            checked_ = false;
            return;
        }

        if( end > 10 )
        {
            // No operator is allowed at the end
            checked_ = false;
        }
    }
}

void Checker::check()
{
    if( is_input_empty( input_ ) )
    { // If the input is empty, no calcul can be done
        std::cout << "Please, write something." << std::endl;
        checked_ = false;
        return;
    }

    for( int a = 0; a <= input_.size() - 1; ++a )
    { // Loop inside the string
        // std::cout << "Current element is  n°" << a  << " : "<< input_[a] <<
        // std::endl;
        if( checked_ == false )
        { // No need to continue if one variable is incorrect
            return;
        }
        int pos = auth_.find( input_[a] ); // Retrieving the character if it is
                                           // valid or npos if not
        check_pos( pos ); // Process the position or the npos
    }
}

void Checker::remove_space( std::string& initial_string )
{
    std::string string_without_spaces;
    for( int pos = 0; pos < initial_string.length(); ++pos )
    {
        if( initial_string[pos] != ' ' )
        {
            string_without_spaces.push_back( initial_string[pos] );
        }
    }

    initial_string = string_without_spaces;
}

void Checker::change_comma_into_point( std::string& initial_string )
{
    for( int pos = 0; pos < initial_string.length(); ++pos )
    {
        if( initial_string[pos] == ',' )
        {
            initial_string[pos] = '.';
        }
    }
}

bool Checker::complete_check()
{
    remove_space( input_ );
    change_comma_into_point( input_ );

    is_end_operator(); // Check is the first and last character are operator
                       // first to avoid the loop
    check();
    return checked_;
}

bool Checker::get_checked()
{
    return checked_;
}