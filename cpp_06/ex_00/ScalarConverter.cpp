#include "ScalarConverter.hpp"

#include <string>

ScalarConverter::ScalarConverter( void ) {
    this->_c = '\0';
    this->_n = 0;
    this->_f = 0.0f;
    this->_d = 0.0;
}

ScalarConverter::ScalarConverter( const ScalarConverter& src ) {
    *this = src;
}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs ) {
    if ( this != &rhs ) {
        this->_n = rhs._n;
        this->_f = rhs._f;
        this->_c = rhs._c;
        this->_d = rhs._d;
    }
    return *this;
}

void ScalarConverter::convert( std::string str )
{
	_str = str;
	_impossible = false;
	ScalarConverter::setType();
	if ( _type == NONE ) {
        throw ScalarConverter::ConverterException();
    }
	ScalarConverter::cast();
	ScalarConverter::print();
}

void ScalarConverter::cast(void)
{
	try {
		switch ( _type ) {
		case CHAR:
			_c = _str[0];
			_n = static_cast< int >( _c );
			_f = static_cast< float >( _c );
			_d = static_cast< double >( _c );
			break;
		case INT:
			_n = stoi( _str );
			_f = static_cast< float >( _n );
			_d = static_cast< double >( _n );
			_c = static_cast< char >( _n );
			break;
		case FLOAT:
			_f = stof( _str );
			_n = static_cast< int >( _f );
			_d = static_cast< double >( _f );
			_c = static_cast< char >( _f );
			break;
		case DOUBLE:
			_d = stod( _str );
			_n = static_cast< int >( _d );
			_f = static_cast< float >( _d );
			_c = static_cast< char >( _d );
			break;
		default:
			break;
    }

	} catch ( std::exception& e) {
		throw ScalarConverter::ConverterCast() ;
		_impossible = true;
		return ;
	}
}

/* ------------------- Print ------------------- */

void ScalarConverter::print()
{
    std::cout << "char: " ; ScalarConverter::printChar();
    std::cout << "int: " ; ScalarConverter::printInt();
    std::cout << "float: " ; ScalarConverter::printFloat();
    std::cout << "double: " ; ScalarConverter::printDouble();
}

void ScalarConverter::printChar(void)
{
	if ( ScalarConverter::isLiterals() || ( !std::isprint( _n ) && ( _n >= 127 ) ) ) {
        std::cout << "Impossible";
    } else if ( !std::isprint( _n ) ) {
        std::cout << "None displayable";
    } else {
        std::cout << "'" << _c << "'";
    }
    std::cout << std::endl;
}

void ScalarConverter::printInt(void)
{
    if ( ScalarConverter::isLiterals() || ( !std::isprint( _n ) && ( _n >= 127 ) ) ) {
        std::cout << "Impossible";
    } else {
        std::cout << _n;
    }
    std::cout << std::endl;
}

void ScalarConverter::printFloat(void)
{
	if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nanf";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inff";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inff";
    } else if ( _impossible ) {
        std::cout << "Impossible";
    } else {
        if ( _f - static_cast< int > ( _f ) == 0 ) {
            std::cout << _f << ".0f";
        } else {
            std::cout << _f << "f";
        }
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(void)
{
	if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inf";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inf";
    } else if ( _impossible ) {
        std::cout << "Impossible";
    } else {
        if ( _d - static_cast< int > ( _d ) == 0 ) {
            std::cout << _d << ".0";
        } else {
            std::cout << _d << "f";
        }
    }
    std::cout << std::endl;
}

/* ---------------- Type Finder ---------------- */

void ScalarConverter::setType( void ) {
    if ( ScalarConverter::isChar() ) {
        _type = CHAR;
    } else if ( ScalarConverter::isInt() ) {
        _type = INT;
    } else if ( ScalarConverter::isFloat() ) {
        _type = FLOAT;
    } else if ( ScalarConverter::isDouble() ) {
        _type = DOUBLE;
    } else if ( ScalarConverter::isLiterals() ) {
        _type = LITERALS;
    } else {
        _type = NONE;
    }
}

bool ScalarConverter::isChar(void)
{
    return _str.length() == 1 && std::isalpha( _str[0] ) && std::isprint( _str[0] );
}

bool ScalarConverter::isInt(void)
{
	int j = 0;
	if ( _str[j] == '-' || _str[j] == '+')
		j++;
	for (int i( j ); i < ( int )_str.length(); i++) {
		if ( !std::isdigit( _str[i] ) )
			return false;
	}
    return true;
}

bool ScalarConverter::isFloat(void)
{
    if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int j = 0;
    int found = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
	}
	return true;
}

bool ScalarConverter::isDouble(void)
{
    if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int j = 0;
    int found = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
	}
	return true;
}

bool ScalarConverter::isLiterals(void)
{
    if (( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
        || ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
        || ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ) ) {
            return true;
    } 
    return false;
}


/* ---------------- Exception Classes ---------------- */

const char* ScalarConverter::ConverterException::what() const throw() {
	return "Unknown type";
}

const char* ScalarConverter::ConverterCast::what() const throw() {
	return "Error while casting";
}

