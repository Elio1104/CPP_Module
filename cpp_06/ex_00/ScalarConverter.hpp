#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>
#include <string>

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter {
    private :
        ScalarConverter( void );
        ScalarConverter( const ScalarConverter& src);
        ~ScalarConverter( void );
        ScalarConverter& operator=( const ScalarConverter& other );

        static char        _c;
        static int         _n;
        static float       _f;
        static double      _d;

        static e_type      _type;
        static std::string _str;

		static bool		_impossible;

    public :
        static void convert( std::string str);
        static void setType( void );

        static bool isChar( void );
        static bool isInt( void );
        static bool isFloat( void );
        static bool isDouble( void );
        static bool isLiterals( void );

		static void printChar( void );
		static void printInt( void );
		static void printFloat( void );
		static void printDouble( void );

		static void cast( void );
		static void print( void );

		class ConverterException : public std::exception {
        	virtual const char* what() const throw();
    	};

		class ConverterCast : public std::exception {
        	virtual const char* what() const throw();
    	};
};

#endif