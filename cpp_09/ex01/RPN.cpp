#include "RPN.hpp"

RPN::RPN ( std::string input ) : _input( input ) {
    readInput();
}

RPN::RPN( const RPN &other ) : _input( other._input ) {
    readInput();
}

RPN::~RPN( void ) {}

RPN &RPN::operator=( const RPN &other ) {
    if (this != &other) {
        this->_input = other._input ;
        readInput();
    }
    return *this;
}

void RPN::error(std::string type)
{
	std::cout << FRED("Error: ") << type << std::endl;
	exit( 1 );
}

void RPN::readInput( void ) {
    if ( _input.size() < 3 )
        error( "argument size too low.");
    for (size_t i = 0; i < _input.size(); i++ ) {
        if (_input[i] != ' ')
		{
			if (isdigit(_input[i]) != 0)
				_numbers.push(_input[i] - '0');
			else if (checkOperator(_input[i]))
				_operators.push(_input[i]);
			if (_operators.size() >= 1 && _numbers.size() >= 2)
				singleOperation();
		}
    }
    if (_operators.size() != 0 || _numbers.size() != 1 )
        error("Invalid RPN.");
    std::cout << _numbers.top() << std::endl;
}

int RPN::checkOperator( char action ) {
    if (action != '+' && action != '-' && action != '/' && action != '*')
		error( "Invalid operator." );
	return (1);
}

void RPN::singleOperation( void ) {
    int operand2 = _numbers.top();
    _numbers.pop();
    int operand1 = _numbers.top();
    _numbers.pop();
    char action = _operators.top();
    _operators.pop();

    switch (action)
	{
		case '*':
			_numbers.push( operand1 * operand2 );
			break;
		case '+':
			_numbers.push( operand1 + operand2 );
			break;
		case '-':
			_numbers.push( operand1 - operand2 );
			break;
		case '/':
            if (operand2 == 0)
                error("Can't divide by 0.");
			_numbers.push( operand1 / operand2 );
			break;
		default:
			error("invalid case.");
	}
}