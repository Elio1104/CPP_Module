#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "colors.h"

#define DATABASE "./data.csv"

class BitcoinExchange {
    private :
        std::map< std::string , float >   _map;
        std::string _inputFile;
        
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& other );
        BitcoinExchange& operator=( const BitcoinExchange& other );

    public :
        BitcoinExchange( std::string database );
        ~BitcoinExchange( void ) ;

        void readDB( void );
        void fillMap( std::string line );

        void readInputFile( void );
        void compareDates( std::string line );

        int checkDate( std::string date );
        int checkDay( std::string day );
        int checkMonth( std::string month );
        int checkYear( std::string year );

        int checkConnector( std::string connector );

        float checkValue( std::string value );

        int checkDateValidity( std::string year, std::string month , std::string day );

        void findDate( std::string date, float val );
        std::string decreaseDate( std::string date );
        
        void error( std::string type );
};